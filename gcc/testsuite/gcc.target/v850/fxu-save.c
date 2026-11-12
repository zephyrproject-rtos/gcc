/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

void
f (void)
{
  __asm__ volatile ("" ::: "wr5", "wr20");
}

/* { dg-final { scan-assembler {\tmov sp,r29\n} } } */
/* { dg-final { scan-assembler {\tmov -16,r12\n} } } */
/* { dg-final { scan-assembler {\tand r12,sp\n} } } */
/* { dg-final { scan-assembler {\tstv\.qw wr5, 0\[sp\]\n\tstv\.qw wr20, 16\[sp\]} } } */
/* { dg-final { scan-assembler {\tldv\.qw 0\[sp\], wr5\n\tldv\.qw 16\[sp\], wr20} } } */
/* { dg-final { scan-assembler {\tmov r29,sp\n} } } */
