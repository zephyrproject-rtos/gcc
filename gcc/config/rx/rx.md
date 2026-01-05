;;  Machine Description for Renesas RX processors
;;  Copyright (C) 2008-2024 Free Software Foundation, Inc.
;;  Contributed by Red Hat.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.


;; This code iterator is used for sign- and zero- extensions.
(define_mode_iterator small_int_modes [(HI "") (QI "")])

;; This code iterator is used for max and min operations.
(define_mode_iterator int_modes [(SI "") (HI "") (QI "")])

;; We do not handle DFmode here because it is either
;; the same as SFmode, or if -m64bit-doubles is active
;; then all operations on doubles have to be handled by
;; library functions.
(define_mode_iterator register_modes
  [(SF "ALLOW_RX_FPU_INSNS") (SI "") (HI "") (QI "")])

(define_constants
  [
   (SP_REG 0)
   (CC_REG 		   48)

   (UNSPEC_LOW_REG         0)
   (UNSPEC_HIGH_REG        1)

   (UNSPEC_RTE             10)
   (UNSPEC_RTFI            11)
   (UNSPEC_NAKED           12)
   (UNSPEC_CONST           13)

   (UNSPEC_MOVSTR          20)
   (UNSPEC_CPYMEM          21)
   (UNSPEC_SETMEM          22)
   (UNSPEC_STRLEN          23)
   (UNSPEC_CMPSTRN         24)

   (UNSPEC_BUILTIN_BRK     30)
   (UNSPEC_BUILTIN_CLRPSW  31)
   (UNSPEC_BUILTIN_INT     32)
   (UNSPEC_BUILTIN_MACHI   33)
   (UNSPEC_BUILTIN_MACLO   34)
   (UNSPEC_BUILTIN_MULHI   35)
   (UNSPEC_BUILTIN_MULLO   36)
   (UNSPEC_BUILTIN_MVFACHI 37)
   (UNSPEC_BUILTIN_MVFACMI 38)
   (UNSPEC_BUILTIN_MVFC    39)
   (UNSPEC_BUILTIN_MVFCP   40)
   (UNSPEC_BUILTIN_MVTACHI 41)
   (UNSPEC_BUILTIN_MVTACLO 42)
   (UNSPEC_BUILTIN_MVTC    43)
   (UNSPEC_BUILTIN_MVTIPL  44)
   (UNSPEC_BUILTIN_RACW	   45)
   (UNSPEC_BUILTIN_REVW    46)
   (UNSPEC_BUILTIN_RMPA	   47)
   (UNSPEC_BUILTIN_RMPA8	   102)
   (UNSPEC_BUILTIN_RMPA16	   103)
   (UNSPEC_BUILTIN_RMPA32	   104)
   (UNSPEC_BUILTIN_ROUND   48)
   (UNSPEC_BUILTIN_DROUND 148)
   (UNSPEC_BUILTIN_SAT     49)
   (UNSPEC_BUILTIN_SETPSW  50)
   (UNSPEC_BUILTIN_WAIT	   51)
   (UNSPEC_BUILTIN_BSET	   52)
   (UNSPEC_BUILTIN_BCLR	   53)
   (UNSPEC_BUILTIN_BNOT	   54)
   (UNSPEC_BUILTIN_BSET_MEM	   95)
   (UNSPEC_BUILTIN_BCLR_MEM	   96)
   (UNSPEC_BUILTIN_BNOT_MEM	   97)

   (UNSPEC_BUILTIN_EMULA_A0		55)
   (UNSPEC_BUILTIN_EMULA_A1		56)
   (UNSPEC_BUILTIN_EMACA_A0		57)
   (UNSPEC_BUILTIN_EMACA_A1		58)
   (UNSPEC_BUILTIN_EMSBA_A0		59)
   (UNSPEC_BUILTIN_EMSBA_A1		60)
   (UNSPEC_BUILTIN_MULLH_A0		61)
   (UNSPEC_BUILTIN_MULLH_A1		62)
   (UNSPEC_BUILTIN_MULHI_A1		63)
   (UNSPEC_BUILTIN_MULLO_A1		64)
   (UNSPEC_BUILTIN_MACLH_A0		65)
   (UNSPEC_BUILTIN_MACLH_A1		66)
   (UNSPEC_BUILTIN_MACHI_A1		67)
   (UNSPEC_BUILTIN_MACLO_A1		68)
   (UNSPEC_BUILTIN_MSBLH_A0		69)
   (UNSPEC_BUILTIN_MSBLH_A1		70)
   (UNSPEC_BUILTIN_MSBHI_A0		71)
   (UNSPEC_BUILTIN_MSBHI_A1		72)
   (UNSPEC_BUILTIN_MSBLO_A0		73)
   (UNSPEC_BUILTIN_MSBLO_A1		74)
   (UNSPEC_BUILTIN_RDACW_A0		75)
   (UNSPEC_BUILTIN_RDACW_A1		76)
   (UNSPEC_BUILTIN_RDACL_A0		77)
   (UNSPEC_BUILTIN_RDACL_A1		78)
   (UNSPEC_BUILTIN_RACW_A1		79)
   (UNSPEC_BUILTIN_RACL_A0		80)
   (UNSPEC_BUILTIN_RACL_A1		81)
   (UNSPEC_BUILTIN_MVFACHI_A0	82)
   (UNSPEC_BUILTIN_MVFACHI_A1	83)
   (UNSPEC_BUILTIN_MVFACMI_A0	84)
   (UNSPEC_BUILTIN_MVFACMI_A1	85)
   (UNSPEC_BUILTIN_MVFACLO_A0	86)
   (UNSPEC_BUILTIN_MVFACLO_A1	87)
   (UNSPEC_BUILTIN_MVFACGU_A0	88)
   (UNSPEC_BUILTIN_MVFACGU_A1	89)
   (UNSPEC_BUILTIN_MVTACHI_A1	90)
   (UNSPEC_BUILTIN_MVTACLO_A1	91)
   (UNSPEC_BUILTIN_MVTACGU_A0	92)
   (UNSPEC_BUILTIN_MVTACGU_A1	93)
   (UNSPEC_BUILTIN_XCHG 94)
   (UNSPEC_BUILTIN_SAVE 95)
   (UNSPEC_BUILTIN_RSTR 96)
   (UNSPEC_BUILTIN_MVFDC 97)
   (UNSPEC_BUILTIN_MVTDC 98)
   (UNSPEC_BUILTIN_MVFDR 99)
   (UNSPEC_BUILTIN_BFMOV 100)
   (UNSPEC_BUILTIN_BFMOVZ 101)
   (UNSPEC_PID_ADDR	   52)

   (CTRLREG_PSW		    0)
   (CTRLREG_PC		    1)
   (CTRLREG_USP		    2)
   (CTRLREG_FPSW	    3)
   (CTRLREG_BPSW	    8)
   (CTRLREG_BPC		    9)
   (CTRLREG_ISP		   10)
   (CTRLREG_FINTV	   11)
   (CTRLREG_INTB	   12)
   (CTRLREG_EXTB     13)
  ]
)

(define_attr "length" "" (const_int 8))

(include "predicates.md")
(include "constraints.md")

;; Pipeline description.

;; The RX only has a single pipeline.  It has five stages (fetch,
;; decode, execute, memory access, writeback) each of which normally
;; takes a single CPU clock cycle.

;; The timings attribute consists of two numbers, the first is the
;; throughput, which is the number of cycles the instruction takes
;; to execute and generate a result.  The second is the latency
;; which is the effective number of cycles the instruction takes to
;; execute if its result is used by the following instruction.  The
;; latency is always greater than or equal to the throughput.
;; These values were taken from tables 2.13 and 2.14 in section 2.8
;; of the RX610 Group Hardware Manual v0.11

;; The insn_group attribute consists of an enum, representing
;; the instruction issue group, as described in Renesas document
;; RXv2_pipeline_info_180112a.pdf

;; Note - it would be nice to use strings rather than integers for
;; the possible values of this attribute, so that we can have the
;; gcc build mechanism check for values that are not supported by
;; the reservations below.  But this will not work because the code
;; in rx_adjust_sched_cost() needs integers not strings.

(define_attr "timings" "" (const_int 11))

(define_attr "insn_group" "IEX,IEP,IML,IBC,IBR,IBS,ILS,ILSP,IFE,IFM,IF1,ISNG" (const_string "ISNG"))

(define_automaton "pipelining")
(define_cpu_unit "throughput_pri,throughput_sec" "pipelining")

(define_insn_reservation "throughput__1_latency__1"  1
  (eq_attr "timings" "11") "throughput_pri|throughput_sec")
(define_insn_reservation "throughput__1_latency__2"  2
  (eq_attr "timings" "12") "throughput_pri|throughput_sec,nothing")
(define_insn_reservation "throughput__2_latency__2"  1
  (eq_attr "timings" "22") "throughput_pri*2|throughput_sec*2")
(define_insn_reservation "throughput__3_latency__3"  1
  (eq_attr "timings" "33") "throughput_pri*3|throughput_sec*3")
(define_insn_reservation "throughput__3_latency__4"  2
  (eq_attr "timings" "34") "throughput_pri*3|throughput_sec*3,nothing")
(define_insn_reservation "throughput__4_latency__4"  1
  (eq_attr "timings" "44") "throughput_pri*4|throughput_sec*4")
(define_insn_reservation "throughput__4_latency__5"  2
  (eq_attr "timings" "45") "throughput_pri*4|throughput_sec*4,nothing")
(define_insn_reservation "throughput__5_latency__5"  1
  (eq_attr "timings" "55") "throughput_pri*5|throughput_sec*5")
(define_insn_reservation "throughput__5_latency__6"  2
  (eq_attr "timings" "56") "throughput_pri*5|throughput_sec*5,nothing")
(define_insn_reservation "throughput__6_latency__6"  1
  (eq_attr "timings" "66") "throughput_pri*6|throughput_sec*6")
(define_insn_reservation "throughput_10_latency_10"  1
  (eq_attr "timings" "1010") "throughput_pri*10|throughput_sec*10")
(define_insn_reservation "throughput_11_latency_11"  1
  (eq_attr "timings" "1111") "throughput_pri*11|throughput_sec*11")
(define_insn_reservation "throughput_16_latency_16"  1
  (eq_attr "timings" "1616") "throughput_pri*16|throughput_sec*16")
(define_insn_reservation "throughput_18_latency_18"  1
  (eq_attr "timings" "1818") "throughput_pri*18|throughput_sec*18")

;; ----------------------------------------------------------------------------

;; Comparisons

;; Note - we do not specify the two instructions necessary to perform
;; a compare-and-branch in the cbranchsi4 pattern because that would
;; allow the comparison to be moved away from the jump before the reload
;; pass has completed.  That would be problematical because reload can
;; generate ADDSI3 instructions which would corrupt the PSW flags.

(define_expand "cbranchsi4"
  [(set (pc)
	(if_then_else
	  (match_operator 0 "comparison_operator"
	    [(match_operand:SI 1 "register_operand")
	     (match_operand:SI 2 "rx_speed_source_operand")])
	  (label_ref (match_operand 3 ""))
	  (pc)))]
  ""
  "
      operands[2] = rx_maybe_pidify_operand (operands[2], 1);
  "
)

(define_insn_and_split "*cbranchsi4_mem"
  [(set (pc)
	(if_then_else
	  (match_operator 3 "comparison_operator"
	    [(match_operand:SI  0 "register_operand"  "r")
	     (match_operand:SI  1 "rx_restricted_mem_operand" "Q")])
	  (match_operand        2 "label_ref_operand" "")
	  (pc)))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rx_split_cbranch (CCmode, GET_CODE (operands[3]),
		    operands[0], operands[1], operands[2]);
  DONE;
})

(define_insn_and_split "*cbranchsi4"
  [(set (pc)
	(if_then_else
	  (match_operator 3 "comparison_operator"
	    [(match_operand:SI  0 "register_operand"  "r")
	     (match_operand:SI  1 "rx_speed_source_operand" "ri")])
	  (match_operand        2 "label_ref_operand" "")
	  (pc)))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rx_split_cbranch (CCmode, GET_CODE (operands[3]),
		    operands[0], operands[1], operands[2]);
  DONE;
})

(define_expand "cmpsi"
  [(set (reg:CC CC_REG)
       (compare:CC (match_operand:SI 0 "register_operand"  "r,r,r,r,r,r,r")
                   (match_operand:SI 1 "rx_source_operand" "r,Uint04,Int08,Sint16,Sint24,i,Q")))]
  ""
  "
      operands[1] = rx_maybe_pidify_operand (operands[1], 1);
  "
  )

