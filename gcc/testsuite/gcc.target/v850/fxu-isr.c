/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));

vf g, h;

void __attribute__ ((interrupt))
isr (void)
{
  vf t = g;
  __asm__ ("" : "+w" (t));
  h = t;
}				/* { dg-message "sorry, unimplemented" } */
