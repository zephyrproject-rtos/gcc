/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */

int v;

int l_relaxed (void) { return __atomic_load_n (&v, __ATOMIC_RELAXED); }
int l_acquire (void) { return __atomic_load_n (&v, __ATOMIC_ACQUIRE); }
int l_seq_cst (void) { return __atomic_load_n (&v, __ATOMIC_SEQ_CST); }
void s_relaxed (int x) { __atomic_store_n (&v, x, __ATOMIC_RELAXED); }
void s_release (int x) { __atomic_store_n (&v, x, __ATOMIC_RELEASE); }
void s_seq_cst (int x) { __atomic_store_n (&v, x, __ATOMIC_SEQ_CST); }
void s_unlock (void) { __sync_lock_release (&v); }

/* { dg-final { scan-assembler-times "ld\\.w" 3 } } */
/* { dg-final { scan-assembler-times "ldl\\.w" 4 } } */
/* { dg-final { scan-assembler-times "stc\\.w" 4 } } */
/* { dg-final { scan-assembler-times "syncm" 7 } } */
/* { dg-final { scan-assembler-not "__atomic_|__sync_" } } */
