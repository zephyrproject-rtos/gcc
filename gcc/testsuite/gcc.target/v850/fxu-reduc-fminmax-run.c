/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O3 -fno-math-errno" } */


typedef unsigned int u32;
#define N 16
union { float f[N]; u32 u[N]; } a __attribute__ ((aligned (16)));
static const u32 in[N] = { 0x40a00000, 0x447a0000, 0xc47a0000, 0x41000000, 0xc1c00000, 0x7fc00000, 0x41c00000, 0x40800000, 0xc2480000, 0xc2000000, 0x42080000, 0x41880000, 0x41a80000, 0xc0c00000, 0x41600000, 0x420c0000 };

__attribute__ ((noipa)) float
fmx (void)
{
  float s = a.f[0];
  for (int i = 0; i < N; i++)
    s = __builtin_fmaxf (s, a.f[i]);
  return s;
}

__attribute__ ((noipa)) float
fmn (void)
{
  float s = a.f[0];
  for (int i = 0; i < N; i++)
    s = __builtin_fminf (s, a.f[i]);
  return s;
}

int
main (void)
{
  union { float f; u32 u; } p, q;
  for (int i = 0; i < N; i++)
    a.u[i] = in[i];
  p.f = fmx ();
  q.f = fmn ();
  if (p.u != 0x447a0000 || q.u != 0xc47a0000)
    __builtin_abort ();
  return 0;
}
