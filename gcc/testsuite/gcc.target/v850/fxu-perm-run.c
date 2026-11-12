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

typedef float vf __attribute__ ((vector_size (16)));
typedef int vi __attribute__ ((vector_size (16)));
union { vf v[N]; u32 u[4 * N]; } rs __attribute__ ((aligned (16)));
union { vi v[1]; u32 u[4]; } ri __attribute__ ((aligned (16)));

static const u32 a_vrev[N] = { 0x10000000, 0x10000001, 0x10000002, 0x10000003, 0x10000004, 0x10000005, 0x10000006, 0x10000007, 0x10000008, 0x10000009, 0x1000000a, 0x1000000b, 0x1000000c, 0x1000000d, 0x1000000e, 0x1000000f };
static const u32 b_vrev[N] = { 0x20000000, 0x20000001, 0x20000002, 0x20000003, 0x20000004, 0x20000005, 0x20000006, 0x20000007, 0x20000008, 0x20000009, 0x2000000a, 0x2000000b, 0x2000000c, 0x2000000d, 0x2000000e, 0x2000000f };
static const u32 e_vrev[N] = { 0x1000000f, 0x1000000e, 0x1000000d, 0x1000000c, 0x1000000b, 0x1000000a, 0x10000009, 0x10000008, 0x10000007, 0x10000006, 0x10000005, 0x10000004, 0x10000003, 0x10000002, 0x10000001, 0x10000000 };

__attribute__ ((noipa)) void
vrev (void)
{
  for (int i = 0; i < N; i++)
    r.f[i] = a.f[N - 1 - i];
}

static const u32 a_vswap[N] = { 0x10000000, 0x10000001, 0x10000002, 0x10000003, 0x10000004, 0x10000005, 0x10000006, 0x10000007, 0x10000008, 0x10000009, 0x1000000a, 0x1000000b, 0x1000000c, 0x1000000d, 0x1000000e, 0x1000000f };
static const u32 b_vswap[N] = { 0x20000000, 0x20000001, 0x20000002, 0x20000003, 0x20000004, 0x20000005, 0x20000006, 0x20000007, 0x20000008, 0x20000009, 0x2000000a, 0x2000000b, 0x2000000c, 0x2000000d, 0x2000000e, 0x2000000f };
static const u32 e_vswap[N] = { 0x10000001, 0x10000000, 0x10000003, 0x10000002, 0x10000005, 0x10000004, 0x10000007, 0x10000006, 0x10000009, 0x10000008, 0x1000000b, 0x1000000a, 0x1000000d, 0x1000000c, 0x1000000f, 0x1000000e };

__attribute__ ((noipa)) void
vswap (void)
{
  for (int i = 0; i < N; i += 2)
    {
      r.f[i] = a.f[i + 1];
      r.f[i + 1] = a.f[i];
    }
}

static const u32 a_vileave[N] = { 0x10000000, 0x10000001, 0x10000002, 0x10000003, 0x10000004, 0x10000005, 0x10000006, 0x10000007, 0x10000008, 0x10000009, 0x1000000a, 0x1000000b, 0x1000000c, 0x1000000d, 0x1000000e, 0x1000000f };
static const u32 b_vileave[N] = { 0x20000000, 0x20000001, 0x20000002, 0x20000003, 0x20000004, 0x20000005, 0x20000006, 0x20000007, 0x20000008, 0x20000009, 0x2000000a, 0x2000000b, 0x2000000c, 0x2000000d, 0x2000000e, 0x2000000f };
static const u32 e_vileave[N] = { 0x10000000, 0x20000000, 0x10000001, 0x20000001, 0x10000002, 0x20000002, 0x10000003, 0x20000003, 0x10000004, 0x20000004, 0x10000005, 0x20000005, 0x10000006, 0x20000006, 0x10000007, 0x20000007 };

__attribute__ ((noipa)) void
vileave (void)
{
  for (int i = 0; i < N / 2; i++)
    {
      r.f[2 * i] = a.f[i];
      r.f[2 * i + 1] = b.f[i];
    }
}

static const u32 a_veven[N] = { 0x10000000, 0x10000001, 0x10000002, 0x10000003, 0x10000004, 0x10000005, 0x10000006, 0x10000007, 0x10000008, 0x10000009, 0x1000000a, 0x1000000b, 0x1000000c, 0x1000000d, 0x1000000e, 0x1000000f };
static const u32 b_veven[N] = { 0x20000000, 0x20000001, 0x20000002, 0x20000003, 0x20000004, 0x20000005, 0x20000006, 0x20000007, 0x20000008, 0x20000009, 0x2000000a, 0x2000000b, 0x2000000c, 0x2000000d, 0x2000000e, 0x2000000f };
static const u32 e_veven[N] = { 0x10000000, 0x10000002, 0x10000004, 0x10000006, 0x10000008, 0x1000000a, 0x1000000c, 0x1000000e, 0x10000001, 0x10000003, 0x10000005, 0x10000007, 0x10000009, 0x1000000b, 0x1000000d, 0x1000000f };

