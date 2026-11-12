/* { dg-do compile } */
/* { dg-options "-O2 -mv850e2v3" } */

int v;

int f_add (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_SEQ_CST); }
int cas (int *e, int x)
{
  return __atomic_compare_exchange_n (&v, e, x, 0, __ATOMIC_SEQ_CST,
				      __ATOMIC_SEQ_CST);
}
void st (int x) { __atomic_store_n (&v, x, __ATOMIC_SEQ_CST); }

#if __GCC_ATOMIC_INT_LOCK_FREE != 1 || defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
#error lock-free macros changed for v850e2v3
#endif

/* { dg-final { scan-assembler "__atomic_fetch_add_4" } } */
/* { dg-final { scan-assembler "__atomic_compare_exchange_4" } } */
/* { dg-final { scan-assembler-not "ldl\\.w|stc\\.w|syncm" } } */
