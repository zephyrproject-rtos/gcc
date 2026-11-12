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
vfloor (void)
{
  for (int i = 0; i < N; i++)
    r.i[i] = __builtin_lfloorf (a.f[i]);
}

void
vceil (void)
{
  for (int i = 0; i < N; i++)
    r.i[i] = __builtin_lceilf (a.f[i]);
}

void
vround (void)
{
  for (int i = 0; i < N; i++)
    r.i[i] = __builtin_lroundf (a.f[i]);
}

void
vrint (void)
{
  for (int i = 0; i < N; i++)
    r.i[i] = __builtin_lrintf (a.f[i]);
}

/* { dg-final { scan-assembler-times "\\tfloorf\\.sw4 " 4 } } */
/* { dg-final { scan-assembler-times "\\tceilf\\.sw4 " 4 } } */
/* { dg-final { scan-assembler-not "\\troundf\\.sw4 " } } */
/* { dg-final { scan-assembler-not "\\tcvtf\\.sw4 " } } */
