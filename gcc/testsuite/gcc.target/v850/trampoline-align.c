/* { dg-do run } */
/* { dg-require-effective-target trampolines } */
/* { dg-options "-O2" } */


extern void abort (void);

__attribute__ ((noipa)) int
call (int (*g) (int), int x)
{
  return g (x);
}

__attribute__ ((noipa)) void
use (volatile char *p)
{
  p[0] = 1;
}

int
main (void)
{
  char pad[2];
  int k = 5;
  int nested (int x) { return x + k + pad[0]; }

  use (pad);
  if ((unsigned long) nested & 3)
    abort ();
  if (call (nested, 1) != 7)
    abort ();
  return 0;
}
