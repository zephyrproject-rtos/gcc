/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -mgcc-abi -mno-disable-callt -O2 -dp" } */


extern void f (void);

void __attribute__ ((interrupt))
h (void)
{
  f ();
}

/* { dg-final { scan-assembler {l=30\]  callt_save_interrupt\n} } } */
