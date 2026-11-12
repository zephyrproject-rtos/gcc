/* Prototypes for v850.cc functions used in the md file & elsewhere.
   Copyright (C) 1999-2024 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

/* Function prototypes that cannot exist in v850.h due to dependency
   complications.  */
#ifndef GCC_V850_PROTOS_H
#define GCC_V850_PROTOS_H

extern void   expand_prologue               (void);
extern void   expand_epilogue               (void);
extern int    v850_handle_pragma            (int (*)(void), void (*)(int), char *);
extern int    compute_register_save_size    (long *);
extern int    compute_frame_size            (poly_int64, long *);
extern HOST_WIDE_INT v850_initial_elimination_offset (int, int);
extern void   v850_init_expanders           (void);

#ifdef RTX_CODE
extern rtx    v850_return_addr              (int);
extern bool v850_fxu_mem_p (rtx, int, bool);
extern bool v850_expand_fxu_move (rtx, rtx);
extern void v850_expand_fxu_misaligned_move (rtx, rtx);
extern int v850_fxu_fcond (enum rtx_code, bool *, bool *);
extern void v850_expand_fxu_vec_cmp (rtx, enum rtx_code, rtx, rtx);
extern void v850_expand_fxu_vcond (rtx, rtx, rtx, enum rtx_code, rtx,
				   rtx);
extern void v850_expand_fxu_dup (rtx, rtx);
extern void v850_expand_fxu_extract (rtx, rtx, int);
extern void v850_expand_fxu_set (rtx, rtx, int);
extern void v850_expand_fxu_init (rtx, rtx);
extern void v850_expand_fxu_reduc (rtx, rtx, int);
extern const char *output_move_single       (rtx *);
extern char * construct_save_jarl           (rtx);
extern char * construct_restore_jr          (rtx);
#ifdef HAVE_MACHINE_MODES
extern char * construct_dispose_instruction (rtx);
extern char * construct_prepare_instruction (rtx);
extern int    ep_memory_operand             (rtx, machine_mode, int);
extern int    v850_adjust_insn_length       (rtx_insn *, int);
extern const char * v850_gen_movdi          (rtx *);
extern rtx    v850_gen_compare              (enum rtx_code, machine_mode,
					     rtx, rtx);
extern machine_mode  v850_gen_float_compare (enum rtx_code,
						  machine_mode, rtx, rtx);
extern machine_mode  v850_select_cc_mode (RTX_CODE, rtx, rtx);
extern void v850_atomic_fence (rtx, bool);
#endif
#endif /* RTX_CODE */

#ifdef TREE_CODE
extern int    v850_interrupt_function_p     (tree);
extern bool v850_interrupt_fe_p (tree);
extern int v850_interrupt_state (void);
extern int v850_interrupt_state_size (int);
extern const char *v850_interrupt_return_insn (void);
extern const char *v850_output_interrupt_state (int, bool);
extern void   v850_output_aligned_bss       (FILE *, tree, const char *, unsigned HOST_WIDE_INT, int);
extern void   v850_output_common            (FILE *, tree, const char *, int, int);
extern void   v850_output_local             (FILE *, tree, const char *, int, int);
extern v850_data_area v850_get_data_area    (tree);
#endif

extern void ghs_pragma_section		    (struct cpp_reader *);
extern void ghs_pragma_interrupt	    (struct cpp_reader *);
extern void ghs_pragma_starttda		    (struct cpp_reader *);
extern void ghs_pragma_startsda		    (struct cpp_reader *);
extern void ghs_pragma_startzda		    (struct cpp_reader *);
extern void ghs_pragma_endtda		    (struct cpp_reader *);
extern void ghs_pragma_endsda		    (struct cpp_reader *);
extern void ghs_pragma_endzda		    (struct cpp_reader *);

#endif /* ! GCC_V850_PROTOS_H */
