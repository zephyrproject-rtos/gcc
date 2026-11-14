/* { dg-do preprocess } */
/* { dg-options "-mg4" } */

#if __GCC_ATOMIC_CHAR_LOCK_FREE != 2 || __GCC_ATOMIC_SHORT_LOCK_FREE != 2 \
    || __GCC_ATOMIC_BOOL_LOCK_FREE != 2 || __GCC_ATOMIC_INT_LOCK_FREE != 2
#error 8, 16 or 32-bit atomics not lock free
#endif
#if !defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 \
    || !defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 \
    || !defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
#error compare and swap missing
#endif
#if __GCC_ATOMIC_LLONG_LOCK_FREE != 1 || defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
#error 64-bit atomics changed
#endif
