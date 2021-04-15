#include "semantic.h"
#include "types.h"
#include "env.h"
#include "errormsg.h"
#include "util.h"

typedef void *Tr_exp;

typedef struct expty_ {
    Tr_exp exp;
    Ty_ty  ty;
} expty;

expty expTy(Tr_exp exp, Ty_ty ty) {
    expty e;
    e.exp = exp;
    e.ty = ty;
    return e;
}

expty transVar(S_table venv, S_table tenv, A_var v);
expty transExp(S_table venv, S_table tenv, A_exp e);
void  transDec(S_table venv, S_table tenv, A_dec d);
Ty_ty transTy (S_table tenv, A_ty t);


static int inside = 0;

// muda 'Ty_name' para o tipo atual
static Ty_ty actual_ty(Ty_ty ty) {
    Ty_ty t = ty;
    while(t->kind == Ty_name) t = t->u.name.ty;
    return t;
}

// Compare dois tipos reais
// Ty_nil == Ty_record
static bool actual_eq(Ty_ty source, Ty_ty target) {
    Ty_ty t1 = actual_ty(source);
    Ty_ty t2 = actual_ty(target);
    return ((t1->kind == Ty_record || t1->kind == Ty_array) && t1 == t2) ||
           (t1->kind == Ty_record && t2->kind == Ty_nil) ||
           (t1->kind == Ty_nil && t2->kind == Ty_record) ||
           (t1->kind != Ty_record && t1->kind != Ty_array && t1->kind == t2->kind);
}

void SEM_transProg(A_exp exp) {
    S_table venv = E_base_venv(), tenv = E_base_tenv();
    transExp(venv, tenv, exp);
}

// traduz variáveis
// return: actual type
expty transVar(S_table venv, S_table tenv, A_var v) {
    switch(v->kind) {
        case A_simpleVar: {
            E_enventry x = S_look(venv, v->u.simple);
            if(x && x->kind == E_varEntry) {
                return expTy(NULL, actual_ty(x->u.var.ty));
            } else {
                EM_error(v->pos, "Variável não definida %s", S_name(v->u.simple));
                return expTy(NULL, Ty_Int());
            }
        }
        case A_fieldVar: {
            expty var = transVar(venv, tenv, v->u.field.var);
            if(var.ty->kind != Ty_record) {
                EM_error(v->u.field.var->pos, "essa variável não é uma variável do tipo de registro");
                return expTy(NULL, Ty_Int());
            } else {
                Ty_fieldList fl;
                for(fl = var.ty->u.record; fl; fl = fl->tail) {
                    if(fl->head->name == v->u.field.sym) {
                        return expTy(NULL, actual_ty(fl->head->ty));
                    }
                }
                EM_error(v->u.field.var->pos, "Não existe nenhum campo <%s> no registro", S_name(v->u.field.sym));
                return expTy(NULL, Ty_Int());
            }
        }
        case A_subscriptVar: {
            expty var = transVar(venv, tenv, v->u.subscript.var);
            if(var.ty->kind != Ty_array) {
                EM_error(v->u.subscript.var->pos, "não é uma variável do tipo array");
                return expTy(NULL, Ty_Int());
            } else {
                expty index = transExp(venv, tenv, v->u.subscript.exp);
                if(index.ty->kind != Ty_int) {
                    EM_error(v->u.subscript.exp->pos, "É necessário um inteiro no índice da matriz");
                    return expTy(NULL, Ty_Int());
                }
                return expTy(NULL, actual_ty(var.ty->u.array));
            }
        }
    }
    assert(0); // wrong kind
}

