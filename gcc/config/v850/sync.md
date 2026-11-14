;; Machine description for the V850 atomic operations.
;; Copyright The GNU Toolchain Authors.

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

(define_c_enum "unspecv" [
  UNSPECV_ATOMIC_CAS
  UNSPECV_ATOMIC_EXCHANGE
  UNSPECV_ATOMIC_OP
  UNSPECV_ATOMIC_STORE
])

(define_code_iterator any_atomic [plus minus and ior xor])
(define_code_attr atomic_optab
  [(plus "add") (minus "sub") (and "and") (ior "or") (xor "xor")])

(define_expand "mem_thread_fence"
  [(match_operand:SI 0 "const_int_operand")]
  "TARGET_V850E3V5_UP"
{
  if (!is_mm_relaxed (memmodel_base (INTVAL (operands[0]))))
    {
      rtx mem = gen_rtx_MEM (BLKmode, gen_rtx_SCRATCH (Pmode));
      MEM_VOLATILE_P (mem) = 1;
      emit_insn (gen_v850_syncm (mem));
    }
  DONE;
})

(define_insn "v850_syncm"
  [(set (match_operand:BLK 0 "" "")
	(unspec:BLK [(match_dup 0)] UNSPEC_SYNCM))]
  "TARGET_V850E3V5_UP"
  "syncm"
  [(set_attr "length" "2")])

(define_expand "atomic_compare_and_swapsi"
  [(match_operand:SI 0 "register_operand")
   (match_operand:SI 1 "register_operand")
   (match_operand:SI 2 "memory_operand")
   (match_operand:SI 3 "register_operand")
   (match_operand:SI 4 "register_operand")
   (match_operand:SI 5 "const_int_operand")
   (match_operand:SI 6 "const_int_operand")
   (match_operand:SI 7 "const_int_operand")]
  "TARGET_V850E3V5_UP"
{
  rtx addr = force_reg (Pmode, XEXP (operands[2], 0));
  v850_atomic_fence (operands[6], true);
  emit_insn (gen_atomic_cas_value_strongsi (operands[1], addr,
					     operands[3], operands[4]));
  v850_atomic_fence (operands[6], false);
  emit_insn (gen_cstoresi4 (operands[0],
			    gen_rtx_EQ (SImode, operands[1], operands[3]),
			    operands[1], operands[3]));
  DONE;
})

