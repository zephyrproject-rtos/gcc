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
  UNSPEC_FXU_LDV_W
  UNSPEC_FXU_STV_W
  UNSPEC_FXU_LDVZ_H4
  UNSPEC_FXU_STVZ_H4
  UNSPEC_FXU_RECIPF
  UNSPEC_FXU_RSQRTF
  UNSPEC_FXU_ADDSUBF
  UNSPEC_FXU_ADDSUBNF
  UNSPEC_FXU_SUBADDF
  UNSPEC_FXU_SUBADDNF
  UNSPEC_FXU_ADDXF
  UNSPEC_FXU_SUBXF
  UNSPEC_FXU_MULXF
  UNSPEC_FXU_ADDSUBXF
  UNSPEC_FXU_ADDSUBNXF
  UNSPEC_FXU_SUBADDXF
  UNSPEC_FXU_SUBADDNXF
  UNSPEC_FXU_ADDRF
  UNSPEC_FXU_SUBRF
  UNSPEC_FXU_MULRF
  UNSPEC_FXU_MAXRF
  UNSPEC_FXU_MINRF
  UNSPEC_FXU_CEILF_SW4
  UNSPEC_FXU_CEILF_SUW4
  UNSPEC_FXU_FLOORF_SW4
  UNSPEC_FXU_FLOORF_SUW4
  UNSPEC_FXU_ROUNDF_SW4
  UNSPEC_FXU_ROUNDF_SUW4
  UNSPEC_FXU_CVTF_SW4
  UNSPEC_FXU_CVTF_SUW4
  UNSPEC_FXU_CVTF_HS4
  UNSPEC_FXU_CVTF_SH4
  UNSPEC_FXU_CMPF
  UNSPEC_FXU_CMOVF
  UNSPEC_FXU_SHFLV
  UNSPEC_FXU_FLPV
  UNSPEC_FXU_TRFSRV
])

(define_int_iterator FXU_BINOP [UNSPEC_FXU_ADDSUBF UNSPEC_FXU_ADDSUBNF
				UNSPEC_FXU_SUBADDF UNSPEC_FXU_SUBADDNF
				UNSPEC_FXU_ADDXF UNSPEC_FXU_SUBXF
				UNSPEC_FXU_MULXF UNSPEC_FXU_ADDSUBXF
				UNSPEC_FXU_ADDSUBNXF UNSPEC_FXU_SUBADDXF
				UNSPEC_FXU_SUBADDNXF UNSPEC_FXU_ADDRF
				UNSPEC_FXU_SUBRF UNSPEC_FXU_MULRF
				UNSPEC_FXU_MAXRF UNSPEC_FXU_MINRF])

(define_int_iterator FXU_UNOP [UNSPEC_FXU_RECIPF UNSPEC_FXU_RSQRTF])

(define_int_iterator FXU_F2I [UNSPEC_FXU_CEILF_SW4 UNSPEC_FXU_CEILF_SUW4
			      UNSPEC_FXU_FLOORF_SW4 UNSPEC_FXU_FLOORF_SUW4
			      UNSPEC_FXU_ROUNDF_SW4 UNSPEC_FXU_ROUNDF_SUW4
			      UNSPEC_FXU_CVTF_SW4 UNSPEC_FXU_CVTF_SUW4
			      UNSPEC_FXU_CVTF_SH4])