__attribute__ ((noipa)) void
veven (void)
{
  for (int i = 0; i < N / 2; i++)
    {
      r.f[i] = a.f[2 * i];
      r.f[i + N / 2] = a.f[2 * i + 1];
    }
}

static const u32 e_sh[4 * N] = { 0x20000003, 0x10000000, 0x20000001, 0x10000002, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000003, 0x10000002, 0x10000001, 0x10000000, 0x20000000, 0x20000001, 0x20000002, 0x20000003, 0x10000001, 0x20000002, 0x10000003, 0x20000000, 0x10000001, 0x10000002, 0x20000001, 0x10000003, 0x20000000, 0x20000001, 0x10000001, 0x20000000, 0x20000000, 0x20000003, 0x10000001, 0x10000002, 0x10000000, 0x10000001, 0x20000001, 0x10000003, 0x10000003, 0x10000002, 0x20000000, 0x20000002, 0x10000000, 0x10000000, 0x10000000, 0x20000000, 0x20000003, 0x10000003, 0x20000001, 0x10000002, 0x20000003, 0x10000002, 0x20000001, 0x20000001, 0x10000003, 0x20000003, 0x20000001, 0x20000001, 0x10000001, 0x20000003, 0x20000000, 0x10000000, 0x10000000, 0x20000002, 0x20000003, 0x20000001 };

__attribute__ ((noipa)) void
shuf (vf p, vf q)
{
  rs.v[0] = __builtin_shuffle (p, q, (vi) { 7, 0, 5, 2 });
  rs.v[1] = __builtin_shuffle (p, q, (vi) { 0, 0, 0, 0 });
  rs.v[2] = __builtin_shuffle (p, q, (vi) { 3, 2, 1, 0 });
  rs.v[3] = __builtin_shuffle (p, q, (vi) { 4, 5, 6, 7 });
  rs.v[4] = __builtin_shuffle (p, q, (vi) { 1, 6, 3, 4 });
  rs.v[5] = __builtin_shuffle (p, q, (vi) { 1, 2, 5, 3 });
  rs.v[6] = __builtin_shuffle (p, q, (vi) { 4, 5, 1, 4 });
  rs.v[7] = __builtin_shuffle (p, q, (vi) { 4, 7, 1, 2 });
  rs.v[8] = __builtin_shuffle (p, q, (vi) { 0, 1, 5, 3 });
  rs.v[9] = __builtin_shuffle (p, q, (vi) { 3, 2, 4, 6 });
  rs.v[10] = __builtin_shuffle (p, q, (vi) { 0, 0, 0, 4 });
  rs.v[11] = __builtin_shuffle (p, q, (vi) { 7, 3, 5, 2 });
  rs.v[12] = __builtin_shuffle (p, q, (vi) { 7, 2, 5, 5 });
  rs.v[13] = __builtin_shuffle (p, q, (vi) { 3, 7, 5, 5 });
  rs.v[14] = __builtin_shuffle (p, q, (vi) { 1, 7, 4, 0 });
  rs.v[15] = __builtin_shuffle (p, q, (vi) { 0, 6, 7, 5 });
}

__attribute__ ((noipa)) void
shufi (vi p)
{
  ri.v[0] = __builtin_shuffle (p, (vi) { 3, 3, 0, 1 });
}

int
main (void)
{
  fill (a_vrev, b_vrev);
  vrev ();
  check (e_vrev);
  fill (a_vswap, b_vswap);
  vswap ();
  check (e_vswap);
  fill (a_vileave, b_vileave);
  vileave ();
  check (e_vileave);
  fill (a_veven, b_veven);
  veven ();
  check (e_veven);
  fill (a_vrev, b_vrev);
  shuf (*(vf *) a.u, *(vf *) b.u);
  for (int i = 0; i < 4 * N; i++)
    if (rs.u[i] != e_sh[i])
      __builtin_abort ();
  shufi (*(vi *) a.u);
  if (ri.u[0] != a.u[3] || ri.u[1] != a.u[3] || ri.u[2] != a.u[0] || ri.u[3] != a.u[1])
    __builtin_abort ();
  return 0;
}
