/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));

vf g;

void
f (int n)
{
  vf t[n];
  t[0] = g;
  t[n - 1] = t[0];
  g = t[n / 2];
}

/* { dg-final { scan-assembler "\tmov sp,r11\n" } } */
/* { dg-final { scan-assembler "\tmov -16,r12 ; and r12,sp\n" } } */
/* { dg-final { scan-assembler "\tst.w r12,16\\\[r29\\\]\n" } } */
/* { dg-final { scan-assembler "\tld.w 16\\\[r29\\\],r12\n" } } */
/* { dg-final { scan-assembler "\tmov r12,sp\n" } } */
