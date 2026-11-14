/* { dg-do compile } */
/* { dg-options "-mv850e3v5 -O2 -g -dA" } */

volatile int cnt;

void __attribute__ ((interrupt)) h (void) { cnt++; }

/* { dg-final { scan-assembler {DW_CFA_def_cfa_offset\n\t\.uleb128 0x14\n} } } */
/* { dg-final { scan-assembler {DW_CFA_def_cfa_offset\n\t\.uleb128 0x1c\n} } } */
/* { dg-final { scan-assembler {DW_CFA_offset, column 0x1e\n\t\.uleb128 0x5\n} } } */
