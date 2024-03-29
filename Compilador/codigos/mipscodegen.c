#include "codegen.h"

static void emit(AS_instr instr);
static void munchStm(T_stm s);
static Temp_temp munchExp(T_exp e);
static Temp_temp emit_binop_imm(string op, T_exp e, int v);
static Temp_temp emit_binop_tri(string op, T_exp e1, T_exp e2);
static Temp_tempList munchArgs(T_expList args);

static AS_instrList instr_head = NULL, instr_last = NULL;
static F_frame stack_frame = NULL;

static char framesize[30];
static const int IMM_MAX = 32767;
static const int IMM_MIN = -32768;

AS_instrList F_codegen(F_frame f, T_stmList stmList) {
  T_stmList sl = stmList;
  instr_head = NULL, instr_last = NULL;
  stack_frame = f;
  for (; sl; sl = sl->tail) {
    munchStm(sl->head);
  }
  return instr_head;
}

static void emit(AS_instr instr) {
  if (instr_head == NULL) {
    instr_head = AS_InstrList(instr, NULL);
    instr_last = instr_head;
  } else {
    instr_last->tail = AS_InstrList(instr, NULL);
    instr_last = instr_last->tail;
  }
}

static void munchStm(T_stm s) {
  switch (s->kind) {
  case T_LABEL: {
    char buf[100];
    sprintf(buf, "%s:\n", Temp_labelstring(s->u.LABEL));
    emit(AS_Label(String(buf), s->u.LABEL));
    break;
  }
  case T_JUMP: {
    emit(AS_Oper(String("j `j0\n"), NULL, NULL, AS_Targets(s->u.JUMP.jumps)));
    break;
  }
  case T_CJUMP: {
    Temp_temp left = munchExp(s->u.CJUMP.left);
    Temp_temp right = munchExp(s->u.CJUMP.right);
    char buf[100];
    switch (s->u.CJUMP.op) {
    case T_eq:
      sprintf(buf, "%s `s0, `s1, `j0\n", "beq");
      break;
    case T_ne:
      sprintf(buf, "%s `s0, `s1, `j0\n", "bne");
      break;
    case T_lt:
      sprintf(buf, "%s `s0, `s1, `j0\n", "blt");
      break;
    case T_gt:
      sprintf(buf, "%s `s0, `s1, `j0\n", "bgt");
      break;
    case T_le:
      sprintf(buf, "%s `s0, `s1, `j0\n", "ble");
      break;
    case T_ge:
      sprintf(buf, "%s `s0, `s1, `j0\n", "bge");
      break;
    default:
      assert(0);
    }
    emit(AS_Oper(String(buf), NULL,
                 Temp_TempList(left, Temp_TempList(right, NULL)),
                 AS_Targets(Temp_LabelList(s->u.CJUMP.true, NULL))));
    break;
  }
  case T_MOVE: {
    T_exp dst = s->u.MOVE.dst, src = s->u.MOVE.src;
    if (dst->kind == T_MEM) {
      if (dst->u.MEM->kind == T_BINOP && dst->u.MEM->u.BINOP.op == T_plus &&
          dst->u.MEM->u.BINOP.right->kind == T_CONST) {
        T_exp e1 = dst->u.MEM->u.BINOP.left, e2 = src;
        char buf[100];
        sprintf(buf, "sw `s0, %d(`s1)\n", dst->u.MEM->u.BINOP.right->u.CONST);
        emit(AS_Oper(
            String(buf), NULL,
            Temp_TempList(munchExp(e2), Temp_TempList(munchExp(e1), NULL)),
            NULL));
      } else if (dst->u.MEM->kind == T_BINOP &&
                 dst->u.MEM->u.BINOP.op == T_plus &&
                 dst->u.MEM->u.BINOP.left->kind == T_CONST) {
        T_exp e1 = dst->u.MEM->u.BINOP.right, e2 = src;
        char buf[100];
        sprintf(buf, "sw `s0, %d(`s1)\n", dst->u.MEM->u.BINOP.left->u.CONST);
        emit(AS_Oper(
            String(buf), NULL,
            Temp_TempList(munchExp(e2), Temp_TempList(munchExp(e1), NULL)),
            NULL));
      } else if (dst->u.MEM->kind == T_CONST) {
        T_exp e2 = src;
        char buf[100];
        sprintf(buf, "sw `s0, %d(`s1)\n", dst->u.MEM->u.CONST);
        emit(AS_Oper(String(buf), NULL,
                     Temp_TempList(munchExp(e2), Temp_TempList(F_ZERO(), NULL)),
                     NULL));
      } else if (src->kind == T_MEM) {
        T_exp e1 = dst->u.MEM, e2 = src->u.MEM;
        char buf[100];
        sprintf(buf, "sw `s0, 0(`s1)\n");
        emit(AS_Oper(
            String(buf), NULL,
            Temp_TempList(munchExp(e2), Temp_TempList(munchExp(e1), NULL)),
            NULL));
      } else {
        T_exp e1 = dst->u.MEM, e2 = src;
        char buf[100];
        sprintf(buf, "sw `s0, 0(`s1)\n");
        emit(AS_Oper(
            String(buf), NULL,
            Temp_TempList(munchExp(e2), Temp_TempList(munchExp(e1), NULL)),
            NULL));
      }
    } else if (dst->kind == T_TEMP) {
      T_exp e1 = dst, e2 = src;
      char buf[100];
      sprintf(buf, "add `d0, `s0, `s1\n");
      emit(AS_Move(String(buf), Temp_TempList(munchExp(e1), NULL),
                   Temp_TempList(F_ZERO(), Temp_TempList(munchExp(e2), NULL))));
    } else {
      assert(0);
    }
    break;
  }
  case T_EXP: {
    munchExp(s->u.EXP);
    break;
  }
  default:
    assert(0);
  }
}

