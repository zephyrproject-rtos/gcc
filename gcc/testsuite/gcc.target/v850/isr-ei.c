/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2" } */

volatile int cnt;

void __attribute__ ((interrupt)) ei0 (void) { cnt++; }
void __attribute__ ((interrupt_handler ("EI"))) ei1 (void) { cnt++; }

/* { dg-final { scan-assembler-times {stsr eipc, r10} 2 } } */
/* { dg-final { scan-assembler-times {stsr eipsw, r10} 2 } } */
/* { dg-final { scan-assembler-times {\tdi\n\tld\.w 4\[sp\], r10\n\tldsr r10, eipsw\n\tld\.w 0\[sp\], r10\n\tldsr r10, eipc\n} 2 } } */
/* { dg-final { scan-assembler-not {fpsr|fxsr|\treti} } } */
