/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O3 -fno-math-errno" } */


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

static const u32 a_vfmax[N] = { 0x80000000, 0x4640e6b6, 0x477fe000, 0xff800000, 0x4640e6b6, 0xbe000000, 0x00000000, 0x3f000000, 0x40c00000, 0x7fc00000, 0x42c80000, 0x0df36390, 0xff800000, 0x50df8476, 0xc0700000, 0x7fc00000 };
static const u32 b_vfmax[N] = { 0x3f800000, 0x40c00000, 0x3f800000, 0xffc01234, 0x3f000000, 0x50df8476, 0xc4800000, 0xc0000000, 0xc4800000, 0x0df36390, 0x50df8476, 0x3f000000, 0x00000000, 0x7e967699, 0x477fe000, 0x7e967699 };
static const u32 e_vfmax[N] = { 0x3f800000, 0x4640e6b6, 0x477fe000, 0xff800000, 0x4640e6b6, 0x50df8476, 0x00000000, 0x3f000000, 0x40c00000, 0x0df36390, 0x50df8476, 0x3f000000, 0x00000000, 0x7e967699, 0x477fe000, 0x7e967699 };

__attribute__ ((noipa)) void
vfmax (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = __builtin_fmaxf (a.f[i], b.f[i]);
}

static const u32 a_vfmin[N] = { 0x80000000, 0x4640e6b6, 0x477fe000, 0xff800000, 0x4640e6b6, 0xbe000000, 0x00000000, 0x3f000000, 0x40c00000, 0x7fc00000, 0x42c80000, 0x0df36390, 0xff800000, 0x50df8476, 0xc0700000, 0x7fc00000 };
static const u32 b_vfmin[N] = { 0x3f800000, 0x40c00000, 0x3f800000, 0xffc01234, 0x3f000000, 0x50df8476, 0xc4800000, 0xc0000000, 0xc4800000, 0x0df36390, 0x50df8476, 0x3f000000, 0x00000000, 0x7e967699, 0x477fe000, 0x7e967699 };
static const u32 e_vfmin[N] = { 0x80000000, 0x40c00000, 0x3f800000, 0xff800000, 0x3f000000, 0xbe000000, 0xc4800000, 0xc0000000, 0xc4800000, 0x0df36390, 0x42c80000, 0x0df36390, 0xff800000, 0x50df8476, 0xc0700000, 0x7e967699 };

__attribute__ ((noipa)) void
vfmin (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = __builtin_fminf (a.f[i], b.f[i]);
}

static const u32 a_vaddsub[N] = { 0x42c80000, 0x42c80000, 0xbe000000, 0x477fe000, 0x0df36390, 0x42c80000, 0xbf800000, 0xc0700000, 0xc4800000, 0x40200000, 0x50df8476, 0xbf800000, 0xc0700000, 0xc0700000, 0xc0700000, 0xc0000000 };
static const u32 b_vaddsub[N] = { 0xc0000000, 0xbe000000, 0xb892ccf7, 0xc4800000, 0x3f000000, 0x477fe000, 0x42c80000, 0x0df36390, 0x40200000, 0x40200000, 0xc0000000, 0x40200000, 0x0df36390, 0x3f800000, 0xc0700000, 0x42c80000 };
static const u32 e_vaddsub[N] = { 0x42cc0000, 0x42c7c000, 0xbdffdb4d, 0x477be000, 0xbf000000, 0x47802200, 0xc2ca0000, 0xc0700000, 0xc4805000, 0x40a00000, 0x50df8476, 0x3fc00000, 0xc0700000, 0xc0300000, 0x00000000, 0x42c40000 };

__attribute__ ((noipa)) void
vaddsub (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i] - b.f[i];
      r.f[i + 1] = a.f[i + 1] + b.f[i + 1];
    }
}

static const u32 a_vcadd90[N] = { 0x42c80000, 0x42c80000, 0xbe000000, 0x477fe000, 0x0df36390, 0x42c80000, 0xbf800000, 0xc0700000, 0xc4800000, 0x40200000, 0x50df8476, 0xbf800000, 0xc0700000, 0xc0700000, 0xc0700000, 0xc0000000 };
static const u32 b_vcadd90[N] = { 0xc0000000, 0xbe000000, 0xb892ccf7, 0xc4800000, 0x3f000000, 0x477fe000, 0x42c80000, 0x0df36390, 0x40200000, 0x40200000, 0xc0000000, 0x40200000, 0x0df36390, 0x3f800000, 0xc0700000, 0x42c80000 };
static const u32 e_vcadd90[N] = { 0x42c84000, 0x42c40000, 0x447ff800, 0x477fe000, 0xc77fe000, 0x42c90000, 0xbf800000, 0x42c08000, 0xc4805000, 0x40a00000, 0x50df8476, 0xc0400000, 0xc0980000, 0xc0700000, 0xc2cf8000, 0xc0b80000 };

__attribute__ ((noipa)) void
vcadd90 (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i] - b.f[i + 1];
      r.f[i + 1] = a.f[i + 1] + b.f[i];
    }
}

static const u32 a_vcadd270[N] = { 0x42c80000, 0x42c80000, 0xbe000000, 0x477fe000, 0x0df36390, 0x42c80000, 0xbf800000, 0xc0700000, 0xc4800000, 0x40200000, 0x50df8476, 0xbf800000, 0xc0700000, 0xc0700000, 0xc0700000, 0xc0000000 };
static const u32 b_vcadd270[N] = { 0xc0000000, 0xbe000000, 0xb892ccf7, 0xc4800000, 0x3f000000, 0x477fe000, 0x42c80000, 0x0df36390, 0x40200000, 0x40200000, 0xc0000000, 0x40200000, 0x0df36390, 0x3f800000, 0xc0700000, 0x42c80000 };
static const u32 e_vcadd270[N] = { 0x42c7c000, 0x42cc0000, 0xc4800400, 0x477fe000, 0x477fe000, 0x42c70000, 0xbf800000, 0xc2cf8000, 0xc47f6000, 0x00000000, 0x50df8476, 0x3f800000, 0xc0300000, 0xc0700000, 0x42c08000, 0x3fe00000 };

__attribute__ ((noipa)) void
vcadd270 (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i] + b.f[i + 1];
      r.f[i + 1] = a.f[i + 1] - b.f[i];
    }
}

int
main (void)
{
  fill (a_vfmax, b_vfmax);
  vfmax ();
  check (e_vfmax);
  fill (a_vfmin, b_vfmin);
  vfmin ();
  check (e_vfmin);
  fill (a_vaddsub, b_vaddsub);
  vaddsub ();
  check (e_vaddsub);
  fill (a_vcadd90, b_vcadd90);
  vcadd90 ();
  check (e_vcadd90);
  fill (a_vcadd270, b_vcadd270);
  vcadd270 ();
  check (e_vcadd270);
  return 0;
}