static Temp_temp emit_binop_imm(string op, T_exp e, int v) {
  Temp_temp t = Temp_newtemp();
  char buf[100];
  sprintf(buf, "%s `d0, `s0, %d\n", op, v);
  emit(AS_Oper(String(buf), Temp_TempList(t, NULL),
               Temp_TempList(munchExp(e), NULL), NULL));
  return t;
}

static Temp_temp emit_binop_tri(string op, T_exp e1, T_exp e2) {
  Temp_temp t = Temp_newtemp();
  char buf[100];
  sprintf(buf, "%s `d0, `s0, `s1\n", op);
  emit(AS_Oper(String(buf), Temp_TempList(t, NULL),
               Temp_TempList(munchExp(e1), Temp_TempList(munchExp(e2), NULL)),
               NULL));
  return t;
}

static Temp_temp munchExp(T_exp e) {
  switch (e->kind) {
  case T_BINOP: {
    string op = NULL;
    T_exp e1 = e->u.BINOP.left, e2 = e->u.BINOP.right;
    int cst = (e1->kind == T_CONST || e2->kind == T_CONST);
    switch (e->u.BINOP.op) {
    case T_plus:
      if (cst)
        op = String("addi");
      else
        op = String("add");
      break;
    case T_minus:
      op = String("sub");
      break;
    case T_mul:
      op = String("mul");
      break;
    case T_div:
      op = String("div");
      break;
    case T_and:
      if (cst)
        op = String("andi");
      else
        op = String("and");
      break;
    case T_or:
      if (cst)
        op = String("ori");
      else
        op = String("or");
      break;
    case T_xor:
      if (cst)
        op = String("xori");
      else
        op = String("xor");
      break;
    case T_lshift:
      op = String("sll");
      break;
    case T_rshift:
      op = String("srl");
      break;
    case T_arshift:
      op = String("sra");
      break;
    default:
      assert(!"Invalid operator");
    }
    if (e->u.BINOP.left->kind == T_CONST) {
      return emit_binop_imm(op, e2, e1->u.CONST);
    } else if (e->u.BINOP.right->kind == T_CONST) {
      return emit_binop_imm(op, e1, e2->u.CONST);
    } else {
      return emit_binop_tri(op, e1, e2);
    }
  }
  case T_MEM: {
    Temp_temp d = Temp_newtemp();
    if (e->u.MEM->kind == T_BINOP) {
      if (e->u.MEM->u.BINOP.op == T_plus) {
        if (e->u.MEM->u.BINOP.left->kind == T_CONST &&
            e->u.MEM->u.BINOP.left->u.CONST <= IMM_MAX &&
            e->u.MEM->u.BINOP.left->u.CONST >= IMM_MIN) {
          if (e->u.MEM->u.BINOP.right->kind == T_TEMP &&
              e->u.MEM->u.BINOP.right->u.TEMP == F_FP()) {
            emit(AS_Oper(
                FormatString("lw `d0, %d+%s(`s0)\n",
                             e->u.MEM->u.BINOP.left->u.CONST, framesize),
                Temp_TempList(d, NULL), Temp_TempList(F_SP(), NULL), NULL));
          } else
            emit(AS_Oper(FormatString("lw `d0, %d(`s0)\n",
                                      e->u.MEM->u.BINOP.left->u.CONST),
                         Temp_TempList(d, NULL),
                         Temp_TempList(munchExp(e->u.MEM->u.BINOP.right), NULL),
                         NULL));
        } else if (e->u.MEM->u.BINOP.right->kind == T_CONST &&
                   e->u.MEM->u.BINOP.right->u.CONST <= IMM_MAX &&
                   e->u.MEM->u.BINOP.right->u.CONST >= IMM_MIN) {
          if (e->u.MEM->u.BINOP.left->kind == T_TEMP &&
              e->u.MEM->u.BINOP.left->u.TEMP == F_FP()) {
            emit(AS_Oper(
                FormatString("lw `d0, %d+%s(`s0)\n",
                             e->u.MEM->u.BINOP.right->u.CONST, framesize),
                Temp_TempList(d, NULL), Temp_TempList(F_SP(), NULL), NULL));
          } else
            emit(AS_Oper(FormatString("lw `d0, %d(`s0)\n",
                                      e->u.MEM->u.BINOP.right->u.CONST),
                         Temp_TempList(d, NULL),
                         Temp_TempList(munchExp(e->u.MEM->u.BINOP.left), NULL),
                         NULL));
        } else {
          emit(AS_Oper("lw `d0, 0(`s0)\n", Temp_TempList(d, NULL),
                       Temp_TempList(munchExp(e->u.MEM), NULL), NULL));
        }
      } else if (e->u.MEM->u.BINOP.op == T_minus &&
                 e->u.MEM->u.BINOP.right->kind == T_CONST &&
                 e->u.MEM->u.BINOP.right->u.CONST <= IMM_MAX + 1 &&
                 e->u.MEM->u.BINOP.right->u.CONST > IMM_MIN) {
        if (e->u.MEM->u.BINOP.left->kind == T_TEMP &&
            e->u.MEM->u.BINOP.left->u.TEMP == F_FP()) {
          emit(AS_Oper(
              FormatString("lw `d0, %d+%s(`s0)\n",
                           -e->u.MEM->u.BINOP.right->u.CONST, framesize),
              Temp_TempList(d, NULL), Temp_TempList(F_SP(), NULL), NULL));
        } else
          emit(AS_Oper(FormatString("lw `d0, %d(`s0)\n",
                                    -e->u.MEM->u.BINOP.right->u.CONST),
                       Temp_TempList(d, NULL),
                       Temp_TempList(munchExp(e->u.MEM->u.BINOP.left), NULL),
                       NULL));
      } else {
        emit(AS_Oper("lw `d0, 0(`s0)\n", Temp_TempList(d, NULL),
                     Temp_TempList(munchExp(e->u.MEM), NULL), NULL));
      }
    } else if (e->u.MEM->kind == T_CONST && e->u.MEM->u.CONST <= IMM_MAX &&
               e->u.MEM->u.CONST >= IMM_MIN) {
      emit(AS_Oper(FormatString("lw `d0, %d($zero)\n", e->u.MEM->u.CONST),
                   Temp_TempList(d, NULL), NULL, NULL));
    } else {
      emit(AS_Oper("lw `d0, 0(`s0)\n", Temp_TempList(d, NULL),
                   Temp_TempList(munchExp(e->u.MEM), NULL), NULL));
    }
    return d;
  }
  case T_TEMP: {
    return e->u.TEMP;
  }
  case T_NAME: {
    Temp_temp t = Temp_newtemp();
    char buf[100];
    sprintf(buf, "la `d0, %s\n", Temp_labelstring(e->u.NAME));
    emit(AS_Oper(String(buf), Temp_TempList(t, NULL), NULL, NULL));
    return t;
  }
  case T_CONST: {
    Temp_temp t = Temp_newtemp();
    char buf[100];
    sprintf(buf, "li `d0, %d\n", e->u.CONST);
    emit(AS_Oper(String(buf), Temp_TempList(t, NULL), NULL, NULL));
    return t;
  }
  case T_CALL: {
    T_exp f = e->u.CALL.fun;
    T_expList a = e->u.CALL.args;
    Temp_tempList l = munchArgs(a);
    char buf[100];
    sprintf(buf, "jal %s\n", Temp_labelstring(f->u.NAME));
    emit(AS_Oper(String(buf), F_CallSaves(), l, NULL));
    return F_RV();
  }
  default:
    assert(0);
  }
}

static Temp_tempList munchArgs(T_expList args) {
  int cnt = 0;
  Temp_temp sp = F_SP();
  Temp_tempList fars = F_ArgsRegs();

  T_expList el = args;
  Temp_tempList rlist = NULL, rlast = NULL;
  for (; el; el = el->tail) {
    Temp_temp t = munchExp(el->head);
    if (rlist == NULL) {
      rlist = rlast = Temp_TempList(t, NULL);
    } else {
      rlast->tail = Temp_TempList(t, NULL);
      rlast = rlast->tail;
    }

    if (cnt < 4) {
      emit(AS_Move(String("move `d0, `s0\n"), Temp_TempList(fars->head, NULL),
                   Temp_TempList(t, NULL)));
      fars = fars->tail;
    } else {
      char buf[100];
      sprintf(buf, "sw `s0, %d(`s1)\n", cnt * 4);
      emit(AS_Oper(String(buf), NULL, Temp_TempList(t, Temp_TempList(sp, NULL)),
                   NULL));
    }
    cnt++;
  }
  return rlist;
}