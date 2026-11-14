/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */


typedef float vf __attribute__ ((vector_size (16)));
typedef int vi __attribute__ ((vector_size (16)));

float ex2 (vf v) { return v[2]; }
int exi3 (vi v) { return v[3]; }
vf st1 (vf v, float s) { v[1] = s; return v; }
vf dup (float s) { return (vf) { s, s, s, s }; }
vi ini (int p, int q, int s, int t) { return (vi) { p, q, s, t }; }

/* { dg-final { scan-assembler "\\tstv\\.w 2, " } } */
/* { dg-final { scan-assembler "\\tstv\\.w 3, " } } */
/* { dg-final { scan-assembler "\\tldv\\.w 2, " } } */
/* { dg-final { scan-assembler-times "\\tldv\\.w 15, " 1 } } */
