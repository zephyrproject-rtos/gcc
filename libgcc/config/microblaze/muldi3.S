/*###################################-*-asm*- 
# 
#  Copyright (C) 2009-2017 Free Software Foundation, Inc.
#
#  Contributed by Michael Eager <eager@eagercon.com>.
#
#  This file is free software; you can redistribute it and/or modify it
#  under the terms of the GNU General Public License as published by the
#  Free Software Foundation; either version 3, or (at your option) any
#  later version.
#
#  GCC is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
#  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
#  License for more details.
#
#  Under Section 7 of GPL version 3, you are granted additional
#  permissions described in the GCC Runtime Library Exception, version
#  3.1, as published by the Free Software Foundation.
#
#  You should have received a copy of the GNU General Public License and
#  a copy of the GCC Runtime Library Exception along with this program;
#  see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
#  <http://www.gnu.org/licenses/>. 
# 
#  muldi3.S
# 
#  Multiply operation for 32 bit integers.
#	Input :	Operand1 in Reg r5
#		Operand2 in Reg r6
#	Output: Result [op1 * op2] in Reg r3
# 
#######################################*/

#ifdef __arch64__
	.globl	__muldi3
	.ent	__muldi3
	.type	__muldi3,@function
__muldi3:
	.frame	r1,0,r15
	addl	r3,r0,r0
	BEALEQI	r5,$L_Result_Is_Zero      # Multiply by Zero
	BEALEQI	r6,$L_Result_Is_Zero      # Multiply by Zero
	XORL	r4,r5,r6                  # Get the sign of the result
	BEALGEI	r5,$L_R5_Pos 
	RSUBLI	r5,r5,0	                  # Make r5 positive
$L_R5_Pos:
	BEALGEI	r6,$L_R6_Pos
	RSUBLI	r6,r6,0	                  # Make r6 positive
$L_R6_Pos:	
	breai	$L1
$L2:	
	addl	r5,r5,r5
$L1:	
	srll	r6,r6
	addlc	r7,r0,r0
	bealeqi	r7,$L2
	addl	r3,r3,r5	
	bealnei	r6,$L2
	beallti	r4,$L_NegateResult			
	rtsd	r15,8
	nop
$L_NegateResult:
	rsubl	r3,r3,r0
	rtsd	r15,8
	nop
$L_Result_Is_Zero:
	addli	r3,r0,0
	rtsd	r15,8
	nop
	.end __muldi3
	.size	__muldi3, . - __muldi3
#endif
