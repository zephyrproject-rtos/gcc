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
#  umoddi3.S
#
#  Unsigned modulo operation for 32 bit integers.
#	Input :	op1 in Reg r5
#		op2 in Reg r6
#	Output: op1 mod op2 in Reg r3
# 
#######################################
	
#ifdef __arch64__
	.globl	__umoddi3
	.ent	__umoddi3
	.type	__umoddi3,@function
__umoddi3:
	.frame	r1,0,r15	

	addlik	r1,r1,-24
	sli	r29,r1,0
	sli	r30,r1,8
	sli	r31,r1,16

	BEALEQI	r6,$LaDiv_By_Zero         # Div_by_Zero   # Division Error
	ADDLIK 	r3,r0,0                  # Clear div
	BEALEQI	r5,$LaResult_Is_Zero     # Result is Zero 
	ADDLIK 	r30,r0,0     	# clear mod
	ADDLIK 	r29,r0,64       # Initialize the loop count

# Check if r6 and r5 are equal # if yes, return 0
	rsubl 	r18,r5,r6
	bealeqi	r18,$LaRETURN_HERE

# Check if (uns)r6 is greater than (uns)r5. In that case, just return r5
	xorl	r18,r5,r6
	addlik	r3,r5,0
	bealgei	r18,$LRSUB
	beallti	r6,$LaRETURN_HERE
	breai	$LCheckr6
$LRSUB:
	rsubl	r18,r5,r6 # MICROBLAZEcmp
	bealgti	r18,$LaRETURN_HERE

# If r6 [bit 31] is set, then return result as r5-r6
$LCheckr6:
	addlik	r3,r0,0
	bealgti	r6,$LaDIV0
	addlik	r18,r0,0x7fffffff
	andl	r5,r5,r18
	andl 	r6,r6,r18
	breaid	$LaRETURN_HERE
	rsubl	r3,r6,r5
# First part: try to find the first '1' in the r5
$LaDIV0:
	BEALLTI	r5,$LaDIV2
$LaDIV1:
	ADDL 	r5,r5,r5     # left shift logical r5
	ADDLIK 	r29,r29,-1
	BEALGEI 	r5,$LaDIV1   #
$LaDIV2:
	ADDL 	r5,r5,r5     # left shift logical  r5 get the '1' into the Carry
	ADDLC 	r3,r3,r3     # Move that bit into the Mod register
	rSUBL 	r31,r6,r3    # Try to subtract (r3 a r6)
	BEALLTi 	r31,$LaMOD_TOO_SMALL
	ORL  	r3,r0,r31    # Move the r31 to mod since the result was positive
	ADDLIK 	r30,r30,1
$LaMOD_TOO_SMALL:
	ADDLIK 	r29,r29,-1
	BEALEQi 	r29,$LaLOOP_END
	ADDL 	r30,r30,r30 # Shift in the '1' into div
	BREAI 	$LaDIV2     # Div2
$LaLOOP_END:
	BREAI 	$LaRETURN_HERE
$LaDiv_By_Zero:
$LaResult_Is_Zero:
	orl 	r3,r0,r0   # set result to 0
$LaRETURN_HERE:
# Restore values of CSRs and that of r3 and the divisor and the dividend
	lli 	r29,r1,0
	lli 	r30,r1,8
	lli 	r31,r1,16
	addlik 	r1,r1,24
	rtsd 	r15,8
        nop
.end __umoddi3
	.size	__umoddi3, . - __umoddi3
#endif
