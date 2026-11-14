/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));

vf a[8], b[8];

void
f (void)
{
  vf t0 = a[0], t1 = a[1], t2 = a[2], t3 = a[3];
  vf t4 = a[4], t5 = a[5], t6 = a[6], t7 = a[7];
  __asm__ volatile ("" : "+w" (t0), "+w" (t1), "+w" (t2), "+w" (t3),
			 "+w" (t4), "+w" (t5), "+w" (t6), "+w" (t7));
  b[0] = t7; b[1] = t6; b[2] = t5; b[3] = t4;
  b[4] = t3; b[5] = t2; b[6] = t1; b[7] = t0;
}

/* { dg-final { scan-assembler {\twr7\M|wr7, } } } */
/* { dg-final { scan-assembler-not {wr8\M} } } */