// traduz expressões
// return: tipo atual
expty transExp(S_table venv, S_table tenv, A_exp e) {
    switch(e->kind) {
        case A_varExp: return transVar(venv, tenv, e->u.var);
        case A_nilExp: return expTy(NULL, Ty_Nil());
        case A_intExp: return expTy(NULL, Ty_Int());
        case A_stringExp: return expTy(NULL, Ty_String());
        case A_callExp: {
            E_enventry fun_entry = S_look(venv, e->u.call.func);
            if(!fun_entry || (fun_entry->kind != E_funEntry)) {
                EM_error(e->pos, "Tipo não definido %s", S_name(e->u.call.func));
                return expTy(NULL, Ty_Int());
            } else {
                A_expList el;
                Ty_tyList tl;
                for(el = e->u.call.args, tl = fun_entry->u.fun.formals; el && tl; el = el->tail, tl = tl->tail) {
                    expty exp = transExp(venv, tenv, el->head);
                    Ty_ty actual = actual_ty(tl->head);
                    if(!actual_eq(tl->head, exp.ty)) {
                        EM_error(el->head->pos, "Tipo de argumento não corresponde ao parâmetro");
                        return expTy(NULL, Ty_Int());
                    }
                }
                if(el) {
                    EM_error(el->head->pos, "Muitos argumentos");
                    return expTy(NULL, Ty_Int());
                }
                if(tl) {
                    EM_error(e->pos, "Argumentos insuficientes");
                    return expTy(NULL, Ty_Int());
                }
                return expTy(NULL, actual_ty(fun_entry->u.fun.results));
            }
        } 
        case A_opExp: {
            expty left  = transExp(venv, tenv, e->u.op.left);
            expty right = transExp(venv, tenv, e->u.op.right);
            switch(e->u.op.oper) {
                case A_plusOp:
                case A_minusOp:
                case A_timesOp:
                case A_divideOp: {
                    if(left.ty->kind != Ty_int)
                        EM_error(e->u.op.left->pos, "Um inteiro é requerido");
                    if(right.ty->kind != Ty_int)
                        EM_error(e->u.op.right->pos, "Um inteiro é requerido");
                    return expTy(NULL, Ty_Int());
                }
                case A_eqOp:
                case A_neqOp: {
                    // pode ser aplicado a inteiros, strings e duas matrizes ou registros
                    if(!actual_eq(left.ty, right.ty)) {
                        EM_error(e->pos, "Tipo diferente para comparar");
                    }
                    return expTy(NULL, Ty_Int());
                }
                case A_ltOp:
                case A_leOp:
                case A_gtOp:
                case A_geOp: {
                    if(left.ty->kind != Ty_int || right.ty->kind != Ty_int) {
                        EM_error(e->pos, "Um inteiro é requerido");
                    }
                    return expTy(NULL, Ty_Int());
                }
            } /* switch */
        } /* A_opExp */
        case A_recordExp: {
            Ty_ty record_typ = S_look(tenv, e->u.record.typ);
            if(!record_typ) {
                EM_error(e->pos, "tipo não definido");
                return expTy(NULL, Ty_Record(NULL));
            }
            Ty_ty actual = actual_ty(record_typ);
            if(actual->kind != Ty_record) {
                EM_error(e->pos, "<%s> não é um tipo de registro", S_name(e->u.record.typ));
                return expTy(NULL, Ty_Record(NULL));
            }
            Ty_fieldList ty_fl;
            A_efieldList fl;
            for(fl = e->u.record.fields, ty_fl = actual->u.record; fl && ty_fl; fl = fl->tail, ty_fl = ty_fl->tail) {
                if(fl->head->name != ty_fl->head->name) {
                    EM_error(e->pos, " <%s> não é um nome de campo válido", S_name(fl->head->name));
                    return expTy(NULL, Ty_Record(NULL));
                }
                expty exp = transExp(venv, tenv, fl->head->exp);
                if(!actual_eq(exp.ty, ty_fl->head->ty)) {
                    EM_error(e->pos, "ambos os tipos de campo divergem");
                    return expTy(NULL, Ty_Record(NULL));
                }
            }
            return expTy(NULL, actual);
        }
        case A_seqExp: {
            expty exp = expTy(NULL, Ty_Void());
            A_expList el;
            for(el = e->u.seq; el; el = el->tail) {
                exp = transExp(venv, tenv, el->head);
            }
            return exp;
        }
        case A_assignExp: {
            expty var = transVar(venv, tenv, e->u.assign.var);
            expty exp = transExp(venv, tenv, e->u.assign.exp);
            if(!actual_eq(var.ty, exp.ty)) {
                EM_error(e->pos, "divergência de tipo entre variável e expressão");
            }
            return expTy(NULL, Ty_Void());
        }
        case A_ifExp: {
            expty test = transExp(venv, tenv, e->u.iff.test);
            if(test.ty->kind != Ty_int) {
                EM_error(e->pos, "a seção de teste deve ser inteira");
                return expTy(NULL, Ty_Void());
            }
            expty then = transExp(venv, tenv, e->u.iff.then);
            if(e->u.iff.elsee) {
                expty elsee = transExp(venv, tenv, e->u.iff.elsee);
                if(!actual_eq(then.ty, elsee.ty)) {
                    EM_error(e->pos, "a secao then-else deve ser do mesmo tipo");
                    return expTy(NULL, Ty_Void());
                }
                return expTy(NULL, then.ty);
            } else {
                if(then.ty->kind != Ty_void) {
                    EM_error(e->pos, "seção then precisa ser void");
                }
                return expTy(NULL, Ty_Void());
            }
        }
        case A_whileExp: {
            expty test = transExp(venv, tenv, e->u.whilee.test);
            if(test.ty->kind != Ty_int) {
                EM_error(e->u.whilee.test->pos, "seção test deve produzir um inteiro ");
                return expTy(NULL, Ty_Void());
            }
            inside++; // inside loop
            expty body = transExp(venv, tenv, e->u.whilee.body);
            inside--; // outside
            if(body.ty->kind != Ty_void) {
                EM_error(e->u.whilee.body->pos, "a seção do corpo não deve produzir valores");
                return expTy(NULL, Ty_Void());
            }
            return expTy(NULL, Ty_Void());
        }
        case A_forExp: {
            expty lo = transExp(venv, tenv, e->u.forr.lo);
            expty hi = transExp(venv, tenv, e->u.forr.hi);
            if(lo.ty->kind != Ty_int) {
                EM_error(e->u.forr.lo->pos, "parte inferior deve ser inteira");
                return expTy(NULL, Ty_Void());
            }
            if(hi.ty->kind != Ty_int) {
                EM_error(e->u.forr.hi->pos, "parte superior deve ser inteira");
                return expTy(NULL, Ty_Void());
            }
            S_beginScope(venv);
            S_enter(venv, e->u.forr.var, Ty_Int());
            inside++; // inside loop
            expty body = transExp(venv, tenv, e->u.forr.body);
            inside--; // outside
            if(body.ty->kind != Ty_void) {
                EM_error(e->u.forr.body->pos, "o corpo precisa ser void");
                return expTy(NULL, Ty_Void());
            }
            S_endScope(venv);
            return expTy(NULL, Ty_Void());
        }
        case A_breakExp: {
            if(!inside) {
                EM_error(e->pos, "expressão break fora do laço");
            }
            return expTy(NULL, Ty_Void());
        }
        case A_letExp: {
            expty exp;
            A_decList d;
            S_beginScope(venv);
            S_beginScope(tenv);
            for(d = e->u.let.decs; d; d = d->tail) {
                transDec(venv, tenv, d->head);
            }
            exp = transExp(venv, tenv, e->u.let.body);
            S_endScope(tenv);
            S_endScope(venv);
            return exp;
        }
        case A_arrayExp: {
            Ty_ty array_typ = S_look(tenv, e->u.array.typ);
            if(!array_typ) {
                EM_error(e->pos, "tipo indefinido %s", S_name(e->u.array.typ));
                return expTy(NULL, Ty_Array(NULL));
            }
            Ty_ty actual = actual_ty(array_typ);
            if(actual->kind != Ty_array) {
                EM_error(e->pos, "tipo de array necessário, mas foi dado outro %s", S_name(e->u.array.typ));
                return expTy(NULL, Ty_Array(NULL));
            }
            expty size_typ = transExp(venv, tenv, e->u.array.size);
            if(size_typ.ty->kind != Ty_int) {
                EM_error(e->u.array.size->pos, "inteiro requerido com tamanho de array");
                return expTy(NULL, Ty_Array(NULL));
            }
            expty init_typ = transExp(venv, tenv, e->u.array.init);
            if(!actual_eq(init_typ.ty, actual->u.array)) {
                EM_error(e->u.array.init->pos, "o tipo de inicialização não corresponde ao tipo fornecido");
                return expTy(NULL, Ty_Array(NULL));
            }
            return expTy(NULL, actual);
        }
    }
    assert(0); // deveria ter retornado de alguma cláusula do switch
}

