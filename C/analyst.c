/*************************************************************************
*									 *
*	 YAP Prolog 							 *
*									 *
*	Yap Prolog was developed at NCCUP - Universidade do Porto	 *
*									 *
* Copyright L.Damas, V.S.Costa and Universidade do Porto 1985-1997	 *
*									 *
**************************************************************************
*									 *
* File:		analyst.c						 *
* Last rev:								 *
* mods:									 *
* comments:	Tracing the abstract machine				 *
*									 *
*************************************************************************/
#ifdef SCCS
static char SccsId[] = "%W% %G%";

#endif

#include "Yap.h"

#ifdef ANALYST
#include "Yatom.h"
#include "yapio.h"
#ifdef HAVE_STRING_H
#include <string.h>
#endif

STATIC_PROTO(Int p_reset_op_counters, (void));
STATIC_PROTO(Int p_show_op_counters, (void));
STATIC_PROTO(Int p_show_ops_by_group, (void));

int opcount[_std_top + 1];

static char *op_names[_std_top + 1] =
{
#define OPCODE(OP,TYPE) #OP
#include "YapOpcodes.h"
#undef  OPCODE
};

static Int 
p_reset_op_counters()
{
  int i;

  for (i = 0; i <= _std_top; ++i)
    opcount[i] = 0;
  return (TRUE);
}

static void 
print_instruction(int inst)
{
  int j;

  YP_fprintf(YP_stderr, "%s", op_names[inst]);
  for (j = strlen(op_names[inst]); j < 25; j++)
    YP_putc(' ', YP_stderr);
  j = opcount[inst];
  if (j < 100000000) {
    YP_putc(' ', YP_stderr);
    if (j < 10000000) {
      YP_putc(' ', YP_stderr);
      if (j < 1000000) {
	YP_putc(' ', YP_stderr);
	if (j < 100000) {
	  YP_putc(' ', YP_stderr);
	  if (j < 10000) {
	    YP_putc(' ', YP_stderr);
	    if (j < 1000) {
	      YP_putc(' ', YP_stderr);
	      if (j < 100) {
		YP_putc(' ', YP_stderr);
		if (j < 10) {
		  YP_putc(' ', YP_stderr);
		}
	      }
	    }
	  }
	}
      }
    }
  }
  YP_fprintf(YP_stderr, "%d\n", opcount[inst]);
}

