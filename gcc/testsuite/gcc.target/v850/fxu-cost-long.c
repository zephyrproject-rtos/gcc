/* { dg-do compile } */
/* { dg-options "-mfxu -O3" } */

/* A long loop with a runtime trip count is still vectorized.  */

void
f (float *__restrict r, const float *__restrict a, const float *__restrict b,
   int n)
{
  for (int i = 0; i < n; i++)
    r[i] = a[i] * b[i] + r[i];
}

/* { dg-final { scan-assembler "\\tfmaf\\.s4 " } } */