(define_insn "*cmpsi_mem"
  [(set (reg:CC CC_REG)
	(compare:CC (match_operand:SI 0 "register_operand"  "r")
		    (match_operand:SI 1 "rx_restricted_mem_operand" "Q")))]
  "reload_completed"
  "cmp\t%Q1, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "cmpsi_internal"
  [(set (reg:CC CC_REG)
	(compare:CC (match_operand:SI 0 "register_operand"  "r,r,r,r,r,r")
		    (match_operand:SI 1 "rx_speed_source_operand" "r,Uint04,Int08,Sint16,Sint24,i")))]
  "reload_completed"
  "cmp\t%Q1, %0"
  [(set_attr "timings" "11,11,11,11,11,11")
   (set_attr "length"  "2,2,3,4,5,6")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX")]
)

;; Canonical method for representing TST.
(define_insn_and_split "*cbranchsi4_tst_mem"
  [(set (pc)
	(if_then_else
	  (match_operator 3 "rx_zs_comparison_operator"
	    [(and:SI (match_operand:SI  0 "register_operand"  "r")
		     (match_operand:SI  1 "rx_restricted_mem_operand" "Q"))
	     (const_int 0)])
	  (match_operand 2 "label_ref_operand" "")
	  (pc)))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rx_split_cbranch (CC_ZSmode, GET_CODE (operands[3]),
		    XEXP (operands[3], 0), XEXP (operands[3], 1),
		    operands[2]);
  DONE;
})

(define_insn_and_split "*cbranchsi4_tst"
  [(set (pc)
	(if_then_else
	  (match_operator 3 "rx_zs_comparison_operator"
	    [(and:SI (match_operand:SI  0 "register_operand"  "r")
		     (match_operand:SI  1 "rx_speed_source_operand" "ri"))
	     (const_int 0)])
	  (match_operand 2 "label_ref_operand" "")
	  (pc)))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rx_split_cbranch (CC_ZSmode, GET_CODE (operands[3]),
		    XEXP (operands[3], 0), XEXP (operands[3], 1),
		    operands[2]);
  DONE;
})

;; Various other ways that GCC codes "var & const"
(define_insn_and_split "*cbranchsi4_tst_ext"
  [(set (pc)
	(if_then_else
	  (match_operator 4 "rx_z_comparison_operator"
	    [(zero_extract:SI
		(match_operand:SI 0 "register_operand" "r")
		(match_operand:SI 1 "rx_constshift_operand" "")
		(match_operand:SI 2 "rx_constshift_operand" ""))
	     (const_int 0)])
	  (match_operand 3 "label_ref_operand" "")
	  (pc)))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  HOST_WIDE_INT mask;
  rtx x;

  mask = 1;
  mask <<= INTVAL (operands[1]);
  mask -= 1;
  mask <<= INTVAL (operands[2]);
  x = gen_rtx_AND (SImode, operands[0], gen_int_mode (mask, SImode));

  rx_split_cbranch (CC_ZSmode, GET_CODE (operands[4]),
		    x, const0_rtx, operands[3]);
  DONE;
})

(define_insn "*tstsi_mem"
  [(set (reg:CC_ZS CC_REG)
	(compare:CC_ZS
	  (and:SI (match_operand:SI 0 "register_operand"  "r")
		  (match_operand:SI 1 "rx_restricted_mem_operand" "Q"))
	  (const_int 0)))]
  "reload_completed"
  "tst\t%Q1, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "6")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*tstsi"
  [(set (reg:CC_ZS CC_REG)
	(compare:CC_ZS
	  (and:SI (match_operand:SI 0 "register_operand"  "r,r")
		  (match_operand:SI 1 "rx_speed_source_operand" "r,i"))
	  (const_int 0)))]
  "reload_completed"
  "tst\t%Q1, %0"
  [(set_attr "timings" "11,11")
   (set_attr "length"  "3,7")
   (set_attr "insn_group"  "IEX,IEX")]
)

(define_expand "cbranchsf4"
  [(set (pc)
	(if_then_else
	  (match_operator 0 "rx_fp_comparison_operator"
	    [(match_operand:SF 1 "register_operand")
	     (match_operand:SF 2 "rx_speed_source_operand")])
	  (label_ref (match_operand 3 ""))
	  (pc)))]
  "ALLOW_RX_FPU_INSNS"
)

(define_insn_and_split "*cbranchsf4_mem"
  [(set (pc)
	(if_then_else
	  (match_operator 3 "rx_fp_comparison_operator"
	    [(match_operand:SF  0 "register_operand"  "r")
	     (match_operand:SF  1 "rx_restricted_mem_operand" "Q")])
	  (match_operand        2 "label_ref_operand" "")
	  (pc)))]
  "ALLOW_RX_FPU_INSNS"
  "#"
  "&& reload_completed"
  [(const_int 0)]
{
  rx_split_cbranch (CC_Fmode, GET_CODE (operands[3]),
		    operands[0], operands[1], operands[2]);
  DONE;
})

(define_insn_and_split "*cbranchsf4"
  [(set (pc)
	(if_then_else
	  (match_operator 3 "rx_fp_comparison_operator"
	    [(match_operand:SF  0 "register_operand"  "r")
	     (match_operand:SF  1 "rx_speed_source_operand" "rF")])
	  (match_operand        2 "label_ref_operand" "")
	  (pc)))]
  "ALLOW_RX_FPU_INSNS"
  "#"
  "&& reload_completed"
  [(const_int 0)]
{
  rx_split_cbranch (CC_Fmode, GET_CODE (operands[3]),
		    operands[0], operands[1], operands[2]);
  DONE;
})

(define_insn "*cmpsf_mem"
  [(set (reg:CC_F CC_REG)
	(compare:CC_F
	  (match_operand:SF 0 "register_operand"  "r")
	  (match_operand:SF 1 "rx_restricted_mem_operand" "Q")))]
  "ALLOW_RX_FPU_INSNS && reload_completed"
  "fcmp\t%1, %0"
  [(set_attr "timings" "33")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*cmpsf"
  [(set (reg:CC_F CC_REG)
	(compare:CC_F
	  (match_operand:SF 0 "register_operand"  "r,r")
	  (match_operand:SF 1 "rx_speed_source_operand" "r,F")))]
  "ALLOW_RX_FPU_INSNS && reload_completed"
  "fcmp\t%1, %0"
  [(set_attr "timings" "11,11")
   (set_attr "length" "3,7")
   (set_attr "insn_group"  "IF1,IF1")]
)

(define_insn "cbranchdf4"
  [(set (pc)
	(if_then_else
	  (match_operator 0 "comparison_operator"
	    [(match_operand:DF  1 "register_operand"  "DFPUreg")
	     (match_operand:DF  2 "register_operand" "DFPUreg")])
	  (label_ref (match_operand 3 ""))
	  (pc)))]
  "flag_dfpu"
  {
	switch(GET_CODE(operands[0]))
	{
	case ORDERED:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbz\t%3";
    case UNORDERED:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbnz\t%3";
    case EQ:
		return "dcmpeq\t%2, %1\n\tmvfdr\n\tbz\t%3";
    case NE:
		return "dcmpeq\t%2, %1\n\tmvfdr\n\tbnz\t%3";
	case LT:
		return "dcmplt\t%2, %1\n\tmvfdr\n\tbz\t%3";
	case LE:
		return "dcmple\t%2, %1\n\tmvfdr\n\tbz\t%3";
	case GT:
		return "dcmplt\t%1, %2\n\tmvfdr\n\tbz\t%3";
	case GE:
		return "dcmple\t%1, %2\n\tmvfdr\n\tbz\t%3";
  case UNEQ:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbnz\t%3\n\tdcmpeq\t%2, %1\n\tmvfdr\n\tbz\t%3";
	case UNLT:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbnz\t%3\n\tdcmplt\t%2, %1\n\tmvfdr\n\tbz\t%3";
	case UNLE:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbnz\t%3\n\tdcmple\t%2, %1\n\tmvfdr\n\tbz\t%3";
	case UNGT:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbnz\t%3\n\tdcmplt\t%1, %2\n\tmvfdr\n\tbz\t%3";
	case UNGE:
		return "dcmpun\t%2, %1\n\tmvfdr\n\tbnz\t%3\n\tdcmple\t%1, %2\n\tmvfdr\n\tbz\t%3";
  case LTGT:
    return "dcmplt\t%2, %1\n\tmvfdr\n\tbz\t%3\n\tdcmplt\t%1, %2\n\tmvfdr\n\tbz\t%3";
	default:
		gcc_unreachable ();
	}
  }
  [(set_attr "timings" "11")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

;; Flow Control Instructions:

(define_insn "*conditional_branch"
  [(set (pc)
	(if_then_else
	  (match_operator 1 "comparison_operator"
	    [(reg CC_REG) (const_int 0)])
	  (label_ref (match_operand 0 "" ""))
	  (pc)))]
  "reload_completed"
  "b%B1\t%0"
  [(set_attr "length" "8")    ;; This length is wrong, but it is
                              ;; too hard to compute statically.
   (set_attr "timings" "33")  ;; The timing assumes that the branch is taken.
   (set_attr "insn_group"  "IBC")]
)

;; ----------------------------------------------------------------------------

(define_insn "jump"
  [(set (pc)
	(label_ref (match_operand 0 "" "")))]
  ""
  "bra\t%0"
  [(set_attr "length" "4")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "IBR")]
)

(define_insn "indirect_jump"
  [(set (pc)
	(match_operand:SI 0 "register_operand" "r"))]
  ""
  "jmp\t%0"
  [(set_attr "length" "2")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "IBR")]
)

(define_insn "tablejump"
  [(set (pc)
	(match_operand:SI          0 "register_operand" "r"))
   (use (label_ref (match_operand  1 "" "")))]
  ""
  { return TARGET_PID ? (TARGET_AS100_SYNTAX ? "\n?:\tbra\t%0"
					     : "\n1:\tbra\t%0")
	                                     : "\n1:jmp\t%0";
  }
  [(set_attr "timings" "33")
   (set_attr "length" "2")
   (set_attr "insn_group"  "IBR")]
)

(define_expand "return"
  [(return)]
  "rx_can_use_simple_return ()"
  "rx_expand_epilogue (false); DONE;"
)

(define_insn "simple_return"
  [(simple_return)]
  ""
  "rts"
  [(set_attr "length" "1")
   (set_attr "timings" "55")
   (set_attr "insn_group"  "ISNG")]
)

;; Unspec used so that the constant will not be invalid
;; if -mmax-constant-size has been specified.
(define_insn "deallocate_and_return"
  [(set (reg:SI SP_REG)
	(plus:SI (reg:SI SP_REG)
		 (const:SI (unspec:SI [(match_operand 0 "const_int_operand" "n")] UNSPEC_CONST))))
   (return)]
  ""
  "rtsd\t%0"
  [(set_attr "length" "2")
   (set_attr "timings" "55")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "pop_and_return"
  [(match_parallel 1 "rx_rtsd_vector"
     [(set (reg:SI SP_REG)
	   (plus:SI (reg:SI SP_REG)
		    (match_operand:SI 0 "const_int_operand" "n")))])
   (return)]
  "reload_completed"
  {
    rx_emit_stack_popm (operands, false);
    return "";
  }
  [(set_attr "length" "3")
   (set_attr "timings" "56")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "fast_interrupt_return"
  [(unspec_volatile [(return)] UNSPEC_RTFI) ]
  ""
  "rtfi"
  [(set_attr "length" "2")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "exception_return"
  [(unspec_volatile [(return)] UNSPEC_RTE) ]
  ""
  "rte"
  [(set_attr "length" "2")
   (set_attr "timings" "66")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "naked_return"
  [(unspec_volatile [(return)] UNSPEC_NAKED) ]
  ""
  "; Naked function: epilogue provided by programmer."
)


;; Note - the following set of patterns do not use the "memory_operand"
;; predicate or an "m" constraint because we do not allow symbol_refs
;; or label_refs as legitimate memory addresses.  This matches the
;; behavior of most of the RX instructions.  Only the call/branch
;; instructions are allowed to refer to symbols/labels directly.
;; The call operands are in QImode because that is the value of
;; FUNCTION_MODE

(define_expand "call"
  [(call (match_operand:QI 0 "general_operand")
	 (match_operand:SI 1 "general_operand"))]
  ""
  {
    rtx dest = XEXP (operands[0], 0);

    if (! rx_call_operand (dest, Pmode))
      dest = force_reg (Pmode, dest);
    emit_call_insn (gen_call_internal (dest));
    DONE;
  }
)

(define_insn "call_internal"
  [(call (mem:QI (match_operand:SI 0 "rx_call_operand" "r,CALL_OP_SYMBOL_REF"))
	 (const_int 0))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  jsr\t%0
  bsr\t%A0"
  [(set_attr "length" "2,4")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "IBS,IBS")]
)

(define_expand "call_value"
  [(set (match_operand          0 "register_operand")
	(call (match_operand:QI 1 "general_operand")
	      (match_operand:SI 2 "general_operand")))]
  ""
  {
    rtx dest = XEXP (operands[1], 0);

    if (! rx_call_operand (dest, Pmode))
      dest = force_reg (Pmode, dest);
    emit_call_insn (gen_call_value_internal (operands[0], dest));
    DONE;
  }
)

(define_insn "call_value_internal"
  [(set (match_operand                  0 "register_operand" "=r,r")
	(call (mem:QI (match_operand:SI 1 "rx_call_operand"   "r,CALL_OP_SYMBOL_REF"))
	      (const_int 0)))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  jsr\t%1
  bsr\t%A1"
  [(set_attr "length" "2,4")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "IBS,IBS")]
)

;; Note - we do not allow indirect sibcalls (with the address
;; held in a register) because we cannot guarantee that the register
;; chosen will be a call-used one.  If it is a call-saved register,
;; then the epilogue code will corrupt it by popping the saved value
;; off of the stack.
(define_expand "sibcall"
  [(parallel
    [(call (mem:QI (match_operand:SI 0 "rx_symbolic_call_operand"))
	   (match_operand:SI         1 "general_operand"))
     (return)])]
  ""
  {
    if (MEM_P (operands[0]))
      operands[0] = XEXP (operands[0], 0);
    emit_call_insn (gen_sibcall_internal (operands[0]));
    DONE;
  }
)

(define_insn "sibcall_internal"
  [(call (mem:QI (match_operand:SI 0 "rx_symbolic_call_operand" "Symbol"))
	 (const_int 0))
   (return)]
  ""
  "bra\t%A0"
  [(set_attr "length"  "4")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "IBR")]
)

(define_expand "sibcall_value"
 [(parallel
   [(set (match_operand                  0 "register_operand")
	 (call (mem:QI (match_operand:SI 1 "rx_symbolic_call_operand"))
	       (match_operand:SI         2 "general_operand")))
    (return)])]
  ""
  {
    if (MEM_P (operands[1]))
      operands[1] = XEXP (operands[1], 0);
    emit_call_insn (gen_sibcall_value_internal (operands[0], operands[1]));
    DONE;
  }
)

(define_insn "sibcall_value_internal"
 [(set (match_operand                  0 "register_operand"         "=r")
       (call (mem:QI (match_operand:SI 1 "rx_symbolic_call_operand" "Symbol"))
	     (const_int 0)))
  (return)]
  ""
  "bra\t%A1"
  [(set_attr "length"  "4")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "IBR")]
)

;; Function Prologue/Epilogue Instructions

(define_expand "prologue"
  [(const_int 0)]
  ""
  "rx_expand_prologue (); DONE;"
)

(define_expand "epilogue"
  [(return)]
  ""
  "rx_expand_epilogue (false); DONE;"
)

(define_expand "sibcall_epilogue"
  [(return)]
  ""
  "rx_expand_epilogue (true); DONE;"
)

;; Move Instructions

;; Note - we do not allow memory to memory moves, even though the ISA
;; supports them.  The reason is that the conditions on such moves are
;; too restrictive, specifically the source addressing mode is limited
;; by the destination addressing mode and vice versa.  (For example it
;; is not possible to use indexed register indirect addressing for one
;; of the operands if the other operand is anything other than a register,
;; but it is possible to use register relative addressing when the other
;; operand also uses register relative or register indirect addressing).
;;
;; GCC does not support computing legitimate addresses based on the
;; nature of other operands involved in the instruction, and reload is
;; not smart enough to cope with a whole variety of different memory
;; addressing constraints, so it is simpler and safer to just refuse
;; to support memory to memory moves.

(define_expand "mov<register_modes:mode>"
  [(set (match_operand:register_modes 0 "general_operand")
	(match_operand:register_modes 1 "general_operand"))]
  ""
  {
    if (MEM_P (operands[0]) && MEM_P (operands[1]))
      operands[1] = copy_to_mode_reg (<register_modes:MODE>mode, operands[1]);
    operands[0] = rx_maybe_pidify_operand (operands[0], 0);
    operands[1] = rx_maybe_pidify_operand (operands[1], 0);
    if (GET_CODE (operands[0]) != REG
	&& GET_CODE (operands[1]) == PLUS)
      operands[1] = copy_to_mode_reg (<register_modes:MODE>mode, operands[1]);
    if (GET_CODE (operands[1]) == PLUS && GET_MODE (operands[1]) == SImode)
      {
        emit_insn (gen_addsi3 (operands[0], XEXP (operands[1], 0), XEXP (operands[1], 1)));
        DONE;
      }
    if (CONST_INT_P (operand1)
        && ! rx_is_legitimate_constant (<register_modes:MODE>mode, operand1))
      FAIL;
  }
)

(define_insn "*mov<register_modes:mode>_internal"
  [(set (match_operand:register_modes
	 0 "nonimmediate_operand" "=r,r,r,r,r, r,r,r,r,r,Rreg,m, Q,Q,Q,Q,r,Q")
	(match_operand:register_modes
	 1 "general_operand" "Uint04,Int08,Sint16,Sint24,i,
	 r,Rreg,Rd05,Rd08,m,r,r, Int08,Sint16,Sint24,i,RpdaRpid,Q"))]
  ""
  { return rx_gen_move_template (operands, false); }
  [(set_attr "length" "2,3,4,5,6, 2,2,2,3,4,2,6, 5,6,7,8,8,2")
   (set_attr "timings" "11,11,11,11,11, 11,12,12,12,12,11,11,
			11,11,11,11,11,12")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,ILS,IEX,ILS,ILS,ILS,ILS,ILS,ILS,ISNG")]
)

;TODO: instead of define_insn what if we use define_expand and/or define_insn_and_split and split the 32 bit movs
; after reload_completed? this is especially useful for case 6 below
(define_insn "movdf"
  [(set (match_operand:DF 0 "nonimmediate_operand" "=DFPUreg,DFPUreg,Q,r,DFPUreg,DFPUreg,r")
  (match_operand:DF 1 "general_operand"            "DFPUreg,Q,DFPUreg,DFPUreg,r,DoubleC,r"))]
  "flag_dfpu"
  {
	switch(which_alternative)
	{
	case 0: return "dmov.D\t%1, %0";
	case 1: return "dmov.D\t%1, %0";
	case 2: return "dmov.D\t%1, %0";
	case 3:
	case 4:
			return "dmov.L\t%L1, %L0\n\tdmov.L\t%H1, %H0";
	case 5:
		{
			long t[2];
      REAL_VALUE_TO_TARGET_DOUBLE (*CONST_DOUBLE_REAL_VALUE (operands[1]), t);
			t[0] = WORDS_BIG_ENDIAN? t[1] : t[0];
			/* if the lower 32 bits are != 0 */
			if(t[0] != 0)
			{
				return "dmov.L\t%L1, %L0\n\tdmov.L\t%H1, %H0";
			}
			else
			{
				return "dmov.D\t%H1, %H0";
			}
		}
		/* TODO: remove this at some point */
	case 6: if(REGNO(operands[1]) > REGNO(operands[0]))
				return "mov.L\t%L1, %L0\n\tmov.L\t%H1, %H0";
			else
				return "mov.L\t%H1, %H0\n\tmov.L\t%L1, %L0";
	}
  }
  [(set_attr "length" "2,4,4,4,4,4,4")
   (set_attr "timings" "11,12,12,12,12,12,12")
   (set_attr "insn_group"  "ISNG,ISNG,ISNG,ISNG,ISNG,ISNG,ISNG")]
)

(define_insn "extend<small_int_modes:mode>si2"
  [(set (match_operand:SI 0 "register_operand"    "=r,r")
        (sign_extend:SI (match_operand:small_int_modes
			  1 "nonimmediate_operand" "r,m")))]
  ""
  { return rx_gen_move_template (operands, false); }
  [(set_attr "length" "2,6")
   (set_attr "timings" "11,12")
   (set_attr "insn_group"  "IEX,ILS")]
)

(define_insn "zero_extend<small_int_modes:mode>si2"
  [(set (match_operand:SI 0 "register_operand"     "=r,r")
        (zero_extend:SI (match_operand:small_int_modes
			  1 "nonimmediate_operand"  "r,m")))]
  ""
  { return rx_gen_move_template (operands, true); }
  [(set_attr "length" "2,4")
   (set_attr "timings" "11,12")
   (set_attr "insn_group"  "IEX,ILS")]
)

(define_insn "stack_push"
  [(set (reg:SI SP_REG)
	(minus:SI (reg:SI SP_REG)
		  (const_int 4)))
   (set (mem:SI (minus:SI (reg:SI SP_REG) (const_int 4)))
	(match_operand:SI 0 "register_operand" "r"))]
  ""
  "push.l\t%0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ILS")]
)

(define_insn "stack_pushm"
  [(match_parallel 1 "rx_store_multiple_vector"
     [(set (reg:SI SP_REG)
	   (minus:SI (reg:SI SP_REG)
		     (match_operand:SI 0 "const_int_operand" "n")))])]
  "reload_completed"
  {
	rx_emit_stack_pushm (operands);
    return "";
  }
  [(set_attr "length" "2")
   (set_attr "timings" "44") ;; The timing is a guesstimate average timing.
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "stack_dpushm"
[(set (reg:SI SP_REG)
	   (minus:SI (reg:SI SP_REG)
		     (const_int 4)))]
  ""
  "dpushm.l\tdcmr-dcmr"

  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "stack_pop"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(mem:SI (reg:SI SP_REG)))
   (set (reg:SI SP_REG)
	(plus:SI (reg:SI SP_REG)
		 (const_int 4)))]
  ""
  "pop\t%0"
  [(set_attr "length" "2")
   (set_attr "timings" "12")
   (set_attr "insn_group"  "ILS")]
)

(define_insn "stack_popm"
  [(match_parallel 1 "rx_load_multiple_vector"
     [(set (reg:SI SP_REG)
	   (plus:SI (reg:SI SP_REG)
		    (match_operand:SI 0 "const_int_operand" "n")))])]
  "reload_completed"
  {
    rx_emit_stack_popm (operands, true);
    return "";
  }
  [(set_attr "length" "2")
   (set_attr "timings" "45") ;; The timing is a guesstimate average timing.
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "stack_dpopm"
  [(set (reg:SI SP_REG)
	   (plus:SI (reg:SI SP_REG)
		    (const_int 4)))]
  ""
  "dpopm.l\tdcmr-dcmr"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn_and_split "cstoresi4_mem"
  [(set (match_operand:SI   0 "register_operand" "=r")
	(match_operator:SI  1 "comparison_operator"
	  [(match_operand:SI 2 "register_operand"  "r")
	   (match_operand:SI 3 "rx_restricted_mem_operand" "Q")]))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rtx flags, x;

  flags = gen_rtx_REG (CCmode, CC_REG);
  x = gen_rtx_COMPARE (CCmode, operands[2], operands[3]);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  x = gen_rtx_fmt_ee (GET_CODE (operands[1]), SImode, flags, const0_rtx);
  x = gen_rtx_SET (operands[0], x);
  emit_insn (x);
  DONE;
})

(define_insn_and_split "cstoresi4"
  [(set (match_operand:SI   0 "register_operand" "=r")
	(match_operator:SI  1 "comparison_operator"
	  [(match_operand:SI 2 "register_operand"  "r")
	   (match_operand:SI 3 "rx_speed_source_operand" "ri")]))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rtx flags, x;

  flags = gen_rtx_REG (CCmode, CC_REG);
  x = gen_rtx_COMPARE (CCmode, operands[2], operands[3]);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  x = gen_rtx_fmt_ee (GET_CODE (operands[1]), SImode, flags, const0_rtx);
  x = gen_rtx_SET (operands[0], x);
  emit_insn (x);
  DONE;
})

(define_insn "*sccc"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(match_operator:SI 1 "comparison_operator"
	  [(reg CC_REG) (const_int 0)]))]
  "reload_completed"
  "sc%B1.L\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn_and_split "cstoresf4_mem"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(match_operator:SI 1 "rx_fp_comparison_operator"
	 [(match_operand:SF 2 "register_operand" "r")
	  (match_operand:SF 3 "rx_restricted_mem_operand" "Q")]))]
  "ALLOW_RX_FPU_INSNS"
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rtx flags, x;

  flags = gen_rtx_REG (CC_Fmode, CC_REG);
  x = gen_rtx_COMPARE (CC_Fmode, operands[2], operands[3]);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  x = gen_rtx_fmt_ee (GET_CODE (operands[1]), SImode, flags, const0_rtx);
  x = gen_rtx_SET (operands[0], x);
  emit_insn (x);
  DONE;
})

(define_insn_and_split "cstoresf4"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(match_operator:SI 1 "rx_fp_comparison_operator"
	 [(match_operand:SF 2 "register_operand" "r")
	  (match_operand:SF 3 "rx_speed_source_operand" "rF")]))]
  "ALLOW_RX_FPU_INSNS"
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rtx flags, x;

  flags = gen_rtx_REG (CC_Fmode, CC_REG);
  x = gen_rtx_COMPARE (CC_Fmode, operands[2], operands[3]);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  x = gen_rtx_fmt_ee (GET_CODE (operands[1]), SImode, flags, const0_rtx);
  x = gen_rtx_SET (operands[0], x);
  emit_insn (x);
  DONE;
})

(define_expand "movsicc"
  [(parallel
    [(set (match_operand:SI                  0 "register_operand")
	  (if_then_else:SI (match_operand 1 "comparison_operator")
			   (match_operand:SI 2 "nonmemory_operand")
			   (match_operand:SI 3 "nonmemory_operand")))
     (clobber (reg:CC CC_REG))])]
  ""
{
  /* Make sure that we have an integer comparison...  */
  if (GET_MODE (XEXP (operands[1], 0)) != CCmode
      && GET_MODE (XEXP (operands[1], 0)) != SImode)
    FAIL;

  /* One operand must be a constant or a register, the other must be a register.  */
  if (   ! CONSTANT_P (operands[2])
      && ! CONSTANT_P (operands[3])
      && ! (REG_P (operands[2]) && REG_P (operands[3])))
    FAIL;
})

(define_insn_and_split "*movsicc_tst_mem"
  [(set (match_operand:SI     0 "register_operand" "=r")
       (if_then_else:SI
         (match_operator 5 "rx_z_comparison_operator"
          [(and:SI (match_operand:SI 3 "register_operand"  "r")
                   (match_operand:SI 4 "rx_restricted_mem_operand" "Q"))
           (const_int 0)])
         (match_operand:SI   1 "nonmemory_operand" "0")
         (match_operand:SI   2 "immediate_operand" "i")))
   (clobber (reg:CC CC_REG))]
  "CONSTANT_P (operands[1]) || CONSTANT_P (operands[2])"
  "#"
  "&& reload_completed"
  [(set (reg:CC_ZS CC_REG)
       (compare:CC_ZS
        (and:SI (match_dup 3)
                (match_dup 4))
        (const_int 0)))
   (set (match_dup 0)
       (if_then_else:SI
        (match_dup 6)
        (match_dup 1)
        (match_dup 2)))
   ]
  {
    rtx flags = gen_rtx_REG (CC_ZSmode, CC_REG);
    operands[6] = gen_rtx_fmt_ee (GET_CODE (operands[5]), CC_ZSmode, flags, const0_rtx);
  }
)

(define_insn_and_split "*movsicc_tst"
  [(set (match_operand:SI     0 "register_operand" "=r")
       (if_then_else:SI
         (match_operator 5 "rx_z_comparison_operator"
          [(and:SI (match_operand:SI 3 "register_operand"  "r")
                   (match_operand:SI 4 "rx_speed_source_operand" "ri"))
           (const_int 0)])
         (match_operand:SI   1 "nonmemory_operand" "0")
         (match_operand:SI   2 "immediate_operand" "i")))
   (clobber (reg:CC CC_REG))]
  "CONSTANT_P (operands[1]) || CONSTANT_P (operands[2])"
  "#"
  "&& reload_completed"
  [(set (reg:CC_ZS CC_REG)
       (compare:CC_ZS
        (and:SI (match_dup 3)
                (match_dup 4))
        (const_int 0)))
   (set (match_dup 0)
       (if_then_else:SI
        (match_dup 6)
        (match_dup 1)
        (match_dup 2)))
   ]
  {
    rtx flags = gen_rtx_REG (CC_ZSmode, CC_REG);
    operands[6] = gen_rtx_fmt_ee (GET_CODE (operands[5]), CC_ZSmode, flags, const0_rtx);
  }
)

(define_insn_and_split "*movsicc_tstz"
  [(set (match_operand:SI     0 "register_operand" "=r")
       (if_then_else:SI
         (match_operator 6 "rx_z_comparison_operator"
          [(zero_extract:SI (match_operand:SI 3 "register_operand"  "r")
                            (match_operand:SI 4 "rx_constshift_operand" "i")
                            (match_operand:SI 5 "rx_constshift_operand" "i"))
           (const_int 0)])
         (match_operand:SI   1 "nonmemory_operand" "0")
         (match_operand:SI   2 "immediate_operand" "i")))
   (clobber (reg:CC CC_REG))]
  "CONSTANT_P (operands[1]) || CONSTANT_P (operands[2])"
  "#"
  "&& reload_completed"
  [(set (reg:CC_ZS CC_REG)
       (compare:CC_ZS
        (and:SI (match_dup 3)
                (match_dup 7))
        (const_int 0)))
   (set (match_dup 0)
       (if_then_else:SI
        (match_dup 8)
        (match_dup 1)
        (match_dup 2)))
   ]
 {
    HOST_WIDE_INT mask;
    rtx flags = gen_rtx_REG (CC_ZSmode, CC_REG);

    mask = 1;
    mask <<= INTVAL (operands[4]);
    mask -= 1;
    mask <<= INTVAL (operands[5]);

    operands[7] = GEN_INT (mask);
    operands[8] = gen_rtx_fmt_ee (GET_CODE (operands[6]), CC_ZSmode, flags, const0_rtx);
  }
)

(define_insn_and_split "*movsicc_mem"
  [(set (match_operand:SI     0 "register_operand" "=r,r,r")
	(if_then_else:SI
	  (match_operator     5 "comparison_operator"
	   [(match_operand:SI 3 "register_operand"  "r,r,r")
	    (match_operand:SI 4 "rx_restricted_mem_operand" "Q,Q,Q")])
	  (match_operand:SI   1 "nonmemory_operand" "i,ri,r")
	  (match_operand:SI   2 "nonmemory_operand" "ri,i,r")))
   (clobber (reg:CC CC_REG))]
  "(CONSTANT_P (operands[1]) || CONSTANT_P (operands[2]))
    || (REG_P (operands[1]) && REG_P (operands[2]))"
  "#"
  "&& reload_completed"
  [(const_int 0)]
{
  rtx x, flags, op0, op1, op2;
  enum rtx_code cmp_code;

  flags = gen_rtx_REG (CCmode, CC_REG);
  x = gen_rtx_COMPARE (CCmode, operands[3], operands[4]);
  emit_insn (gen_rtx_SET (flags, x));

  cmp_code = GET_CODE (operands[5]);
  op0 = operands[0];
  op1 = operands[1];
  op2 = operands[2];

  /* If OP2 is the constant, reverse the sense of the move.
     Likewise if both operands are registers but OP1 == OP0.  */
  if ((! CONSTANT_P (operands[1]) && CONSTANT_P (operands[2]))
      || (REG_P (operands[1]) && REG_P (operands[2])
          && rtx_equal_p (op0, op1)))
    {
      x = op1, op1 = op2, op2 = x;
      cmp_code = reverse_condition (cmp_code);
    }

  /* If OP2 does not match the output, copy it into place.  We have allowed
     these alternatives so that the destination can legitimately be one of
     the comparison operands without increasing register pressure.  */
  if (! rtx_equal_p (op0, op2))
    emit_move_insn (op0, op2);

  x = gen_rtx_fmt_ee (cmp_code, VOIDmode, flags, const0_rtx);
  x = gen_rtx_IF_THEN_ELSE (SImode, x, op1, op0);
  emit_insn (gen_rtx_SET (op0, x));
  DONE;
})