static Int 
p_show_op_counters()
{
  int i;
  char *program;
  Term t1 = Deref(ARG1);

  if (IsVarTerm(t1) || !IsAtomTerm(t1))
    return (FALSE);
  else
    program = RepAtom(AtomOfTerm(t1))->StrOfAE;

  YP_fprintf(YP_stderr, "\n Instructions Executed in %s \n", program);
  for (i = 0; i <= _std_top; ++i)
    print_instruction(i);
  YP_fprintf(YP_stderr, "\n Control Instructions \n");
  print_instruction(_op_fail);
  print_instruction(_execute);
  print_instruction(_dexecute);
  print_instruction(_call);
  print_instruction(_fcall);
  print_instruction(_call_cpred);
  print_instruction(_call_c_wfail);
  print_instruction(_procceed);
  print_instruction(_allocate);
  print_instruction(_deallocate);

  YP_fprintf(YP_stderr, "\n Choice Point Manipulation Instructions\n");
  print_instruction(_try_me);
  print_instruction(_retry_me);
  print_instruction(_trust_me);
  print_instruction(_try_me0);
  print_instruction(_retry_me0);
  print_instruction(_trust_me0);
  print_instruction(_try_me1);
  print_instruction(_retry_me1);
  print_instruction(_trust_me1);
  print_instruction(_try_me2);
  print_instruction(_retry_me2);
  print_instruction(_trust_me2);
  print_instruction(_try_me3);
  print_instruction(_retry_me3);
  print_instruction(_trust_me3);
  print_instruction(_try_me4);
  print_instruction(_retry_me4);
  print_instruction(_trust_me4);
  print_instruction(_try_clause);
  print_instruction(_try_in);
  print_instruction(_retry);
  print_instruction(_trust_in);
  print_instruction(_trust);
  print_instruction(_retry_first);
  print_instruction(_trust_first_in);
  print_instruction(_trust_first);
  print_instruction(_retry_tail);
  print_instruction(_trust_tail_in);
  print_instruction(_trust_tail);
  print_instruction(_retry_head);
  print_instruction(_trust_head_in);
  print_instruction(_trust_head);

  YP_fprintf(YP_stderr, "\n Disjunction Instructions\n");
  print_instruction(_either);
  print_instruction(_or_else);
  print_instruction(_or_last);
  print_instruction(_jump);
  print_instruction(_move_back);

  YP_fprintf(YP_stderr, "\n Dynamic Predicates Choicepoint Instructions\n");
  print_instruction(_try_and_mark);
  print_instruction(_retry_and_mark);

  YP_fprintf(YP_stderr, "\n C Predicates Choicepoint Instructions\n");
  print_instruction(_try_c);
  print_instruction(_retry_c);

  YP_fprintf(YP_stderr, "\n Indexing Instructions\n");
  YP_fprintf(YP_stderr, "\n  Switch on Type\n");
  print_instruction(_switch_on_type);
  print_instruction(_switch_on_nonv);
  print_instruction(_switch_last);
  print_instruction(_switch_on_head);
  print_instruction(_switch_list_nl);
  print_instruction(_switch_list_nl_prefetch);
  print_instruction(_switch_nv_list);
  print_instruction(_switch_l_list);
  YP_fprintf(YP_stderr, "\n  Switch on Value\n");
  print_instruction(_if_cons);
  print_instruction(_go_on_cons);
  print_instruction(_switch_on_cons);
  print_instruction(_if_func);
  print_instruction(_go_on_func);
  print_instruction(_switch_on_func);
  YP_fprintf(YP_stderr, "\n  Other Switches\n");
  print_instruction(_if_not_then);

  YP_fprintf(YP_stderr, "\n Get Instructions\n");
  print_instruction(_get_x_var);
  print_instruction(_get_y_var);
  print_instruction(_get_x_val);
  print_instruction(_get_y_val);
  print_instruction(_get_atom);
  print_instruction(_get_list);
  print_instruction(_get_struct);
  YP_fprintf(YP_stderr, "\n   Optimised Get Instructions\n");
  print_instruction(_glist_valx);
  print_instruction(_glist_valy);
  print_instruction(_gl_void_varx);
  print_instruction(_gl_void_vary);
  print_instruction(_gl_void_valx);
  print_instruction(_gl_void_valy);

  YP_fprintf(YP_stderr, "\n Unify Read Instructions\n");
  print_instruction(_unify_x_var);
  print_instruction(_unify_x_var2);
  print_instruction(_unify_y_var);
  print_instruction(_unify_x_val);
  print_instruction(_unify_y_val);
  print_instruction(_unify_x_loc);
  print_instruction(_unify_y_loc);
  print_instruction(_unify_atom);
  print_instruction(_unify_n_atoms);
  print_instruction(_unify_n_voids);
  print_instruction(_unify_list);
  print_instruction(_unify_struct);
  YP_fprintf(YP_stderr, "\n   Unify Last Read Instructions\n");
  print_instruction(_unify_l_x_var);
  print_instruction(_unify_l_x_var2);
  print_instruction(_unify_l_y_var);
  print_instruction(_unify_l_x_val);
  print_instruction(_unify_l_y_val);
  print_instruction(_unify_l_x_loc);
  print_instruction(_unify_l_y_loc);
  print_instruction(_unify_l_atom);
  print_instruction(_unify_l_n_voids);
  print_instruction(_unify_l_list);
  print_instruction(_unify_l_struc);

  YP_fprintf(YP_stderr, "\n Unify Write Instructions\n");
  print_instruction(_unify_x_var_write);
  print_instruction(_unify_x_var2_write);
  print_instruction(_unify_y_var_write);
  print_instruction(_unify_x_val_write);
  print_instruction(_unify_y_val_write);
  print_instruction(_unify_x_loc_write);
  print_instruction(_unify_y_loc_write);
  print_instruction(_unify_atom_write);
  print_instruction(_unify_n_atoms_write);
  print_instruction(_unify_n_voids_write);
  print_instruction(_unify_list_write);
  print_instruction(_unify_struct_write);
  YP_fprintf(YP_stderr, "\n   Unify Last Read Instructions\n");
  print_instruction(_unify_l_x_var_write);
  print_instruction(_unify_l_x_var2_write);
  print_instruction(_unify_l_y_var_write);
  print_instruction(_unify_l_x_val_write);
  print_instruction(_unify_l_y_val_write);
  print_instruction(_unify_l_x_loc_write);
  print_instruction(_unify_l_y_loc_write);
  print_instruction(_unify_l_atom_write);
  print_instruction(_unify_l_n_voids_write);
  print_instruction(_unify_l_list_write);
  print_instruction(_unify_l_struc_write);

  YP_fprintf(YP_stderr, "\n Put Instructions\n");
  print_instruction(_put_x_var);
  print_instruction(_put_y_var);
  print_instruction(_put_x_val);
  print_instruction(_put_y_val);
  print_instruction(_put_unsafe);
  print_instruction(_put_atom);
  print_instruction(_put_list);
  print_instruction(_put_struct);

  YP_fprintf(YP_stderr, "\n Write Instructions\n");
  print_instruction(_write_x_var);
  print_instruction(_write_y_var);
  print_instruction(_write_x_val);
  print_instruction(_write_y_val);
  print_instruction(_write_x_loc);
  print_instruction(_write_y_loc);
  print_instruction(_write_atom);
  print_instruction(_write_n_atoms);
  print_instruction(_write_n_voids);
  print_instruction(_write_list);
  print_instruction(_write_struct);
  YP_fprintf(YP_stderr, "\n   Last Write Instructions\n");
  print_instruction(_write_l_list);
  print_instruction(_write_l_struc);

  YP_fprintf(YP_stderr, "\n Miscellaneous Instructions\n");
  print_instruction(_cut);
  print_instruction(_cut_t);
  print_instruction(_cut_e);
  print_instruction(_skip);
  print_instruction(_pop);
  print_instruction(_pop_n);
  print_instruction(_trust_fail);
  print_instruction(_index_pred);
  print_instruction(_save_b_x);
  print_instruction(_save_b_y);
  print_instruction(_save_pair_x);
  print_instruction(_save_pair_y);
  print_instruction(_save_pair_x_write);
  print_instruction(_save_pair_y_write);
  print_instruction(_save_appl_x);
  print_instruction(_save_appl_y);
  print_instruction(_save_appl_x_write);
  print_instruction(_save_appl_y_write);
  print_instruction(_Ystop);
  print_instruction(_Nstop);

  return (TRUE);
}

