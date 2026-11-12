/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

#include <stdarg.h>

typedef float vf __attribute__ ((vector_size (16)));

vf
get (int n, ...)
{
  va_list ap;
  vf r;
  va_start (ap, n);
  r = va_arg (ap, vf);
  va_end (ap);
  return r;
}

/* { dg-final { scan-assembler {\tldv\.dw 3, [0-9]+\[r29\], wr[0-9]+\n\tldv\.dw 2, [0-9]+\[r29\], wr[0-9]+} } } */
/* { dg-final { scan-assembler {\tstv\.qw wr[0-9]+, 0\[r6\]} } } */
