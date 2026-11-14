/* { dg-do assemble } */
/* { dg-options "-mg4" } */

void
f (void)
{
  __asm__ volatile ("clip.b r1, r2");
}
