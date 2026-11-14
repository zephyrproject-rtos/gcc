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

static const u32 a_vfloor[N] = { 0x3fc00000, 0xbfc00000, 0x40000000, 0xc0000000, 0x3efae148, 0xbefae148, 0x4e6e6b28, 0xce6e6b28, 0x7f800000, 0xcf32d05e, 0x40200000, 0xc0200000, 0x42f78000, 0x7fc00000, 0x00000000, 0x40fff7cf };
static const u32 b_vfloor[N] = { 0x3fc00000, 0xbfc00000, 0x40000000, 0xc0000000, 0x3efae148, 0xbefae148, 0x4e6e6b28, 0xce6e6b28, 0x7f800000, 0xcf32d05e, 0x40200000, 0xc0200000, 0x42f78000, 0x7fc00000, 0x00000000, 0x40fff7cf };
static const u32 e_vfloor[N] = { 0x00000001, 0xfffffffe, 0x00000002, 0xfffffffe, 0x00000000, 0xffffffff, 0x3b9aca00, 0xc4653600, 0x7fffffff, 0x80000000, 0x00000002, 0xfffffffd, 0x0000007b, 0x80000000, 0x00000000, 0x00000007 };

__attribute__ ((noipa)) void
vfloor (void)
{
  for (int i = 0; i < N; i++)
    r.i[i] = __builtin_lfloorf (a.f[i]);
}

static const u32 a_vceil[N] = { 0x3fc00000, 0xbfc00000, 0x40000000, 0xc0000000, 0x3efae148, 0xbefae148, 0x4e6e6b28, 0xce6e6b28, 0x7f800000, 0xcf32d05e, 0x40200000, 0xc0200000, 0x42f78000, 0x7fc00000, 0x00000000, 0x40fff7cf };
static const u32 b_vceil[N] = { 0x3fc00000, 0xbfc00000, 0x40000000, 0xc0000000, 0x3efae148, 0xbefae148, 0x4e6e6b28, 0xce6e6b28, 0x7f800000, 0xcf32d05e, 0x40200000, 0xc0200000, 0x42f78000, 0x7fc00000, 0x00000000, 0x40fff7cf };
static const u32 e_vceil[N] = { 0x00000002, 0xffffffff, 0x00000002, 0xfffffffe, 0x00000001, 0x00000000, 0x3b9aca00, 0xc4653600, 0x7fffffff, 0x80000000, 0x00000003, 0xfffffffe, 0x0000007c, 0x80000000, 0x00000000, 0x00000008 };

__attribute__ ((noipa)) void
vceil (void)
{
  for (int i = 0; i < N; i++)
    r.i[i] = __builtin_lceilf (a.f[i]);
}

int
main (void)
{
  fill (a_vfloor, b_vfloor);
  vfloor ();
  check (e_vfloor);
  fill (a_vceil, b_vceil);
  vceil ();
  check (e_vceil);
  return 0;
}