(define_int_attr fxu_insn [(UNSPEC_FXU_ADDSUBF "addsubf.s4")
			   (UNSPEC_FXU_ADDSUBNF "addsubnf.s4")
			   (UNSPEC_FXU_SUBADDF "subaddf.s4")
			   (UNSPEC_FXU_SUBADDNF "subaddnf.s4")
			   (UNSPEC_FXU_ADDXF "addxf.s4")
			   (UNSPEC_FXU_SUBXF "subxf.s4")
			   (UNSPEC_FXU_MULXF "mulxf.s4")
			   (UNSPEC_FXU_ADDSUBXF "addsubxf.s4")
			   (UNSPEC_FXU_ADDSUBNXF "addsubnxf.s4")
			   (UNSPEC_FXU_SUBADDXF "subaddxf.s4")
			   (UNSPEC_FXU_SUBADDNXF "subaddnxf.s4")
			   (UNSPEC_FXU_ADDRF "addrf.s4")
			   (UNSPEC_FXU_SUBRF "subrf.s4")
			   (UNSPEC_FXU_MULRF "mulrf.s4")
			   (UNSPEC_FXU_MAXRF "maxrf.s4")
			   (UNSPEC_FXU_MINRF "minrf.s4")
			   (UNSPEC_FXU_RECIPF "recipf.s4")
			   (UNSPEC_FXU_RSQRTF "rsqrtf.s4")
			   (UNSPEC_FXU_CEILF_SW4 "ceilf.sw4")
			   (UNSPEC_FXU_CEILF_SUW4 "ceilf.suw4")
			   (UNSPEC_FXU_FLOORF_SW4 "floorf.sw4")
			   (UNSPEC_FXU_FLOORF_SUW4 "floorf.suw4")
			   (UNSPEC_FXU_ROUNDF_SW4 "roundf.sw4")
			   (UNSPEC_FXU_ROUNDF_SUW4 "roundf.suw4")
			   (UNSPEC_FXU_CVTF_SW4 "cvtf.sw4")
			   (UNSPEC_FXU_CVTF_SUW4 "cvtf.suw4")
			   (UNSPEC_FXU_CVTF_SH4 "cvtf.sh4")])

(define_int_attr fxu_name [(UNSPEC_FXU_ADDSUBF "addsubf")
			   (UNSPEC_FXU_ADDSUBNF "addsubnf")
			   (UNSPEC_FXU_SUBADDF "subaddf")
			   (UNSPEC_FXU_SUBADDNF "subaddnf")
			   (UNSPEC_FXU_ADDXF "addxf")
			   (UNSPEC_FXU_SUBXF "subxf")
			   (UNSPEC_FXU_MULXF "mulxf")
			   (UNSPEC_FXU_ADDSUBXF "addsubxf")
			   (UNSPEC_FXU_ADDSUBNXF "addsubnxf")
			   (UNSPEC_FXU_SUBADDXF "subaddxf")
			   (UNSPEC_FXU_SUBADDNXF "subaddnxf")
			   (UNSPEC_FXU_ADDRF "addrf")
			   (UNSPEC_FXU_SUBRF "subrf")
			   (UNSPEC_FXU_MULRF "mulrf")
			   (UNSPEC_FXU_MAXRF "maxrf")
			   (UNSPEC_FXU_MINRF "minrf")
			   (UNSPEC_FXU_RECIPF "recipf")
			   (UNSPEC_FXU_RSQRTF "rsqrtf")
			   (UNSPEC_FXU_CEILF_SW4 "ceilf_sw4")
			   (UNSPEC_FXU_CEILF_SUW4 "ceilf_suw4")
			   (UNSPEC_FXU_FLOORF_SW4 "floorf_sw4")
			   (UNSPEC_FXU_FLOORF_SUW4 "floorf_suw4")
			   (UNSPEC_FXU_ROUNDF_SW4 "roundf_sw4")
			   (UNSPEC_FXU_ROUNDF_SUW4 "roundf_suw4")
			   (UNSPEC_FXU_CVTF_SW4 "cvtf_sw4")
			   (UNSPEC_FXU_CVTF_SUW4 "cvtf_suw4")
			   (UNSPEC_FXU_CVTF_SH4 "cvtf_sh4")])

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

(define_insn "fxu_realign_sp"
  [(set (reg:SI SP_REGNUM)
	(and:SI (reg:SI SP_REGNUM)
		(match_operand:SI 0 "const_int_operand" "n")))
   (clobber (reg:SI 12))
   (clobber (reg:CC CC_REGNUM))]
  "reload_completed"
{
  if (CONST_OK_FOR_J (INTVAL (operands[0])))
    return "mov %0,r12 ; and r12,sp";
  if (CONST_OK_FOR_K (INTVAL (operands[0])))
    return "movea %0,r0,r12 ; and r12,sp";
  return "mov %0,r12 ; and r12,sp";
}
  [(set (attr "length")
	(cond [(match_test "CONST_OK_FOR_J (INTVAL (operands[0]))")
	       (const_int 4)
	       (match_test "CONST_OK_FOR_K (INTVAL (operands[0]))")
	       (const_int 6)]
	      (const_int 8)))])

