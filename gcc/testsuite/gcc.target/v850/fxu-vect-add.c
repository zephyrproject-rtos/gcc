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
vadd (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] + b.f[i];
}

/* { dg-final { scan-assembler-times "\\taddf\\.s4 " 4 } } */
/* { dg-final { scan-assembler-not "\\taddf\\.s " } } */
