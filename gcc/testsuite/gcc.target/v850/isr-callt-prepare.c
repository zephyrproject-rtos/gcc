/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -mgcc-abi -O2" } */

volatile int v;

void __attribute__ ((interrupt))
h (void)
{
  __asm__ volatile ("mov 5, r20" ::: "r20");
  v++;
}

/* { dg-final { scan-assembler {\tprepare \{r20\}, 0\n} } } */
/* { dg-final { scan-assembler-not {__callt_save_r20_r29} } } */
/* { dg-final { scan-assembler-not {st\.w r1, *24\[sp\]} } } */
