/* { dg-do compile } */
/* { dg-options "-mfxu -O2 -g -dA" } */

typedef float vf __attribute__ ((vector_size (16)));

vf
f (vf a, vf b)
{
  vf t = a * b;
  __asm__ ("" : "+w" (t));
  return t + a;
}

/* { dg-final { scan-assembler {\tmov -16,r12 ; and r12,sp\n} } } */
/* { dg-final { scan-assembler-not {DW_OP_breg12} } } */
