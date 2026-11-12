/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-skip-if "tests the RH850 ABI" { *-*-* } { "-mgcc-abi" } { "" } } */

#define Z __attribute__ ((zda))
extern char c Z;
extern short s Z;
extern int i Z;
extern float f Z;
extern int a[8] Z;

int lc (void) { return c; }
int ls (void) { return s; }
int li (void) { return i; }
float lf (void) { return f; }
int la (void) { return a[3]; }
int lax (int k) { return a[k]; }
void sc (char v) { c = v; }
void ss (short v) { s = v; }
void si (int v) { i = v; }
void sf (float v) { f = v; }
void sa (int v) { a[5] = v; }
void bit (void) { i |= 4; }

/* { dg-final { scan-assembler-times {movea zdaoff\(_c\),r0,} 2 } } */
/* { dg-final { scan-assembler-times {movea zdaoff\(_s\),r0,} 2 } } */
/* { dg-final { scan-assembler-times {movea zdaoff\(_i\),r0,} 3 } } */
/* { dg-final { scan-assembler-times {movea zdaoff\(_f\),r0,} 2 } } */
/* { dg-final { scan-assembler {movea zdaoff\(_a\),r0,} } } */
/* { dg-final { scan-assembler-not {zdaoff\([^)]*\)\[r0\]} } } */
