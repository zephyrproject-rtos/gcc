/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -mgcc-abi -O2" } */

extern void g (void);
int f (int x) { g (); return x; }
void h (void) { g (); g (); }

/* { dg-final { scan-assembler {callt ctoff\(__callt_save_r[0-9]+_r31c\)} } } */
/* { dg-final { scan-assembler-not {\tprepare } } } */
