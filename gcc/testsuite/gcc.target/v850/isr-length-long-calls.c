/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -mlong-calls -O2 -dp" } */


extern void f (void);

void __attribute__ ((interrupt))
h (void)
{
  f ();
}

/* { dg-final { scan-assembler {l=40\]  save_interrupt\n} } } */
/* { dg-final { scan-assembler {l=108\]  save_all_interrupt\n} } } */
/* { dg-final { scan-assembler {l=108\]  restore_all_interrupt\n} } } */
/* { dg-final { scan-assembler {l=28\]  return_interrupt\n} } } */
