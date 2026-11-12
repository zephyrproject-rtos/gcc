;; Machine description for the RH850 FXU vector unit.
;; Copyright The GNU Toolchain Authors.
;;
;; This file is part of GCC.
;;
;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.
;;
;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(define_c_enum "unspec" [
  UNSPEC_FXU_LDV_DW
  UNSPEC_FXU_LDV_DW_BOTH
  UNSPEC_FXU_STV_DW
])

(define_mode_iterator VFXU [V4SF V4SI])

(define_expand "mov<mode>"
  [(set (match_operand:VFXU 0 "nonimmediate_operand")
	(match_operand:VFXU 1 "general_operand"))]
  "TARGET_FXU"
{
  if (v850_expand_fxu_move (operands[0], operands[1]))
    DONE;
})

(define_expand "movmisalign<mode>"
  [(set (match_operand:VFXU 0 "nonimmediate_operand")
	(match_operand:VFXU 1 "general_operand"))]
  "TARGET_FXU"
{
  v850_expand_fxu_misaligned_move (operands[0], operands[1]);
  DONE;
})

(define_insn "*mov<mode>_fxu"
  [(set (match_operand:VFXU 0 "nonimmediate_operand" "=w,w,Yq")
	(match_operand:VFXU 1 "nonimmediate_operand" "w,Yq,w"))]
  "TARGET_FXU
   && (register_operand (operands[0], <MODE>mode)
       || register_operand (operands[1], <MODE>mode))"
  "@
   movv.w4 %1, %0
   ldv.qw %1, %0
   stv.qw %1, %0"
  [(set_attr "length" "4,6,6")
   (set_attr "type" "fpu,load,store")])

(define_insn "@fxu_ldv_dw_both<mode>"
  [(set (match_operand:VFXU 0 "register_operand" "=w")
	(unspec:VFXU [(match_operand:DI 1 "memory_operand" "Yd")]
		     UNSPEC_FXU_LDV_DW_BOTH))]
  "TARGET_FXU"
  "ldv.dw 3, %1, %0"
  [(set_attr "length" "6")
   (set_attr "type" "load")])

(define_insn "@fxu_ldv_dw<mode>"
  [(set (match_operand:VFXU 0 "register_operand" "=w")
	(unspec:VFXU [(match_operand:VFXU 1 "register_operand" "0")
		      (match_operand:DI 2 "memory_operand" "Yd")
		      (match_operand:SI 3 "const_int_operand" "n")]
		     UNSPEC_FXU_LDV_DW))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[3]), 1, 3)"
  "ldv.dw %3, %2, %0"
  [(set_attr "length" "6")
   (set_attr "type" "load")])

(define_insn "@fxu_stv_dw<mode>"
  [(set (match_operand:DI 0 "memory_operand" "=Yd")
	(unspec:DI [(match_operand:VFXU 1 "register_operand" "w")
		    (match_operand:SI 2 "const_int_operand" "n")]
		   UNSPEC_FXU_STV_DW))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[2]), 0, 1)"
  "stv.dw %2, %1, %0"
  [(set_attr "length" "6")
   (set_attr "type" "store")])
