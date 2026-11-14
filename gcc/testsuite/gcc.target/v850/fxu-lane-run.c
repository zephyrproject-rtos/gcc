/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O2" } */


typedef float vf __attribute__ ((vector_size (16)));
typedef int vi __attribute__ ((vector_size (16)));
typedef unsigned int u32;
union uf { vf v; float f[4]; u32 u[4]; };
union ui { vi v; int i[4]; };

#define EX(n) __attribute__ ((noipa)) float ex##n (vf v) { return v[n]; }
#define EXI(n) __attribute__ ((noipa)) int exi##n (vi v) { return v[n]; }
#define ST(n) __attribute__ ((noipa)) vf st##n (vf v, float s) { v[n] = s; return v; }
#define STI(n) __attribute__ ((noipa)) vi sti##n (vi v, int s) { v[n] = s; return v; }
EX (0) EX (1) EX (2) EX (3)
EXI (0) EXI (1) EXI (2) EXI (3)
ST (0) ST (1) ST (2) ST (3)
STI (0) STI (1) STI (2) STI (3)

__attribute__ ((noipa)) vf dup (float s) { return (vf) { s, s, s, s }; }
__attribute__ ((noipa)) vi dupi (int s) { return (vi) { s, s, s, s }; }
__attribute__ ((noipa)) vf ini (float p, float q, float s, float t)
{ return (vf) { p, q, s, t }; }
__attribute__ ((noipa)) vi inii (int p, int q, int s, int t)
{ return (vi) { p, q, s, t }; }
__attribute__ ((noipa)) vf inc (void) { return (vf) { 1.0f, -2.0f, 3.5f, 0.0f }; }

float m[4] __attribute__ ((aligned (16)));
__attribute__ ((noipa)) void scal (float s)
{
  for (int i = 0; i < 4; i++)
    m[i] = m[i] * s;
}

int
main (void)
{
  union uf u = { .f = { 1.5f, -2.25f, 3.0f, 4.75f } };
  union ui w = { .i = { 10, -20, 30, -40 } };
  float (*ex[4]) (vf) = { ex0, ex1, ex2, ex3 };
  int (*exi[4]) (vi) = { exi0, exi1, exi2, exi3 };
  vf (*st[4]) (vf, float) = { st0, st1, st2, st3 };
  vi (*sti[4]) (vi, int) = { sti0, sti1, sti2, sti3 };

  for (int n = 0; n < 4; n++)
    {
      if (ex[n] (u.v) != u.f[n] || exi[n] (w.v) != w.i[n])
	__builtin_abort ();
      union uf s = { .v = st[n] (u.v, 9.0f) };
      union ui si = { .v = sti[n] (w.v, 99) };
      for (int k = 0; k < 4; k++)
	if (s.f[k] != (k == n ? 9.0f : u.f[k])
	    || si.i[k] != (k == n ? 99 : w.i[k]))
	  __builtin_abort ();
    }
  union uf d = { .v = dup (-6.5f) };
  union ui di = { .v = dupi (7) };
  union uf in = { .v = ini (1.0f, 2.0f, 3.0f, 4.0f) };
  union ui ii = { .v = inii (5, 6, 7, 8) };
  union uf c = { .v = inc () };
  for (int k = 0; k < 4; k++)
    if (d.f[k] != -6.5f || di.i[k] != 7 || in.f[k] != k + 1
	|| ii.i[k] != k + 5)
      __builtin_abort ();
  if (c.f[0] != 1.0f || c.f[1] != -2.0f || c.f[2] != 3.5f || c.f[3] != 0.0f)
    __builtin_abort ();
  m[0] = 1; m[1] = 2; m[2] = 3; m[3] = 4;
  scal (0.5f);
  for (int k = 0; k < 4; k++)
    if (m[k] != (k + 1) * 0.5f)
      __builtin_abort ();
  return 0;
}
