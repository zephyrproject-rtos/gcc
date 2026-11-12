/* { dg-do compile } */
/* { dg-options "-mfxu -O3" } */


float a[4] __attribute__ ((aligned (16)));
float b[4] __attribute__ ((aligned (16)));
float r[4] __attribute__ ((aligned (16)));

void
f (void)
{
  for (int i = 0; i < 4; i++)
    r[i] = a[i] + b[i];
}

/* { dg-final { scan-assembler-not "\\taddf\\.s4 " } } */
/* { dg-final { scan-assembler-not "\\tstv\\.qw wr" } } */
/* { dg-final { scan-assembler-times "\\taddf\\.s " 4 } } */
