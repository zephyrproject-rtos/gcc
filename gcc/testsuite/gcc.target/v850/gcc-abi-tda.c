/* { dg-do compile } */
/* { dg-options "-mgcc-abi -mep -mtda=4" } */

int t __attribute__ ((tda));
int f (void) { return t; }

/* { dg-final { scan-assembler {tdaoff\(_t\)} } } */
