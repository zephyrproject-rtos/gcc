/* { dg-do compile } */
/* { dg-options "-mv850e2v3 -O2 -mno-prolog-function" } */
/* { dg-skip-if "tests the base targets" { *-*-* } { "-mfxu" "-mg4" "-mg4mh2" "-mv850e3v5" } { "" } } */

volatile int cnt;

void __attribute__ ((interrupt)) h (void) { cnt++; }

/* { dg-final { scan-assembler {\treti\n} } } */
/* { dg-final { scan-assembler-not {eiret|feret|eipc|fpsr} } } */
