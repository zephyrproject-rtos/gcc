/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2" } */

volatile int cnt;
extern void f (void);

void __attribute__ ((interrupt ("FE"))) fe0 (void) { cnt++; }
void __attribute__ ((interrupt_handler ("FE"))) fe1 (void) { f (); }

/* { dg-final { scan-assembler-times {\tferet\n} 2 } } */
/* { dg-final { scan-assembler-not {eipc|eipsw|fepc|fepsw|eiret|\treti|__return_interrupt} } } */
