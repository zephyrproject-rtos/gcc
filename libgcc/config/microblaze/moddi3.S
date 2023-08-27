###################################
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
#  moddi3.S
# 
#  modulo operation for 32 bit integers.
#	Input :	op1 in Reg r5
#		op2 in Reg r6
#	Output: op1 mod op2 in Reg r3
# 
#######################################

#ifdef __arch64__
	.globl	__moddi3
	.ent	__moddi3
	.type	__moddi3,@function
__moddi3:
	.frame	r1,0,r15	

	addlik	r1,r1,-32
	sli	r28,r1,0
	sli	r29,r1,8
	sli	r30,r1,16
	sli	r31,r1,32

	BEALEQI	r6,$LaDiv_By_Zero       # Div_by_Zero   # Division Error
	BEALEQI	r5,$LaResult_Is_Zero    # Result is Zero 
	ADDL	r28,r5,r0               # Get the sign of the result [ Depends only on the first arg]
	BEALGEI	r5,$LaR5_Pos 
	RSUBLI	r5,r5,0	                # Make r5 positive
$LaR5_Pos:
	BEALGEI	r6,$LaR6_Pos
	RSUBLI	r6,r6,0	    # Make r6 positive
$LaR6_Pos:
	ADDLIK	r3,r0,0      # Clear mod
	ADDLIK	r30,r0,0     # clear div
	ADDLIK	r29,r0,64    # Initialize the loop count
	BEALLTI	r5,$LaDIV2   # If r5 is still negative (0x80000000), skip
			     # the first bit search.
   # First part try to find the first '1' in the r5
$LaDIV1:
	ADDL	r5,r5,r5         # left shift logical r5
	ADDLIK	r29,r29,-1
	BEALGEI	r5,$LaDIV1       #
$LaDIV2:
	ADDL	r5,r5,r5         # left shift logical  r5 get the '1' into the Carry
	ADDLC	r3,r3,r3         # Move that bit into the Mod register
	rSUBL	r31,r6,r3        # Try to subtract (r30 a r6)
	BEALLTi	r31,$LaMOD_TOO_SMALL
	ORL	r3,r0,r31       # Move the r31 to mod since the result was positive
	ADDLIK	r30,r30,1
$LaMOD_TOO_SMALL:
	ADDLIK	r29,r29,-1
	BEALEQi	r29,$LaLOOP_END
	ADDL	r30,r30,r30         # Shift in the '1' into div
	BREAI	$LaDIV2          # Div2
$LaLOOP_END:
	BEALGEI	r28,$LaRETURN_HERE
	rsubli	r3,r3,0 # Negate the result
	BREAI	$LaRETURN_HERE
$LaDiv_By_Zero:
$LaResult_Is_Zero:
	orl	r3,r0,r0        # set result to 0 [Both mod as well as div are 0]
$LaRETURN_HERE:
# Restore values of CSRs and that of r3 and the divisor and the dividend
	lli	r28,r1,0
	lli	r29,r1,8
	lli	r30,r1,16
	lli	r31,r1,24
	addlik	r1,r1,32
	rtsd	r15,8
        nop
        .end __moddi3
	.size	__moddi3, . - __moddi3
#endif
