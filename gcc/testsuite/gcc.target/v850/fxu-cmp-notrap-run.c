/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O3 -fno-trapping-math" } */


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

static const u32 a_vlt[N] = { 0xffc01234, 0x4640e6b6, 0x3f000000, 0xff800000, 0x3f000000, 0x477fe000, 0x7f800000, 0xc4800000, 0xc0000000, 0x7fc00000, 0x477fe000, 0x477fe000, 0x00000000, 0xbe000000, 0xbf800000, 0xff800000 };
static const u32 b_vlt[N] = { 0x00000000, 0x4640e6b6, 0xc4800000, 0xff800000, 0xbe000000, 0x477fe000, 0xff800000, 0xc4800000, 0x50df8476, 0x7fc00000, 0x7e967699, 0x477fe000, 0x7fc00000, 0xbe000000, 0xb892ccf7, 0xff800000 };
static const u32 e_vlt[N] = { 0x22220000, 0x22220001, 0x22220002, 0x22220003, 0x22220004, 0x22220005, 0x22220006, 0x22220007, 0x11110008, 0x22220009, 0x1111000a, 0x2222000b, 0x2222000c, 0x2222000d, 0x1111000e, 0x2222000f };

__attribute__ ((noipa)) void
vlt (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] < b.f[i] ? x.f[i] : y.f[i];
}

static const u32 a_vle[N] = { 0xffc01234, 0x4640e6b6, 0x3f000000, 0xff800000, 0x3f000000, 0x477fe000, 0x7f800000, 0xc4800000, 0xc0000000, 0x7fc00000, 0x477fe000, 0x477fe000, 0x00000000, 0xbe000000, 0xbf800000, 0xff800000 };
static const u32 b_vle[N] = { 0x00000000, 0x4640e6b6, 0xc4800000, 0xff800000, 0xbe000000, 0x477fe000, 0xff800000, 0xc4800000, 0x50df8476, 0x7fc00000, 0x7e967699, 0x477fe000, 0x7fc00000, 0xbe000000, 0xb892ccf7, 0xff800000 };
static const u32 e_vle[N] = { 0x22220000, 0x11110001, 0x22220002, 0x11110003, 0x22220004, 0x11110005, 0x22220006, 0x11110007, 0x11110008, 0x22220009, 0x1111000a, 0x1111000b, 0x2222000c, 0x1111000d, 0x1111000e, 0x1111000f };

__attribute__ ((noipa)) void
vle (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] <= b.f[i] ? x.f[i] : y.f[i];
}

static const u32 a_vgt[N] = { 0xffc01234, 0x4640e6b6, 0x3f000000, 0xff800000, 0x3f000000, 0x477fe000, 0x7f800000, 0xc4800000, 0xc0000000, 0x7fc00000, 0x477fe000, 0x477fe000, 0x00000000, 0xbe000000, 0xbf800000, 0xff800000 };
static const u32 b_vgt[N] = { 0x00000000, 0x4640e6b6, 0xc4800000, 0xff800000, 0xbe000000, 0x477fe000, 0xff800000, 0xc4800000, 0x50df8476, 0x7fc00000, 0x7e967699, 0x477fe000, 0x7fc00000, 0xbe000000, 0xb892ccf7, 0xff800000 };
static const u32 e_vgt[N] = { 0x22220000, 0x22220001, 0x11110002, 0x22220003, 0x11110004, 0x22220005, 0x11110006, 0x22220007, 0x22220008, 0x22220009, 0x2222000a, 0x2222000b, 0x2222000c, 0x2222000d, 0x2222000e, 0x2222000f };

__attribute__ ((noipa)) void
vgt (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] > b.f[i] ? x.f[i] : y.f[i];
}

static const u32 a_vge[N] = { 0xffc01234, 0x4640e6b6, 0x3f000000, 0xff800000, 0x3f000000, 0x477fe000, 0x7f800000, 0xc4800000, 0xc0000000, 0x7fc00000, 0x477fe000, 0x477fe000, 0x00000000, 0xbe000000, 0xbf800000, 0xff800000 };
static const u32 b_vge[N] = { 0x00000000, 0x4640e6b6, 0xc4800000, 0xff800000, 0xbe000000, 0x477fe000, 0xff800000, 0xc4800000, 0x50df8476, 0x7fc00000, 0x7e967699, 0x477fe000, 0x7fc00000, 0xbe000000, 0xb892ccf7, 0xff800000 };
static const u32 e_vge[N] = { 0x22220000, 0x11110001, 0x11110002, 0x11110003, 0x11110004, 0x11110005, 0x11110006, 0x11110007, 0x22220008, 0x22220009, 0x2222000a, 0x1111000b, 0x2222000c, 0x1111000d, 0x2222000e, 0x1111000f };

__attribute__ ((noipa)) void
vge (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[i] >= b.f[i] ? x.f[i] : y.f[i];
}

static const u32 a_vltgt[N] = { 0xffc01234, 0x4640e6b6, 0x3f000000, 0xff800000, 0x3f000000, 0x477fe000, 0x7f800000, 0xc4800000, 0xc0000000, 0x7fc00000, 0x477fe000, 0x477fe000, 0x00000000, 0xbe000000, 0xbf800000, 0xff800000 };
static const u32 b_vltgt[N] = { 0x00000000, 0x4640e6b6, 0xc4800000, 0xff800000, 0xbe000000, 0x477fe000, 0xff800000, 0xc4800000, 0x50df8476, 0x7fc00000, 0x7e967699, 0x477fe000, 0x7fc00000, 0xbe000000, 0xb892ccf7, 0xff800000 };
static const u32 e_vltgt[N] = { 0x22220000, 0x22220001, 0x11110002, 0x22220003, 0x11110004, 0x22220005, 0x11110006, 0x22220007, 0x11110008, 0x22220009, 0x1111000a, 0x2222000b, 0x2222000c, 0x2222000d, 0x1111000e, 0x2222000f };

__attribute__ ((noipa)) void
vltgt (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = (a.f[i] < b.f[i] || a.f[i] > b.f[i]) ? x.f[i] : y.f[i];
}

int
main (void)
{
  fill (a_vlt, b_vlt);
  vlt ();
  check (e_vlt);
  fill (a_vle, b_vle);
  vle ();
  check (e_vle);
  fill (a_vgt, b_vgt);
  vgt ();
  check (e_vgt);
  fill (a_vge, b_vge);
  vge ();
  check (e_vge);
  fill (a_vltgt, b_vltgt);
  vltgt ();
  check (e_vltgt);
  return 0;
}
