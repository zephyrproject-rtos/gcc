/* { dg-do compile } */
/* { dg-skip-if "tests the RH850 ABI" { *-*-* } { "-mgcc-abi" } { "" } } */

int t __attribute__ ((tda));	/* { dg-error "the 'tda' attribute is not supported with the RH850 ABI; use '-mgcc-abi'" } */
int z __attribute__ ((zda));
int s __attribute__ ((sda));
