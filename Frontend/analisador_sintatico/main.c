// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include "util.h"
// #include <string.h>
// #include "parse.h"
// #include "absyn.h"
// #include "prabsyn.h"
// #include "semant.h"
// #include "frame.h"
// #include "translate.h"
// //#include "canon.h"
// //#include "mipsgen.h"
// #include "escape.h"


// void main(int argc, char **argv) {
//     int param, print_abs = 0, print_ir = 0, print_canon = 0, print_assem = 0;
//     string fname = checked_malloc(50);
//     FILE *out = stdout;
//     A_exp absyn_tree_root;

//     read_params(argc, argv, fname, &print_abs, &print_ir, &print_canon, &print_assem);

//   absyn_tree_root = parse(fname);
//   if (absyn_tree_root == NULL) {
//     fprintf(stderr, "parsing failed!\n");
//     return 0;
//   }

//   if (print_abs) {
//     fprintf(out, "============= Absyn  Tree =============\n");
//     pr_exp(out, absyn_tree_root, 0);
//     fprintf(out, "\n\n\n");
//   }

//   Esc_findEscape(absyn_tree_root);

//   F_fragList frags = SEM_transProg(absyn_tree_root, print_ir);

//   for(F_fragList f = frags; f; f = f->tail) {
//     if(f->head->kind == F_procFrag) {
//       do_proc(out, f->head->u.proc.frame, f->head->u.proc.body, print_canon, print_assem);
//     }
//   }
//   string fname = checked_malloc(50);
//   A_exp absyn_tree_root;

//   int opt;
//   while ((opt = getopt(argc, argv, "p:a:i:c:h")) != -1) {
//     switch (opt) {
// 			case 'p': // nome do programa de entrada
// 				strcpy(fname, optarg);
// 				break;

// 			case 'a': // imprime a arvore sintatica abstrata
// 				absyn_tree_root = parse(fname);
// 				if (absyn_tree_root)
// 					pr_exp(stdout, absyn_tree_root, 0);
// 				else {
// 					fprintf(stderr, "parsing falhou!\n");
// 				}
// 				break;

// 			case 'i': // imprime a representação intermediária
// 				absyn_tree_root = parse(fname);
// 				if (absyn_tree_root) {
// 					F_fragList fl = SEM_transProg(absyn_tree_root, 1);
// 				} else {
// 					fprintf(stderr, "parsing falhou!\n");
// 				}

// 				break;
//     }
//   }
// }

// static void do_proc(FILE *out, F_frame frame, T_stm body, int print_canon, int print_assem) {
//   AS_instrList instr_l = NULL;
//   T_stmList stm_l = NULL;

//   stm_l = C_linearize(body);
//   stm_l = C_traceSchedule(C_basicBlocks(stm_l));

//   instr_l = F_codegen(frame, stm_l);

//   if (print_canon) {
//     fprintf(out, "============== Canon  IR ==============\n");
//     Tr_printCanonTree(stm_l);
//     fprintf(out, "\n\n\n");
//   }

//   if (print_assem) {
//     fprintf(out, "========== Assembly w/o regs ==========\n");
//     AS_printInstrList(out, instr_l, F_tempMap());
//   }
// }

// static void read_params(int argc, char **argv, string fname, int *abs, int *ir, int *canon, int *assem) {
//   int param;

//   while ((param = getopt(argc, argv, "p:aics")) != -1) {
//     switch(param) {
//       case 'p':
//         strcpy(fname, optarg);
//       break;
      
//       case 'a':
//         *abs = 1;
//       break;

//       case 'i':
//         *ir = 1;
//       break;

//       case 'c':
//         *canon = 1;
//       break;

//       case 's':
//         *assem = 1;
//       break;
//     }
//   }
// }

// int main(int argc, char **argv) {
//   int param, print_abs = 0, print_ir = 0, print_canon = 0, print_assem = 0;
//   string fname = checked_malloc(50);
//   FILE *out = stdout;
//   A_exp absyn_tree_root;

//   read_params(argc, argv, fname, &print_abs, &print_ir, &print_canon, &print_assem);

//   absyn_tree_root = parse(fname);
//   if (absyn_tree_root == NULL) {
//     fprintf(stderr, "parsing failed!\n");
//     return 0;
//   }

//   if (print_abs) {
//     fprintf(out, "============= Absyn  Tree =============\n");
//     pr_exp(out, absyn_tree_root, 0);
//     fprintf(out, "\n\n\n");
//   }

//   Esc_findEscape(absyn_tree_root);

//   F_fragList frags = SEM_transProg(absyn_tree_root, print_ir);

//   for(F_fragList f = frags; f; f = f->tail) {
//     if(f->head->kind == F_procFrag) {
//       do_proc(out, f->head->u.proc.frame, f->head->u.proc.body, print_canon, print_assem);
//     }
//   }

// }