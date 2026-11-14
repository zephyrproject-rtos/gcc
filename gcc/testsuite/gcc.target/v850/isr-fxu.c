/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

volatile int cnt;
extern void f (void);

void __attribute__ ((interrupt)) calls (void) { f (); }
void __attribute__ ((interrupt)) plain (void) { cnt++; }

/* { dg-final { scan-assembler-times {stsr fxsr, r10} 1 } } */
/* { dg-final { scan-assembler-times {ldsr r10, fxsr} 1 } } */
