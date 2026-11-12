/* { dg-do compile } */
/* { dg-options "-mtda=4" } */
/* { dg-skip-if "tests the RH850 ABI" { *-*-* } { "-mgcc-abi" } { "" } } */
/* { dg-error "'-mtda' is not supported with the RH850 ABI; use '-mgcc-abi'" "" { target *-*-* } 0 } */

int x;