(define_insn_and_split "*movsicc"
  [(set (match_operand:SI     0 "register_operand" "=r,r,r")
	(if_then_else:SI
	  (match_operator 5 "comparison_operator"
	   [(match_operand:SI 3 "register_operand"  "r,r,r")
	    (match_operand:SI 4 "rx_speed_source_operand" "ri,ri,ri")])
	  (match_operand:SI   1 "nonmemory_operand" "i,ri,r")
	  (match_operand:SI   2 "nonmemory_operand" "ri,i,r")))
   (clobber (reg:CC CC_REG))]
  "(CONSTANT_P (operands[1]) || CONSTANT_P (operands[2])) || (REG_P(operands[1]) && REG_P(operands[2]))"
  "#"
  "&& reload_completed"
  [(const_int 0)]
{
  rtx x, flags, op0, op1, op2;
  enum rtx_code cmp_code;

  flags = gen_rtx_REG (CCmode, CC_REG);
  x = gen_rtx_COMPARE (CCmode, operands[3], operands[4]);
  emit_insn (gen_rtx_SET (flags, x));

  cmp_code = GET_CODE (operands[5]);
  op0 = operands[0];
  op1 = operands[1];
  op2 = operands[2];

  /* If OP2 is the constant, reverse the sense of the move.  */
  if ((!CONSTANT_P (operands[1]) && CONSTANT_P (operands[2]))
      || (REG_P(operands[1]) && REG_P(operands[2])
	  && rtx_equal_p (op0, op1)))
     {
       x = op1, op1 = op2, op2 = x;
       cmp_code = reverse_condition (cmp_code);
    }

  /* If OP2 does not match the output, copy it into place.  We have allowed
     these alternatives so that the destination can legitimately be one of
     the comparison operands without increasing register pressure.  */
  if (! rtx_equal_p (op0, op2))
    emit_move_insn (op0, op2);

  x = gen_rtx_fmt_ee (cmp_code, VOIDmode, flags, const0_rtx);
  x = gen_rtx_IF_THEN_ELSE (SImode, x, op1, op0);
  emit_insn (gen_rtx_SET (op0, x));
  DONE;
})

