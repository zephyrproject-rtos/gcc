/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */

int v;

int f_add (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_RELAXED); }
int f_sub (int x) { return __atomic_fetch_sub (&v, x, __ATOMIC_RELAXED); }
int f_and (int x) { return __atomic_fetch_and (&v, x, __ATOMIC_RELAXED); }
int f_or (int x) { return __atomic_fetch_or (&v, x, __ATOMIC_RELAXED); }
int f_xor (int x) { return __atomic_fetch_xor (&v, x, __ATOMIC_RELAXED); }
int f_nand (int x) { return __atomic_fetch_nand (&v, x, __ATOMIC_RELAXED); }
int add_f (int x) { return __atomic_add_fetch (&v, x, __ATOMIC_RELAXED); }
int sub_f (int x) { return __atomic_sub_fetch (&v, x, __ATOMIC_RELAXED); }
int and_f (int x) { return __atomic_and_fetch (&v, x, __ATOMIC_RELAXED); }
int or_f (int x) { return __atomic_or_fetch (&v, x, __ATOMIC_RELAXED); }
int xor_f (int x) { return __atomic_xor_fetch (&v, x, __ATOMIC_RELAXED); }
int nand_f (int x) { return __atomic_nand_fetch (&v, x, __ATOMIC_RELAXED); }
int s_add (int x) { return __sync_fetch_and_add (&v, x); }
int s_nand (int x) { return __sync_fetch_and_nand (&v, x); }

/* { dg-final { scan-assembler-times "ldl\\.w" 14 } } */
/* { dg-final { scan-assembler-times "stc\\.w" 14 } } */
/* { dg-final { scan-assembler-times "\tnot " 4 } } */
/* { dg-final { scan-assembler-not "__atomic_|__sync_" } } */