(define_insn "fxu_restore_sp"
  [(set (reg:SI SP_REGNUM)
	(match_operand:SI 0 "register_operand" "r"))
   (clobber (mem:BLK (scratch)))]
  "reload_completed"
  "mov %0,sp"
  [(set_attr "length" "2")])

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

(define_code_iterator FXU_ARITH [plus minus mult div smax smin])

(define_code_attr fxu_arith_name [(plus "add") (minus "sub") (mult "mul")
				  (div "div") (smax "smax") (smin "smin")])

(define_code_attr fxu_arith_insn [(plus "addf.s4") (minus "subf.s4")
				  (mult "mulf.s4") (div "divf.s4")
				  (smax "maxf.s4") (smin "minf.s4")])

(define_insn "<fxu_arith_name>v4sf3"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(FXU_ARITH:V4SF (match_operand:V4SF 1 "register_operand" "w")
			(match_operand:V4SF 2 "register_operand" "w")))]
  "TARGET_FXU"
  "<fxu_arith_insn> %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "sqrtv4sf2"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(sqrt:V4SF (match_operand:V4SF 1 "register_operand" "w")))]
  "TARGET_FXU"
  "sqrtf.s4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "absv4sf2"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(abs:V4SF (match_operand:V4SF 1 "register_operand" "w")))]
  "TARGET_FXU"
  "absf.s4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "negv4sf2"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(neg:V4SF (match_operand:V4SF 1 "register_operand" "w")))]
  "TARGET_FXU"
  "negf.s4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fmav4sf4"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(fma:V4SF (match_operand:V4SF 1 "register_operand" "w")
		  (match_operand:V4SF 2 "register_operand" "w")
		  (match_operand:V4SF 3 "register_operand" "0")))]
  "TARGET_FXU"
  "fmaf.s4 %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fmsv4sf4"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(fma:V4SF (match_operand:V4SF 1 "register_operand" "w")
		  (match_operand:V4SF 2 "register_operand" "w")
		  (neg:V4SF (match_operand:V4SF 3 "register_operand" "0"))))]
  "TARGET_FXU"
  "fmsf.s4 %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_fnmaf"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(neg:V4SF
	  (fma:V4SF (match_operand:V4SF 1 "register_operand" "w")
		    (match_operand:V4SF 2 "register_operand" "w")
		    (match_operand:V4SF 3 "register_operand" "0"))))]
  "TARGET_FXU"
  "fnmaf.s4 %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_fnmsf"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(neg:V4SF
	  (fma:V4SF (match_operand:V4SF 1 "register_operand" "w")
		    (match_operand:V4SF 2 "register_operand" "w")
		    (neg:V4SF (match_operand:V4SF 3 "register_operand" "0")))))]
  "TARGET_FXU"
  "fnmsf.s4 %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_<fxu_name>"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(unspec:V4SF [(match_operand:V4SF 1 "register_operand" "w")
		      (match_operand:V4SF 2 "register_operand" "w")]
		     FXU_BINOP))]
  "TARGET_FXU"
  "<fxu_insn> %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_<fxu_name>"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(unspec:V4SF [(match_operand:V4SF 1 "register_operand" "w")]
		     FXU_UNOP))]
  "TARGET_FXU"
  "<fxu_insn> %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fix_truncv4sfv4si2"
  [(set (match_operand:V4SI 0 "register_operand" "=w")
	(fix:V4SI (match_operand:V4SF 1 "register_operand" "w")))]
  "TARGET_FXU"
  "trncf.sw4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fixuns_truncv4sfv4si2"
  [(set (match_operand:V4SI 0 "register_operand" "=w")
	(unsigned_fix:V4SI (match_operand:V4SF 1 "register_operand" "w")))]
  "TARGET_FXU"
  "trncf.suw4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "floatv4siv4sf2"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(float:V4SF (match_operand:V4SI 1 "register_operand" "w")))]
  "TARGET_FXU"
  "cvtf.ws4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "floatunsv4siv4sf2"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(unsigned_float:V4SF (match_operand:V4SI 1 "register_operand" "w")))]
  "TARGET_FXU"
  "cvtf.uws4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_<fxu_name>"
  [(set (match_operand:V4SI 0 "register_operand" "=w")
	(unspec:V4SI [(match_operand:V4SF 1 "register_operand" "w")]
		     FXU_F2I))]
  "TARGET_FXU"
  "<fxu_insn> %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_cvtf_hs4"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(unspec:V4SF [(match_operand:V4SI 1 "register_operand" "w")]
		     UNSPEC_FXU_CVTF_HS4))]
  "TARGET_FXU"
  "cvtf.hs4 %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_cmpf"
  [(set (match_operand:V4SI 0 "register_operand" "=w")
	(unspec:V4SI [(match_operand:V4SF 1 "register_operand" "w")
		      (match_operand:V4SF 2 "register_operand" "w")
		      (match_operand:SI 3 "const_int_operand" "n")]
		     UNSPEC_FXU_CMPF))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[3]), 0, 15)"
  "cmpf.s4 %3, %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "@fxu_cmovf<mode>"
  [(set (match_operand:VFXU 0 "register_operand" "=w")
	(unspec:VFXU [(match_operand:V4SI 1 "register_operand" "w")
		      (match_operand:VFXU 2 "register_operand" "w")
		      (match_operand:VFXU 3 "register_operand" "w")]
		     UNSPEC_FXU_CMOVF))]
  "TARGET_FXU"
  "cmovf.w4 %1, %2, %3, %0"
  [(set_attr "length" "6")
   (set_attr "type" "fpu")])

