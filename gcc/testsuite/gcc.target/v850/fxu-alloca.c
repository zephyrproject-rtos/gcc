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
}				/* { dg-message "sorry, unimplemented" } */
