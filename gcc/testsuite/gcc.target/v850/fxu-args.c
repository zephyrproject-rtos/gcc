/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));

vf g;
int gi;

void
callee (vf a, int i, vf b)
{
  gi = i;
  g = b;
}

vf
ret (vf a, vf b)
{
  return b;
}

extern void ext (vf, int, vf);

void
caller (void)
{
  ext (g, 5, g);
}

/* { dg-final { scan-assembler {\tst\.w r6,0\[r[0-9]+\]} } } */
/* { dg-final { scan-assembler {\tstv\.qw wr1, 0\[r[0-9]+\]} } } */
/* { dg-final { scan-assembler {\tmov r6,r10\n(.*\n)*\tstv\.qw wr1, 0\[r6\]} } } */
/* { dg-final { scan-assembler {\tmov 5,r6} } } */
/* { dg-final { scan-assembler {\tmovv\.w4 wr[0-9]+, wr0|\tmovv\.w4 wr[0-9]+, wr1} } } */
