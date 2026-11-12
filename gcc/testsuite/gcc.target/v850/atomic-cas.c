/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */

int v;

int cas_strong (int *e, int x)
{
  return __atomic_compare_exchange_n (&v, e, x, 0, __ATOMIC_RELAXED,
				      __ATOMIC_RELAXED);
}

int cas_weak (int *e, int x)
{
  return __atomic_compare_exchange_n (&v, e, x, 1, __ATOMIC_RELAXED,
				      __ATOMIC_RELAXED);
}

int s_bool (int o, int n) { return __sync_bool_compare_and_swap (&v, o, n); }
int s_val (int o, int n) { return __sync_val_compare_and_swap (&v, o, n); }
int xchg (int x) { return __atomic_exchange_n (&v, x, __ATOMIC_RELAXED); }
int s_tas (int x) { return __sync_lock_test_and_set (&v, x); }

/* { dg-final { scan-assembler-times "ldl\\.w" 6 } } */
/* { dg-final { scan-assembler-times "stc\\.w" 6 } } */
/* { dg-final { scan-assembler-not "caxi" } } */
/* { dg-final { scan-assembler-not "__atomic_|__sync_" } } */