void  transDec(S_table venv, S_table tenv, A_dec d) {
    switch(d->kind) {
        case A_varDec: {
            Ty_ty dec_ty = NULL; // declarar tipo talvez NULL
            if(d->u.var.typ != NULL) {
                dec_ty = S_look(tenv, d->u.var.typ);
                if(!dec_ty) {
                    EM_error(d->pos, "tipo indefinido %s", S_name(d->u.var.typ));
                    return;
                }
            }
            expty init_exp = transExp(venv, tenv, d->u.var.init);
            if(dec_ty != NULL) {
                if(!actual_eq(dec_ty, init_exp.ty)) {
                    EM_error(d->pos, "tipo de incompatibilidade entre declarar e inicializar");
                    return;
                }
            } else {
                if(init_exp.ty->kind == Ty_nil) {
                    EM_error(d->pos, "tipo nil ilegal: nil deve ser atribuído a um tipo de registro explicitamente");
                    return;
                }
            }
            S_enter(venv, d->u.var.var, E_VarEntry(init_exp.ty));
            return;
        }
        case A_typeDec: {
            A_nametyList type_list;
            bool cycle_decl = TRUE;

            int index = 0;
            void *typenames[10]; 

            for(type_list = d->u.type; type_list; type_list = type_list->tail) {
                S_enter(tenv, type_list->head->name, Ty_Name(type_list->head->name, NULL));
                for(int i = 0; i < index; i++) {
                    if(typenames[i] == (void *)type_list->head->name) {
                        EM_error(type_list->head->ty->pos, "tipo de redeclaração <%s>, existem dois tipos com o mesmo nome no mesmo lote (consecutivo) de tipos mutuamente recursivos.", S_name(type_list->head->name));
                    }
                }
                typenames[index++] = (void *)type_list->head->name;
            }
            for(type_list = d->u.type; type_list; type_list = type_list->tail) {
                Ty_ty t = transTy(tenv, type_list->head->ty);
                Ty_ty name_type = S_look(tenv, type_list->head->name);
                name_type->u.name.ty = t;
                if(t->kind != Ty_name) cycle_decl = FALSE;
            }
            if(cycle_decl) {
                EM_error(d->pos, "declaração de tipo de ciclo ilegal: deve conter pelo menos um tipo embutido");
                return;
            }
            return;
        }
        case A_functionDec: {
            A_fundecList fun_list;

            int index = 0;
            void *typenames[10];
            for(fun_list = d->u.function; fun_list; fun_list = fun_list->tail) {
                A_fieldList fl;
                Ty_ty ty;
                Ty_tyList head = NULL, tail = NULL;
                Ty_ty r;
                if(fun_list->head->result) {
                    r = S_look(tenv, fun_list->head->result);
                    if(!r) {
                        EM_error(fun_list->head->pos, "tipo de return indefinido %s", S_name(fun_list->head->result));
                        return;
                    }
                } else {
                    r = Ty_Void();
                }
                for(fl = fun_list->head->params; fl; fl = fl->tail) {
                    ty = S_look(tenv, fl->head->typ);
                    if(!ty) {
                        EM_error(fl->head->pos, "tipo de parametro indefinido %s", S_name(fl->head->typ));
                        return;
                    }
                    if(head) {
                        tail->tail = Ty_TyList(ty, NULL);
                        tail = tail->tail;
                    } else {
                        head = Ty_TyList(ty, NULL);
                        tail = head;
                    }
                }
                S_enter(venv, fun_list->head->name, E_FunEntry(head, r));

                for(int i = 0; i < index; i++) {
                    if(typenames[i] == (void *)fun_list->head->name) {
                        EM_error(fun_list->head->pos, "tipo de redeclaração <%s>, existem dois tipos com o mesmo nome no mesmo lote (consecutivo) de tipos mutuamente recursivos.", S_name(fun_list->head->name));
                    }
                }
                typenames[index++] = (void *)fun_list->head->name;
            }
            for(fun_list = d->u.function; fun_list; fun_list = fun_list->tail) {
                E_enventry fun_entry = S_look(venv, fun_list->head->name);
                S_beginScope(venv);
                A_fieldList fl;
                Ty_tyList tl = fun_entry->u.fun.formals;

                for(fl = fun_list->head->params; fl; fl = fl->tail, tl = tl->tail) {
                    S_enter(venv, fl->head->name, E_VarEntry(tl->head));
                }
                expty exp = transExp(venv, tenv, fun_list->head->body);
                if(!actual_eq(fun_entry->u.fun.results, exp.ty)) {
                    EM_error(d->pos, "tipo de corpo e tipo de retorno com <%s>", S_name(fun_list->head->name));
                    S_endScope(venv);
                    return;
                }
                S_endScope(venv);
            }
            return;
        }
    }
}

