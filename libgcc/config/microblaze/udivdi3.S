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
#  udivdi3.S
# 
#  Unsigned divide operation.
#	Input :	Divisor in Reg r5
#		Dividend in Reg r6
#	Output: Result in Reg r3
# 
#######################################
	
#ifdef __arch64__
	.globl	__udivdi3
	.ent	__udivdi3
	.type	__udivdi3,@function
__udivdi3:
	.frame	r1,0,r15	

	ADDlIK   r1,r1,-24
    	SLI     r29,r1,0
	SLI     r30,r1,8
	SLI     r31,r1,16

	BEALEQI    r6,$LaDiv_By_Zero           # Div_by_Zero   # Division Error
	ADDLIK   r30,r0,0                    # Clear mod
	BEALEQI   r5,$LaResult_Is_Zero        # Result is Zero 
	ADDLIK   r29,r0,64                   # Initialize the loop count

        # Check if r6 and r5 are equal # if yes, return 1
	RSUBL 	r18,r5,r6
	ADDLIK	r3,r0,1
	BEALEQI	r18,$LaRETURN_HERE

        # Check if (uns)r6 is greater than (uns)r5. In that case, just return 0
	XORL	r18,r5,r6
	ADDL	r3,r0,r0                    # We would anyways clear r3
	BEALGEI	r18,$LRSUBL
	BEALLTI	r6,$LaRETURN_HERE           # r6[bit 31 = 1] hence is greater
	BREAI	$LCheckr6
$LRSUBL:
	RSUBL	r18,r6,r5                   # MICROBLAZEcmp
	BEALLTI	r18,$LaRETURN_HERE

        # If r6 [bit 31] is set, then return result as 1
$LCheckr6:
	BEALGTI	r6,$LaDIV0
	ADDLIK	r3,r0,1
	BREAI	$LaRETURN_HERE

        # First part try to find the first '1' in the r5
$LaDIV0:
	BEALLTI    r5,$LaDIV2	
$LaDIV1:
	ADDL     r5,r5,r5                    # left shift logical r5
	ADDLIK   r29,r29,-1
	BEALGTI   r5,$LaDIV1       
$LaDIV2:
	ADDL     r5,r5,r5                    # left shift logical  r5 get the '1' into the Carry
	ADDLC    r30,r30,r30                 # Move that bit into the Mod register
	RSUBL    r31,r6,r30                  # Try to subtract (r30 a r6)
    	BEALLTI    r31,$LaMOD_TOO_SMALL
	ORL      r30,r0,r31                  # Move the r31 to mod since the result was positive
	ADDLIK   r3,r3,1
$LaMOD_TOO_SMALL:
	ADDLIK   r29,r29,-1
	BEALEQi    r29,$LaLOOP_END
	ADDL     r3,r3,r3 # Shift in the '1' into div
	BREAI     $LaDIV2   # Div2
$LaLOOP_END:
	BREAI     $LaRETURN_HERE
$LaDiv_By_Zero:
$LaResult_Is_Zero:
	ORL      r3,r0,r0 # set result to 0
$LaRETURN_HERE:
        # Restore values of CSRs and that of r3 and the divisor and the dividend
	LLI     r29,r1,0
	LLI     r30,r1,8
	LLI     r31,r1,16
	ADDLIK   r1,r1,24
	RTSD    r15,8
        NOP
        .end __udivdi3
	.size	__udivdi3, . - __udivdi3
#endif
