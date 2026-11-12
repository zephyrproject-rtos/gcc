/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O0 -g -dA" } */

void g (char *);

void
f (int n)
{
  char *p = __builtin_alloca (n);
  g (p);
}

/* { dg-final { scan-assembler {DW_CFA_def_cfa_register\n\t\.uleb128 0x3\n} } } */
/* { dg-final { scan-assembler {DW_CFA_restore, column 0x1d\n} } } */
/* { dg-final { scan-assembler {DW_CFA_restore, column 0x1f\n} } } */
/* { dg-final { scan-assembler {DW_CFA_def_cfa_offset\n\t\.uleb128 0\n\t\.align 2\n} } } */
