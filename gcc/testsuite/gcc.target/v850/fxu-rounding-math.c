/* { dg-do compile } */
/* { dg-options "-mfxu -O3 -frounding-math" } */


float a[64], b[64], r[64];

void
f (void)
{
  for (int i = 0; i < 64; i++)
    r[i] = a[i] + b[i];
}

/* { dg-final { scan-assembler-not "\\.s4 " } } */
/* { dg-final { scan-assembler "\\taddf\\.s " } } */
