/* { dg-do compile } */
/* { dg-options "-mfxu -Os" } */

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

/* { dg-final { scan-assembler {\tldv\.qw 0\[r29\], wr0\n((\t|\.L)[^\n]*\n)*\tmov r12,sp\n} } } */
/* { dg-final { scan-assembler-not {\tmov r12,sp\n((\t|\.L)[^\n]*\n)*\tldv\.qw 0\[r29\], wr0\n} } } */
