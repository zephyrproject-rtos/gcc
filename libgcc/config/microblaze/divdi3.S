###################################-
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
#  divdi3.S
# 
#  Divide operation for 32 bit integers.
#	Input :	Dividend in Reg r5
#		Divisor in Reg r6
#	Output: Result in Reg r3
# 
#######################################

#ifdef __arch64__	
	.globl	__divdi3
	.ent	__divdi3
	.type	__divdi3,@function
__divdi3:
	.frame	r1,0,r15	

	ADDLIK   r1,r1,-32
	SLI     r28,r1,0
	SLI     r29,r1,8
	SLI     r30,r1,16
	SLI     r31,r1,24

	BEALEQI    r6,$LaDiv_By_Zero       # Div_by_Zero   # Division Error
	BEALEQI    r5,$LaResult_Is_Zero    # Result is Zero 
	XORL     r28,r5,r6               # Get the sign of the result
	BEALGEI   r5,$LaR5_Pos 
	RSUBLI   r5,r5,0                 # Make r5 positive
$LaR5_Pos:
	BEALGEI    r6,$LaR6_Pos
	RSUBLI   r6,r6,0                 # Make r6 positive
$LaR6_Pos:
	ADDLIK   r30,r0,0                # Clear mod
	ADDLIK   r3,r0,0                 # clear div
	ADDLIK   r29,r0,64               # Initialize the loop count

        # First part try to find the first '1' in the r5
$LaDIV0: 
        BEALLTI    r5,$LaDIV2              # This traps r5 == 0x80000000 
$LaDIV1:
	ADDL     r5,r5,r5                # left shift logical r5
	ADDLIK   r29,r29,-1
	BEALGTI   r5,$LaDIV1       
$LaDIV2:
	ADDL     r5,r5,r5                # left shift logical  r5 get the '1' into the Carry
	ADDLC    r30,r30,r30             # Move that bit into the Mod register
	RSUBL    r31,r6,r30              # Try to subtract (r30 a r6)
	BEALLTI    r31,$LaMOD_TOO_SMALL
	ORL      r30,r0,r31              # Move the r31 to mod since the result was positive
	ADDLIK   r3,r3,1
$LaMOD_TOO_SMALL:
	ADDLIK   r29,r29,-1
	BEALEQi    r29,$LaLOOP_END
	ADDL     r3,r3,r3                # Shift in the '1' into div
	BREAI     $LaDIV2                 # Div2
$LaLOOP_END:
	BEALGEI    r28,$LaRETURN_HERE
	RSUBLI   r3,r3,0                 # Negate the result
	BREAI    $LaRETURN_HERE
$LaDiv_By_Zero:
$LaResult_Is_Zero:
	ORL      r3,r0,r0 # set result to 0
$LaRETURN_HERE:
# Restore values of CSRs and that of r3 and the divisor and the dividend
	LLI     r28,r1,0
	LLI     r29,r1,8
	LLI     r30,r1,16
	LLI     r31,r1,24
	ADDLIK   r1,r1,32
	RTSD    r15,8
        nop
.end __divdi3
	.size	__divdi3, . - __divdi3
#endif
