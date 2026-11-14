/* { dg-do compile } */
/* { dg-options "-mgcc-abi -O2" } */

extern int i __attribute__ ((zda));

int li (void) { return i; }
void si (int v) { i = v; }

/* { dg-final { scan-assembler {ld\.w zdaoff\(_i\)\[r0\]} } } */
/* { dg-final { scan-assembler {st\.w r[0-9]+,zdaoff\(_i\)\[r0\]} } } */
