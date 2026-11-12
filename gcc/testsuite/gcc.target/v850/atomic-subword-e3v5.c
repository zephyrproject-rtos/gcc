/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */
/* { dg-skip-if "tests the code without -mg4" { *-*-* } { "-mg4" "-mg4mh2" "-mfxu" } { "" } } */

unsigned char c;
short s;

int fc (unsigned char x) { return __atomic_fetch_add (&c, x, __ATOMIC_SEQ_CST); }
int fs (short x) { return __atomic_exchange_n (&s, x, __ATOMIC_SEQ_CST); }

/* { dg-final { scan-assembler "__atomic_fetch_add_1" } } */
/* { dg-final { scan-assembler "__atomic_exchange_2" } } */
/* { dg-final { scan-assembler-not "ldl\\.bu|ldl\\.hu|stc\\.b|stc\\.h" } } */
