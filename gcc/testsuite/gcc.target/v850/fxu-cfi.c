/* { dg-do compile } */
/* { dg-options "-mfxu -O2 -g -dA" } */

void
f (void)
{
  __asm__ volatile ("" ::: "wr5");
}

void
g (int n)
{
  char *p = __builtin_alloca (n);

  __asm__ volatile ("" : : "r" (p) : "wr7");
}

/* { dg-final { scan-assembler {DW_CFA_expression\n\t\.byte\t0x29\n\t\.uleb128 0x2\n\t\.byte\t0x73\t# DW_OP_breg3\n\t\.sleb128 0\n} } } */
/* { dg-final { scan-assembler {DW_CFA_def_cfa\n\t\.uleb128 0xb\n\t\.uleb128 0\n} } } */
/* { dg-final { scan-assembler {DW_CFA_def_cfa\n\t\.uleb128 0xc\n\t\.uleb128 0x4\n} } } */
/* { dg-final { scan-assembler-times {DW_CFA_def_cfa_expression} 1 } } */
/* { dg-final { scan-assembler {DW_CFA_expression\n\t\.byte\t0x2b\n\t\.uleb128 0x2\n\t\.byte\t0x8d\t# DW_OP_breg29\n\t\.sleb128 0\n} } } */
/* { dg-final { scan-assembler {DW_CFA_restore, column 0x29\n} } } */
/* { dg-final { scan-assembler {DW_CFA_restore, column 0x2b\n} } } */
/* { dg-final { scan-assembler-times {DW_CFA_def_cfa\n\t\.uleb128 0xc\n\t\.uleb128 0x4\n} 2 } } */
