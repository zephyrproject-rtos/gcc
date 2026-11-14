/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2 -dp" } */


extern void f (void);

void __attribute__ ((interrupt))
h (void)
{
  f ();
}

/* { dg-final { scan-assembler {l=16\]  save_interrupt\n} } } */
/* { dg-final { scan-assembler {l=4\]  save_all_interrupt\n} } } */
/* { dg-final { scan-assembler {l=4\]  restore_all_interrupt\n} } } */
/* { dg-final { scan-assembler {l=4\]  return_interrupt\n} } } */
