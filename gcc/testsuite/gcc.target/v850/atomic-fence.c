/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */

int v;

int m_relaxed (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_RELAXED); }
int m_acquire (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_ACQUIRE); }
int m_release (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_RELEASE); }
int m_acq_rel (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_ACQ_REL); }
int m_seq_cst (int x) { return __atomic_fetch_add (&v, x, __ATOMIC_SEQ_CST); }
void t_seq_cst (void) { __atomic_thread_fence (__ATOMIC_SEQ_CST); }
void t_relaxed (void) { __atomic_thread_fence (__ATOMIC_RELAXED); }
void t_signal (void) { __atomic_signal_fence (__ATOMIC_SEQ_CST); }
void s_sync (void) { __sync_synchronize (); }

/* { dg-final { scan-assembler-times "syncm" 8 } } */
/* { dg-final { scan-assembler-not "__atomic_|__sync_" } } */
