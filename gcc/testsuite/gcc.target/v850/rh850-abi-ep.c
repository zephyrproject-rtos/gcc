/* { dg-do compile } */
/* { dg-options "-mep" } */
/* { dg-skip-if "tests the RH850 ABI" { *-*-* } { "-mgcc-abi" } { "" } } */
/* { dg-error "'-mep' is not supported with the RH850 ABI; use '-mgcc-abi'" "" { target *-*-* } 0 } */

int x;
