/* { dg-do compile } */
/* { dg-options "-mfxu -O0" } */

typedef float vf __attribute__ ((vector_size (16)));

extern int g (vf);

int
f (void)
{
  return g ((vf) { 1.0f, 2.0f, 3.0f, 4.0f });
}

/* { dg-final { scan-assembler {and r12,sp\n} } } */
/* { dg-final { scan-assembler {\tstv\.qw wr0, [0-9]+\[sp\]} } } */
