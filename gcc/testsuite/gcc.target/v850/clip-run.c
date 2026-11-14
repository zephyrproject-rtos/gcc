/* { dg-do run } */
/* { dg-options "-O2 -mg4" } */

extern void abort (void);

#define NOIPA __attribute__ ((noipa))

NOIPA int sb (int x) { return x > 127 ? 127 : x < -128 ? -128 : x; }
NOIPA int sh (int x) { return x < -32768 ? -32768 : x > 32767 ? 32767 : x; }
NOIPA unsigned ub (unsigned x) { return x > 255 ? 255 : x; }
NOIPA unsigned uh (unsigned x) { return x > 65535 ? 65535 : x; }
NOIPA int su (int x) { return x > 255 ? 255 : x < 0 ? 0 : x; }
NOIPA int smin (int x, int y) { return x < y ? x : y; }
NOIPA int smax (int x, int y) { return x > y ? x : y; }
NOIPA unsigned umin (unsigned x, unsigned y) { return x < y ? x : y; }
NOIPA unsigned umax (unsigned x, unsigned y) { return x > y ? x : y; }
NOIPA int smin5 (int x) { return x < 7 ? x : 7; }
NOIPA unsigned umax5 (unsigned x) { return x > 9 ? x : 9; }

static const int vals[] = {
  0, 1, -1, 7, 9, 126, 127, 128, 129, -127, -128, -129, 254, 255, 256,
  32766, 32767, 32768, -32767, -32768, -32769, 65534, 65535, 65536,
  0x7fffffff, -0x7fffffff - 1, 0x12345678, -0x12345678
};

int
main (void)
{
  unsigned i, j;

  for (i = 0; i < sizeof vals / sizeof vals[0]; i++)
    {
      int x = vals[i];
      unsigned u = x;
      int r;

      r = x > 127 ? 127 : x < -128 ? -128 : x;
      if (sb (x) != r)
	abort ();
      r = x > 32767 ? 32767 : x < -32768 ? -32768 : x;
      if (sh (x) != r)
	abort ();
      if (ub (u) != (u > 255 ? 255 : u))
	abort ();
      if (uh (u) != (u > 65535 ? 65535 : u))
	abort ();
      if (su (x) != (x > 255 ? 255 : x < 0 ? 0 : x))
	abort ();
      if (smin5 (x) != (x < 7 ? x : 7) || umax5 (u) != (u > 9 ? u : 9))
	abort ();
      for (j = 0; j < sizeof vals / sizeof vals[0]; j++)
	{
	  int y = vals[j];
	  unsigned v = y;

	  if (smin (x, y) != (x < y ? x : y) || smax (x, y) != (x > y ? x : y))
	    abort ();
	  if (umin (u, v) != (u < v ? u : v) || umax (u, v) != (u > v ? u : v))
	    abort ();
	}
    }
  return 0;
}
