/* { dg-do preprocess } */
/* { dg-options "-mv850e3v5" } */
/* { dg-skip-if "tests the code without -mg4" { *-*-* } { "-mg4" "-mg4mh2" } { "" } } */

#if __GCC_ATOMIC_INT_LOCK_FREE != 2 || __GCC_ATOMIC_LONG_LOCK_FREE != 2 \
    || __GCC_ATOMIC_POINTER_LOCK_FREE != 2
#error 32-bit atomics not lock free
#endif
#ifndef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
#error no 32-bit compare and swap
#endif
#if __GCC_ATOMIC_CHAR_LOCK_FREE != 1 || __GCC_ATOMIC_SHORT_LOCK_FREE != 1 \
    || __GCC_ATOMIC_LLONG_LOCK_FREE != 1
#error sub-word or 64-bit atomics changed
#endif
#if defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 \
    || defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 \
    || defined __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
#error sub-word or 64-bit compare and swap changed
#endif