(define_insn "@fxu_shflv<mode>"
  [(set (match_operand:VFXU 0 "register_operand" "=w")
	(unspec:VFXU [(match_operand:VFXU 1 "register_operand" "w")
		      (match_operand:VFXU 2 "register_operand" "w")
		      (match_operand:SI 3 "const_int_operand" "n")]
		     UNSPEC_FXU_SHFLV))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[3]), 0, 4095)"
  "shflv.w4 %3, %1, %2, %0"
  [(set_attr "length" "6")
   (set_attr "type" "fpu")])

(define_insn "fxu_flpv"
  [(set (match_operand:V4SF 0 "register_operand" "=w")
	(unspec:V4SF [(match_operand:V4SF 1 "register_operand" "w")
		      (match_operand:SI 2 "const_int_operand" "n")]
		     UNSPEC_FXU_FLPV))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[2]), 0, 3)"
  "flpv.s4 %2, %1, %0"
  [(set_attr "type" "fpu")])

(define_insn "fxu_trfsrv"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:V4SI 1 "register_operand" "w")
		    (match_operand:SI 2 "const_int_operand" "n")]
		   UNSPEC_FXU_TRFSRV))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[2]), 0, 5)"
  "trfsrv.w4 %2, %1 ; setf z, %0"
  [(set_attr "length" "8")])

(define_insn "@fxu_ldv_w<mode>"
  [(set (match_operand:VFXU 0 "register_operand" "=w")
	(unspec:VFXU [(match_operand:VFXU 1 "register_operand" "0")
		      (match_operand:SI 2 "memory_operand" "Yw")
		      (match_operand:SI 3 "const_int_operand" "n")]
		     UNSPEC_FXU_LDV_W))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[3]), 0, 15)"
  "ldv.w %3, %2, %0"
  [(set_attr "length" "6")
   (set_attr "type" "load")])

(define_insn "@fxu_stv_w<mode>"
  [(set (match_operand:SI 0 "memory_operand" "=Yw")
	(unspec:SI [(match_operand:VFXU 1 "register_operand" "w")
		    (match_operand:SI 2 "const_int_operand" "n")]
		   UNSPEC_FXU_STV_W))]
  "TARGET_FXU && IN_RANGE (INTVAL (operands[2]), 0, 3)"
  "stv.w %2, %1, %0"
  [(set_attr "length" "6")
   (set_attr "type" "store")])

(define_insn "fxu_ldvz_h4"
  [(set (match_operand:V4SI 0 "register_operand" "=w")
	(unspec:V4SI [(match_operand:DI 1 "memory_operand" "Yd")]
		     UNSPEC_FXU_LDVZ_H4))]
  "TARGET_FXU"
  "ldvz.h4 %1, %0"
  [(set_attr "length" "6")
   (set_attr "type" "load")])

(define_insn "fxu_stvz_h4"
  [(set (match_operand:DI 0 "memory_operand" "=Yd")
	(unspec:DI [(match_operand:V4SI 1 "register_operand" "w")]
		   UNSPEC_FXU_STVZ_H4))]
  "TARGET_FXU"
  "stvz.h4 %1, %0"
  [(set_attr "length" "6")
   (set_attr "type" "store")])
