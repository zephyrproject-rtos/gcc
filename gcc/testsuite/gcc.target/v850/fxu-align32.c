/* { dg-do compile } */
/* { dg-options "-O2 -mfxu" } */


extern void g (char *);

void
f (void)
{
  char a[16] __attribute__ ((aligned (32)));
  g (a);
}

/* { dg-final { scan-assembler {\tmovea -32,r0,r12 ; and r12,sp\n} } } */
