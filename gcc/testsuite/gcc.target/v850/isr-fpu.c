/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2" } */
/* { dg-skip-if "tests the code without -mfxu" { *-*-* } { "-mfxu" } { "" } } */

volatile float fv;
volatile int cnt;
extern void f (void);

void __attribute__ ((interrupt)) uses_fpu (void) { fv = fv * 2.0f; }
void __attribute__ ((interrupt)) calls (void) { f (); }
void __attribute__ ((interrupt)) plain (void) { cnt++; }

/* { dg-final { scan-assembler-times {stsr fpsr, r10} 2 } } */
/* { dg-final { scan-assembler-times {stsr fpepc, r10} 2 } } */
/* { dg-final { scan-assembler-times {\tsynce\n\tdi\n} 2 } } */
/* { dg-final { scan-assembler-not {fxsr} } } */
