/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));

vf g;
extern void vext (int, ...);

void
call (void)
{
  vext (1, g);
}

/* { dg-final { scan-assembler-not {wr[0-9]} } } */
/* { dg-final { scan-assembler {\tst\.w r[0-9]+,(4|8|12|16)\[sp\]} } } */
