/* { dg-do compile } */
/* { dg-options "-O2 -mg4" } */

#define OPS(T, N)							\
  T N##_v;								\
  int N##_cas (T *e, T x)						\
  {									\
    return __atomic_compare_exchange_n (&N##_v, e, x, 0,		\
					__ATOMIC_RELAXED, __ATOMIC_RELAXED); \
  }									\
  T N##_xchg (T x) { return __atomic_exchange_n (&N##_v, x, __ATOMIC_RELAXED); } \
  T N##_add (T x) { return __atomic_fetch_add (&N##_v, x, __ATOMIC_RELAXED); } \
  T N##_sub (T x) { return __atomic_fetch_sub (&N##_v, x, __ATOMIC_RELAXED); } \
  T N##_and (T x) { return __atomic_fetch_and (&N##_v, x, __ATOMIC_RELAXED); } \
  T N##_or (T x) { return __atomic_fetch_or (&N##_v, x, __ATOMIC_RELAXED); } \
  T N##_xor (T x) { return __atomic_fetch_xor (&N##_v, x, __ATOMIC_RELAXED); } \
  T N##_nand (T x) { return __atomic_fetch_nand (&N##_v, x, __ATOMIC_RELAXED); } \
  void N##_st (T x) { __atomic_store_n (&N##_v, x, __ATOMIC_RELAXED); }

OPS (unsigned char, c)
OPS (short, s)

/* { dg-final { scan-assembler-times "ldl\\.bu" 9 } } */
/* { dg-final { scan-assembler-times "stc\\.b" 9 } } */
/* { dg-final { scan-assembler-times "ldl\\.hu" 9 } } */
/* { dg-final { scan-assembler-times "stc\\.h" 9 } } */
/* { dg-final { scan-assembler-not "__atomic_|__sync_" } } */