typedef struct {
  int nxvar, nxval, nyvar, nyval, ncons, nlist, nstru, nmisc;
} uopcount;

typedef struct {
  int ncalls, nexecs, nproceeds, ncallbips, ncuts, nallocs, ndeallocs;
} copcount;

typedef struct {
  int ntries, nretries, ntrusts;
} ccpcount;

static Int 
p_show_ops_by_group(void)
{

  uopcount c_get, c_unify, c_put, c_write;
  copcount c_control;
  ccpcount c_cp;
  int gets, unifies, puts, writes, controls, choice_pts, indexes, misc,
    total;
  char *program;
  Term t1;

  t1 = Deref(ARG1);
  if (IsVarTerm(t1) || !IsAtomTerm(t1))
    return (FALSE);
  else
    program = RepAtom(AtomOfTerm(t1))->StrOfAE;

  c_get.nxvar =
    opcount[_get_x_var];
  c_get.nyvar =
    opcount[_get_y_var];
  c_get.nxval =
    opcount[_get_x_val];
  c_get.nyval =
    opcount[_get_y_val];
  c_get.ncons =
    opcount[_get_atom];
  c_get.nlist =
    opcount[_get_list] +
    opcount[_glist_valx] +
    opcount[_glist_valy] +
    opcount[_gl_void_varx] +
    opcount[_gl_void_vary] +
    opcount[_gl_void_valx] +
    opcount[_gl_void_valy];
  c_get.nstru =
    opcount[_get_struct];

  gets = c_get.nxvar + c_get.nyvar + c_get.nxval + c_get.nyval +
    c_get.ncons + c_get.nlist + c_get.nstru;

  c_unify.nxvar =
    opcount[_unify_x_var] +
    opcount[_unify_void] +
    opcount[_unify_n_voids] +
    2 * opcount[_unify_x_var2] +
    2 * opcount[_gl_void_varx] +
    opcount[_gl_void_vary] +
    opcount[_gl_void_valx] +
    opcount[_unify_l_x_var] +
    opcount[_unify_l_void] +
    opcount[_unify_l_n_voids] +
    2 * opcount[_unify_l_x_var2] +
    opcount[_unify_x_var_write] +
    opcount[_unify_void_write] +
    opcount[_unify_n_voids_write] +
    2 * opcount[_unify_x_var2_write] +
    opcount[_unify_l_x_var_write] +
    opcount[_unify_l_void_write] +
    opcount[_unify_l_n_voids_write] +
    2 * opcount[_unify_l_x_var2_write];
  c_unify.nyvar =
    opcount[_unify_y_var] +
    opcount[_gl_void_vary] +
    opcount[_unify_l_y_var] +
    opcount[_unify_y_var_write] +
    opcount[_unify_l_y_var_write];
  c_unify.nxval =
    opcount[_unify_x_val] +
    opcount[_unify_x_loc] +
    opcount[_glist_valx] +
    opcount[_gl_void_valx] +
    opcount[_unify_l_x_val] +
    opcount[_unify_l_x_loc] +
    opcount[_unify_x_val_write] +
    opcount[_unify_x_loc_write] +
    opcount[_unify_l_x_val_write] +
    opcount[_unify_l_x_loc_write];
  c_unify.nyval =
    opcount[_unify_y_val] +
    opcount[_unify_y_loc] +
    opcount[_glist_valy] +
    opcount[_gl_void_valy] +
    opcount[_unify_l_y_val] +
    opcount[_unify_l_y_loc] +
    opcount[_unify_y_val_write] +
    opcount[_unify_y_loc_write] +
    opcount[_unify_l_y_val_write] +
    opcount[_unify_l_y_loc_write];
  c_unify.ncons =
    opcount[_unify_atom] +
    opcount[_unify_n_atoms] +
    opcount[_unify_l_atom] +
    opcount[_unify_atom_write] +
    opcount[_unify_n_atoms_write] +
    opcount[_unify_l_atom_write];
  c_unify.nlist =
    opcount[_unify_list] +
    opcount[_unify_l_list] +
    opcount[_unify_list_write] +
    opcount[_unify_l_list_write];
  c_unify.nstru =
    opcount[_unify_struct] +
    opcount[_unify_l_struc] +
    opcount[_unify_struct_write] +
    opcount[_unify_l_struc_write];
  c_unify.nmisc =
    opcount[_pop] +
    opcount[_pop_n];

  unifies = c_unify.nxvar + c_unify.nyvar + c_unify.nxval + c_unify.nyval +
    c_unify.ncons + c_unify.nlist + c_unify.nstru + c_unify.nmisc;

  c_put.nxvar =
    opcount[_put_x_var];
  c_put.nyvar =
    opcount[_put_y_var];
  c_put.nxval =
    opcount[_put_x_val];
  c_put.nyval =
    opcount[_put_y_val];
  c_put.ncons =
    opcount[_put_atom];
  c_put.nlist =
    opcount[_put_list];
  c_put.nstru =
    opcount[_put_struct];

  puts = c_put.nxvar + c_put.nyvar + c_put.nxval + c_put.nyval +
    c_put.ncons + c_put.nlist + c_put.nstru;

  c_write.nxvar =
    opcount[_write_x_var] +
    opcount[_write_void] +
    opcount[_write_n_voids];
  c_write.nyvar =
    opcount[_write_y_var];
  c_write.nxval =
    opcount[_write_x_val];
  c_write.nyval =
    opcount[_write_y_val];
  c_write.ncons =
    opcount[_write_atom];
  c_write.nlist =
    opcount[_write_list];
  c_write.nstru =
    opcount[_write_struct];

  writes = c_write.nxvar + c_write.nyvar + c_write.nxval + c_write.nyval +
    c_write.ncons + c_write.nlist + c_write.nstru;

  c_control.nexecs =
    opcount[_execute] +
    opcount[_dexecute];

  c_control.ncalls =
    opcount[_call] +
    opcount[_fcall];

  c_control.nproceeds =
    opcount[_procceed];

  c_control.ncallbips =
    opcount[_call_cpred] +
    opcount[_call_c_wfail] +
    opcount[_try_c] +
    opcount[_retry_c] +
    opcount[_op_fail] +
    opcount[_trust_fail] +
    opcount[_p_atom_x] +
    opcount[_p_atom_y] +
    opcount[_p_atomic_x] +
    opcount[_p_atomic_y] +
    opcount[_p_compound_x] +
    opcount[_p_compound_y] +
    opcount[_p_float_x] +
    opcount[_p_float_y] +
    opcount[_p_integer_x] +
    opcount[_p_integer_y] +
    opcount[_p_nonvar_x] +
    opcount[_p_nonvar_y] +
    opcount[_p_number_x] +
    opcount[_p_number_y] +
    opcount[_p_var_x] +
    opcount[_p_var_y] +
    opcount[_p_db_ref_x] +
    opcount[_p_db_ref_y] +
    opcount[_p_cut_by_x] +
    opcount[_p_cut_by_y] +
    opcount[_p_primitive_x] +
    opcount[_p_primitive_y] +
    opcount[_p_equal] +
    opcount[_p_plus_vv] +
    opcount[_p_plus_vc] +
    opcount[_p_plus_y_vv] +
    opcount[_p_plus_y_vc] +
    opcount[_p_minus_vv] +
    opcount[_p_minus_cv] +
    opcount[_p_minus_y_vv] +
    opcount[_p_minus_y_cv] +
    opcount[_p_times_vv] +
    opcount[_p_times_vc] +
    opcount[_p_times_y_vv] +
    opcount[_p_times_y_vc] +
    opcount[_p_div_vv] +
    opcount[_p_div_vc] +
    opcount[_p_div_cv] +
    opcount[_p_div_y_vv] +
    opcount[_p_div_y_vc] +
    opcount[_p_div_y_cv] +
    opcount[_p_or_vv] +
    opcount[_p_or_vc] +
    opcount[_p_or_y_vv] +
    opcount[_p_or_y_vc] +
    opcount[_p_and_vv] +
    opcount[_p_and_vc] +
    opcount[_p_and_y_vv] +
    opcount[_p_and_y_vc] +
    opcount[_p_sll_vv] +
    opcount[_p_sll_vc] +
    opcount[_p_sll_y_vv] +
    opcount[_p_sll_y_vc] +
    opcount[_p_slr_vv] +
    opcount[_p_slr_vc] +
    opcount[_p_slr_y_vv] +
    opcount[_p_slr_y_vc] +
    opcount[_p_dif] +
    opcount[_p_eq] +
    opcount[_p_arg_vv] +
    opcount[_p_arg_cv] +
    opcount[_p_arg_y_vv] +
    opcount[_p_arg_y_cv] +
    opcount[_p_functor];
    opcount[_p_func2s_vv] +
    opcount[_p_func2s_cv] +
    opcount[_p_func2s_vc] +
    opcount[_p_func2s_y_vv] +
    opcount[_p_func2s_y_cv] +
    opcount[_p_func2s_y_vc] +
    opcount[_p_func2f_xx] +
    opcount[_p_func2f_xy] +
    opcount[_p_func2f_yx] +
    opcount[_p_func2f_yy];

  c_control.ncuts =
    opcount[_cut] +
    opcount[_cut_t] +
    opcount[_cut_e] +
    opcount[_comit_b_x] +
    opcount[_comit_b_y];

  c_control.nallocs =
    opcount[_allocate] +
    opcount[_fcall];

  c_control.ndeallocs =
    opcount[_dexecute] +
    opcount[_deallocate];

  controls =
    c_control.nexecs +
    c_control.ncalls +
    c_control.nproceeds +
    c_control.ncuts +
    c_control.nallocs +
    c_control.ndeallocs +
    opcount[_jump] +
    opcount[_move_back] +
    opcount[_try_in];



  c_cp.ntries =
    opcount[_try_me] +
    opcount[_try_me0] +
    opcount[_try_me1] +
    opcount[_try_me2] +
    opcount[_try_me3] +
    opcount[_try_me4] +
    opcount[_try_and_mark] +
    opcount[_try_c] +
    opcount[_try_clause] +
    opcount[_either];

  c_cp.nretries =
    opcount[_retry_me] +
    opcount[_retry_me0] +
    opcount[_retry_me1] +
    opcount[_retry_me2] +
    opcount[_retry_me3] +
    opcount[_retry_me4] +
    opcount[_retry_and_mark] +
    opcount[_retry_c] +
    opcount[_retry] +
    opcount[_trust_in] +
    opcount[_retry_first] +
    opcount[_trust_first_in] +
    opcount[_retry_tail] +
    opcount[_trust_tail_in] +
    opcount[_retry_head] +
    opcount[_trust_head_in] +
    opcount[_or_else];

  c_cp.ntrusts =
    opcount[_trust_me] +
    opcount[_trust_me0] +
    opcount[_trust_me1] +
    opcount[_trust_me2] +
    opcount[_trust_me3] +
    opcount[_trust_me4] +
    opcount[_trust] +
    opcount[_trust_first] +
    opcount[_trust_tail] +
    opcount[_trust_head] +
    opcount[_or_last];

  choice_pts =
    c_cp.ntries +
    c_cp.nretries +
    c_cp.ntrusts;

  indexes =
    opcount[_jump_if_var] +
    opcount[_switch_on_type] +
    opcount[_switch_on_nonv] +
    opcount[_switch_last] +
    opcount[_switch_on_head] +
    opcount[_switch_list_nl] +
    opcount[_switch_list_nl_prefetch] +
    opcount[_switch_nv_list] +
    opcount[_switch_l_list] +
    opcount[_switch_on_cons] +
    opcount[_go_on_cons] +
    opcount[_if_cons] +
    opcount[_switch_on_func] +
    opcount[_go_on_func] +
    opcount[_if_func] +
    opcount[_if_not_then];
  misc =
    c_control.ncallbips +
    opcount[_Ystop] +
    opcount[_Nstop] +
    opcount[_index_pred] +
    opcount[_save_b_x] +
    opcount[_save_b_y] +
    opcount[_undef_p] +
    opcount[_spy_pred] +
    opcount[_spy_or_trymark] +
    opcount[_save_pair_x] +
    opcount[_save_pair_y] +
    opcount[_save_pair_x_write] +
    opcount[_save_pair_y_write] +
    opcount[_save_appl_x] +
    opcount[_save_appl_y] +
    opcount[_save_appl_x_write] +
    opcount[_save_appl_y_write];
  total = gets + unifies + puts + writes + controls + choice_pts + indexes + misc;

  /*  for (i = 0; i <= _std_top; ++i)
   * print_instruction(i);
   */

  YP_fprintf(YP_stderr, "\n Instructions Executed in %s\n", program);
  YP_fprintf(YP_stderr, "Groups are\n\n");
  YP_fprintf(YP_stderr, "  GET               instructions: %8d (%3d%%)\n", gets,
	     (gets * 100) / total);
  YP_fprintf(YP_stderr, "  UNIFY             instructions: %8d (%3d%%)\n", unifies,
	     (unifies * 100) / total);
  YP_fprintf(YP_stderr, "  PUT               instructions: %8d (%3d%%)\n", puts,
	     (puts * 100) / total);
  YP_fprintf(YP_stderr, "  WRITE             instructions: %8d (%3d%%)\n", writes,
	     (writes * 100) / total);
  YP_fprintf(YP_stderr, "  CONTROL           instructions: %8d (%3d%%)\n", controls,
	     (controls * 100) / total);
  YP_fprintf(YP_stderr, "  CHOICE POINT      instructions: %8d (%3d%%)\n", choice_pts,
	     (choice_pts * 100) / total);
  YP_fprintf(YP_stderr, "  INDEXING          instructions: %8d (%3d%%)\n", indexes,
	     (indexes * 100) / total);
  YP_fprintf(YP_stderr, "  MISCELLANEOUS     instructions: %8d (%3d%%)\n", misc,
	     (misc * 100) / total);
  YP_fprintf(YP_stderr, "_______________________________________________\n");
  YP_fprintf(YP_stderr, "   TOTAL            instructions: %8d (%3d%%)\n\n", total,
	     (total * 100) / total);

  YP_fprintf(YP_stderr, "\n Analysis of Unification Instructions in %s \n", program);
  YP_fprintf(YP_stderr, "           XVAR,   YVAR,    XVAL,    YVAL,     CONS,     LIST,  STRUCT\n");
  YP_fprintf(YP_stderr, "  GET: %8d %8d %8d %8d %8d %8d %8d\n",
	     c_get.nxvar,
	     c_get.nyvar,
	     c_get.nxval,
	     c_get.nyval,
	     c_get.ncons,
	     c_get.nlist,
	     c_get.nstru);
  YP_fprintf(YP_stderr, "UNIFY: %8d %8d %8d %8d %8d %8d %8d\n",
	     c_unify.nxvar,
	     c_unify.nyvar,
	     c_unify.nxval,
	     c_unify.nyval,
	     c_unify.ncons,
	     c_unify.nlist,
	     c_unify.nstru);
  YP_fprintf(YP_stderr, "  PUT: %8d %8d %8d %8d %8d %8d %8d\n",
	     c_put.nxvar,
	     c_put.nyvar,
	     c_put.nxval,
	     c_put.nyval,
	     c_put.ncons,
	     c_put.nlist,
	     c_put.nstru);
  YP_fprintf(YP_stderr, "WRITE: %8d %8d %8d %8d %8d %8d %8d\n",
	     c_write.nxvar,
	     c_write.nyvar,
	     c_write.nxval,
	     c_write.nyval,
	     c_write.ncons,
	     c_write.nlist,
	     c_write.nstru);
  YP_fprintf(YP_stderr, "      ___________________________________________________\n");
  YP_fprintf(YP_stderr, "TOTAL: %8d %8d %8d %8d %8d %8d %8d\n",
	     c_get.nxvar + c_unify.nxvar + c_put.nxvar + c_write.nxvar,
	     c_get.nyvar + c_unify.nyvar + c_put.nyvar + c_write.nyvar,
	     c_get.nxval + c_unify.nxval + c_put.nxval + c_write.nxval,
	     c_get.nyval + c_unify.nyval + c_put.nyval + c_write.nyval,
	     c_get.ncons + c_unify.ncons + c_put.ncons + c_write.ncons,
	     c_get.nlist + c_unify.nlist + c_put.nlist + c_write.nlist,
	     c_get.nstru + c_unify.nstru + c_put.nstru + c_write.nstru
    );

  YP_fprintf(YP_stderr, "\n Analysis of Unification Instructions in %s \n", program);
  YP_fprintf(YP_stderr, "           XVAR,   YVAR,    XVAL,    YVAL,     CONS,     LIST,  STRUCT\n");
  YP_fprintf(YP_stderr, "  GET:  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%\n",
	     (((double) c_get.nxvar) * 100) / total,
	     (((double) c_get.nyvar) * 100) / total,
	     (((double) c_get.nxval) * 100) / total,
	     (((double) c_get.nyval) * 100) / total,
	     (((double) c_get.ncons) * 100) / total,
	     (((double) c_get.nlist) * 100) / total,
	     (((double) c_get.nstru) * 100) / total);
  YP_fprintf(YP_stderr, "UNIFY:  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%\n",
	     (((double) c_unify.nxvar) * 100) / total,
	     (((double) c_unify.nyvar) * 100) / total,
	     (((double) c_unify.nxval) * 100) / total,
	     (((double) c_unify.nyval) * 100) / total,
	     (((double) c_unify.ncons) * 100) / total,
	     (((double) c_unify.nlist) * 100) / total,
	     (((double) c_unify.nstru) * 100) / total);
  YP_fprintf(YP_stderr, "  PUT:  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%\n",
	     (((double) c_put.nxvar) * 100) / total,
	     (((double) c_put.nyvar) * 100) / total,
	     (((double) c_put.nxval) * 100) / total,
	     (((double) c_put.nyval) * 100) / total,
	     (((double) c_put.ncons) * 100) / total,
	     (((double) c_put.nlist) * 100) / total,
	     (((double) c_put.nstru) * 100) / total);
  YP_fprintf(YP_stderr, "WRITE:  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%\n",
	     (((double) c_write.nxvar) * 100) / total,
	     (((double) c_write.nyvar) * 100) / total,
	     (((double) c_write.nxval) * 100) / total,
	     (((double) c_write.nyval) * 100) / total,
	     (((double) c_write.ncons) * 100) / total,
	     (((double) c_write.nlist) * 100) / total,
	     (((double) c_write.nstru) * 100) / total);
  YP_fprintf(YP_stderr, "      ___________________________________________________\n");
  YP_fprintf(YP_stderr, "TOTAL:  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%  %3.2f%%\n",
	     (((double) c_get.nxvar + c_unify.nxvar + c_put.nxvar + c_write.nxvar) * 100) / total,
	     (((double) c_get.nyvar + c_unify.nyvar + c_put.nyvar + c_write.nyvar) * 100) / total,
	     (((double) c_get.nxval + c_unify.nxval + c_put.nxval + c_write.nxval) * 100) / total,
	     (((double) c_get.nyval + c_unify.nyval + c_put.nyval + c_write.nyval) * 100) / total,
	     (((double) c_get.ncons + c_unify.ncons + c_put.ncons + c_write.ncons) * 100) / total,
	     (((double) c_get.nlist + c_unify.nlist + c_put.nlist + c_write.nlist) * 100) / total,
	     (((double) c_get.nstru + c_unify.nstru + c_put.nstru + c_write.nstru) * 100) / total
    );

  YP_fprintf(YP_stderr, "\n Control Instructions Executed in %s \n", program);
  YP_fprintf(YP_stderr, "Grouped as\n\n");
  YP_fprintf(YP_stderr, "  CALL              instructions: %8d (%3d%%)\n",
	     c_control.ncalls, (c_control.ncalls * 100) / total);
  YP_fprintf(YP_stderr, "  PROCEED           instructions: %8d (%3d%%)\n",
	     c_control.nproceeds, (c_control.nproceeds * 100) / total);
  YP_fprintf(YP_stderr, "  EXECUTE           instructions: %8d (%3d%%)\n",
	     c_control.nexecs, (c_control.nexecs * 100) / total);
  YP_fprintf(YP_stderr, "  CUT               instructions: %8d (%3d%%)\n",
	     c_control.ncuts, (c_control.ncuts * 100) / total);
  YP_fprintf(YP_stderr, "  CALL_BIP          instructions: %8d (%3d%%)\n",
	     c_control.ncallbips, (c_control.ncallbips * 100) / total);
  YP_fprintf(YP_stderr, "  ALLOCATE          instructions: %8d (%3d%%)\n",
	     c_control.nallocs, (c_control.nallocs * 100) / total);
  YP_fprintf(YP_stderr, "  DEALLOCATE        instructions: %8d (%3d%%)\n",
	     c_control.ndeallocs, (c_control.ndeallocs * 100) / total);
  YP_fprintf(YP_stderr, "_______________________________________________\n");
  YP_fprintf(YP_stderr, "   TOTAL            instructions: %8d (%3d%%)\n\n", total,
	     (total * 100) / total);

  YP_fprintf(YP_stderr, "\n Choice Point Manipulation Instructions Executed in %s \n", program);
  YP_fprintf(YP_stderr, "Grouped as\n\n");
  YP_fprintf(YP_stderr, "  TRY              instructions: %8d (%3d%%)\n",
	     c_cp.ntries, (c_cp.ntries * 100) / total);
  YP_fprintf(YP_stderr, "  RETRY            instructions: %8d (%3d%%)\n",
	     c_cp.nretries, (c_cp.nretries * 100) / total);
  YP_fprintf(YP_stderr, "  TRUST            instructions: %8d (%3d%%)\n",
	     c_cp.ntrusts, (c_cp.ntrusts * 100) / total);
  YP_fprintf(YP_stderr, "_______________________________________________\n");
  YP_fprintf(YP_stderr, "   TOTAL            instructions: %8d (%3d%%)\n\n", total,
	     (total * 100) / total);

  return (TRUE);
}

void 
InitAnalystPreds(void)
{
  InitCPred("reset_op_counters", 0, p_reset_op_counters, SafePredFlag |SyncPredFlag);
  InitCPred("show_op_counters", 1, p_show_op_counters, SafePredFlag|SyncPredFlag);
  InitCPred("show_ops_by_group", 1, p_show_ops_by_group, SafePredFlag |SyncPredFlag);

}

#endif /* ANALYST */
