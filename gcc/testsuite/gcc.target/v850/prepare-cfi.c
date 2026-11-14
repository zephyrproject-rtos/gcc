/* { dg-do compile } */
/* { dg-options "-O2 -g -dA -mv850e3v5 -mrh850-abi" } */


extern void g (int *);

int
f (int a)
{
  int x = a;

  g (&x);
  return x + a;
}

/* { dg-final { scan-assembler "prepare" } } */
/* { dg-final { scan-assembler "DW_CFA_offset, column 0x1f" } } */
