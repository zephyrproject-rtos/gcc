/* { dg-do run } */
/* { dg-options "-O2 -mg4" } */

extern void abort (void);

#define TEST(T, N, M)							\
  static volatile T N;							\
  static void								\
  test_##N (void)							\
  {									\
    T e;								\
    N = 0x5a;								\
    if (__atomic_fetch_add (&N, 0x10, __ATOMIC_SEQ_CST) != 0x5a || N != 0x6a) \
      abort ();								\
    if (__atomic_fetch_sub (&N, 0x6b, __ATOMIC_SEQ_CST) != 0x6a || N != (T) -1) \
      abort ();								\
    N = 0x0f;								\
    if (__atomic_fetch_and (&N, 0x3c, __ATOMIC_SEQ_CST) != 0x0f || N != 0x0c) \
      abort ();								\
    if (__atomic_fetch_or (&N, 0x30, __ATOMIC_SEQ_CST) != 0x0c || N != 0x3c) \
      abort ();								\
    if (__atomic_fetch_xor (&N, 0x0f, __ATOMIC_SEQ_CST) != 0x3c || N != 0x33) \
      abort ();								\
    if (__atomic_fetch_nand (&N, 0x0f, __ATOMIC_SEQ_CST) != 0x33	\
	|| N != (T) ~0x03)						\
      abort ();								\
    if (__atomic_add_fetch (&N, 4, __ATOMIC_SEQ_CST) != (T) (~0x03 + 4)) \
      abort ();								\
    N = M;								\
    if (__atomic_exchange_n (&N, 7, __ATOMIC_SEQ_CST) != M || N != 7) \
      abort ();								\
    e = 7;								\
    if (!__atomic_compare_exchange_n (&N, &e, M, 0, __ATOMIC_SEQ_CST,	\
				      __ATOMIC_SEQ_CST) || N != M)	\
      abort ();								\
    e = 7;								\
    if (__atomic_compare_exchange_n (&N, &e, 9, 0, __ATOMIC_SEQ_CST,	\
				     __ATOMIC_SEQ_CST) || e != M || N != M) \
      abort ();								\
    __atomic_store_n (&N, 3, __ATOMIC_SEQ_CST);				\
    if (__atomic_load_n (&N, __ATOMIC_SEQ_CST) != 3)			\
      abort ();								\
    if (!__sync_bool_compare_and_swap (&N, 3, (T) -2) || N != (T) -2)	\
      abort ();								\
  }

TEST (signed char, sc, (signed char) -100)
TEST (unsigned char, uc, 200)
TEST (short, ss, (short) -30000)
TEST (unsigned short, us, 60000)

static volatile _Bool flag;

int
main (void)
{
  test_sc ();
  test_uc ();
  test_ss ();
  test_us ();
  if (__atomic_test_and_set (&flag, __ATOMIC_SEQ_CST))
    abort ();
  if (!__atomic_test_and_set (&flag, __ATOMIC_SEQ_CST))
    abort ();
  __atomic_clear (&flag, __ATOMIC_SEQ_CST);
  if (flag)
    abort ();
  return 0;
}
