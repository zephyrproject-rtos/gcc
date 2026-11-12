/* { dg-do compile } */
/* { dg-options "-mfxu -O3 -ffast-math" } */


#define N 16
float a[N] __attribute__ ((aligned (16)));

float sum (void) { float s = 0.0f; for (int i = 0; i < N; i++) s += a[i]; return s; }
float smax (void) { float s = a[0]; for (int i = 0; i < N; i++) s = s > a[i] ? s : a[i]; return s; }
float smin (void) { float s = a[0]; for (int i = 0; i < N; i++) s = s < a[i] ? s : a[i]; return s; }

/* { dg-final { scan-assembler-times "\\taddrf\\.s4 " 1 } } */
/* { dg-final { scan-assembler-times "\\tmaxrf\\.s4 " 1 } } */
/* { dg-final { scan-assembler-times "\\tminrf\\.s4 " 1 } } */
/* { dg-final { scan-assembler-times "\\tstv\\.w 0, " 3 } } */
