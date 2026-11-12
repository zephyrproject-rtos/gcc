/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));

vf g1, g2;

#define A(n) vf a##n
void
f (A(0), A(1), A(2), A(3), A(4), A(5), A(6), A(7), A(8), A(9), A(10), A(11),
   A(12), A(13), A(14), A(15), A(16), A(17), A(18), A(19), A(20), A(21),
   A(22), A(23), A(24), A(25), A(26), A(27), A(28), A(29), A(30), A(31),
   A(32), int k)
{
  g1 = a31;
  g2 = a32;
}

/* { dg-final { scan-assembler {\tstv\.qw wr31, 0\[r[0-9]+\]} } } */
/* { dg-final { scan-assembler {\tldv\.dw 3, 0\[r[0-9]+\], wr[0-9]+} } } */
/* { dg-final { scan-assembler {\tldv\.dw 2, 0\[r[0-9]+\], wr[0-9]+} } } */
