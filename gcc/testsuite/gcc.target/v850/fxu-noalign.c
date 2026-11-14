/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

extern int g (int);

int
f (int x)
{
  return g (x) + 1;
}

/* { dg-final { scan-assembler-not {and r12,sp} } } */
/* { dg-final { scan-assembler-not {wr[0-9]} } } */
/* { dg-final { scan-assembler-not {mov sp,r29} } } */
