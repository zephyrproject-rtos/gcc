/* { dg-do run } */
/* { dg-options "-O2 -mv850e3v5" } */

extern void abort (void);

static volatile int v;

int
main (void)
{
  int e;

  v = 10;
  if (__atomic_fetch_add (&v, 5, __ATOMIC_SEQ_CST) != 10 || v != 15)
    abort ();
  if (__atomic_fetch_sub (&v, 3, __ATOMIC_ACQUIRE) != 15 || v != 12)
    abort ();
  v = 0x0f;
  if (__atomic_fetch_and (&v, 0x3c, __ATOMIC_RELEASE) != 0x0f || v != 0x0c)
    abort ();
  if (__atomic_fetch_or (&v, 0x30, __ATOMIC_ACQ_REL) != 0x0c || v != 0x3c)
    abort ();
  if (__atomic_fetch_xor (&v, 0x0f, __ATOMIC_RELAXED) != 0x3c || v != 0x33)
    abort ();
  if (__atomic_fetch_nand (&v, 0x0f, __ATOMIC_SEQ_CST) != 0x33 || v != ~0x03)
    abort ();
  if (__atomic_nand_fetch (&v, 0x0f, __ATOMIC_SEQ_CST) != ~0x0c)
    abort ();
  if (__atomic_exchange_n (&v, 7, __ATOMIC_SEQ_CST) != ~0x0c || v != 7)
    abort ();
  e = 7;
  if (!__atomic_compare_exchange_n (&v, &e, 8, 0, __ATOMIC_SEQ_CST,
				    __ATOMIC_SEQ_CST) || v != 8)
    abort ();
  if (__atomic_compare_exchange_n (&v, &e, 9, 0, __ATOMIC_SEQ_CST,
				   __ATOMIC_RELAXED) || e != 8 || v != 8)
    abort ();
  __atomic_store_n (&v, 3, __ATOMIC_RELEASE);
  if (__atomic_load_n (&v, __ATOMIC_ACQUIRE) != 3)
    abort ();
  if (__sync_val_compare_and_swap (&v, 3, 4) != 3 || v != 4)
    abort ();
  if (__sync_lock_test_and_set (&v, 1) != 4)
    abort ();
  __sync_lock_release (&v);
  if (v != 0)
    abort ();
  __sync_synchronize ();
  return 0;
}
