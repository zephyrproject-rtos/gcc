/* ISO C11 Standard: 7.26 - Thread support library  <threads.h>.
   Copyright (C) 2018-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/* weak C11 thread.h implementations to support gthr-c11.h */

#include <threads.h>

__attribute__((weak))
int thrd_create(thrd_t *__thr, thrd_start_t __func, void *__arg)
{
    (void) __thr;
    (void) __func;
    (void) __arg;

    return thrd_error;
}

__attribute__((weak))
int thrd_equal(thrd_t __lhs, thrd_t __rhs)
{
    (void) __lhs;
    (void) __rhs;

    return 0;
}

__attribute__((weak))
thrd_t thrd_current(void)
{
    return (thrd_t)-1;
}

__attribute__((weak))
int thrd_sleep(const struct timespec *__time_point,
		       struct timespec *__remaining)
{
    (void) __time_point;
    (void) __remaining;

    return -1;
}

__attribute__ ((__noreturn__))
__attribute__((weak))
void thrd_exit(int __res)
{
    (void) __res;

    do {
    } while(1);
}

__attribute__((weak))
int thrd_detach (thrd_t __thr)
{
    (void) __thr;

    return thrd_error;
}

__attribute__((weak))
int thrd_join(thrd_t __thr, int *__res)
{
    (void) __thr;
    (void) __res;

    return thrd_error;
}

__attribute__((weak))
void thrd_yield(void)
{
}

__attribute__((weak))
int mtx_init (mtx_t *__mutex, int __type)
{
    (void) __mutex;
    (void) __type;

    return thrd_error;
}

__attribute__((weak))
int mtx_lock (mtx_t *__mutex)
{
    (void) __mutex;

    return thrd_error;
}

__attribute__((weak))
int mtx_timedlock (mtx_t *__restrict __mutex,
			  const struct timespec *__restrict __time_point)
{
    (void) __mutex;
    (void) __time_point;

    return thrd_error;
}

__attribute__((weak))
int mtx_trylock (mtx_t *__mutex)
{
    (void) __mutex;

    return thrd_error;
}

__attribute__((weak))
int mtx_unlock (mtx_t *__mutex)
{
    (void) __mutex;

    return thrd_error;
}

__attribute__((weak))
void mtx_destroy (mtx_t *__mutex)
{
    (void) __mutex;
}

__attribute__((weak))
void call_once(once_flag *__flag, void (*__func)(void))
{
    (void) __flag;
    (void) __func;
}

__attribute__((weak))
int cnd_init (cnd_t *__cond)
{
    (void) __cond;

    return thrd_error;
}

__attribute__((weak))
int cnd_signal (cnd_t *__cond)
{
    (void) __cond;

    return thrd_error;
}

__attribute__((weak))
int cnd_broadcast (cnd_t *__cond)
{
    (void) __cond;

    return thrd_error;
}

__attribute__((weak))
int cnd_wait (cnd_t *__cond, mtx_t *__mutex)
{
    (void) __cond;
    (void) __mutex;

    return thrd_error;
}

__attribute__((weak))
int cnd_timedwait (cnd_t *__restrict __cond,
			  mtx_t *__restrict __mutex,
			  const struct timespec *__restrict __time_point)
{
    (void) __cond;
    (void) __mutex;
    (void) __time_point;

    return thrd_error;
}

__attribute__((weak))
void cnd_destroy (cnd_t *__COND)
{
    (void) __COND;
}


/* Thread specific storage functions.  */

__attribute__((weak))
int tss_create (tss_t *__tss_id, tss_dtor_t __destructor)
{
    (void) __tss_id;
    (void) __destructor;

    return thrd_error;
}

__attribute__((weak))
void *tss_get (tss_t __tss_id)
{
    (void) __tss_id;

    return NULL;
}

__attribute__((weak))
int tss_set (tss_t __tss_id, void *__val)
{
    (void) __tss_id;
    (void) __val;

    return thrd_error;
}

__attribute__((weak))
void tss_delete (tss_t __tss_id)
{
    (void) __tss_id;
}
