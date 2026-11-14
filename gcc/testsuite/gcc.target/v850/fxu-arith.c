/* { dg-do compile } */
/* { dg-options "-mfxu -O3 -fno-math-errno" } */


typedef unsigned int u32;
#define N 16
union fu { float f[N]; u32 u[N]; int i[N]; };
union fu a __attribute__ ((aligned (16)));
union fu b __attribute__ ((aligned (16)));
union fu x __attribute__ ((aligned (16)));
union fu y __attribute__ ((aligned (16)));
union fu r __attribute__ ((aligned (16)));


void
vfmax (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = __builtin_fmaxf (a.f[i], b.f[i]);
}

void
vfmin (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = __builtin_fminf (a.f[i], b.f[i]);
}

void
vaddsub (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i] - b.f[i];
      r.f[i + 1] = a.f[i + 1] + b.f[i + 1];
    }
}

void
vcadd90 (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i] - b.f[i + 1];
      r.f[i + 1] = a.f[i + 1] + b.f[i];
    }
}

void
vcadd270 (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i] + b.f[i + 1];
      r.f[i + 1] = a.f[i + 1] - b.f[i];
    }
}

/* { dg-final { scan-assembler-times "\\tmaxf\\.s4 " 4 } } */
/* { dg-final { scan-assembler-times "\\tminf\\.s4 " 4 } } */
/* { dg-final { scan-assembler-times "\\taddsubf\\.s4 " 4 } } */
/* { dg-final { scan-assembler-times "\\taddsubxf\\.s4 " 4 } } */
/* { dg-final { scan-assembler-times "\\tsubaddxf\\.s4 " 4 } } */
