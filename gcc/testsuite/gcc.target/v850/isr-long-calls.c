/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2 -mlong-calls -mno-ep" } */

extern void f (void);

void __attribute__ ((interrupt)) h (void) { f (); }

/* { dg-final { scan-assembler {\taddi -120, sp, sp\n\tst\.w r31, 116\[sp\]\n} } } */
/* { dg-final { scan-assembler {\tld\.w 16\[sp\],  r29\n\taddi  120, sp, sp\n} } } */
