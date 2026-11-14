/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O3" } */


typedef unsigned int u32;
#define N 16
union fu { float f[N]; u32 u[N]; int i[N]; };
union fu a __attribute__ ((aligned (16)));
union fu b __attribute__ ((aligned (16)));
union fu x __attribute__ ((aligned (16)));
union fu y __attribute__ ((aligned (16)));
union fu r __attribute__ ((aligned (16)));

static void
fill (const u32 *pa, const u32 *pb)
{
  for (int i = 0; i < N; i++)
    {
      a.u[i] = pa[i];
      b.u[i] = pb[i];
      x.u[i] = 0x11110000 + i;
      y.u[i] = 0x22220000 + i;
      r.u[i] = 0xdeadbeef;
    }
}

static void
check (const u32 *e)
{
  for (int i = 0; i < N; i++)
    if (r.u[i] != e[i])
      __builtin_abort ();
}

static const u32 a_vadd[N] = { 0xc4800000, 0xb892ccf7, 0x4640e6b6, 0x3f800000, 0xc4800000, 0x50df8476, 0x4640e6b6, 0x3f800000, 0xb892ccf7, 0xbe000000, 0x42c80000, 0x3f800000, 0x0df36390, 0x40200000, 0xbe000000, 0x3f800000 };
static const u32 b_vadd[N] = { 0xc0700000, 0x40c00000, 0xbe000000, 0x40c00000, 0xc0700000, 0x4640e6b6, 0x0df36390, 0xb892ccf7, 0x40200000, 0xc0000000, 0x40c00000, 0xb892ccf7, 0x477fe000, 0x3f800000, 0xbf800000, 0xc4800000 };
static const u32 e_vadd[N] = { 0xc4807800, 0x40bfff6d, 0x4640e636, 0x40e00000, 0xc4807800, 0x50df847c, 0x4640e6b6, 0x3f7ffb6a, 0x401ffeda, 0xc0080000, 0x42d40000, 0x3f7ffb6a, 0x477fe000, 0x40600000, 0xbf900000, 0xc47fc000 };

__attribute__ ((noipa)) void
vadd (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] + b.f[i];
}

int
main (void)
{
  fill (a_vadd, b_vadd);
  vadd ();
  check (e_vadd);
  return 0;
}
