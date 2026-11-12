/* { dg-do assemble } */
/* { dg-options "-mfxu" } */

void
f (void)
{
  __asm__ volatile ("addf.s4 wr1, wr2, wr3\n\tldv.qw 16[r6], wr4\n\tstsr fxsr, r10");
}