//traduuz o tipo
Ty_ty transTy (S_table tenv, A_ty t) {
    switch(t->kind) {
        case A_nameTy: {
            Ty_ty ty = S_look(tenv, t->u.name);
            if(!ty) {
                EM_error(t->pos, "tipo indefinido %s", S_name(t->u.name));
                return Ty_Void();
            }
            return ty;
        }
        case A_recordTy: {
            A_fieldList fl;
            Ty_field ty_f;
            Ty_fieldList ty_fl_head = NULL, ty_fl_tail = NULL;
            Ty_ty ty;
            for(fl = t->u.record; fl; fl = fl->tail) {
                ty = S_look(tenv, fl->head->typ);
                if(!ty) {
                    EM_error(fl->head->pos, "tipo indefinido %s", S_name(fl->head->typ));
                    return Ty_Void();
                }
                ty_f = Ty_Field(fl->head->name, ty);
                if(ty_fl_head) {
                    ty_fl_tail->tail = Ty_FieldList(ty_f, NULL);
                    ty_fl_tail = ty_fl_tail->tail;
                } else {
                    ty_fl_head = Ty_FieldList(ty_f, NULL);
                    ty_fl_tail = ty_fl_head;
                }
            }
            return Ty_Record(ty_fl_head);
        }
        case A_arrayTy: {
            Ty_ty ty = S_look(tenv, t->u.array);
            if(!ty) {
                EM_error(t->pos, "tipo indefinido %s", S_name(t->u.array));
                return Ty_Void();
            }
            return Ty_Array(ty);
        }
    }
    assert(0); 
}