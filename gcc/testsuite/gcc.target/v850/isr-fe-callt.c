/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -mgcc-abi -O2" } */

volatile int cnt;

void __attribute__ ((interrupt ("FE"))) fe0 (void) { cnt++; }

/* { dg-final { scan-assembler {callt ctoff\(__callt_save_interrupt\)} } } */
/* { dg-final { scan-assembler {ldsr r1, ctpsw\n.*\n\tldsr r1, ctpc\n} } } */
/* { dg-final { scan-assembler {\tferet\n} } } */
/* { dg-final { scan-assembler-not {__callt_return_interrupt|eiret|\treti} } } */
