/* { dg-do compile } */
/* { dg-options "-O2 -mfxu" } */


extern void gcall (void (*) (void));

int
f (void)
{
  __label__ out;
  void h (void) { goto out; }
  gcall (h);
  return 4;
 out:
  return 1;
}

/* { dg-final { scan-assembler {\tmov -16,r12 ; and r12,sp\n} } } */
/* { dg-final { scan-assembler {\tstv\.qw wr0, } } } */
