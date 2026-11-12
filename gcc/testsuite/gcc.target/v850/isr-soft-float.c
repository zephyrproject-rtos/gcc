/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -msoft-float -O2" } */

volatile float fv;
extern void f (void);

void __attribute__ ((interrupt)) uses_float (void) { fv = fv * 2.0f; }
void __attribute__ ((interrupt)) calls (void) { f (); }

/* { dg-final { scan-assembler-not {fpsr|fpepc|synce} } } */
