/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-skip-if "tests the base targets" { *-*-* } { "-mv850e3v5" } { "" } } */

volatile int v;

void __attribute__ ((interrupt))
h (void)
{
  __asm__ volatile ("mov 5, r20" ::: "r20");
  v++;
}

/* { dg-final { scan-assembler {\tadd -4,sp\n(\.LCFI[0-9]+:\n)?\tst\.w r20,0\[sp\]\n} } } */
/* { dg-final { scan-assembler {\tld\.w 0\[sp\],r20\n} } } */
/* { dg-final { scan-assembler {\tld\.w 0\[sp\],r20\n(.*\n)*\tadd 4,sp\n} } } */
