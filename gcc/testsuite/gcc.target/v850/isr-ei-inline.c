/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2 -mno-prolog-function" } */

volatile int cnt;

void __attribute__ ((interrupt)) ei0 (void) { cnt++; }

/* { dg-final { scan-assembler {\teiret\n} } } */
/* { dg-final { scan-assembler-not {\treti|__return_interrupt} } } */