(define_insn "atomic_cas_value_strongsi"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(mem:SI (match_operand:SI 1 "register_operand" "r")))
   (set (mem:SI (match_dup 1))
	(unspec_volatile:SI [(match_operand:SI 2 "register_operand" "r")
			     (match_operand:SI 3 "register_operand" "r")]
	 UNSPECV_ATOMIC_CAS))
   (clobber (match_scratch:SI 4 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_V850E3V5_UP"
{
  return "1:\;"
	 "ldl.w [%1],%0\;"
	 "cmp %2,%0\;"
	 "bne 2f\;"
	 "mov %3,%4\;"
	 "stc.w %4,[%1]\;"
	 "cmp r0,%4\;"
	 "be 1b\;"
	 "2:";
}
  [(set_attr "length" "18")])

(define_expand "atomic_exchangesi"
  [(match_operand:SI 0 "register_operand")
   (match_operand:SI 1 "memory_operand")
   (match_operand:SI 2 "register_operand")
   (match_operand:SI 3 "const_int_operand")]
  "TARGET_V850E3V5_UP"
{
  rtx addr = force_reg (Pmode, XEXP (operands[1], 0));
  v850_atomic_fence (operands[3], true);
  emit_insn (gen_atomic_exchangesi_insn (operands[0], addr, operands[2]));
  v850_atomic_fence (operands[3], false);
  DONE;
})

(define_insn "atomic_exchangesi_insn"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(mem:SI (match_operand:SI 1 "register_operand" "r")))
   (set (mem:SI (match_dup 1))
	(unspec_volatile:SI [(match_operand:SI 2 "register_operand" "r")]
	 UNSPECV_ATOMIC_EXCHANGE))
   (clobber (match_scratch:SI 3 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_V850E3V5_UP"
  "1:\;ldl.w [%1],%0\;mov %2,%3\;stc.w %3,[%1]\;cmp r0,%3\;be 1b"
  [(set_attr "length" "14")])

(define_expand "atomic_fetch_<atomic_optab>si"
  [(match_operand:SI 0 "register_operand")
   (any_atomic:SI (match_operand:SI 1 "memory_operand")
		  (match_operand:SI 2 "register_operand"))
   (match_operand:SI 3 "const_int_operand")]
  "TARGET_V850E3V5_UP"
{
  rtx addr = force_reg (Pmode, XEXP (operands[1], 0));
  v850_atomic_fence (operands[3], true);
  emit_insn (gen_atomic_fetch_<atomic_optab>si_insn (operands[0], addr,
						     operands[2]));
  v850_atomic_fence (operands[3], false);
  DONE;
})

(define_insn "atomic_fetch_<atomic_optab>si_insn"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(mem:SI (match_operand:SI 1 "register_operand" "r")))
   (set (mem:SI (match_dup 1))
	(unspec_volatile:SI
	  [(any_atomic:SI (mem:SI (match_dup 1))
			  (match_operand:SI 2 "register_operand" "r"))]
	 UNSPECV_ATOMIC_OP))
   (clobber (match_scratch:SI 3 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_V850E3V5_UP"
{
  return "1:\;"
	 "ldl.w [%1],%0\;"
	 "mov %0,%3\;"
	 "<atomic_optab> %2,%3\;"
	 "stc.w %3,[%1]\;"
	 "cmp r0,%3\;"
	 "be 1b";
}
  [(set_attr "length" "16")])

(define_expand "atomic_fetch_nandsi"
  [(match_operand:SI 0 "register_operand")
   (match_operand:SI 1 "memory_operand")
   (match_operand:SI 2 "register_operand")
   (match_operand:SI 3 "const_int_operand")]
  "TARGET_V850E3V5_UP"
{
  rtx addr = force_reg (Pmode, XEXP (operands[1], 0));
  v850_atomic_fence (operands[3], true);
  emit_insn (gen_atomic_fetch_nandsi_insn (operands[0], addr, operands[2]));
  v850_atomic_fence (operands[3], false);
  DONE;
})

(define_insn "atomic_fetch_nandsi_insn"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(mem:SI (match_operand:SI 1 "register_operand" "r")))
   (set (mem:SI (match_dup 1))
	(unspec_volatile:SI
	  [(not:SI (and:SI (mem:SI (match_dup 1))
			   (match_operand:SI 2 "register_operand" "r")))]
	 UNSPECV_ATOMIC_OP))
   (clobber (match_scratch:SI 3 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_V850E3V5_UP"
{
  return "1:\;"
	 "ldl.w [%1],%0\;"
	 "mov %0,%3\;"
	 "and %2,%3\;"
	 "not %3,%3\;"
	 "stc.w %3,[%1]\;"
	 "cmp r0,%3\;"
	 "be 1b";
}
  [(set_attr "length" "18")])

(define_expand "atomic_storesi"
  [(match_operand:SI 0 "memory_operand")
   (match_operand:SI 1 "register_operand")
   (match_operand:SI 2 "const_int_operand")]
  "TARGET_V850E3V5_UP"
{
  rtx addr = force_reg (Pmode, XEXP (operands[0], 0));
  v850_atomic_fence (operands[2], true);
  emit_insn (gen_atomic_storesi_insn (addr, operands[1]));
  if (is_mm_seq_cst (memmodel_base (INTVAL (operands[2]))))
    v850_atomic_fence (operands[2], false);
  DONE;
})

(define_insn "atomic_storesi_insn"
  [(set (mem:SI (match_operand:SI 0 "register_operand" "r"))
	(unspec_volatile:SI [(match_operand:SI 1 "register_operand" "r")]
	 UNSPECV_ATOMIC_STORE))
   (clobber (match_scratch:SI 2 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_V850E3V5_UP"
  "1:\;ldl.w [%0],%2\;mov %1,%2\;stc.w %2,[%0]\;cmp r0,%2\;be 1b"
  [(set_attr "length" "14")])

(define_mode_iterator SUBW [QI HI])
(define_mode_attr ldl_sfx [(QI "bu") (HI "hu")])
(define_mode_attr stc_sfx [(QI "b") (HI "h")])

(define_expand "atomic_compare_and_swap<mode>"
  [(match_operand:SI 0 "register_operand")
   (match_operand:SUBW 1 "register_operand")
   (match_operand:SUBW 2 "memory_operand")
   (match_operand:SUBW 3 "register_operand")
   (match_operand:SUBW 4 "register_operand")
   (match_operand:SI 5 "const_int_operand")
   (match_operand:SI 6 "const_int_operand")
   (match_operand:SI 7 "const_int_operand")]
  "TARGET_G4"
{
  rtx addr = force_reg (Pmode, XEXP (operands[2], 0));
  rtx expected = force_reg (SImode, convert_to_mode (SImode, operands[3], 1));
  rtx desired = force_reg (SImode, convert_to_mode (SImode, operands[4], 1));
  rtx old = gen_reg_rtx (SImode);

  v850_atomic_fence (operands[6], true);
  emit_insn (gen_atomic_cas_value_strong<mode> (old, addr, expected, desired));
  v850_atomic_fence (operands[6], false);
  emit_move_insn (operands[1], gen_lowpart (<MODE>mode, old));
  emit_insn (gen_cstoresi4 (operands[0],
			    gen_rtx_EQ (SImode, old, expected),
			    old, expected));
  DONE;
})

(define_insn "atomic_cas_value_strong<mode>"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(zero_extend:SI (mem:SUBW (match_operand:SI 1 "register_operand" "r"))))
   (set (mem:SUBW (match_dup 1))
	(unspec_volatile:SUBW [(match_operand:SI 2 "register_operand" "r")
			       (match_operand:SI 3 "register_operand" "r")]
	 UNSPECV_ATOMIC_CAS))
   (clobber (match_scratch:SI 4 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_G4"
{
  return "1:\;"
	 "ldl.<ldl_sfx> [%1],%0\;"
	 "cmp %2,%0\;"
	 "bne 2f\;"
	 "mov %3,%4\;"
	 "stc.<stc_sfx> %4,[%1]\;"
	 "cmp r0,%4\;"
	 "be 1b\;"
	 "2:";
}
  [(set_attr "length" "18")])

(define_expand "atomic_exchange<mode>"
  [(match_operand:SUBW 0 "register_operand")
   (match_operand:SUBW 1 "memory_operand")
   (match_operand:SUBW 2 "register_operand")
   (match_operand:SI 3 "const_int_operand")]
  "TARGET_G4"
{
  rtx addr = force_reg (Pmode, XEXP (operands[1], 0));
  rtx value = force_reg (SImode, convert_to_mode (SImode, operands[2], 1));
  rtx old = gen_reg_rtx (SImode);

  v850_atomic_fence (operands[3], true);
  emit_insn (gen_atomic_exchange<mode>_insn (old, addr, value));
  v850_atomic_fence (operands[3], false);
  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));
  DONE;
})

(define_insn "atomic_exchange<mode>_insn"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(zero_extend:SI (mem:SUBW (match_operand:SI 1 "register_operand" "r"))))
   (set (mem:SUBW (match_dup 1))
	(unspec_volatile:SUBW [(match_operand:SI 2 "register_operand" "r")]
	 UNSPECV_ATOMIC_EXCHANGE))
   (clobber (match_scratch:SI 3 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_G4"
{
  return "1:\;"
	 "ldl.<ldl_sfx> [%1],%0\;"
	 "mov %2,%3\;"
	 "stc.<stc_sfx> %3,[%1]\;"
	 "cmp r0,%3\;"
	 "be 1b";
}
  [(set_attr "length" "14")])

(define_expand "atomic_fetch_<atomic_optab><mode>"
  [(match_operand:SUBW 0 "register_operand")
   (any_atomic:SUBW (match_operand:SUBW 1 "memory_operand")
		    (match_operand:SUBW 2 "register_operand"))
   (match_operand:SI 3 "const_int_operand")]
  "TARGET_G4"
{
  rtx addr = force_reg (Pmode, XEXP (operands[1], 0));
  rtx value = force_reg (SImode, convert_to_mode (SImode, operands[2], 1));
  rtx old = gen_reg_rtx (SImode);

  v850_atomic_fence (operands[3], true);
  emit_insn (gen_atomic_fetch_<atomic_optab><mode>_insn (old, addr, value));
  v850_atomic_fence (operands[3], false);
  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));
  DONE;
})

(define_insn "atomic_fetch_<atomic_optab><mode>_insn"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(zero_extend:SI (mem:SUBW (match_operand:SI 1 "register_operand" "r"))))
   (set (mem:SUBW (match_dup 1))
	(unspec_volatile:SUBW
	  [(any_atomic:SI (zero_extend:SI (mem:SUBW (match_dup 1)))
			  (match_operand:SI 2 "register_operand" "r"))]
	 UNSPECV_ATOMIC_OP))
   (clobber (match_scratch:SI 3 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_G4"
{
  return "1:\;"
	 "ldl.<ldl_sfx> [%1],%0\;"
	 "mov %0,%3\;"
	 "<atomic_optab> %2,%3\;"
	 "stc.<stc_sfx> %3,[%1]\;"
	 "cmp r0,%3\;"
	 "be 1b";
}
  [(set_attr "length" "16")])

(define_expand "atomic_fetch_nand<mode>"
  [(match_operand:SUBW 0 "register_operand")
   (match_operand:SUBW 1 "memory_operand")
   (match_operand:SUBW 2 "register_operand")
   (match_operand:SI 3 "const_int_operand")]
  "TARGET_G4"
{
  rtx addr = force_reg (Pmode, XEXP (operands[1], 0));
  rtx value = force_reg (SImode, convert_to_mode (SImode, operands[2], 1));
  rtx old = gen_reg_rtx (SImode);

  v850_atomic_fence (operands[3], true);
  emit_insn (gen_atomic_fetch_nand<mode>_insn (old, addr, value));
  v850_atomic_fence (operands[3], false);
  emit_move_insn (operands[0], gen_lowpart (<MODE>mode, old));
  DONE;
})

(define_insn "atomic_fetch_nand<mode>_insn"
  [(set (match_operand:SI 0 "register_operand" "=&r")
	(zero_extend:SI (mem:SUBW (match_operand:SI 1 "register_operand" "r"))))
   (set (mem:SUBW (match_dup 1))
	(unspec_volatile:SUBW
	  [(not:SI (and:SI (zero_extend:SI (mem:SUBW (match_dup 1)))
			   (match_operand:SI 2 "register_operand" "r")))]
	 UNSPECV_ATOMIC_OP))
   (clobber (match_scratch:SI 3 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_G4"
{
  return "1:\;"
	 "ldl.<ldl_sfx> [%1],%0\;"
	 "mov %0,%3\;"
	 "and %2,%3\;"
	 "not %3,%3\;"
	 "stc.<stc_sfx> %3,[%1]\;"
	 "cmp r0,%3\;"
	 "be 1b";
}
  [(set_attr "length" "18")])

(define_expand "atomic_store<mode>"
  [(match_operand:SUBW 0 "memory_operand")
   (match_operand:SUBW 1 "register_operand")
   (match_operand:SI 2 "const_int_operand")]
  "TARGET_G4"
{
  rtx addr = force_reg (Pmode, XEXP (operands[0], 0));
  rtx value = force_reg (SImode, convert_to_mode (SImode, operands[1], 1));

  v850_atomic_fence (operands[2], true);
  emit_insn (gen_atomic_store<mode>_insn (addr, value));
  if (is_mm_seq_cst (memmodel_base (INTVAL (operands[2]))))
    v850_atomic_fence (operands[2], false);
  DONE;
})

(define_insn "atomic_store<mode>_insn"
  [(set (mem:SUBW (match_operand:SI 0 "register_operand" "r"))
	(unspec_volatile:SUBW [(match_operand:SI 1 "register_operand" "r")]
	 UNSPECV_ATOMIC_STORE))
   (clobber (match_scratch:SI 2 "=&r"))
   (clobber (reg:CC CC_REGNUM))]
  "TARGET_G4"
{
  return "1:\;"
	 "ldl.<ldl_sfx> [%0],%2\;"
	 "mov %1,%2\;"
	 "stc.<stc_sfx> %2,[%0]\;"
	 "cmp r0,%2\;"
	 "be 1b";
}
  [(set_attr "length" "14")])