;; TODO: didn't add this because it's selected
;; comparing with the imm cases where the flow is:
;;  cbranchsi4 -> cstoresi4 -> movsicc
;; for this case cbranchsi4 is not transformed to cstoresi4.
;; TODO: also *stcc_rev
;;(define_insn "*stcc"
;;  [(set (match_operand:SI 0 "register_operand" "+r,r,r,r,r")
;;	(if_then_else:SI
;;	  (match_operator 2 "rx_z_comparison_operator"
;;	    [(reg CC_REG) (const_int 0)])
;;	  (match_operand:SI 1 "nonmemory_operand" "Sint08,Sint16,Sint24,i,RXV2")
;;	  (match_dup 0)))]
;;  "reload_completed
;;   && ((GET_CODE (operands[2]) == EQ) || (GET_CODE (operands[2]) == NE))"
;;  {
;;    if (GET_CODE (operands[2]) == EQ)
;;      return "stz\t%1, %0";
;;    else
;;     return "stnz\t%1, %0";
;;  }
;;  [(set_attr "length" "4,5,6,7,3")
;;   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX")]
;;)

(define_insn "*stcc"
  [(set (match_operand:SI 0 "register_operand" "+r,r,r,r")
	(if_then_else:SI
	  (match_operator 2 "rx_z_comparison_operator"
	    [(reg CC_REG) (const_int 0)])
	  (match_operand:SI 1 "immediate_operand" "Sint08,Sint16,Sint24,i")
	  (match_dup 0)))]
  "reload_completed
   && ((GET_CODE (operands[2]) == EQ) || (GET_CODE (operands[2]) == NE))"
  {
    if (GET_CODE (operands[2]) == EQ)
      return "stz\t%1, %0";
    else
     return "stnz\t%1, %0";
  }
  [(set_attr "length" "4,5,6,7")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX")]
)

(define_insn "*stcc_reg"
  [(set (match_operand:SI 0 "register_operand" "+r,r,r,r,r,r")
	(if_then_else:SI
	  (match_operator 2 "comparison_operator"
	    [(reg CC_REG) (const_int 0)])
	  (match_operand:SI 1 "nonmemory_operand"
		              "r,Uint04,Sint08,Sint16,Sint24,i")
	  (match_dup 0)))]
  "reload_completed"
  {
    PUT_CODE (operands[2], reverse_condition (GET_CODE (operands[2])));
    return "b%B2 1f\n\tmov %1, %0\n1:";
  }
  [(set_attr "length" "3,3,4,5,6,7")
   (set_attr "insn_group"  "ISNG,ISNG,ISNG,ISNG,ISNG,ISNG")]
)

(define_insn "*stcc_rev"
  [(set (match_operand:SI 0 "register_operand" "+r,r,r,r")
	(if_then_else:SI
	  (match_operator 2 "rx_z_comparison_operator"
	   [(reg CC_REG) (const_int 0)])
	  (match_dup 0)
	  (match_operand:SI 1 "immediate_operand" "Sint08,Sint16,Sint24,i")))]
  "reload_completed"
{
  if (GET_CODE (operands[2]) == EQ)
    return "stnz\t%1, %0";
  else
    return "stz\t%1, %0";
}
  [(set_attr "length" "4,5,6,7")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX")]
)

;; Arithmetic Instructions

(define_insn "abssi2"
  [(set (match_operand:SI         0 "register_operand" "=r,r")
        (abs:SI (match_operand:SI 1 "register_operand"  "0,r")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  abs\t%0
  abs\t%1, %0"
  [(set_attr "length" "2,3")
   (set_attr "insn_group"  "IEP,IEP")]
)

(define_insn "absdf2"
  [(set (match_operand:DF         0 "register_operand" "=DFPUreg")
        (abs:DF (match_operand:DF 1 "register_operand"  "DFPUreg")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "dabs\t%1, %0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*abssi2_flags"
  [(set (reg CC_REG)
        (compare (abs:SI (match_operand:SI 1 "register_operand"  "0,r"))
		 (const_int 0)))
   (set (match_operand:SI		   0 "register_operand" "=r,r")
	(abs:SI (match_dup 1)))]
  ;; Note - although the ABS instruction does set the O bit in the processor
  ;; status word, it does not do so in a way that is comparable with the CMP
  ;; instruction.  Hence we use CC_ZSmode rather than CC_ZSOmode.
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  abs\t%0
  abs\t%1, %0"
  [(set_attr "length" "2,3")
   (set_attr "insn_group"  "IEP,IEP")]
)

(define_expand "addsi3"
  [(parallel [(set (match_operand:SI          0 "register_operand"  "")
	(plus:SI (match_operand:SI 1 "register_operand"  "")
		 (match_operand:SI 2 "rx_source_operand" "")))
    (clobber (reg:CC CC_REG))])]
  ""
  "
      operands[0] = rx_maybe_pidify_operand (operands[0], 1);
      operands[1] = rx_maybe_pidify_operand (operands[1], 1);
      operands[2] = rx_maybe_pidify_operand (operands[2], 1);
  "
)

(define_insn "addsi3_mem"
  [(set (match_operand:SI          0 "register_operand"  "=r")
	(plus:SI (match_operand:SI 1 "register_operand"  "%0")
		 (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  ""
  "add\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"   "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "addsi3_internal"
  [(set (match_operand:SI          0 "register_operand"  "=r,r,r,r,r,r,r,r,r,r,r,r,r")
	(plus:SI (match_operand:SI 1 "register_operand"  "%0,0,0,0,0,0,0,r,r,r,r,r,r")
		 (match_operand:SI 2 "rx_speed_source_operand" "rQ,Uint04,NEGint4,Sint08,Sint16,Sint24,i,0,r,Sint08,Sint16,Sint24,i")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  add\t%2, %0
  add\t%2, %0
  sub\t%N2, %0
  add\t%2, %0
  add\t%2, %0
  add\t%2, %0
  add\t%2, %0
  add\t%1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0"
  [(set_attr "timings" "11,11,11,11,11,11,11,11,11,11,11,11,11")
   (set_attr "length"   "2,2,2,3,4,5,6,2,3,3,4,5,6")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX")]
)

(define_insn "*addsi3_flags_mem"
  [(set (match_operand:SI          0 "register_operand"  "=r")
	(plus:SI (match_operand:SI 1 "register_operand"  "%0")
		 (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (set (reg CC_REG)
	(compare (plus:SI (match_dup 1) (match_dup 2))
		 (const_int 0)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSCmode)"
  "add\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"   "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*addsi3_flags"
  [(set (reg CC_REG)
	(compare (plus:SI (match_operand:SI 1 "register_operand"  "%0,0,0,0,0,0,0,r,r,r,r,r,r")
			  (match_operand:SI 2 "rx_speed_source_operand" "r,Uint04,NEGint4,Sint08,Sint16,Sint24,i,0,r,Sint08,Sint16,Sint24,i"))
		 (const_int 0)))
   (set (match_operand:SI		    0 "register_operand"  "=r,r,r,r,r,r,r,r,r,r,r,r,r")
	(plus:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSCmode)"
  "@
  add\t%2, %0
  add\t%2, %0
  sub\t%N2, %0
  add\t%2, %0
  add\t%2, %0
  add\t%2, %0
  add\t%2, %0
  add\t%1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0
  add\t%2, %1, %0"
  [(set_attr "timings" "11,11,11,11,11,11,11,11,11,11,11,11,11")
   (set_attr "length"   "2,2,2,3,4,5,6,2,3,3,4,5,6")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX")]
)

;; A helper to expand the above with the CC_MODE filled in.
(define_expand "addsi3_flags"
  [(parallel [(set (reg:CC_ZSC CC_REG)
		   (compare:CC_ZSC
		     (plus:SI (match_operand:SI 1 "register_operand")
			      (match_operand:SI 2 "rx_speed_source_operand"))
		     (const_int 0)))
	      (set (match_operand:SI 0 "register_operand")
		   (plus:SI (match_dup 1) (match_dup 2)))])]
)

(define_insn "adc_internal_mem"
  [(set (match_operand:SI     0 "register_operand"  "=r")
	(plus:SI
	  (plus:SI
	    (ltu:SI (reg:CC CC_REG) (const_int 0))
	    (match_operand:SI 1 "register_operand"  "%0"))
	  (match_operand:SI   2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "reload_completed"
  "adc %2,%0"
  [(set_attr "timings" "33")
   (set_attr "length"   "6")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "adc_internal"
  [(set (match_operand:SI     0 "register_operand"  "=r,r,r,r,r")
	(plus:SI
	  (plus:SI
	    (ltu:SI (reg:CC CC_REG) (const_int 0))
	    (match_operand:SI 1 "register_operand"  "%0,0,0,0,0"))
	  (match_operand:SI   2 "rx_speed_source_operand" "r,Sint08,Sint16,Sint24,i")))
    (clobber (reg:CC CC_REG))]
  "reload_completed"
  "adc\t%2, %0"
  [(set_attr "timings" "11,11,11,11,11")
   (set_attr "length"   "3,4,5,6,7")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX")]
)

(define_insn "*adc_flags_mem"
  [(set (match_operand:SI     0 "register_operand"  "=r")
	(plus:SI
	  (plus:SI
	    (ltu:SI (reg:CC CC_REG) (const_int 0))
	    (match_operand:SI 1 "register_operand"  "%0"))
	  (match_operand:SI   2 "rx_restricted_mem_operand" "Q")))
   (set (reg CC_REG)
	(compare
	  (plus:SI
	    (plus:SI
	      (ltu:SI (reg:CC CC_REG) (const_int 0))
	      (match_dup 1))
	    (match_dup 2))
	  (const_int 0)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSCmode)"
  "adc %2,%0"
  [(set_attr "timings" "33")
   (set_attr "length"   "6")
   (set_attr "insn_group"  "ISNG")]
 )

(define_insn "*adc_flags"
  [(set (reg CC_REG)
	(compare
	  (plus:SI
	    (plus:SI
	      (ltu:SI (reg:CC CC_REG) (const_int 0))
	      (match_operand:SI 1 "register_operand"  "%0,0,0,0,0"))
	    (match_operand:SI   2 "rx_source_operand" "r,Sint08,Sint16,Sint24,i"))
	  (const_int 0)))
   (set (match_operand:SI	0 "register_operand"  "=r,r,r,r,r")
	(plus:SI
	  (plus:SI
	    (ltu:SI (reg:CC CC_REG) (const_int 0))
	    (match_dup 1))
	  (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSCmode)"
  "adc\t%2, %0"
  [(set_attr "timings" "11,11,11,11,11")
   (set_attr "length"   "3,4,5,6,7")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX")]
)

;; Peepholes to match:
;;   (set (reg A) (reg B))
;;   (set (CC) (compare:CC (reg A/reg B) (const_int 0)))
;; and replace them with the addsi3_flags pattern, using an add
;; of zero to copy the register and set the condition code bits.
(define_peephole2
  [(set (match_operand:SI 0 "register_operand")
        (match_operand:SI 1 "register_operand"))
   (set (reg:CC CC_REG)
        (compare:CC (match_dup 0)
                    (const_int 0)))]
  ""
  [(parallel [(set (reg:CC_ZSC CC_REG)
		   (compare:CC_ZSC (plus:SI (match_dup 1) (const_int 0))
				   (const_int 0)))
	      (set (match_dup 0)
		   (plus:SI (match_dup 1) (const_int 0))) ])]
)

(define_peephole2
  [(set (match_operand:SI 0 "register_operand")
        (match_operand:SI 1 "register_operand"))
   (set (reg:CC CC_REG)
        (compare:CC (match_dup 1)
                    (const_int 0)))]
  ""
  [(parallel [(set (reg:CC_ZSC CC_REG)
		   (compare:CC_ZSC (plus:SI (match_dup 1) (const_int 0))
				   (const_int 0)))
	      (set (match_dup 0)
		   (plus:SI (match_dup 1) (const_int 0)))])]
)

(define_expand "adddi3"
  [(set (match_operand:DI          0 "register_operand")
	(plus:DI (match_operand:DI 1 "register_operand")
           (match_operand:DI 2 "nonmemory_operand")))]
  ""
{
  rtx op0l, op0h, op1l, op1h, op2l, op2h;

  op0l = gen_lowpart (SImode, operands[0]);
  op1l = gen_lowpart (SImode, operands[1]);
  op2l = gen_lowpart (SImode, operands[2]);
  op0h = gen_highpart (SImode, operands[0]);
  op1h = gen_highpart (SImode, operands[1]);
  op2h = gen_highpart_mode (SImode, DImode, operands[2]);

  emit_insn (gen_adddi3_internal (op0l, op0h, op1l, op2l, op1h, op2h));
  DONE;
})

(define_insn_and_split "adddi3_internal"
  [(set (match_operand:SI          0 "register_operand"  "=&r")
	(plus:SI (match_operand:SI 2 "register_operand"  "r")
		 (match_operand:SI 3 "rx_source_operand" "riQ")))
   (set (match_operand:SI          1 "register_operand"  "=r")
	(plus:SI
	  (plus:SI
	    (ltu:SI (plus:SI (match_dup 2) (match_dup 3)) (match_dup 2))
	    (match_operand:SI      4 "register_operand"  "%1"))
	  (match_operand:SI        5 "rx_source_operand" "riQ")))
   (clobber (match_scratch:SI      6                     "=&r"))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  rtx op0l = operands[0];
  rtx op0h = operands[1];
  rtx op1l = operands[2];
  rtx op2l = operands[3];
  rtx op1h = operands[4];
  rtx op2h = operands[5];
  rtx scratch = operands[6];
  rtx x;

  if (reg_overlap_mentioned_p (op0l, op1h))
    {
      emit_move_insn (scratch, op0l);
      op1h = scratch;
      if (reg_overlap_mentioned_p (op0l, op2h))
	op2h = scratch;
    }
  else if (reg_overlap_mentioned_p (op0l, op2h))
    {
      emit_move_insn (scratch, op0l);
      op2h = scratch;
    }

  if (rtx_equal_p (op0l, op1l))
    ;
  /* It is preferable that op0l == op1l...  */
  else if (rtx_equal_p (op0l, op2l))
    x = op1l, op1l = op2l, op2l = x;
  /* ... but it is only a requirement if op2l == MEM.  */
  else if (MEM_P (op2l))
    {
      /* Let's hope that we still have a scratch register free.  */
      gcc_assert (op1h != scratch);
      emit_move_insn (scratch, op2l);
      op2l = scratch;
    }

  emit_insn (gen_addsi3_flags (op0l, op1l, op2l));

  if (rtx_equal_p (op0h, op1h))
    ;
  else if (rtx_equal_p (op0h, op2h))
    x = op1h, op1h = op2h, op2h = x;
  else
    {
      emit_move_insn (op0h, op1h);
      op1h = op0h;
    }
  emit_insn (gen_adc_internal (op0h, op1h, op2h));
  DONE;
})

(define_insn "andsi3_mem"
  [(set (match_operand:SI         0 "register_operand"  "=r")
	(and:SI (match_operand:SI 1 "register_operand"  "%0")
		(match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  ""
  "and\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn_and_split "andsi3"
  [(set (match_operand:SI         0 "register_operand"  "=r,r,r,r,r,r,r,r")
	(and:SI (match_operand:SI 1 "register_operand"  "%0,0,0,0,0,0,r,r")
		(match_operand:SI 2 "rx_speed_source_operand" "rQ,Uint04,Sint08,Sint16,Sint24,i,0,r")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%1, %0
  and\t%2, %1, %0"
  "&& RX_REG_P (operands[1]) && CONST_INT_P (operands[2])
   && pow2p_hwi (~UINTVAL (operands[2]))"
 [(const_int 0)]
{
  /* For negated single bit constants use the bclr insn for smaller code.  */

  if (!rx_reg_dead_or_unused_after_insn (curr_insn, CC_REG))
    FAIL;

  rx_copy_reg_dead_or_unused_notes (operands[1], curr_insn,
    emit_insn (gen_bclr (operands[0],
			   GEN_INT (exact_log2 (~UINTVAL (operands[2]))),
			   operands[1])));
  DONE;
}
  [(set_attr "timings" "11,11,11,11,11,11,11,11")
   (set_attr "length" "2,2,3,4,5,6,2,5")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX")]
)

(define_insn "*andsi3_flags_mem"
  [(set (match_operand:SI         0 "register_operand"  "=r")
	(and:SI (match_operand:SI 1 "register_operand"  "%0")
		(match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (set (reg CC_REG)
	(compare (and:SI (match_dup 1) (match_dup 2))
		 (const_int 0)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "and\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*andsi3_flags"
  [(set (reg CC_REG)
	(compare (and:SI (match_operand:SI 1 "register_operand"  "%0,0,0,0,0,0,r,r")
			 (match_operand:SI 2 "rx_source_operand" "r,Uint04,Sint08,Sint16,Sint24,i,0,r"))
		 (const_int 0)))
   (set (match_operand:SI		   0 "register_operand"  "=r,r,r,r,r,r,r,r")
	(and:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%2, %0
  and\t%1, %0
  and\t%2, %1, %0"
  [(set_attr "timings" "11,11,11,11,11,11,11,11")
   (set_attr "length" "2,2,3,4,5,6,2,5")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX")]
)

;; Byte swap (single 32-bit value).
(define_insn "bswapsi2"
  [(set (match_operand:SI           0 "register_operand" "=r")
	(bswap:SI (match_operand:SI 1 "register_operand"  "r")))]
  ""
  "revl\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

;; Byte swap (single 16-bit value).  Note - we ignore the swapping of the high 16-bits.
(define_insn "bswaphi2"
  [(set (match_operand:HI           0 "register_operand" "=r")
	(bswap:HI (match_operand:HI 1 "register_operand"  "r")))]
  ""
  "revw\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

(define_insn "divsi3_mem"
  [(set (match_operand:SI         0 "register_operand" "=r")
	(div:SI (match_operand:SI 1 "register_operand"  "0")
		(match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "(optimize_size || reload_completed)"
  "div\t%Q2, %0"
  [(set_attr "timings" "1111") ;; Strictly speaking the timing should be
                               ;; 2222, but that is a worst case sceanario.
   (set_attr "length" "6")
   (set_attr "insn_group"  "ISNG")]
)
(define_insn "divsi3"
  [(set (match_operand:SI         0 "register_operand" "=r,r,r,r,r")
	(div:SI (match_operand:SI 1 "register_operand"  "0,0,0,0,0")
		(match_operand:SI 2 "rx_speed_source_operand" "r,Sint08,Sint16,Sint24,i")))
   (clobber (reg:CC CC_REG))]
  ""
  "div\t%Q2, %0"
  [(set_attr "timings" "1111") ;; Strictly speaking the timing should be
                               ;; 2222, but that is a worst case sceanario.
   (set_attr "length" "3,4,5,6,7")
   (set_attr "insn_group"  "ISNG,ISNG,ISNG,ISNG,ISNG")]
)

(define_insn "udivsi3_mem"
  [(set (match_operand:SI          0 "register_operand"  "=r")
	(udiv:SI (match_operand:SI 1 "register_operand"   "0")
		 (match_operand:SI 2 "rx_restricted_mem_operand"  "Q")))
   (clobber (reg:CC CC_REG))]
  "(optimize_size || reload_completed)"
  "divu\t%Q2, %0"
  [(set_attr "timings" "1010") ;; Strictly speaking the timing should be
                               ;; 2020, but that is a worst case sceanario.
   (set_attr "length" "6")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "udivsi3"
  [(set (match_operand:SI          0 "register_operand"  "=r,r,r,r,r")
	(udiv:SI (match_operand:SI 1 "register_operand"   "0,0,0,0,0")
		 (match_operand:SI 2 "rx_speed_source_operand"  "r,Sint08,Sint16,Sint24,i")))
   (clobber (reg:CC CC_REG))]
  ""
  "divu\t%Q2, %0"
  [(set_attr "timings" "1010") ;; Strictly speaking the timing should be
                               ;; 2020, but that is a worst case sceanario.
   (set_attr "length" "3,4,5,6,7")
   (set_attr "insn_group"  "ISNG,ISNG,ISNG,ISNG,ISNG")]
)

;; Note - these patterns are suppressed in big-endian mode because they
;; generate a little endian result.  ie the most significant word of the
;; result is placed in the higher numbered register of the destination
;; register pair.

(define_insn "mulsidi3_mem"
  [(set (match_operand:DI          0 "register_operand"  "=r")
	(mult:DI (sign_extend:DI (match_operand:SI
				  1 "register_operand"  "%0"))
		 (sign_extend:DI (match_operand:SI
				  2 "rx_restricted_mem_operand" "Q"))))]
  "(optimize_size || reload_completed) && ! TARGET_BIG_ENDIAN_DATA"
  "emul\t%Q2, %0"
  [(set_attr "length" "6")
   (set_attr "timings" "44")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "mulsidi3"
  [(set (match_operand:DI          0 "register_operand"  "=r,r,r,r,r")
        (mult:DI (sign_extend:DI (match_operand:SI
				  1 "register_operand"  "%0,0,0,0,0"))
                 (sign_extend:DI (match_operand:SI
				  2 "rx_speed_source_operand"
				  "r,Sint08,Sint16,Sint24,i"))))]
  "! TARGET_BIG_ENDIAN_DATA"
  "emul\t%Q2, %0"
  [(set_attr "length" "3,4,5,6,7")
   (set_attr "timings" "22,22,22,22,22")
   (set_attr "insn_group"  "ISNG,ISNG,ISNG,ISNG,ISNG")]
)

;; See comment for mulsidi3.
;; Note - the zero_extends are to distinguish this pattern from the
;; mulsidi3 pattern.  Immediate mode addressing is not supported
;; because gcc cannot handle the expression: (zero_extend (const_int)).
(define_insn "umulsidi3_mem"
  [(set (match_operand:DI                          0 "register_operand"         "=r")
	(mult:DI (zero_extend:DI (match_operand:SI 1 "register_operand"  "%0"))
		 (zero_extend:DI (match_operand:SI 2 "rx_restricted_mem_operand" "Q"))))]
  "(optimize_size || reload_completed) && ! TARGET_BIG_ENDIAN_DATA"
  "emulu\t%Q2, %0"
  [(set_attr "length" "6")
   (set_attr "timings" "44")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "umulsidi3"
  [(set (match_operand:DI                          0 "register_operand"	 "=r")
        (mult:DI (zero_extend:DI (match_operand:SI 1 "register_operand"  "%0"))
                 (zero_extend:DI (match_operand:SI 2 "rx_speed_compare_operand" "r"))))]
  "! TARGET_BIG_ENDIAN_DATA"
  "emulu\t%Q2, %0"
  [(set_attr "length" "3")
   (set_attr "timings" "22")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "smaxsi3_mem"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(smax:SI (match_operand:SI 1 "register_operand" "%0")
		 (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))]
  "(optimize_size || reload_completed)"
  "max\t%Q2, %0"
  [(set_attr "length" "6")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "smaxsi3"
  [(set (match_operand:SI          0 "register_operand" "=r,r,r,r,r")
	(smax:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0")
		 (match_operand:SI 2 "rx_speed_source_operand"
				   "r,Sint08,Sint16,Sint24,i")))]
  ""
  "max\t%Q2, %0"
  [(set_attr "length" "3,4,5,6,7")
   (set_attr "timings" "11,11,11,11,11")
   (set_attr "insn_group"  "IEP,IEP,IEP,IEP,IEP")]
)

(define_insn "sminsi3_mem"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(smin:SI (match_operand:SI 1 "register_operand" "%0")
		 (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))]
  "(optimize_size || reload_completed)"
  "min\t%Q2, %0"
  [(set_attr "length"  "6")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "sminsi3"
  [(set (match_operand:SI          0 "register_operand" "=r,r,r,r,r")
	(smin:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0")
		 (match_operand:SI 2 "rx_speed_source_operand"
				   "r,Sint08,Sint16,Sint24,i")))]
  ""
  "min\t%Q2, %0"
  [(set_attr "length"  "3,4,5,6,7")
   (set_attr "timings" "11,11,11,11,11")
   (set_attr "insn_group"  "IEP,IEP,IEP,IEP,IEP")]
)


; Need to search for this patch
(define_insn "unsign_maxqi3_mem"
  [(set (match_operand:QI          0 "register_operand" "=r")
	(umax:QI (match_operand:QI 1 "register_operand" "%0")
		 (match_operand:QI 2 "rx_restricted_mem_operand" "Q")))]
  ""
  "movu.B\t%0, %0\n\tmax\t%R2, %0"
  [(set_attr "length" "8")
   (set_attr "timings" "44")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "unsign_maxhi3_mem"
  [(set (match_operand:HI          0 "register_operand" "=r")
        (umax:HI (match_operand:HI 1 "register_operand" "%0")
                 (match_operand:HI 2 "rx_restricted_mem_operand" "Q")))]
  ""
  "movu.W\t%0, %0\n\tmax\t%R2, %0"
  [(set_attr "length" "8")
   (set_attr "timings" "44")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "unsign_minhi3_mem"
  [(set (match_operand:HI          0 "register_operand" "=r")
        (umin:HI (match_operand:HI 1 "register_operand" "%0")
                 (match_operand:HI 2 "rx_restricted_mem_operand" "Q")))]
  ""
  "movu.W\t%0, %0\n\tmin\t%R2, %0"
  [(set_attr "length" "8")
   (set_attr "timings" "44")
   (set_attr "insn_group"  "ISNG")]
)


(define_insn "unsign_minqi3_mem"
  [(set (match_operand:QI          0 "register_operand" "=r")
	(umin:QI (match_operand:QI 1 "register_operand" "%0")
		 (match_operand:QI 2 "rx_restricted_mem_operand" "Q")))]
  ""
  "movu.B\t%0, %0\n\tmin\t%R2, %0"
  [(set_attr "length" "8")
   (set_attr "timings" "44")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "mulsi3_mem"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(mult:SI (match_operand:SI 1 "register_operand" "%0")
		 (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))]
  "(optimize_size || reload_completed)"
  "mul\t%Q2, %0"
  [(set_attr "length"  "5")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "mulsi3"
  [(set (match_operand:SI          0 "register_operand" "=r,r,r,r,r,r,r,r")
	(mult:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0,0,r,r")
		 (match_operand:SI 2 "rx_speed_source_operand"
				   "r,Uint04,Sint08,Sint16,Sint24,i,0,r")))]
  ""
  "@
  mul\t%2, %0
  mul\t%2, %0
  mul\t%2, %0
  mul\t%2, %0
  mul\t%2, %0
  mul\t%Q2, %0
  mul\t%1, %0
  mul\t%2, %1, %0"
  [(set_attr "length"  "2,2,3,4,5,6,2,3")
   (set_attr "timings" "11,11,11,11,11,11,11,11")
   (set_attr "insn_group"  "IML,IML,IML,IML,IML,IML,IML,IML")]
)

(define_insn "negsi2"
  [(set (match_operand:SI         0 "register_operand" "=r,r")
        (neg:SI (match_operand:SI 1 "register_operand"  "0,r")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  neg\t%0
  neg\t%1, %0"
  [(set_attr "length" "2,3")
   (set_attr "insn_group"  "IEX,IEX")]
)

(define_insn "negdf2"
  [(set (match_operand:DF         0 "register_operand" "=DFPUreg")
        (neg:DF (match_operand:DF 1 "register_operand"  "DFPUreg")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "dneg\t%1, %0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "negsf2"
  [(set (match_operand:SF         0 "register_operand" "=r")
        (neg:SF (match_operand:SF 1 "register_operand"  "r")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "add\t#-2147483648, %1"
  [(set_attr "length" "6")
   (set_attr "insn_group"  "IEX")]
)

;; Note that the O and C flags are not set as per a normal compare,
;; and thus are unusable in that context.
(define_insn "*negsi2_flags"
  [(set (reg CC_REG)
        (compare (neg:SI (match_operand:SI 1 "register_operand"  "0,r"))
		 (const_int 0)))
   (set (match_operand:SI		   0 "register_operand" "=r,r")
	(neg:SI (match_dup 1)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  neg\t%0
  neg\t%1, %0"
  [(set_attr "length" "2,3")
   (set_attr "insn_group"  "IEX,IEX")]
)

(define_insn "one_cmplsi2"
  [(set (match_operand:SI         0 "register_operand" "=r,r")
	(not:SI (match_operand:SI 1 "register_operand"  "0,r")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  not\t%0
  not\t%1, %0"
  [(set_attr "length" "2,3")
   (set_attr "insn_group"  "IEX,IEX")]
)

(define_insn "*one_cmplsi2_flags"
  [(set (reg CC_REG)
	(compare (not:SI (match_operand:SI 1 "register_operand"  "0,r"))
		 (const_int 0)))
   (set (match_operand:SI		   0 "register_operand" "=r,r")
	(not:SI (match_dup 1)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  not\t%0
  not\t%1, %0"
  [(set_attr "length" "2,3")
   (set_attr "insn_group"  "IEX,IEX")]
)

(define_insn "iorsi3_mem"
  [(set (match_operand:SI         0 "register_operand" "=r")
	(ior:SI (match_operand:SI 1 "register_operand" "%0")
	        (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  ""
  "
   or\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn_and_split "iorsi3"
  [(set (match_operand:SI         0 "register_operand" "=r,r,r,r,r,r,r,r")
	(ior:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0,0,r,r")
	        (match_operand:SI 2 "rx_speed_source_operand" "r,Uint04,Sint08,Sint16,Sint24,i,0,r")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  or\t%2, %0
  or\t%2, %0
  or\t%2, %0
  or\t%2, %0
  or\t%2, %0
  or\t%Q2, %0
  or\t%1, %0
  or\t%2, %1, %0"
  "&& RX_REG_P (operands[1]) && CONST_INT_P (operands[2])
   && pow2p_hwi (UINTVAL (operands[2]))"
  [(const_int 0)]
{
  /* For single bit constants use the bset insn for smaller code.  */

  if (!rx_reg_dead_or_unused_after_insn (curr_insn, CC_REG))
    FAIL;

  rx_copy_reg_dead_or_unused_notes (operands[1], curr_insn,
    emit_insn (gen_bitset (operands[0],
			   GEN_INT (exact_log2 (UINTVAL (operands[2]))),
			   operands[1])));
  DONE;
}
  [(set_attr "timings" "11,11,11,11,11,11,11,11")
   (set_attr "length"  "2,2,3,4,5,6,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX")]
)

(define_insn "*iorsi3_flags_mem"
  [(set (match_operand:SI         0 "register_operand" "=r")
	(ior:SI (match_operand:SI 1 "register_operand" "%0")
	        (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (set (reg CC_REG)
	(compare (ior:SI (match_dup 1) (match_dup 2))
		 (const_int 0)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "
  or\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*iorsi3_flags"
  [(set (match_operand:SI         0 "register_operand" "=r,r,r,r,r,r,r,r")
	(ior:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0,0,r,r")
	        (match_operand:SI 2 "rx_speed_source_operand" "r,Uint04,Sint08,Sint16,Sint24,i,0,r")))
   (set (reg CC_REG)
	(compare (ior:SI (match_dup 1) (match_dup 2))
		 (const_int 0)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  or\t%2, %0
  or\t%2, %0
  or\t%2, %0
  or\t%2, %0
  or\t%2, %0
  or\t%Q2, %0
  or\t%1, %0
  or\t%2, %1, %0"
  [(set_attr "timings" "11,11,11,11,11,11,11,11")
   (set_attr "length"  "2,2,3,4,5,6,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,IEX,IEX,IEX,IEX")]
)

(define_insn "rotlsi3"
  [(set (match_operand:SI            0 "register_operand" "=r")
	(rotate:SI (match_operand:SI 1 "register_operand"  "0")
		   (match_operand:SI 2 "rx_shift_operand" "rn")))
   (clobber (reg:CC CC_REG))]
  ""
  "rotl\t%2, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

(define_insn "*rotlsi3_flags"
  [(set (reg CC_REG)
	(compare (rotate:SI (match_operand:SI 1 "register_operand"  "0")
			    (match_operand:SI 2 "rx_shift_operand" "rn"))
		 (const_int 0)))
   (set (match_operand:SI		      0 "register_operand" "=r")
	(rotate:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "rotl\t%2, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

(define_insn "rotrsi3"
  [(set (match_operand:SI              0 "register_operand" "=r")
	(rotatert:SI (match_operand:SI 1 "register_operand"  "0")
		     (match_operand:SI 2 "rx_shift_operand" "rn")))
   (clobber (reg:CC CC_REG))]
  ""
  "rotr\t%2, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

(define_insn "*rotrsi3_flags"
  [(set (reg CC_REG)
	(compare (rotatert:SI (match_operand:SI 1 "register_operand"  "0")
			      (match_operand:SI 2 "rx_shift_operand" "rn"))
		 (const_int 0)))
   (set (match_operand:SI			0 "register_operand" "=r")
	(rotatert:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "rotr\t%2, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

(define_insn "ashrsi3"
  [(set (match_operand:SI              0 "register_operand" "=r,r,r")
	(ashiftrt:SI (match_operand:SI 1 "register_operand"  "0,0,r")
		     (match_operand:SI 2 "rx_shift_operand"  "r,n,n")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  shar\t%2, %0
  shar\t%2, %0
  shar\t%2, %1, %0"
  [(set_attr "length" "3,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX")]
)

(define_insn "*ashrsi3_flags"
  [(set (reg CC_REG)
	(compare (ashiftrt:SI (match_operand:SI 1 "register_operand"  "0,0,r")
			      (match_operand:SI 2 "rx_shift_operand"  "r,n,n"))
		 (const_int 0)))
   (set (match_operand:SI              0 "register_operand" "=r,r,r")
	(ashiftrt:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  shar\t%2, %0
  shar\t%2, %0
  shar\t%2, %1, %0"
  [(set_attr "length" "3,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX")]
)

(define_insn "lshrsi3"
  [(set (match_operand:SI              0 "register_operand" "=r,r,r")
	(lshiftrt:SI (match_operand:SI 1 "register_operand"  "0,0,r")
		     (match_operand:SI 2 "rx_shift_operand"  "r,n,n")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  shlr\t%2, %0
  shlr\t%2, %0
  shlr\t%2, %1, %0"
  [(set_attr "length" "3,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX")]
)

(define_insn "*lshrsi3_flags"
  [(set (reg CC_REG)
	(compare (lshiftrt:SI (match_operand:SI 1 "register_operand"  "0,0,r")
			      (match_operand:SI 2 "rx_shift_operand"  "r,n,n"))
		 (const_int 0)))
   (set (match_operand:SI			0 "register_operand" "=r,r,r")
	(lshiftrt:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  shlr\t%2, %0
  shlr\t%2, %0
  shlr\t%2, %1, %0"
  [(set_attr "length" "3,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX")]
)

(define_insn "ashlsi3"
  [(set (match_operand:SI            0 "register_operand" "=r,r,r")
	(ashift:SI (match_operand:SI 1 "register_operand"  "0,0,r")
	           (match_operand:SI 2 "rx_shift_operand"  "r,n,n")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  shll\t%2, %0
  shll\t%2, %0
  shll\t%2, %1, %0"
  [(set_attr "length" "3,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX")]
)

(define_insn "*ashlsi3_flags"
  [(set (reg CC_REG)
	(compare (ashift:SI (match_operand:SI 1 "register_operand"  "0,0,r")
			    (match_operand:SI 2 "rx_shift_operand"  "r,n,n"))
		 (const_int 0)))
   (set (match_operand:SI		      0 "register_operand" "=r,r,r")
	(ashift:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "@
  shll\t%2, %0
  shll\t%2, %0
  shll\t%2, %1, %0"
  [(set_attr "length" "3,2,3")
   (set_attr "insn_group"  "IEX,IEX,IEX")]
)

;; Saturate to 32-bits
(define_insn_and_split "ssaddsi3_mem"
  [(set (match_operand:SI             0 "register_operand" "=r")
	(ss_plus:SI (match_operand:SI 1 "register_operand"  "r")
		    (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(parallel [(set (match_dup 0)
		   (plus:SI (match_dup 1) (match_dup 2)))
	      (set (reg:CC_ZSC CC_REG)
		   (compare:CC_ZSC
		     (plus:SI (match_dup 1) (match_dup 2))
		     (const_int 0)))])
   (set (match_dup 0)
	(unspec:SI [(match_dup 0) (reg:CC CC_REG)]
		   UNSPEC_BUILTIN_SAT))]
   ""
)

(define_insn_and_split "ssaddsi3"
  [(set (match_operand:SI             0 "register_operand" "=r")
	(ss_plus:SI (match_operand:SI 1 "register_operand"  "r")
		    (match_operand:SI 2 "rx_speed_source_operand" "ri")))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(parallel [(set (reg:CC_ZSC CC_REG)
		   (compare:CC_ZSC
		     (plus:SI (match_dup 1) (match_dup 2))
		     (const_int 0)))
	      (set (match_dup 0)
		   (plus:SI (match_dup 1) (match_dup 2)))])
   (set (match_dup 0)
	(unspec:SI [(match_dup 0) (reg:CC CC_REG)]
		   UNSPEC_BUILTIN_SAT))]
   ""
)

(define_insn "*sat"
  [(set (match_operand:SI             0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"  "0")
		    (reg:CC CC_REG)]
		   UNSPEC_BUILTIN_SAT))]
  "reload_completed"
  "sat\t%0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "IEP")]
)

(define_insn "subsi3_mem"
  [(set (match_operand:SI           0 "register_operand" "=r")
	(minus:SI (match_operand:SI 1 "register_operand"  "0")
		  (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "(optimize_size || reload_completed)"
  "
  sub\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "subsi3"
  [(set (match_operand:SI           0 "register_operand" "=r,r,r,r")
	(minus:SI (match_operand:SI 1 "register_operand"  "0,0,0,r")
		  (match_operand:SI 2 "rx_speed_source_operand" "r,Uint04,n,r")))
   (clobber (reg:CC CC_REG))]
  ""
  "@
  sub\t%2, %0
  sub\t%2, %0
  add\t%N2, %0
  sub\t%2, %1, %0"
  [(set_attr "timings" "11,11,11,11")
   (set_attr "length" "2,2,6,3")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX")]
)

;; Note that the O flag is set as if (compare op1 op2) not for
;; what is described here, (compare op0 0).
(define_insn "*subsi3_flags_mem"
  [(set (match_operand:SI           0 "register_operand" "=r")
	(minus:SI (match_operand:SI 1 "register_operand"  "0")
		  (match_operand:SI 2 "rx_restricted_mem_operand" "m")))
   (set (reg CC_REG)
	(compare (minus:SI (match_dup 1) (match_dup 2))
		 (const_int 0)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSCmode)"
  "
  sub\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*subsi3_flags"
  [(set (reg CC_REG)
	(compare (minus:SI (match_operand:SI 1 "register_operand"  "0,0,0,r,0")
			   (match_operand:SI 2 "rx_source_operand" "r,Uint04,n,r,Q"))
		 (const_int 0)))
   (set (match_operand:SI		     0 "register_operand" "=r,r,r,r,r")
	(minus:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSCmode)"
  "@
  sub\t%2, %0
  sub\t%2, %0
  add\t%N2, %0
  sub\t%2, %1, %0
  sub\t%Q2, %0"
  [(set_attr "timings" "11,11,11,11,33")
   (set_attr "length" "2,2,6,3,5")
   (set_attr "insn_group"  "IEX,IEX,IEX,IEX,ISNG")]
)

;; A helper to expand the above with the CC_MODE filled in.
(define_expand "subsi3_flags"
  [(parallel [(set (reg:CC_ZSC CC_REG)
		   (compare:CC_ZSC
		     (minus:SI (match_operand:SI 1 "register_operand")
			       (match_operand:SI 2 "rx_source_operand"))
		     (const_int 0)))
	      (set (match_operand:SI 0 "register_operand")
		   (minus:SI (match_dup 1) (match_dup 2)))])]
)

(define_insn "sbb_internal_mem"
  [(set (match_operand:SI     0 "register_operand"   "=r")
	(minus:SI
	  (minus:SI
	    (match_operand:SI 1 "register_operand"   "0")
	    (match_operand:SI 2 "rx_restricted_mem_operand" "Q"))
	  (geu:SI (reg:CC CC_REG) (const_int 0))))
    (clobber (reg:CC CC_REG))]
  "reload_completed"
  "sbb\t%2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "6")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "sbb_internal"
  [(set (match_operand:SI     0 "register_operand"   "=r")
	(minus:SI
	  (minus:SI
	    (match_operand:SI 1 "register_operand"   " 0")
	    (match_operand:SI 2 "rx_speed_compare_operand" " r"))
	  (geu:SI (reg:CC CC_REG) (const_int 0))))
    (clobber (reg:CC CC_REG))]
  "reload_completed"
  "sbb\t%2, %0"
  [(set_attr "timings" "11")
   (set_attr "length"  "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn "*sbb_flags_mem"
  [(set (match_operand:SI     0 "register_operand"   "=r")
	(minus:SI
	  (minus:SI
	    (match_operand:SI 1 "register_operand"   " 0")
	    (match_operand:SI 2 "rx_restricted_mem_operand" "Q"))
	  (geu:SI (reg:CC CC_REG) (const_int 0))))
   (set (reg CC_REG)
	(compare
	  (minus:SI
	    (minus:SI (match_dup 1) (match_dup 2))
	    (geu:SI (reg:CC CC_REG) (const_int 0)))
	  (const_int 0)))]
  "reload_completed"
  "sbb\t%2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "6")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*sbb_flags"
  [(set (reg CC_REG)
	(compare
	  (minus:SI
	    (minus:SI
	      (match_operand:SI 1 "register_operand"   " 0")
	      (match_operand:SI 2 "rx_compare_operand" " r"))
	    (geu:SI (reg:CC CC_REG) (const_int 0)))
	  (const_int 0)))
   (set (match_operand:SI	0 "register_operand"   "=r")
	(minus:SI
	  (minus:SI (match_dup 1) (match_dup 2))
	  (geu:SI (reg:CC CC_REG) (const_int 0))))]
  "reload_completed"
  "sbb\t%2, %0"
  [(set_attr "timings" "11")
   (set_attr "length"  "3")
   (set_attr "insn_group"  "IEX")]
)

(define_expand "subdi3"
  [(set (match_operand:DI           0 "register_operand")
	(minus:DI (match_operand:DI 1 "register_operand")
		  (match_operand:DI 2 "register_operand")))]
  ""
{
  rtx op0l, op0h, op1l, op1h, op2l, op2h;

  op0l = gen_lowpart (SImode, operands[0]);
  op1l = gen_lowpart (SImode, operands[1]);
  op2l = gen_lowpart (SImode, operands[2]);
  op0h = gen_highpart (SImode, operands[0]);
  op1h = gen_highpart (SImode, operands[1]);
  op2h = gen_highpart_mode (SImode, DImode, operands[2]);

  emit_insn (gen_subdi3_internal (op0l, op0h, op1l, op2l, op1h, op2h));
  DONE;
})

(define_insn_and_split "subdi3_internal_mem"
  [(set (match_operand:SI          0 "register_operand"   "=&r")
	(minus:SI (match_operand:SI 2 "register_operand"  "0")
		  (match_operand:SI 3 "rx_restricted_mem_operand" "Q")))
   (set (match_operand:SI          1 "register_operand"   "=r")
	(minus:SI
	  (minus:SI
	    (match_operand:SI      4 "register_operand"   "1")
	    (match_operand:SI      5 "rx_restricted_mem_operand" " Q"))
	  (gtu:SI (match_dup 3) (match_dup 2))))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  emit_insn (gen_subsi3_flags (operands[0], operands[2], operands[3]));
  emit_insn (gen_sbb_internal (operands[1], operands[4], operands[5]));
  DONE;
})

(define_insn_and_split "subdi3_internal_mem2"
  [(set (match_operand:SI          0 "register_operand"   "=&r")
	(minus:SI (match_operand:SI 2 "register_operand"  "r")
		  (match_operand:SI 3 "register_operand"  "r")))
   (set (match_operand:SI          1 "register_operand"   "=r")
	(minus:SI
	  (minus:SI
	    (match_operand:SI      4 "register_operand"   "1")
	    (match_operand:SI      5 "rx_restricted_mem_operand" "Q"))
	  (gtu:SI (match_dup 3) (match_dup 2))))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  emit_insn (gen_subsi3_flags (operands[0], operands[2], operands[3]));
  emit_insn (gen_sbb_internal (operands[1], operands[4], operands[5]));
  DONE;
})

(define_insn_and_split "subdi3_internal"
  [(set (match_operand:SI          0 "register_operand"   "=&r,&r")
	(minus:SI (match_operand:SI 2 "register_operand"  "  0, r")
		  (match_operand:SI 3 "rx_speed_compare_operand" "r, r")))
   (set (match_operand:SI          1 "register_operand"   "= r, r")
	(minus:SI
	  (minus:SI
	    (match_operand:SI      4 "register_operand"   "  1, 1")
	    (match_operand:SI      5 "rx_speed_compare_operand" " r,r"))
	  (gtu:SI (match_dup 3) (match_dup 2))))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(const_int 0)]
{
  emit_insn (gen_subsi3_flags (operands[0], operands[2], operands[3]));
  emit_insn (gen_sbb_internal (operands[1], operands[4], operands[5]));
  DONE;
})

(define_insn "xorsi3_mem"
  [(set (match_operand:SI         0 "register_operand" "=r")
	(xor:SI (match_operand:SI 1 "register_operand" "%0")
	        (match_operand:SI 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "(optimize_size || reload_completed)"
  "xor\t%Q2, %0"
  [(set_attr "timings" "33")
   (set_attr "length" "6")
   (set_attr "insn_group"  "ISNG")]
)


(define_insn_and_split "xorsi3"
  [(set (match_operand:SI         0 "register_operand" "=r,r,r,r,r,r")
	(xor:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0,0")
	        (match_operand:SI 2 "rx_source_operand"
				  "r,Sint08,Sint16,Sint24,i,Q")))
   (clobber (reg:CC CC_REG))]
  ""
  "xor\t%Q2, %0"
  "&& RX_REG_P (operands[1]) && CONST_INT_P (operands[2])
   && pow2p_hwi (UINTVAL (operands[2]))"
  [(const_int 0)]
{
  /* For single bit constants use the bnot insn for smaller code.  */

  if (!rx_reg_dead_or_unused_after_insn (curr_insn, CC_REG))
    FAIL;

  rx_copy_reg_dead_or_unused_notes (operands[1], curr_insn,
    emit_insn (gen_bitinvert (operands[0],
			      GEN_INT (exact_log2 (UINTVAL (operands[2]))),
			      operands[1])));
  DONE;
}
  [(set_attr "timings" "11,11,11,11,11,33")
   (set_attr "length" "3,4,5,6,7,6")]
)

(define_insn "*xorsi3_flags"
  [(set (reg CC_REG)
	(compare (xor:SI (match_operand:SI 1 "register_operand" "%0,0,0,0,0,0")
			 (match_operand:SI 2 "rx_source_operand"
						"r,Sint08,Sint16,Sint24,i,Q"))
		 (const_int 0)))
   (set (match_operand:SI		   0 "register_operand" "=r,r,r,r,r,r")
	(xor:SI (match_dup 1) (match_dup 2)))]
  "reload_completed && rx_match_ccmode (insn, CC_ZSmode)"
  "xor\t%Q2, %0"
  [(set_attr "timings" "11,11,11,11,11,33")
   (set_attr "length" "3,4,5,6,7,6")]
)

;; A set of peepholes to catch extending loads followed by arithmetic operations.
;; We use iterators where possible to reduce the amount of typing and hence the
;; possibilities for typos.

(define_code_iterator extend_types [(zero_extend "") (sign_extend "")])
(define_code_attr     letter       [(zero_extend "R") (sign_extend "Q")])

(define_code_iterator memex_commutative [(plus "") (and "") (ior "") (xor "")])
(define_code_iterator memex_noncomm     [(div "") (udiv "") (minus "")])
(define_code_iterator memex_nocc        [(smax "") (smin "") (mult "")])

(define_code_attr     op                [(plus "add") (and "and") (div "div") (udiv "divu") (smax "max") (smin "min") (mult "mul") (ior "or") (minus "sub") (xor "xor")])

(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand")))
   (parallel [(set (match_operand:SI                    2 "register_operand")
		   (memex_commutative:SI (match_dup 0)
					 (match_dup 2)))
	      (clobber (reg:CC CC_REG))])]
  "peep2_regno_dead_p (2, REGNO (operands[0])) && (optimize < 3 || optimize_size)"
  [(parallel [(set (match_dup 2)
		   (memex_commutative:SI (match_dup 2)
					 (extend_types:SI (match_dup 1))))
	      (clobber (reg:CC CC_REG))])]
)

(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand")))
   (parallel [(set (match_operand:SI                    2 "register_operand")
		   (memex_commutative:SI (match_dup 2)
					 (match_dup 0)))
	      (clobber (reg:CC CC_REG))])]
  "peep2_regno_dead_p (2, REGNO (operands[0])) && (optimize < 3 || optimize_size)"
  [(parallel [(set (match_dup 2)
		   (memex_commutative:SI (match_dup 2)
					 (extend_types:SI (match_dup 1))))
	      (clobber (reg:CC CC_REG))])]
)

(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand")))
   (parallel [(set (match_operand:SI                    2 "register_operand")
		   (memex_noncomm:SI (match_dup 2)
				     (match_dup 0)))
	      (clobber (reg:CC CC_REG))])]
  "peep2_regno_dead_p (2, REGNO (operands[0])) && (optimize < 3 || optimize_size)"
  [(parallel [(set (match_dup 2)
		   (memex_noncomm:SI (match_dup 2)
				     (extend_types:SI (match_dup 1))))
	      (clobber (reg:CC CC_REG))])]
)

(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand")))
   (set (match_operand:SI                               2 "register_operand")
	(memex_nocc:SI (match_dup 0)
		       (match_dup 2)))]
  "peep2_regno_dead_p (2, REGNO (operands[0])) && (optimize < 3 || optimize_size)"
  [(set (match_dup 2)
	(memex_nocc:SI (match_dup 2)
		       (extend_types:SI (match_dup 1))))]
)

(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand")))
   (set (match_operand:SI                               2 "register_operand")
	(memex_nocc:SI (match_dup 2)
		       (match_dup 0)))]
  "peep2_regno_dead_p (2, REGNO (operands[0])) && (optimize < 3 || optimize_size)"
  [(set (match_dup 2)
	(memex_nocc:SI (match_dup 2)
		       (extend_types:SI (match_dup 1))))]
)

(define_insn "<memex_commutative:code>si3_<extend_types:code><small_int_modes:mode>"
  [(set (match_operand:SI                                                     0 "register_operand" "=r")
	(memex_commutative:SI (match_operand:SI                               1 "register_operand" "%0")
 		              (extend_types:SI (match_operand:small_int_modes 2 "rx_restricted_mem_operand" "Q"))))
   (clobber (reg:CC CC_REG))]
  "(optimize < 3 || optimize_size)"
  "<memex_commutative:op>\t%<extend_types:letter>2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5") ;; This length is corrected in rx_adjust_insn_length
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "<memex_noncomm:code>si3_<extend_types:code><small_int_modes:mode>"
  [(set (match_operand:SI                                                 0 "register_operand" "=r")
	(memex_noncomm:SI (match_operand:SI                               1 "register_operand" "0")
                          (extend_types:SI (match_operand:small_int_modes 2 "rx_restricted_mem_operand" "Q"))))
   (clobber (reg:CC CC_REG))]
  "(optimize < 3 || optimize_size)"
  "<memex_noncomm:op>\t%<extend_types:letter>2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5") ;; This length is corrected in rx_adjust_insn_length
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "<memex_nocc:code>si3_<extend_types:code><small_int_modes:mode>"
  [(set (match_operand:SI                                              0 "register_operand" "=r")
	(memex_nocc:SI (match_operand:SI                               1 "register_operand" "%0")
		       (extend_types:SI (match_operand:small_int_modes 2 "rx_restricted_mem_operand" "Q"))))]
  "(optimize < 3 || optimize_size)"
  "<memex_nocc:op>\t%<extend_types:letter>2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5") ;; This length is corrected in rx_adjust_insn_length
   (set_attr "insn_group"  "ISNG")]
)

(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand")))
   (set (reg:CC CC_REG)
	(compare:CC (match_operand:SI                   2 "register_operand")
		    (match_dup 0)))]
  "peep2_regno_dead_p (2, REGNO (operands[0])) && (optimize < 3 || optimize_size)"
  [(set (reg:CC CC_REG)
	(compare:CC (match_dup 2)
		    (extend_types:SI (match_dup 1))))]
)

;; Convert:
;;   (set (reg1) (sign_extend (mem))
;;   (set (reg2) (zero_extend (reg1))
;; into
;;   (set (reg2) (zero_extend (mem)))
(define_peephole2
  [(set (match_operand:SI                              0 "register_operand")
	(sign_extend:SI (match_operand:small_int_modes 1 "memory_operand")))
   (set (match_operand:SI                              2 "register_operand")
	(zero_extend:SI (match_operand:small_int_modes 3 "register_operand")))]
  "REGNO (operands[0]) == REGNO (operands[3])
   && (REGNO (operands[0]) == REGNO (operands[2])
       || peep2_regno_dead_p (2, REGNO (operands[0])))"
  [(set (match_dup 2)
	(zero_extend:SI (match_dup 1)))]
)

;; Remove the redundant sign extension from:
;;   (set (reg) (extend (mem)))
;;   (set (reg) (extend (reg)))
(define_peephole2
  [(set (match_operand:SI                               0 "register_operand")
	(extend_types:SI (match_operand:small_int_modes 1 "memory_operand")))
   (set (match_dup 0)
	(extend_types:SI (match_operand:small_int_modes 2 "register_operand")))]
  "REGNO (operands[0]) == REGNO (operands[2])"
  [(set (match_dup 0) (extend_types:SI (match_dup 1)))]
)

(define_insn "comparesi3_<extend_types:code><small_int_modes:mode>"
  [(set (reg:CC CC_REG)
	(compare:CC (match_operand:SI                               0 "register_operand" "r")
		    (extend_types:SI (match_operand:small_int_modes 1 "rx_restricted_mem_operand" "Q"))))]
  "(optimize < 3 || optimize_size)"
  "cmp\t%<extend_types:letter>1, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "5") ;; This length is corrected in rx_adjust_insn_length
   (set_attr "insn_group"  "ISNG")]
)

;; Floating Point Instructions

(define_insn "addsf3_mem"
  [(set (match_operand:SF          0 "register_operand"  "=r")
	(plus:SF (match_operand:SF 1 "register_operand"  "%0")
		 (match_operand:SF 2 "rx_restricted_mem_operand"  "Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (optimize_size || reload_completed)"
  "fadd\t%2, %0"
  [(set_attr "timings" "66")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_expand "addsf3"
  [(set (match_operand:SF          0 "register_operand")
	(plus:SF (match_operand:SF 1 "register_operand" )
		 (match_operand:SF 2 "rx_speed_source_operand")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS"
  {
	if(TARGET_RXV2)
		emit_insn(gen_addsf3v2(operands[0], operands[1], operands[2]));
	else
		emit_insn(gen_addsf3v1(operands[0], operands[1], operands[2]));
	DONE;
  }
 )

(define_insn "addsf3v1"
  [(set (match_operand:SF          0 "register_operand"  "=r,r")
	(plus:SF (match_operand:SF 1 "register_operand"  "%0,0")
		 (match_operand:SF 2 "rx_speed_source_operand"  "r,F")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (!TARGET_RXV2)"
  "@
  fadd\t%2, %0
  fadd\t%2, %0"
  [(set_attr "timings" "44,44")
   (set_attr "length" "3,7")
   (set_attr "insn_group"  "IFE,IFE")]
)

(define_insn "addsf3v2"
  [(set (match_operand:SF          0 "register_operand"  "=r,r,r")
	(plus:SF (match_operand:SF 1 "register_operand"  "%0,0,r")
		 (match_operand:SF 2 "rx_speed_source_operand"  "r,F,r")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && TARGET_RXV2"
  "@
  fadd\t%2, %0
  fadd\t%2, %0
  fadd\t%1, %2, %0"
  [(set_attr "timings" "44,44,44")
   (set_attr "length" "3,7,3")
   (set_attr "insn_group"  "IFE,IFE,IFE")]
)

;;for dfpu instructions we don't need to model any CC registers because only for cbranchdf4 we copy the result
;;to the CC reg using mvfdr
(define_insn "adddf3"
  [(set (match_operand:DF          0 "register_operand"  "=DFPUreg")
  (plus:DF (match_operand:DF 1 "register_operand"  "DFPUreg")
     (match_operand:DF 2 "register_operand"  "DFPUreg")))]
  "flag_dfpu"
  "dadd\t%1, %2, %0"
  [(set_attr "timings" "44")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "divdf3"
  [(set (match_operand:DF         0 "register_operand" "=DFPUreg")
        (div:DF (match_operand:DF 1 "register_operand"  "DFPUreg")
                (match_operand:DF 2 "register_operand" "DFPUreg")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "ddiv\t%2, %1, %0"
  [(set_attr "timings" "1616")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "divsf3_mem"
  [(set (match_operand:SF         0 "register_operand" "=r")
	(div:SF (match_operand:SF 1 "register_operand"  "0")
		(match_operand:SF 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (optimize_size || reload_completed)"
  "fdiv\t%2, %0"
  [(set_attr "timings" "1818")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "divsf3"
  [(set (match_operand:SF         0 "register_operand" "=r,r")
	(div:SF (match_operand:SF 1 "register_operand"  "0,0")
		(match_operand:SF 2 "rx_speed_source_operand" "r,F")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS"
  "fdiv\t%2, %0"
  [(set_attr "timings" "1616,1616")
   (set_attr "length" "3,7")
   (set_attr "insn_group"  "ISNG,ISNG")]
)

(define_insn "mulsf3_mem"
  [(set (match_operand:SF          0 "register_operand" "=r")
	(mult:SF (match_operand:SF 1 "register_operand" "%0")
		(match_operand:SF  2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (optimize_size || reload_completed)"
  "fmul\t%2, %0"
  [(set_attr "timings" "55")
   (set_attr "length"  "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_expand "mulsf3"
  [(set (match_operand:SF          0 "register_operand")
	(mult:SF (match_operand:SF 1 "register_operand")
		(match_operand:SF  2 "rx_speed_source_operand")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS"
  {
	if(TARGET_RXV2)
		emit_insn(gen_mulsf3v2(operands[0], operands[1], operands[2]));
	else
		emit_insn(gen_mulsf3v1(operands[0], operands[1], operands[2]));
	DONE;
  }
 )

(define_insn "mulsf3v1"
  [(set (match_operand:SF          0 "register_operand" "=r,r")
	(mult:SF (match_operand:SF 1 "register_operand" "%0,0")
		(match_operand:SF  2 "rx_speed_source_operand" "r,F")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (!TARGET_RXV2)"
  "@
  fmul\t%2, %0
  fmul\t%2, %0"
  [(set_attr "timings" "33,33")
   (set_attr "length"  "3,7")
   (set_attr "insn_group"  "IFM,IFM")]
)

(define_insn "mulsf3v2"
  [(set (match_operand:SF          0 "register_operand" "=r,r,r")
	(mult:SF (match_operand:SF 1 "register_operand" "%0,0,r")
		(match_operand:SF  2 "rx_speed_source_operand" "r,F,r")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && TARGET_RXV2"
  "@
  fmul\t%2, %0
  fmul\t%2, %0
  fmul\t%1, %2, %0"
  [(set_attr "timings" "33,33,33")
   (set_attr "length"  "3,7,3")
   (set_attr "insn_group"  "IFM,IFM,IFM")]
)

(define_insn "muldf3"
  [(set (match_operand:DF          0 "register_operand" "=DFPUreg")
        (mult:DF (match_operand:DF 1 "register_operand" "DFPUreg")
                 (match_operand:DF  2 "rx_speed_source_operand" "DFPUreg")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "dmul\t%1, %2, %0"
  [(set_attr "timings" "33")
   (set_attr "length"  "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "subdf3"
  [(set (match_operand:DF           0 "register_operand" "=DFPUreg")
        (minus:DF (match_operand:DF 1 "register_operand"  "DFPUreg")
                  (match_operand:DF 2 "rx_speed_source_operand" "DFPUreg")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "dsub\t%2, %1, %0"
  [(set_attr "timings" "44")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "subsf3_mem"
  [(set (match_operand:SF           0 "register_operand" "=r")
	(minus:SF (match_operand:SF 1 "register_operand"  "0")
		  (match_operand:SF 2 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (optimize_size || reload_completed)"
  "fsub\t%Q2, %0"
  [(set_attr "timings" "66")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_expand "subsf3"
  [(set (match_operand:SF           0 "register_operand")
	(minus:SF (match_operand:SF 1 "register_operand")
		  (match_operand:SF 2 "rx_speed_source_operand")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS"
  {
	if(TARGET_RXV2)
		emit_insn(gen_subsf3v2(operands[0], operands[1], operands[2]));
	else
		emit_insn(gen_subsf3v1(operands[0], operands[1], operands[2]));
	DONE;
  }
)

(define_insn "subsf3v1"
  [(set (match_operand:SF           0 "register_operand" "=r,r")
	(minus:SF (match_operand:SF 1 "register_operand"  "0,0")
		  (match_operand:SF 2 "rx_speed_source_operand" "r,F")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (!TARGET_RXV2)"
  "@
  fsub\t%Q2, %0
  fsub\t%Q2, %0"
  [(set_attr "timings" "44,44")
   (set_attr "length" "3,7")
   (set_attr "insn_group"  "IFE,IFE")]
)

(define_insn "subsf3v2"
  [(set (match_operand:SF           0 "register_operand" "=r,r,r")
	(minus:SF (match_operand:SF 1 "register_operand"  "0,0,r")
		  (match_operand:SF 2 "rx_speed_source_operand" "r,F,r")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && TARGET_RXV2"
  "@
  fsub\t%Q2, %0
  fsub\t%Q2, %0
  fsub\t%2, %1, %0"
  [(set_attr "timings" "44,44,44")
   (set_attr "length" "3,7,3")
   (set_attr "insn_group"  "IFE,IFE,IFE")]
)

(define_insn "fix_truncsfsi2_mem"
  [(set (match_operand:SI         0 "register_operand"  "=r")
	(fix:SI (match_operand:SF 1 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (optimize_size || reload_completed)"
  "ftoi\t%Q1, %0"
  [(set_attr "timings" "44")
   (set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "fix_truncsfsi2"
  [(set (match_operand:SI         0 "register_operand"  "=r")
	(fix:SI (match_operand:SF 1 "rx_speed_compare_operand" "r")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS"
  "ftoi\t%Q1, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "IFE")]
)

(define_insn "fix_truncdfsi2"
  [(set (match_operand:SI         0 "register_operand"  "=r")
	(fix:SI (match_operand:DF 1 "rx_speed_compare_operand" "DFPUreg")))
   (clobber (match_scratch:DF 2                     "=&DFPUreg"))
  ]
  "flag_dfpu"
  "dtoi\t%Q1, %2\n\tdmov.L\t%L2, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "fixuns_truncsfsi2"
  [(set (match_operand:SI         0 "register_operand"  "=r,r")
  	(unsigned_fix:SI (match_operand:SF 1 "general_operand" "r,Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && TARGET_RXV2"
  "ftou\t%1, %0"
  [(set_attr "timings" "22,44")
   (set_attr "length" "3,4")
   (set_attr "insn_group"  "IFE,ISNG")]
)

(define_insn "fixuns_truncdfsi2"
  [(set (match_operand:SI         0 "register_operand"  "=r")
    (unsigned_fix:SI (match_operand:DF 1 "general_operand" "DFPUreg")))
   (clobber (match_scratch:DF 2                     "=&DFPUreg"))
  ]
  "flag_dfpu"
  "dtou\t%1, %2\n\tdmov.L\t%L2, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "floatunssisf2"
  [(set (match_operand:SF         0 "register_operand"  "=r,r")
  	(unsigned_float:SF (match_operand:SI 1 "general_operand" "r,Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && TARGET_RXV2"
  "utof\t%1, %0"
  [(set_attr "timings" "22,44")
   (set_attr "length" "3,4")
   (set_attr "insn_group"  "IFE,ISNG")]
)

(define_insn "floatunssidf2"
  [(set (match_operand:DF         0 "register_operand"  "=DFPUreg")
    (unsigned_float:DF (match_operand:SI 1 "general_operand" "r")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "utod\t%1, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

;DPFU registers work only with double values anyway so no need to keep it in such registers
(define_insn "truncdfsf2"
  [(set (match_operand:SF           0 "register_operand"  "=r")
	(float_truncate:SF (match_operand:DF 1 "register_operand" "DFPUreg")))
   (clobber (match_scratch:DF 2                     "=&DFPUreg"))
  ]
  "flag_dfpu"
  "dtof\t%1, %2\n\tdmov.L\t%L2, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "extendsfdf2"
  [(set (match_operand:DF         0 "register_operand"  "=DFPUreg")
    (float_extend:DF (match_operand:SF 1 "register_operand" "r")))
  ]
  "flag_dfpu"
  "ftod\t%1, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "floatsisf2_mem"
  [(set (match_operand:SF           0 "register_operand"  "=r")
	(float:SF (match_operand:SI 1 "rx_restricted_mem_operand" "Q")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS && (optimize_size || reload_completed)"
  "itof\t%Q1, %0"
  [(set_attr "timings" "44")
   (set_attr "length" "6")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "floatsisf2"
  [(set (match_operand:SF           0 "register_operand"  "=r")
	(float:SF (match_operand:SI 1 "rx_speed_compare_operand" "r")))
   (clobber (reg:CC CC_REG))]
  "ALLOW_RX_FPU_INSNS"
  "itof\t%Q1, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "IFE")]
)

(define_insn "floatsidf2"
  [(set (match_operand:DF           0 "register_operand"  "=DFPUreg")
  (float:DF (match_operand:SI 1 "general_operand" "r")))
   (clobber (reg:CC CC_REG))]
  "flag_dfpu"
  "itod\t%Q1, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "sqrtsf2"
  [(set (match_operand:SF 0 "register_operand" "=RXV2,RXV2")
	(sqrt:SF (match_operand:SF 1 "general_operand" "r,Q")))]
  "ALLOW_RX_FPU_INSNS && ALLOW_HW_SQRT"
  "fsqrt %Q1, %0"
  [(set_attr "timings" "1616")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG,ISNG")]
)

(define_insn "sqrtdf2"
  [(set (match_operand:DF 0 "register_operand" "=DFPUreg")
  (sqrt:DF (match_operand:DF 1 "general_operand" "DFPUreg")))]
  "flag_dfpu"
  "dsqrt %1, %0"
  [(set_attr "timings" "1616")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

;; Bit manipulation instructions.

;; The *_in_memory patterns will not be matched automatically, not even with
;; combiner bridge patterns.  Especially when the memory operands have a
;; displacement, the resulting patterns look too complex.
;; Instead we manually look around the matched insn to see if there is a
;; preceeding memory load and a following memory store of the modified register
;; which can be fused into the single *_in_memory insn.
;; Do that before register allocation, as it can eliminate one temporary
;; register that needs to be allocated.

(define_insn_and_split "bitset"
  [(set (match_operand:SI                    0 "register_operand" "=r")
	(ior:SI (ashift:SI (const_int 1)
			   (match_operand:SI 1 "rx_shift_operand" "ri"))
		(match_operand:SI            2 "register_operand" "0")))]
  ""
  "bset\t%1, %0"
  "&& can_create_pseudo_p ()"
  [(const_int 0)]
{
  if (rx_fuse_in_memory_bitop (operands, curr_insn, &gen_bitset_in_memory))
    DONE;
  else
    FAIL;
}
  [(set_attr "length" "3")]
)

(define_insn "*bitset"
  [(set (match_operand:SI                    0 "register_operand" "=r")
	(ior:SI (ashift:SI (const_int 1)
			   (match_operand:SI 1 "rx_shift_operand" "ri"))
		(match_operand:SI            2 "register_operand" "0")))]
  ""
  "bset\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn "bset"
  [(set (match_operand:SI                    0 "register_operand" "=r")
	(unspec:SI [(ior:SI (ashift:SI (const_int 1)
			   		(match_operand:SI 1 "rx_shift_operand" "ri"))
					(match_operand:SI            2 "register_operand" "0"))]
				UNSPEC_BUILTIN_BSET))]
  ""
  "bset\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn "bitset_in_memory"
  [(set (match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
        (unspec:QI [(ior:QI (ashift:QI (const_int 1)
                                       (match_operand:QI 1 "nonmemory_operand" "ri"))
                                       (match_dup 0))]
                               UNSPEC_BUILTIN_BSET_MEM))]
  ""
  "bset\t%1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*bitset_in_memory"
  [(set (match_operand:QI                    0 "rx_restricted_mem_operand" "+Q")
	(ior:QI (ashift:QI (const_int 1)
			   (match_operand:QI 1 "nonmemory_operand" "ri"))
		(match_dup 0)))]
  ""
  "bset\t%1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*bitset_in_memory2"
  [(set (match_operand:QI                    0 "rx_restricted_mem_operand" "+Q")
	(ior:QI (ashift:QI (const_int 1)
			   (match_operand:SI 1 "nonmemory_operand" "ri"))
		(match_dup 0)))]
  ""
  "bset\t%1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*bitset_in_memory_2"
  [(set (match_operand:QI                    0 "rx_restricted_mem_operand" "+Q")
	(ior:QI (match_dup 0)
		(match_operand 1 "rx_bitset_operand" "i")
		))]
  ""
  "bset\t%b1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn_and_split "bitinvert"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(xor:SI (ashift:SI (const_int 1)
			   (match_operand:SI 1 "rx_shift_operand" "ri"))
		(match_operand:SI 2 "register_operand" "0")))]
  ""
  "bnot\t%1, %0"
  "&& can_create_pseudo_p ()"
  [(const_int 0)]
{
  if (rx_fuse_in_memory_bitop (operands, curr_insn, &gen_bitinvert_in_memory))
    DONE;
  else
    FAIL;
}
  [(set_attr "length" "3")]
)

(define_insn "binvert"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(xor:SI (ashift:SI (const_int 1)
			   		(match_operand:SI 1 "rx_shift_operand" "ri"))
					(match_operand:SI 2 "register_operand" "0"))]
				UNSPEC_BUILTIN_BNOT))]
  ""
  "bnot\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn "bnot_memory"
  [(set (match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
      (unspec:QI [(xor:SI (ashift:QI (const_int 1)
                           (match_operand:QI 1 "nonmemory_operand" "ri"))
                           (match_dup 0))]
                           UNSPEC_BUILTIN_BNOT_MEM))]
   ""
   "bnot\t%1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)
(define_insn "bitinvert_in_memory"
  [(set (match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
	(xor:QI (ashift:QI (const_int 1)
			   (match_operand:QI 1 "nonmemory_operand" "ri"))
		(match_dup 0)))]
  ""
  "bnot\t%1, %0.B"
  [(set_attr "length" "5")
   (set_attr "timings" "33")]
)

(define_insn "*bitclr"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(and:SI (not:SI
		  (ashift:SI
		    (const_int 1)
		    (match_operand:SI 1 "rx_shift_operand" "ri")))
		(match_operand:SI 2 "register_operand" "0")))]
  ""
  "bclr\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn_and_split "bclr"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec: SI [(and:SI (not:SI
		  (ashift:SI
		    (const_int 1)
		    (match_operand:SI 1 "rx_shift_operand" "ri")))
		(match_operand:SI 2 "register_operand" "0"))]
    UNSPEC_BUILTIN_BCLR))]
  ""
  "bclr\t%1, %0"
  "&& can_create_pseudo_p ()"
  [(const_int 0)]
{
  if (rx_fuse_in_memory_bitop (operands, curr_insn, &gen_bitclr_in_memory))
    DONE;
  else
    FAIL;
}
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn "bclr_memory"
  [(set(match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
       (unspec:QI [(and:QI (not:QI
                 (ashift:QI (const_int 1)
                 (match_operand:QI 1 "nonmemory_operand" "ri")))
                 (match_dup 0))]
                 UNSPEC_BUILTIN_BCLR_MEM))]
  ""
  "bclr\t%1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "bitclr_in_memory"
  [(set (match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
	(and:QI (not:QI
		  (ashift:QI
		    (const_int 1)
		    (match_operand:QI 1 "nonmemory_operand" "ri")))
		(match_dup 0)))]
  ""
  "bclr\t%1, %0.B"
[(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*bitclr_in_memory2"
  [(set (match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
	(and:QI (not:QI
		  (ashift:QI
		    (const_int 1)
		    (match_operand:SI 1 "nonmemory_operand" "ri")))
		(match_dup 0)))]
  ""
  "bclr\t%1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*bittest"
  [(set (reg:CC_ZS CC_REG)
	(compare:CC_ZS
		(and:SI (match_operand:SI 0 "register_operand"  "r,r")
		(ashift:SI
		  (const_int 1)
		  (match_operand:SI 1 "rx_speed_source_operand" "r,i")))
	(const_int 0)))]
  ""
  "btst\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX,IEX")]
)

(define_insn "*bittest_in_memory"
[(set (reg:CC_ZS CC_REG)
      (compare:CC_ZS
	      (and:QI (match_operand:QI 0 "rx_restricted_mem_operand" "Q")
		(ashift:QI
		  (const_int 1)
		  (match_operand:SI 1 "nonmemory_operand" "ri")))
	(const_int 0)))]
  ""
  "btst\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*bitclr_in_memory_2"
  [(set (match_operand:QI 0 "rx_restricted_mem_operand" "+Q")
       (and:QI (match_dup 0)
               (match_operand 1 "rx_bitclr_operand" "i")
               ))]
  ""
  "bclr\t%b1, %0.B"
  [(set_attr "length" "3")
   (set_attr "timings" "33")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "*insv_imm"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand" "+r")
	  (const_int 1)
	  (match_operand:SI 1 "rx_shift_operand" "ri"))
	(match_operand:SI 2 "const_int_operand" ""))]
  ""
{
  if (INTVAL (operands[2]) & 1)
    return "bset\t%1, %0";
  else
    return "bclr\t%1, %0";
}
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

(define_insn_and_split "rx_insv_reg"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand" "+r")
	  (const_int 1)
	  (match_operand:SI 1 "const_int_operand" ""))
	(match_operand:SI 2 "register_operand" "r"))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(set (zero_extract:SI (match_dup 0) (const_int 1) (match_dup 1))
	(match_dup 3))]
{
  rtx flags, x;

  /* Emit tst #1, op2.  */
  flags = gen_rtx_REG (CC_ZSmode, CC_REG);
  x = gen_rtx_AND (SImode, operands[2], const1_rtx);
  x = gen_rtx_COMPARE (CC_ZSmode, x, const0_rtx);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  /* Emit bmne.  */
  operands[3] = gen_rtx_NE (SImode, flags, const0_rtx);
})

(define_insn_and_split "*insv_cond_mem"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand" "+r")
	  (const_int 1)
	  (match_operand:SI 1 "const_int_operand" ""))
	(match_operator:SI 4 "comparison_operator"
	  [(match_operand:SI 2 "register_operand" "r")
	   (match_operand:SI 3 "rx_restricted_mem_operand" "Q")]))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(set (zero_extract:SI (match_dup 0) (const_int 1) (match_dup 1))
	(match_dup 4))]
{
  rtx flags, x;

  flags = gen_rtx_REG (CCmode, CC_REG);
  x = gen_rtx_COMPARE (CCmode, operands[2], operands[3]);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  operands[4] = gen_rtx_fmt_ee (GET_CODE (operands[4]), SImode,
			        flags, const0_rtx);
})

(define_insn_and_split "*insv_cond"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand" "+r")
	  (const_int 1)
	  (match_operand:SI 1 "const_int_operand" ""))
	(match_operator:SI 4 "comparison_operator"
	  [(match_operand:SI 2 "register_operand" "r")
	   (match_operand:SI 3 "rx_speed_source_operand" "ri")]))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  "reload_completed"
  [(set (zero_extract:SI (match_dup 0) (const_int 1) (match_dup 1))
	(match_dup 4))]
{
  rtx flags, x;

  flags = gen_rtx_REG (CCmode, CC_REG);
  x = gen_rtx_COMPARE (CCmode, operands[2], operands[3]);
  x = gen_rtx_SET (flags, x);
  emit_insn (x);

  operands[4] = gen_rtx_fmt_ee (GET_CODE (operands[4]), SImode,
			        flags, const0_rtx);
})

(define_insn "*bmcc"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand" "+r")
	  (const_int 1)
	  (match_operand:SI 1 "const_int_operand" ""))
	(match_operator:SI 2 "comparison_operator"
	  [(reg CC_REG) (const_int 0)]))]
  "reload_completed"
  "bm%B2\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEX")]
)

;; Work around the fact that X=Y<0 is preferentially expanded as a shift.
(define_insn_and_split "*insv_cond_lt"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand" "+r")
	  (const_int 1)
	  (match_operand:SI 1 "const_int_operand" ""))
	(match_operator:SI 3 "rshift_operator"
	  [(match_operand:SI 2 "register_operand" "r")
	   (const_int 31)]))
   (clobber (reg:CC CC_REG))]
  ""
  "#"
  ""
  [(parallel [(set (zero_extract:SI (match_dup 0) (const_int 1) (match_dup 1))
		   (lt:SI (match_dup 2) (const_int 0)))
	      (clobber (reg:CC CC_REG))])]
  ""
)

(define_expand "insv"
  [(set (zero_extract:SI
	  (match_operand:SI 0 "register_operand")	;; Destination
	  (match_operand:SI 1 "const_int_operand")	;; # of bits to set
	  (match_operand:SI 2 "nonmemory_operand"))	;; Starting bit
	(match_operand:SI   3 "nonmemory_operand"))]	;; Bits to insert
  ""
{
  /* We only handle single-bit inserts.  */
  if (!CONST_INT_P (operands[1]) || INTVAL (operands[1]) != 1)
    FAIL;

  /* Either the bit to insert or the position must be constant.  */
  if (CONST_INT_P (operands[3]))
    operands[3] = GEN_INT (INTVAL (operands[3]) & 1);
  else if (CONST_INT_P (operands[2]))
    {
      emit_insn (gen_rx_insv_reg (operands[0], operands[2], operands[3]));
      DONE;
    }
  else
    FAIL;
})

;; Atomic operations.

;; Atomic exchange operation.

(define_code_iterator FETCHOP [plus minus ior xor and])
(define_code_iterator FETCHOP_NO_MINUS [plus ior xor and])

(define_code_attr fetchop_name
  [(plus "add") (minus "sub") (ior "or") (xor "xor") (and "and")])

(define_code_attr fetchop_name2
  [(plus "add") (minus "sub") (ior "ior") (xor "xor") (and "and")])

(define_mode_iterator QIHI [QI HI])
(define_mode_attr BW [(QI "B") (HI "W")])

(define_insn "sync_lock_test_and_setsi"
  [(set (match_operand:SI 0 "register_operand"   "=r,r")
	(match_operand:SI 1 "rx_compare_operand" "=r,Q"))
   (set (match_dup 1)
	(match_operand:SI 2 "register_operand"    "0,0"))]
  ""
  "xchg\t%1, %0"
  [(set_attr "length" "3,6")
   (set_attr "timings" "22")
   (set_attr "insn_group"  "ISNG,ISNG")]
)

(define_expand "atomic_exchange<mode>"
  [(match_operand:QIHI 0 "register_operand")		;; oldval output
   (match_operand:QIHI 1 "rx_restricted_mem_operand")	;; memory
   (match_operand:QIHI 2 "register_operand")		;; newval input
   (match_operand:QIHI 3 "const_int_operand")]		;; memory model
  ""
{
  emit_insn (gen_xchg_mem<mode> (operands[0], operands[1], operands[2]));
  DONE;
})

(define_expand "atomic_exchangesi"
  [(match_operand:SI 0 "register_operand")		;; oldval output
   (match_operand:SI 1 "rx_restricted_mem_operand")	;; memory
   (match_operand:SI 2 "register_operand")		;; newval input
   (match_operand:SI 3 "const_int_operand")]		;; memory model
  ""
{
  emit_insn (gen_sync_lock_test_and_setsi (operands[0], operands[1],
					   operands[2]));
  DONE;
})

(define_insn "xchg_mem<mode>"
  [(set (match_operand:QIHI 0 "register_operand"   "=r")
	(match_operand:QIHI 1 "rx_compare_operand" "=Q"))
   (set (match_dup 1)
	(match_operand:QIHI 2 "register_operand"    "0"))]
  ""
  "xchg\t%1.<BW>, %0"
  [(set_attr "length" "6")
   (set_attr "timings" "22")]
)

;; read - modify - write - return old value
(define_expand "atomic_fetch_<fetchop_name>si"
  [(set (match_operand:SI 0 "register_operand")
	(match_operand:SI 1 "memory_operand"))
   (set (match_dup 1)
	(FETCHOP:SI (match_dup 1) (match_operand:SI 2 "rx_source_operand")))
   (match_operand:SI 3 "const_int_operand")]		;; memory model
  ""
{
  {
    rx_atomic_sequence seq (current_function_decl);

    emit_move_insn (operands[0], operands[1]);

    rtx tmp = gen_reg_rtx (SImode);
    emit_insn (gen_<fetchop_name2>si3 (tmp, operands[0], operands[2]));

    emit_move_insn (operands[1], tmp);
  }
  DONE;
})

(define_expand "atomic_fetch_nandsi"
  [(set (match_operand:SI 0 "register_operand")
	(match_operand:SI 1 "memory_operand"))
   (set (match_dup 1)
	(not:SI (and:SI (match_dup 1)
			(match_operand:SI 2 "rx_source_operand"))))
   (match_operand:SI 3 "const_int_operand")]		;; memory model
  ""
{
  {
    rx_atomic_sequence seq (current_function_decl);

    emit_move_insn (operands[0], operands[1]);

    rtx tmp = gen_reg_rtx (SImode);
    emit_insn (gen_andsi3 (tmp, operands[0], operands[2]));
    emit_insn (gen_one_cmplsi2 (tmp, tmp));

    emit_move_insn (operands[1], tmp);
  }
  DONE;
})

;; read - modify - write - return new value
;; Because subtraction is not commutative we need to specify a different
;; set of patterns for it.
(define_expand "atomic_<fetchop_name>_fetchsi"
  [(set (match_operand:SI 0 "register_operand")
	(FETCHOP_NO_MINUS:SI (match_operand:SI 1 "rx_restricted_mem_operand")
			     (match_operand:SI 2 "register_operand")))
   (set (match_dup 1)
	(FETCHOP_NO_MINUS:SI (match_dup 1) (match_dup 2)))
   (match_operand:SI 3 "const_int_operand")]		;; memory model
  ""
{
  {
    rx_atomic_sequence seq (current_function_decl);

    emit_move_insn (operands[0], operands[2]);
    emit_insn (gen_<fetchop_name2>si3 (operands[0], operands[0], operands[1]));
    emit_move_insn (operands[1], operands[0]);
  }
  DONE;
})

(define_expand "atomic_sub_fetchsi"
  [(set (match_operand:SI 0 "register_operand")
	(minus:SI (match_operand:SI 1 "rx_restricted_mem_operand")
		  (match_operand:SI 2 "rx_source_operand")))
   (set (match_dup 1)
	(minus:SI (match_dup 1) (match_dup 2)))
   (match_operand:SI 3 "const_int_operand")]		;; memory model
  ""
{
  {
    rx_atomic_sequence seq (current_function_decl);

    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_subsi3 (operands[0], operands[0], operands[2]));
    emit_move_insn (operands[1], operands[0]);
  }
  DONE;
})

(define_expand "atomic_nand_fetchsi"
  [(set (match_operand:SI 0 "register_operand")
	(not:SI (and:SI (match_operand:SI 1 "rx_restricted_mem_operand")
			(match_operand:SI 2 "register_operand"))))
   (set (match_dup 1)
	(not:SI (and:SI (match_dup 1) (match_dup 2))))
   (match_operand:SI 3 "const_int_operand")]		;; memory model
  ""
{
  {
    rx_atomic_sequence seq (current_function_decl);

    emit_move_insn (operands[0], operands[2]);
    emit_insn (gen_andsi3 (operands[0], operands[0], operands[1]));
    emit_insn (gen_one_cmplsi2 (operands[0], operands[0]));
    emit_move_insn (operands[1], operands[0]);
  }
  DONE;
});


;; Block move functions.

(define_expand "movstr"
  [(set (match_operand:BLK 1 "memory_operand")    ;; Dest
	(match_operand:BLK 2 "memory_operand"))   ;; Source
   (use (match_operand:SI  0 "register_operand")) ;; Updated Dest
  ]
   "(rx_allow_string_insns && (!optimize_size))"
  {
    rtx addr1 = gen_rtx_REG (SImode, 1);
    rtx addr2 = gen_rtx_REG (SImode, 2);
    rtx len   = gen_rtx_REG (SImode, 3);
    rtx dest_copy = gen_reg_rtx (SImode);

    emit_move_insn (len, GEN_INT (-1));
    emit_move_insn (addr1, force_operand (XEXP (operands[1], 0), NULL_RTX));
    emit_move_insn (addr2, force_operand (XEXP (operands[2], 0), NULL_RTX));
    operands[1] = replace_equiv_address_nv (operands[1], addr1);
    operands[2] = replace_equiv_address_nv (operands[2], addr2);
    emit_move_insn (dest_copy, addr1);
    emit_insn (gen_rx_movstr ());
    emit_move_insn (len, GEN_INT (-1));
    emit_insn (gen_rx_strend (operands[0], dest_copy));
    DONE;
  }
)

(define_insn "rx_movstr"
  [(set (mem:BLK (reg:SI 1))
	(mem:BLK (reg:SI 2)))
   (unspec_volatile:BLK [(reg:SI 1) (reg:SI 2) (reg:SI 3)] UNSPEC_MOVSTR)
   (clobber (reg:SI 1))
   (clobber (reg:SI 2))
   (clobber (reg:SI 3))]
  "rx_allow_string_insns"
  "smovu"
  [(set_attr "length" "2")
   (set_attr "timings" "1111") ;; The timing is a guesstimate.
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "rx_strend"
  [(set (match_operand:SI                      0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "register_operand"  "r")
				(reg:SI 3)] UNSPEC_STRLEN))
   (clobber (reg:SI 1))
   (clobber (reg:SI 2))
   (clobber (reg:SI 3))
   (clobber (reg:CC CC_REG))
   ]
  "rx_allow_string_insns"
  "mov\t%1, r1\n\tmov\t#0, r2\n\tsuntil.b\n\tmov\tr1, %0\n\tsub\t#1, %0"
  [(set_attr "length" "10")
   (set_attr "timings" "1111") ;; The timing is a guesstimate.
   (set_attr "insn_group"  "ISNG")]
)

(define_expand "cpymemsi"
  [(parallel
    [(set (match_operand:BLK 0 "memory_operand")    ;; Dest
	  (match_operand:BLK 1 "memory_operand"))   ;; Source
     (use (match_operand:SI  2 "register_operand")) ;; Length in bytes
     (match_operand          3 "immediate_operand") ;; Align
     (unspec_volatile:BLK [(reg:SI 1) (reg:SI 2) (reg:SI 3)] UNSPEC_CPYMEM)]
    )]
  "rx_allow_string_insns"
  {
    rtx addr1 = gen_rtx_REG (SImode, 1);
    rtx addr2 = gen_rtx_REG (SImode, 2);
    rtx len   = gen_rtx_REG (SImode, 3);

    /* Do not use when the source or destination are volatile - the SMOVF
       instruction will read and write in word sized blocks, which may be
       outside of the valid address range.  */
    if (MEM_P (operands[0]) && MEM_VOLATILE_P (operands[0]))
      FAIL;
    if (MEM_P (operands[1]) && MEM_VOLATILE_P (operands[1]))
      FAIL;

    if (REG_P (operands[0]) && (REGNO (operands[0]) == 2
				      || REGNO (operands[0]) == 3))
      FAIL;
    if (REG_P (operands[1]) && (REGNO (operands[1]) == 1
				      || REGNO (operands[1]) == 3))
      FAIL;
    if (REG_P (operands[2]) && (REGNO (operands[2]) == 1
				      || REGNO (operands[2]) == 2))
      FAIL;

    emit_move_insn (addr1, force_operand (XEXP (operands[0], 0), NULL_RTX));
    emit_move_insn (addr2, force_operand (XEXP (operands[1], 0), NULL_RTX));
    emit_move_insn (len, force_operand (operands[2], NULL_RTX));
    operands[0] = replace_equiv_address_nv (operands[0], addr1);
    operands[1] = replace_equiv_address_nv (operands[1], addr2);
    emit_insn (gen_rx_cpymem ());
    DONE;
  }
)

(define_insn "rx_cpymem"
  [(set (mem:BLK (reg:SI 1))
	(mem:BLK (reg:SI 2)))
   (use (reg:SI 3))
   (unspec_volatile:BLK [(reg:SI 1) (reg:SI 2) (reg:SI 3)] UNSPEC_CPYMEM)
   (clobber (reg:SI 1))
   (clobber (reg:SI 2))
   (clobber (reg:SI 3))]
  "rx_allow_string_insns"
  "smovf"
  [(set_attr "length" "2")
   (set_attr "timings" "1111") ;; The timing is a guesstimate.
   (set_attr "insn_group"  "ISNG")]
)

(define_expand "setmemsi"
  [(set (match_operand:BLK 0 "memory_operand")     ;; Dest
        (match_operand:QI  2 "nonmemory_operand")) ;; Value
   (use (match_operand:SI  1 "nonmemory_operand")) ;; Length
   (match_operand          3 "immediate_operand")  ;; Align
   (unspec_volatile:BLK [(reg:SI 1) (reg:SI 2) (reg:SI 3)] UNSPEC_SETMEM)]
  "rx_allow_string_insns"
  {
    rtx addr = gen_rtx_REG (SImode, 1);
    rtx val  = gen_rtx_REG (QImode, 2);
    rtx len  = gen_rtx_REG (SImode, 3);

    emit_move_insn (addr, force_operand (XEXP (operands[0], 0), NULL_RTX));
    emit_move_insn (len, force_operand (operands[1], NULL_RTX));
    emit_move_insn (val, operands[2]);
    emit_insn (gen_rx_setmem ());
    DONE;
  }
)

(define_insn "rx_setmem"
  [(set (mem:BLK (reg:SI 1))
	(unspec_volatile:BLK [(reg:SI 1) (reg:SI 2) (reg:SI 3)] UNSPEC_SETMEM))
   (clobber (reg:SI 1))
   (clobber (reg:SI 3))]
  "rx_allow_string_insns"
  "sstr.b"
  [(set_attr "length" "2")
   (set_attr "timings" "1111")] ;; The timing is a guesstimate.
)

(define_expand "cmpstrnsi"
  [(set (match_operand:SI                       0 "register_operand")   ;; Result
	(unspec_volatile:SI [(match_operand:BLK 1 "memory_operand")     ;; String1
			     (match_operand:BLK 2 "memory_operand")]    ;; String2
			    UNSPEC_CMPSTRN))
   (use (match_operand:SI                       3 "nonmemory_operand"))  ;; Max Length
   (match_operand:SI                            4 "immediate_operand")] ;; Known Align
  "(rx_allow_string_insns && (!optimize_size))"
  {
    bool const_len = CONST_INT_P(operands[3]);
    if (const_len)
    {
      if (INTVAL(operands[3]) == 0)
      {
        emit_move_insn (operands[0], GEN_INT(0));
        DONE;
      }
    }

    rtx str1 = gen_rtx_REG (SImode, 1);
    rtx str2 = gen_rtx_REG (SImode, 2);
    rtx len  = gen_rtx_REG (SImode, 3);

    emit_move_insn (str1, force_operand (XEXP (operands[1], 0), NULL_RTX));
    emit_move_insn (str2, force_operand (XEXP (operands[2], 0), NULL_RTX));
    emit_move_insn (len, force_operand (operands[3], NULL_RTX));

    /* Set flags in case len is zero */
    if (!const_len) {
      emit_insn (gen_setpsw (GEN_INT('C')));
      emit_insn (gen_setpsw (GEN_INT('Z')));
    }

    emit_insn (gen_rx_cmpstrn (operands[0], operands[1], operands[2]));
    DONE;
  }
)

(define_expand "cmpstrsi"
  [(set (match_operand:SI                       0 "register_operand")   ;; Result
	(unspec_volatile:SI [(match_operand:BLK 1 "memory_operand")     ;; String1
			     (match_operand:BLK 2 "memory_operand")]    ;; String2
			    UNSPEC_CMPSTRN))
   (match_operand:SI                            3 "immediate_operand")] ;; Known Align
  "(rx_allow_string_insns && (!optimize_size))"
  {
    rtx str1 = gen_rtx_REG (SImode, 1);
    rtx str2 = gen_rtx_REG (SImode, 2);
    rtx len  = gen_rtx_REG (SImode, 3);

    emit_move_insn (str1, force_reg (SImode, XEXP (operands[1], 0)));
    emit_move_insn (str2, force_reg (SImode, XEXP (operands[2], 0)));
    emit_move_insn (len, GEN_INT (-1));

    emit_insn (gen_rx_cmpstrn (operands[0], operands[1], operands[2]));
    DONE;
  }
)

(define_insn "rx_cmpstrn"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(reg:SI 1) (reg:SI 2) (reg:SI 3)]
			    UNSPEC_CMPSTRN))
   (use (match_operand:BLK 1 "memory_operand" "m"))
   (use (match_operand:BLK 2 "memory_operand" "m"))
   (clobber (reg:SI 1))
   (clobber (reg:SI 2))
   (clobber (reg:SI 3))
   (clobber (reg:CC CC_REG))]
  "rx_allow_string_insns"
  "scmpu		; Perform the string comparison
   mov     #-1, %0      ; Set up -1 result (which cannot be created
                        ; by the SC insn)
   bnc	   ?+		; If Carry is not set skip over
   scne.L  %0		; Set result based on Z flag
?:
"
  [(set_attr "length" "9")
   (set_attr "timings" "1111") ;; The timing is a guesstimate.
   (set_attr "insn_group"  "ISNG")]
)

;;   Builtin Functions
;;
;; GCC does not have the ability to generate the following instructions
;; on its own so they are provided as builtins instead.  To use them from
;; a program for example invoke them as __builtin_rx_<insn_name>.  For
;; example:
;;
;;    int short_byte_swap (int arg) { return __builtin_rx_revw (arg); }

(define_insn "save"
  [(unspec_volatile:SI [(match_operand:SI 0 "general_operand" "ri")]
           UNSPEC_BUILTIN_SAVE)]
  "TARGET_RXV3"
  "save\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "rstr"
  [(unspec_volatile:SI [(match_operand:SI 0 "general_operand" "ri")]
           UNSPEC_BUILTIN_RSTR)]
  "TARGET_RXV3"
  "rstr\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "mvfdc"
  [(set (match_operand:SI 0 "register_operand" "=r")
		(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
        UNSPEC_BUILTIN_MVFDC)
	)]
  "TARGET_RXV3"
  "mvfdc\t%D1, %0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

;;TODO: write a proper pattern for this and if GCC doesn't select it we might write some peepholes, same for bfmovz
(define_insn "bfmov"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_dup 0)
		(match_operand:SI 1 "register_operand" "r")
		(match_operand:SI 2 "immediate_operand" "Uint05")
		(match_operand:SI 3 "immediate_operand" "Uint05")
		(match_operand:SI 4 "immediate_operand" "Uintz5")]
		UNSPEC_BUILTIN_BFMOV))
  ]
  "TARGET_RXV3"
  "bfmov\t%2, %3, %4, %1, %0"
  [(set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)


(define_insn "bfmovz"
 [(set (match_operand:SI 0 "register_operand" "=r")
		(unspec_volatile:SI [(match_operand:SI 1 "register_operand" "r")
					(match_operand:SI 2 "immediate_operand" "Uint05")
					(match_operand:SI 3 "immediate_operand" "Uint05")
					(match_operand:SI 4 "immediate_operand" "Uintz5")]
					UNSPEC_BUILTIN_BFMOVZ))]
  "TARGET_RXV3"
  "bfmovz\t%2, %3, %4, %1, %0"
  [(set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "mvtdc"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")
         (match_operand:SI 1 "nonmemory_operand" "r")]
        UNSPEC_BUILTIN_MVTDC)]
  ""
  "mvtdc\t%1, %D0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "mvfdr"
  [(unspec_volatile [(const_int 0)]
        UNSPEC_BUILTIN_MVFDR)]
  ""
  "mvfdr"
  [(set_attr "length" "1")
   (set_attr "timings" "66")
   (set_attr "insn_group"  "ISNG")]
)
;;---------- Accumulator Support ------------------------

;;Extended MULtiply to Accumulator
(define_insn "emula_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_EMULA_A0)]
  ""
  "emula\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "emula_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_EMULA_A1)]
  ""
  "emula\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "emaca_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_EMACA_A0)]
  ""
  "emaca\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "emaca_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_EMACA_A1)]
  ""
  "emaca\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "emsba_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_EMSBA_A0)]
  ""
  "emsba\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "emsba_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_EMSBA_A1)]
  ""
  "emsba\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply-ACcumulate Low-order word and High-order word
(define_insn "maclh_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MACLH_A0)]
  ""
  "maclh\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "maclh_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MACLH_A1)]
  ""
  "maclh\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply & Accumulate (high)
;; A0 is implicit here for RXV2
(define_insn "machi"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MACHI)]
  ""
  "machi\t%0, %1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "machi_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MACHI_A1)]
  ""
  "machi\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply & Accumulate (low)
;; A0 is implicit here for RXV2
(define_insn "maclo"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MACLO)]
  ""
  "maclo\t%0, %1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "maclo_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MACLO_A1)]
  ""
  "maclo\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply Low-order word and High-order word
(define_insn "mullh_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MULLH_A0)]
  ""
  "mullh\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mullh_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MULLH_A1)]
  ""
  "mullh\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply (high)
;; A0 is implicit here for RXV2
(define_insn "mulhi"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MULHI)]
  ""
  "mulhi\t%0, %1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mulhi_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MULHI_A1)]
  ""
  "mulhi\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply (low)
;; A0 is implicit here for RXV2
(define_insn "mullo"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MULLO)]
  ""
  "mullo\t%0, %1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mullo_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MULLO_A1)]
  ""
  "mullo\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Multiply-SuBtract Low-order word and High-order word
(define_insn "msblh_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MSBLH_A0)]
  ""
  "msblh\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "msblh_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MSBLH_A1)]
  ""
  "msblh\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "msbhi_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MSBHI_A0)]
  ""
  "msbhi\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "msbhi_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MSBHI_A1)]
  ""
  "msbhi\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "msblo_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MSBLO_A0)]
  ""
  "msblo\t%0, %1, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "msblo_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")
	       (match_operand:SI 1 "register_operand" "r")]
	      UNSPEC_BUILTIN_MSBLO_A1)]
  ""
  "msblo\t%0, %1, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)


;; Move from Accumulator (high)
;; A0 is implicit here for RXV2
(define_insn "mvfachi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(const_int 0)]
		   UNSPEC_BUILTIN_MVFACHI))]
  ""
  "mvfachi\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfachi_A0"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACHI_A0))]
  ""
  "mvfachi\t%1, A0, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfachi_A1"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACHI_A1))]
  ""
  "mvfachi\t%1, A1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Move from Accumulator (middle)
;; A0 is implicit here for RXV2
(define_insn "mvfacmi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(const_int 0)]
		   UNSPEC_BUILTIN_MVFACMI))]
  ""
  "mvfacmi\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfacmi_A0"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACMI_A0))]
  ""
  "mvfacmi\t%1, A0, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfacmi_A1"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACMI_A1))]
  ""
  "mvfacmi\t%1, A1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfaclo_A0"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACLO_A0))]
  ""
  "mvfaclo\t%1, A0, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfaclo_A1"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACLO_A1))]
  ""
  "mvfaclo\t%1, A1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfacgu_A0"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACGU_A0))]
  ""
  "mvfacgu\t%1, A0, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvfacgu_A1"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFACGU_A1))]
  ""
  "mvfacgu\t%1, A1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Move to Accumulator (high)
;; A0 is implicit here for RXV2
(define_insn "mvtachi"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")]
		       UNSPEC_BUILTIN_MVTACHI)]
  ""
  "mvtachi\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvtachi_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")]
		       UNSPEC_BUILTIN_MVTACHI_A1)]
  ""
  "mvtachi\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Move to Accumulator (low)
;; A0 is implicit here for RXV2
(define_insn "mvtaclo"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")]
		       UNSPEC_BUILTIN_MVTACLO)]
  ""
  "mvtaclo\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvtaclo_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")]
		       UNSPEC_BUILTIN_MVTACLO_A1)]
  ""
  "mvtaclo\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvtacgu_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")]
		       UNSPEC_BUILTIN_MVTACGU_A0)]
  ""
  "mvtacgu\t%0, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "mvtacgu_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "register_operand" "r")]
		       UNSPEC_BUILTIN_MVTACGU_A1)]
  ""
  "mvtacgu\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Round Accumulator
(define_insn "rdacw_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RDACW_A0)]
  ""
  "rdacw\t%0, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "rdacw_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RDACW_A1)]
  ""
  "rdacw\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "rdacl_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RDACL_A0)]
  ""
  "rdacl\t%0, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "rdacl_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RDACL_A1)]
  ""
  "rdacl\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; A0 is implicit here for RXV2
(define_insn "racw"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RACW)]
  ""
  "racw\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "racw_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RACW_A1)]
  ""
  "racw\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "racl_A0"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RACL_A0)]
  ""
  "racl\t%0, A0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

(define_insn "racl_A1"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_RACL_A1)]
  ""
  "racl\t%0, A1"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IML")]
)

;; Repeat multiply and accumulate

(define_insn "rmpa"
  [(unspec:SI [(const_int 0) (reg:SI 1) (reg:SI 2) (reg:SI 3)
	       (reg:SI 4) (reg:SI 5) (reg:SI 6)]
	      UNSPEC_BUILTIN_RMPA)
  (clobber (reg:SI 1))
  (clobber (reg:SI 2))
  (clobber (reg:SI 3))]
  "rx_allow_string_insns"
  "rmpa"
  [(set_attr "length" "2")
   (set_attr "timings" "1010")]
)


(define_insn "rmpa8"
  [(set (match_operand:DI 3 "register_operand" "=r") (unspec_volatile:DI [ (match_operand:SI 0 "register_operand" "+r") (match_operand:SI 1 "register_operand" "+r") (match_operand: SI 2 "register_operand" "+r")
	       (match_dup 3)(match_operand:SI 4 "register_operand" "r")]
	      UNSPEC_BUILTIN_RMPA8))
  (clobber (reg:SI 1))
  (clobber (reg:SI 2))
  (clobber (reg:SI 3))
  (clobber (reg:SI 4))
  (clobber (reg:SI 5))
  (clobber (reg:SI 6))]
  "rx_allow_string_insns"
  "rmpa.B"
  [(set_attr "length" "2")
   (set_attr "timings" "1010")
   (set_attr "insn_group"  "ISNG")]
)


(define_insn "rmpa16"
  [(set (match_operand:DI 3 "register_operand" "=r") (unspec_volatile:DI [ (match_operand:SI 0 "register_operand" "+r") (match_operand:SI 1 "register_operand" "+r") (match_operand: SI 2 "register_operand" "+r")
	       (match_dup 3)(match_operand:SI 4 "register_operand" "r")]
	      UNSPEC_BUILTIN_RMPA16))
  (clobber (reg:SI 1))
  (clobber (reg:SI 2))
  (clobber (reg:SI 3))
  (clobber (reg:SI 4))
  (clobber (reg:SI 5))
  (clobber (reg:SI 6))]
  "rx_allow_string_insns"
  "rmpa.W"
  [(set_attr "length" "2")
   (set_attr "timings" "1010")
   (set_attr "insn_group"  "ISNG")]
)

(define_insn "rmpa32"
  [(set (match_operand:DI 3 "register_operand" "=r") (unspec_volatile:DI [ (match_operand:SI 0 "register_operand" "+r") (match_operand:SI 1 "register_operand" "+r") (match_operand: SI 2 "register_operand" "+r")
	       (match_dup 3) (match_operand:SI 4 "register_operand" "r")]
	      UNSPEC_BUILTIN_RMPA32))
  (clobber (reg:SI 1))
  (clobber (reg:SI 2))
  (clobber (reg:SI 3))
  (clobber (reg:SI 4))
  (clobber (reg:SI 5))
  (clobber (reg:SI 6))]
  "rx_allow_string_insns"
  "rmpa.L"
  [(set_attr "length" "2")
   (set_attr "timings" "1010")
   (set_attr "insn_group"  "ISNG")]
)

;;---------- Arithmetic ------------------------

;; Byte swap (two 16-bit values).
(define_insn "revw"
  [(set (match_operand:SI             0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"  "r")]
		   UNSPEC_BUILTIN_REVW))]
  ""
  "revw\t%1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "IEP")]
)

;; Round to integer.
(define_insn "lrintsf2"
  [(set (match_operand:SI             0 "register_operand"  "=r,r")
	(unspec:SI [(match_operand:SF 1 "rx_compare_operand" "r,Q")]
		   UNSPEC_BUILTIN_ROUND))
   (clobber (reg:CC CC_REG))]
  ""
  "round\t%1, %0"
  [(set_attr "timings" "22,44")
   (set_attr "length" "3,5")
   (set_attr "insn_group"  "IFE,ISNG")]
)

(define_insn "lrintdf2"
  [(set (match_operand:SI             0 "register_operand" "=r")
        (unspec:SI [(match_operand:DF  1 "register_operand" "DFPUreg")]
			UNSPEC_BUILTIN_DROUND)
	)
   (clobber (match_scratch:DF 2                     "=&DFPUreg"))
  ]
  "flag_dfpu"
  "dround\t%1, %2\n\tdmov.L\t%L2, %0"
  [(set_attr "timings" "22")
   (set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)
;;---------- Control Registers ------------------------

;; Clear Processor Status Word
(define_insn "clrpsw"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
	      UNSPEC_BUILTIN_CLRPSW)
   (clobber (reg:CC CC_REG))]
  ""
  "clrpsw\t%F0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

;; Set Processor Status Word
(define_insn "setpsw"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
	      UNSPEC_BUILTIN_SETPSW)
   (clobber (reg:CC CC_REG))]
  ""
  "setpsw\t%F0"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

;; Move from control register
(define_insn "mvfc"
  [(set (match_operand:SI             0 "register_operand" "=r")
	(unspec_volatile:SI [(match_operand:SI 1 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFC))]
  ""
  "mvfc\t%C1, %0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

;; Move to control register
;; This insn can be used in atomic sequences to restore the previous PSW
;; and re-enable interrupts.  Because of that it always clobbers the CC_REG.
(define_insn "mvtc"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i,i")
	       (match_operand:SI 1 "nonmemory_operand" "r,i")]
	      UNSPEC_BUILTIN_MVTC)
   (clobber (reg:CC CC_REG))]
  ""
  "mvtc\t%1, %C0"
  [(set_attr "length" "3,7")
   (set_attr "insn_group"  "ISNG,ISNG")]
  ;; Ignore possible clobbering of the comparison flags in the
  ;; PSW register.  This is a cc0 target so any cc0 setting
  ;; instruction will always be paired with a cc0 user, without
  ;; the possibility of this instruction being placed in between
  ;; them.
)

;; Move to interrupt priority level
(define_insn "mvtipl"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "Uint04")]
	      UNSPEC_BUILTIN_MVTIPL)]
  ""
  "mvtipl\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

;;---------- Interrupts ------------------------

;; Break
(define_insn "brk"
  [(unspec_volatile [(const_int 0)]
		    UNSPEC_BUILTIN_BRK)]
  ""
  "brk"
  [(set_attr "length" "1")
   (set_attr "timings" "66")
   (set_attr "insn_group"  "ISNG")]
)

;; Interrupt
(define_insn "int"
  [(unspec_volatile:SI [(match_operand:SI 0 "immediate_operand" "i")]
		       UNSPEC_BUILTIN_INT)]
  ""
  "int\t%0"
  [(set_attr "length" "3")
   (set_attr "insn_group"  "ISNG")]
)

;; Wait
(define_insn "wait"
  [(unspec_volatile [(const_int 0)]
		    UNSPEC_BUILTIN_WAIT)]
  ""
  "wait"
  [(set_attr "length" "2")
   (set_attr "insn_group"  "ISNG")]
)

;;---------- CoProcessor Support ------------------------

;; FIXME: The instructions are currently commented out because
;; the bit patterns have not been finalized, so the assembler
;; does not support them.  Once they are decided and the assembler
;; supports them, enable the instructions here.

;; Move from co-processor register
(define_insn "mvfcp"
  [(set (match_operand:SI             0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "immediate_operand" "i")
		    (match_operand:SI 2 "immediate_operand" "i")]
		   UNSPEC_BUILTIN_MVFCP))]
  ""
  "; mvfcp\t%1, %0, %2"
  [(set_attr "length" "5")
   (set_attr "insn_group"  "ISNG")]
)

;;---------- Misc ------------------------

;; Required by cfglayout.c...
(define_insn "nop"
  [(const_int 0)]
  ""
  "nop"
  [(set_attr "length" "1")
   (set_attr "insn_group"  "IEX")]
)

(define_expand "pid_addr"
  [(plus:SI (match_operand:SI 0)
	    (const:SI (unspec:SI [(match_operand:SI 1)] UNSPEC_PID_ADDR)))]
  ""
  ""
)


(define_insn "movdi"
  [(set (match_operand:DI 0 "nonimmediate_operand" "=rm")
        (match_operand:DI 1 "general_operand"      "rmi"))]
  "TARGET_ENABLE_LRA"
  { return rx_gen_move_template (operands, false); }
  [(set_attr "length" "16")
   (set_attr "timings" "22")]
)

(define_insn "exchange<register_modes:mode>"
  [(unspec_volatile:SI [(match_operand:register_modes 0 "register_operand" "+r,r")
		(match_operand:register_modes 1 "general_operand"  "+r,Q")]
		   UNSPEC_BUILTIN_XCHG)]
  ""
  "xchg\t%Q1, %0"
  [(set_attr "length" "3,6")
   (set_attr "timings" "22")
   (set_attr "insn_group"  "ISNG, ISNG")]
)

;;====BCLR peepholes====

;; mov.L #-2, ra
;; rotl rb, ra
;; and [rc].B, ra
;; mov.b ra [rc]
;; convert to:
;; bclr rb, [rc].B
(define_peephole2
[(set (match_operand:SI 0 "register_operand" "")
		(const_int -2))
 (parallel [(set (match_dup 0)
				(rotate:SI (match_dup 0)
					(match_operand:SI 1 "register_operand" "")))
	(clobber (reg:CC CC_REG))])
 (set (match_operand:SI 2 "register_operand" "")
 	(sign_extend:SI (match_operand:QI 3 "rx_restricted_mem_operand" "")))
 (parallel [(set (match_dup 0)
				(and:SI (match_dup 0)
					(match_dup 2)))
	(clobber (reg:CC CC_REG))])
 (set (match_dup 3) (match_operand:QI 4 "register_operand" ""))]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && MEM_P(operands[3]) && REG_P(operands[4]) && (REGNO (operands[0]) == REGNO (operands[4])) && peep2_regno_dead_p (5, REGNO (operands[0])) && peep2_regno_dead_p (5, REGNO (operands[2]))"
[(set (match_dup 3)
	(and:QI (not:QI (ashift:QI (const_int 1)
			   (match_dup 1)))
		(match_dup 3)))]
)

;; the only difference to the above peephole is the order of the operands in the and
(define_peephole2
[(set (match_operand:SI 0 "register_operand" "")
		(const_int -2))
 (parallel [(set (match_dup 0)
				(rotate:SI (match_dup 0)
					(match_operand:SI 1 "register_operand" "")))
	(clobber (reg:CC CC_REG))])
 (set (match_operand:SI 2 "register_operand" "")
 	(sign_extend:SI (match_operand:QI 3 "rx_restricted_mem_operand" "")))
 (parallel [(set (match_dup 0)
				(and:SI (match_dup 2)
					(match_dup 0)))
	(clobber (reg:CC CC_REG))])
 (set (match_dup 3) (match_operand:QI 4 "register_operand" ""))]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && MEM_P(operands[3]) && REG_P(operands[4]) && (REGNO (operands[0]) == REGNO (operands[4])) && peep2_regno_dead_p (5, REGNO (operands[0])) && peep2_regno_dead_p (5, REGNO (operands[2]))"
[(set (match_dup 3)
	(and:QI (not:QI (ashift:QI (const_int 1)
			   (match_dup 1)))
		(match_dup 3)))]
)

;; mov.L #-2, ra
;; rotl	rb, ra
;; and	ra, rc
;; convert to:
;; bclr rb, rc
(define_peephole2
[(set (match_operand:SI 0 "register_operand" "")
		(const_int -2))
 (parallel [(set (match_dup 0)
				(rotate:SI (match_dup 0)
					(match_operand:SI 1 "register_operand" "")))
	(clobber (reg:CC CC_REG))])
 (parallel [(set (match_operand:SI 2 "register_operand" "")
				(and:SI (match_dup 0)
					(match_dup 2)))
	(clobber (reg:CC CC_REG))])]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && peep2_regno_dead_p (3, REGNO (operands[0]))"
[(set (match_dup 2)
	(and:SI (not:SI (ashift:SI (const_int 1)
			   (match_dup 1)))
		(match_dup 2)))]
)

;; the only difference to the above peephole is the order of the operands in the and
(define_peephole2
[(set (match_operand:SI 0 "register_operand" "")
		(const_int -2))
 (parallel [(set (match_dup 0)
				(rotate:SI (match_dup 0)
					(match_operand:SI 1 "register_operand" "")))
	(clobber (reg:CC CC_REG))])
 (parallel [(set (match_operand:SI 2 "register_operand" "")
				(and:SI (match_dup 2)
					(match_dup 0)))
	(clobber (reg:CC CC_REG))])]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && peep2_regno_dead_p (3, REGNO (operands[0]))"
[(set (match_dup 2)
	(and:SI (not:SI (ashift:SI (const_int 1)
			   (match_dup 1)))
		(match_dup 2)))]
)

;; mov.b [ra], rb
;; and #imm, rb
;; mov.b rb [ra]
;; convert to:
;; bclr #imm, [ra].B
;;(define_peephole
;;[(set (match_operand:SI 0 "register_operand" "r")
;;		(sign_extend:SI (match_operand:QI 1 "rx_restricted_mem_operand" "Q")))
;; (parallel [(set (match_dup 0)
;;	(and:SI (match_dup 0)
;;		(match_operand:SI 2 "immediate_operand" "i")))
;;	(clobber (reg:CC CC_REG))])
;; (set (match_dup 1)
;; 	(match_operand:QI 3 "register_operand" "r"))]
;;"(REGNO (operands[0]) == REGNO (operands[3])) && (exact_log2 (0xFFFFFFFF & ~ ;;;;INTVAL (operands[2])) >= 0) &&
;;	dead_or_set_p (insn, operands[0])"
;;{
;;	operands[0] = gen_rtx_CONST_INT(QImode, exact_log2 (0xFFFFFFFF & ~ INTVAL ;;;;(operands[2])));
;;	return "bclr %0, %1.B";
;;}
;;)

;; and #imm, ra
;; convert to:
;; btst #imm, ra
;; or
;; bclr #imm, ra
(define_peephole
[(parallel [(set (match_operand:SI 0 "register_operand"  "r")
		(and:SI (match_operand:SI 1 "register_operand"  "r")
		(match_operand:SI 2 "immediate_operand" "i")))
             (clobber (reg:CC CC_REG))])]
;; "(exact_log2 (INTVAL (operands[2])) >= 0) && (exact_log2 (INTVAL (operands[2])) <= 31)"
"(REGNO (operands[0]) == REGNO (operands[1]))"
{
	rtx note;
	HOST_WIDE_INT val = INTVAL (operands[2]);

	/* check if dest reg is unused. only then we can replace the and with an btst
	otherwise we can replace it with an bclr see below  */
	for (note = REG_NOTES (insn); note; note = XEXP (note, 1))
	    if (REG_NOTE_KIND (note) == REG_UNUSED)
	    	if((exact_log2 (INTVAL (operands[2])) >= 0) &&
	    		(exact_log2 (INTVAL (operands[2])) <= 31) &&
	    		(REGNO (XEXP (note, 0)) == REGNO(operands[0])))
		    	{
					operands[2] = gen_rtx_CONST_INT(SImode, exact_log2 (INTVAL (operands[2])));
					return "btst %2, %0";
				}
			else if((REGNO (XEXP (note, 0)) == CC_REG) &&
						(exact_log2(0xFFFFFFFF & ~ val) >= 0) && (exact_log2(0xFFFFFFFF & ~ val) <= 31))
	    	{
				operands[2] = gen_rtx_CONST_INT(SImode, exact_log2(0xFFFFFFFF & ~ val));
				return "bclr %2, %0";
			}
	/* otherwise we don't do eny replacement  */
	return "and %2, %0";
}
)

;; mov.L #-2, ra
;; rotl	rb, ra
;; mov.W [rc], rd
;; and	ra, rd
;; convert to:
;; mov.W [rc], ra
;; bclr rb, ra
(define_peephole2
[(set (match_operand:SI 0 "register_operand"  "")
	(const_int -2))
 (parallel [(set (match_dup 0)
 				(rotate:SI (match_dup 0)
 					(match_operand:SI 1 "register_operand"  "")))
 			(clobber (reg:CC CC_REG))])
 (set (match_operand:SI 2 "register_operand"  "")
 	(sign_extend:SI (match_operand:HI 3 "memory_operand"  "")))
 (parallel [(set (match_dup 0)
 				(and:SI (match_dup 0)
 					(match_dup 2)))
 			(clobber (reg:CC CC_REG))])
]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && MEM_P(operands[3]) && peep2_regno_dead_p (4, REGNO (operands[2]))"
[(set (match_dup 0) (sign_extend:SI (match_dup 3)))
 (set (match_dup 0)
 		(and:SI (not:SI
		  	(ashift:SI
		    	(const_int 1)
		    	(match_dup 1)))
		    (match_dup 0)))]
)

;; the only difference to the above peephole is the order of the operands in the and
(define_peephole2
[(set (match_operand:SI 0 "register_operand"  "")
	(const_int -2))
 (parallel [(set (match_dup 0)
 				(rotate:SI (match_dup 0)
 					(match_operand:SI 1 "register_operand"  "")))
 			(clobber (reg:CC CC_REG))])
 (set (match_operand:SI 2 "register_operand"  "")
 	(sign_extend:SI (match_operand:HI 3 "memory_operand"  "")))
 (parallel [(set (match_dup 0)
 				(and:SI (match_dup 2)
 					(match_dup 0)))
 			(clobber (reg:CC CC_REG))])
]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && MEM_P(operands[3]) && peep2_regno_dead_p (4, REGNO (operands[2]))"
[(set (match_dup 0) (sign_extend:SI (match_dup 3)))
 (set (match_dup 0)
 		(and:SI (not:SI
		  	(ashift:SI
		    	(const_int 1)
		    	(match_dup 1)))
		    (match_dup 0)))]
)

;; mov.L #-2, ra
;; rotl	 rb, ra
;; and	[rd], ra
;; convert to:
;; mov.L [rd], ra
;; bclr rb, ra
(define_peephole2
[(set (match_operand:SI 0 "register_operand"  "")
	(const_int -2))
 (parallel [(set (match_dup 0)
 				(rotate:SI (match_dup 0)
 					(match_operand:SI 1 "register_operand"  "")))
 			(clobber (reg:CC CC_REG))])
 (parallel [(set (match_dup 0)
 				(and:SI (match_dup 0)
 					(match_operand:SI 2 "memory_operand"  "")))
 			(clobber (reg:CC CC_REG))])
]
"REG_P(operands[0]) && REG_P(operands[1]) && MEM_P(operands[2])"
[(set (match_dup 0) (match_dup 2))
 (set (match_dup 0)
 		(and:SI (not:SI
		  	(ashift:SI
		    	(const_int 1)
		    	(match_dup 1)))
		    (match_dup 0)))]
)

;; mov.L #-2, ra
;; rotl	 rb, ra
;; mov.L [rd], rc
;; and	rc, ra
;; convert to:
;; mov.L [rd], ra
;; bclr rb, ra
(define_peephole2
[(set (match_operand:SI 0 "register_operand"  "")
	(const_int -2))
 (parallel [(set (match_dup 0)
 				(rotate:SI (match_dup 0)
 					(match_operand:SI 1 "register_operand"  "")))
 			(clobber (reg:CC CC_REG))])
 (set (match_operand:SI 2 "register_operand"  "")
 		(match_operand:SI 3 "memory_operand"  ""))
 (parallel [(set (match_dup 0)
 				(and:SI (match_dup 2)
 					(match_dup 0)))
 			(clobber (reg:CC CC_REG))])
]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && MEM_P(operands[3]) && peep2_regno_dead_p (4, REGNO (operands[2]))"
[(set (match_dup 0) (match_dup 3))
 (set (match_dup 0)
 		(and:SI (not:SI
		  	(ashift:SI
		    	(const_int 1)
		    	(match_dup 1)))
		    (match_dup 0)))]
)

;; the only difference to the above peephole is the order of the operands in the and
(define_peephole2
[(set (match_operand:SI 0 "register_operand"  "")
	(const_int -2))
 (parallel [(set (match_dup 0)
 				(rotate:SI (match_dup 0)
 					(match_operand:SI 1 "register_operand"  "")))
 			(clobber (reg:CC CC_REG))])
 (set (match_operand:SI 2 "register_operand"  "")
 		(match_operand:SI 3 "memory_operand"  ""))
 (parallel [(set (match_dup 0)
 				(and:SI (match_dup 0)
 					(match_dup 2)))
 			(clobber (reg:CC CC_REG))])
]
"REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && MEM_P(operands[3]) && peep2_regno_dead_p (4, REGNO (operands[2]))"
[(set (match_dup 0) (match_dup 3))
 (set (match_dup 0)
 		(and:SI (not:SI
		  	(ashift:SI
		    	(const_int 1)
		    	(match_dup 1)))
		    (match_dup 0)))]
)

;;and to tst
(define_peephole2
  [(parallel [
      (set (reg:CC_ZS CC_REG)
           (compare:CC_ZS (and:SI (match_operand:SI 0 "register_operand" "")
                                  (match_operand:SI 1 "rx_speed_source_operand" ""))
                          (const_int 0)))
      (set (match_dup 0)
           (and:SI (match_dup 0)
                   (match_dup 1)))
    ])]
  "reload_completed && peep2_reg_dead_p (1, operands[0])"
  [(set (reg:CC_ZS CC_REG)
        (compare:CC_ZS (and:SI (match_dup 0)
                               (match_dup 1))
                       (const_int 0)))]
  ""
)

;;====BTST Peepholes====

;;convert tst #nr, ra to btst #;log2(nr), ra
(define_peephole2
 [(set (reg:CC_ZS CC_REG)
	(compare:CC_ZS
	  (and:SI (match_operand:SI 0 "register_operand"  "")
		  (match_operand:SI 1 "immediate_operand" ""))
	  (const_int 0)))]
 "REG_P(operands[0]) && (!REG_P(operands[1]) && !MEM_P(operands[1])) && (exact_log2 (INTVAL (operands[1])) >= 0) &&
 (operands[1] = gen_rtx_CONST_INT(QImode, exact_log2 (INTVAL (operands[1]))), 1)"
[(set (reg:CC_ZS CC_REG)
	(compare:CC_ZS
		(and:SI (match_dup 0)
		  (ashift:SI
		    (const_int 1)
		    (match_dup 1)))
	  (const_int 0)))]
 )

(define_peephole2
  [(parallel [(set (reg:CC_ZS CC_REG)
                   (compare:CC_ZS (and:SI (match_operand:SI 0 "register_operand" "")
                                          (match_operand:SI 1 "const_int_operand" ""))
                                  (const_int 0)))
              (set (match_operand:SI 2 "register_operand" "")
                   (and:SI (match_dup 0) (match_dup 1)))])
   (set (match_operand:SI 3 "register_operand" "")
        (if_then_else:SI (match_operator 6 "rx_z_comparison_operator"
                                         [(reg:CC_ZS CC_REG) (const_int 0)])
                         (match_operand:SI 4 "immediate_operand" "")
                         (match_operand:SI 5 "register_operand" "")))]
  "exact_log2 (INTVAL (operands[1])) >= 0 &&
    rtx_equal_p (operands[3], operands[5]) && INTVAL (operands[4]) == 0 &&
    ((GET_CODE (operands[6]) == EQ) || (GET_CODE (operands[6]) == NE))"
  [(set (reg:CC_ZS CC_REG)
        (compare:CC_ZS (and:SI (match_dup 3)
                              (ashift:SI (const_int 1)
                                         (match_operand:SI 7 "rx_speed_source_operand" "")))
                       (const_int 0)))
   (set (match_dup 3)
        (if_then_else:SI (match_operator 8 "rx_z_comparison_operator"
                                         [(reg:CC_ZS CC_REG) (const_int 0)])
                         (match_dup 3) (match_dup 4)))]
  {
    HOST_WIDE_INT mask = INTVAL (operands[1]);
    int pos = ctz_hwi (mask);
    operands[7] = GEN_INT (pos);
    /* Invert the condition: EQ -> NE, NE -> EQ */
    if (GET_CODE (operands[6]) == EQ)
      operands[8] = gen_rtx_NE (VOIDmode, operands[6], const0_rtx);
    else /* NE */
      operands[8] = gen_rtx_EQ (VOIDmode, operands[6], const0_rtx);
  }
)

(define_peephole2
  [(parallel [(set (reg:CC_ZS CC_REG)
                   (compare:CC_ZS (and:SI (match_operand:SI 0 "register_operand" "")
                                          (match_operand:SI 1 "const_int_operand" ""))
                                  (const_int 0)))
              (set (match_operand:SI 2 "register_operand" "")
                   (and:SI (match_dup 0) (match_dup 1)))])
   (set (match_operand:SI 3 "register_operand" "")
        (if_then_else:SI (match_operator 6 "rx_z_comparison_operator"
                                         [(reg:CC_ZS CC_REG) (const_int 0)])
                         (match_operand:SI 4 "immediate_operand" "")
                         (match_operand:SI 5 "register_operand" "")))]
  "rtx_equal_p (operands[3], operands[5]) && INTVAL (operands[4]) == 0 &&
   ((GET_CODE (operands[6]) == EQ) || (GET_CODE (operands[6]) == NE))"
  [(set (reg:CC_ZS CC_REG)
        (compare:CC_ZS (and:SI (match_dup 3) (match_dup 1)) (const_int 0)))
   (set (match_dup 3)
        (if_then_else:SI (match_operator 8 "rx_z_comparison_operator"
                                         [(reg:CC_ZS CC_REG) (const_int 0)])
                         (match_dup 3) (match_dup 4)))]
  {
    /* Invert the condition: EQ -> NE, NE -> EQ */
    if (GET_CODE (operands[6]) == EQ)
      operands[8] = gen_rtx_NE (VOIDmode, operands[6], const0_rtx);
    else /* NE */
      operands[8] = gen_rtx_EQ (VOIDmode, operands[6], const0_rtx);
  }
)

;;====XCHG Peepholes====

(define_peephole2
 [
 	(set (match_operand:SI 0 "register_operand"   "")
 		(match_operand:SI 1 "rx_compare_operand"   ""))
 	(set (match_dup 1)
 		(match_operand:SI 2 "register_operand"   ""))
 	(set (match_dup 2) (match_dup 0))
 ]
 "REG_P(operands[0]) && (REG_P(operands[1]) || MEM_P(operands[1])) && REG_P(operands[2]) && peep2_regno_dead_p (3, REGNO (operands[0]))"
 [(unspec_volatile:SI [(match_dup 2) (match_dup 1)] UNSPEC_BUILTIN_XCHG)]
)

(define_peephole2
 [
 	(set (match_operand:SI 0 "register_operand"   "")
 		(sign_extend:SI (match_operand:HI 1 "rx_compare_operand"   "")))
 	(set (match_dup 1)
 		(match_operand:HI 2 "register_operand"   ""))
 	(set (match_dup 2) (match_operand:HI 3 "register_operand"   ""))
 ]
 "REG_P(operands[0]) && (REG_P(operands[1]) || MEM_P(operands[1])) && REG_P(operands[2]) && (REGNO (operands[0]) == REGNO (operands[3])) && peep2_regno_dead_p (3, REGNO (operands[0]))"
 [(unspec_volatile:SI [(match_dup 2) (match_dup 1)] UNSPEC_BUILTIN_XCHG)]
)

(define_peephole2
 [
 	(set (match_operand:SI 0 "register_operand"   "")
 		(sign_extend:SI (match_operand:QI 1 "rx_compare_operand"   "")))
 	(set (match_dup 1)
 		(match_operand:QI 2 "register_operand"   ""))
 	(set (match_dup 2) (match_operand:QI 3 "register_operand"   ""))
 ]
 "REG_P(operands[0]) && (REG_P(operands[1]) || MEM_P(operands[1])) && REG_P(operands[2]) && (REGNO (operands[0]) == REGNO (operands[3])) && peep2_regno_dead_p (3, REGNO (operands[0]))"
 [(unspec_volatile:SI [(match_dup 2) (match_dup 1)] UNSPEC_BUILTIN_XCHG)]
)

;; mov.L [ra], rt
;; add rv, rt
;; mov.L rt, [ra]
;;   to:
;; add [ra], rv
;; mov.L rv, [ra]
(define_peephole2
  [(set (match_operand:SI 0 "register_operand" "")
        (mem:SI (match_operand:SI 1 "register_operand" "")))
   (parallel [(set (match_dup 0)
                   (plus:SI (match_dup 0)
                            (match_operand:SI 2 "register_operand" "")))
              (clobber (reg:CC CC_REG))])
   (set (mem:SI (match_dup 1))
        (match_dup 0))]
  "REG_P(operands[0]) && REG_P(operands[1]) && REG_P(operands[2]) && (REGNO(operands[0]) != REGNO(operands[2])) &&
   peep2_regno_dead_p(3, REGNO(operands[0])) && peep2_regno_dead_p(3, REGNO(operands[2]))"
  [(parallel [(set (match_dup 2)
                   (plus:SI (match_dup 2)
                            (mem:SI (match_dup 1))))
              (clobber (reg:CC CC_REG))])
   (set (mem:SI (match_dup 1))
        (match_dup 2))]
  ""
)
