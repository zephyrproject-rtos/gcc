/* { dg-do compile } */
/* { dg-options "-O2 -mg4" } */

int sb (int x) { return x > 127 ? 127 : x < -128 ? -128 : x; }
int sh (int x) { if (x > 32767) x = 32767; if (x < -32768) x = -32768; return x; }
unsigned ub (unsigned x) { return x > 255 ? 255 : x; }
unsigned uh (unsigned x) { return x > 65535 ? 65535 : x; }
int su (int x) { return x > 255 ? 255 : x < 0 ? 0 : x; }

/* { dg-final { scan-assembler-times "clip\\.b " 1 } } */
/* { dg-final { scan-assembler-times "clip\\.h " 1 } } */
/* { dg-final { scan-assembler-times "clip\\.bu " 1 } } */
/* { dg-final { scan-assembler-times "clip\\.hu " 1 } } */
