/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -mgcc-abi -O2 -mep -mno-prolog-function -g" } */

volatile float fv;
volatile int n;

void __attribute__ ((interrupt)) h (void) { fv = fv * 1.1f; n++; }

/* { dg-final { scan-assembler {\tsst\.w r1[23],[04]\[ep\]\n} } } */
