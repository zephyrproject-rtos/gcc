/* { dg-do compile } */
/* { dg-options "-mfxu -O3" } */


typedef unsigned int u32;
#define N 16
union fu { float f[N]; u32 u[N]; int i[N]; };
union fu a __attribute__ ((aligned (16)));
union fu b __attribute__ ((aligned (16)));
union fu x __attribute__ ((aligned (16)));
union fu y __attribute__ ((aligned (16)));
union fu r __attribute__ ((aligned (16)));


void
vrev (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[N - 1 - i];
}

void
vswap (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i + 1];
      r.f[i + 1] = a.f[i];
    }
}

void
vileave (void)
{
  for (int i = 0; i < N / 2; i++)
    {
      r.f[2 * i] = a.f[i];
      r.f[2 * i + 1] = b.f[i];
    }
}

void
veven (void)
{
  for (int i = 0; i < N / 2; i++)
    {
      r.f[i] = a.f[2 * i];
      r.f[i + N / 2] = a.f[2 * i + 1];
    }
}

/* { dg-final { scan-assembler-times "\\tshflv\\.w4 " 16 } } */
