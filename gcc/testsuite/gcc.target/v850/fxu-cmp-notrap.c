/* { dg-do compile } */
/* { dg-options "-mfxu -O3 -fno-trapping-math" } */


typedef unsigned int u32;
#define N 16
union fu { float f[N]; u32 u[N]; int i[N]; };
union fu a __attribute__ ((aligned (16)));
union fu b __attribute__ ((aligned (16)));
union fu x __attribute__ ((aligned (16)));
union fu y __attribute__ ((aligned (16)));
union fu r __attribute__ ((aligned (16)));


void
vlt (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] < b.f[i] ? x.f[i] : y.f[i];
}

void
vle (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] <= b.f[i] ? x.f[i] : y.f[i];
}

void
vgt (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] > b.f[i] ? x.f[i] : y.f[i];
}

void
vge (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] >= b.f[i] ? x.f[i] : y.f[i];
}

void
vltgt (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = (a.f[i] < b.f[i] || a.f[i] > b.f[i]) ? x.f[i] : y.f[i];
}

/* { dg-final { scan-assembler-times "\\tcmpf\\.s4 " 20 } } */
/* { dg-final { scan-assembler-not "\\tcmpf\\.s4 (8|9|1\[0-5\])," } } */
