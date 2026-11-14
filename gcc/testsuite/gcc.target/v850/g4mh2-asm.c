/* { dg-do assemble } */
/* { dg-options "-mg4mh2" } */

void
f (void)
{
  __asm__ volatile ("ldm.mp [r1], r2-r5\n\tstm.gsr [r6]\n\tclip.b r1, r2");
}
