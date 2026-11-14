/* RH850 FXU intrinsics.

   Copyright The GNU Toolchain Authors.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _GCC_V850_FXU_H
#define _GCC_V850_FXU_H

#ifndef __V850_FXU__
#error "v850_fxu.h requires -mfxu"
#endif

typedef float __v850_v4sf __attribute__ ((__vector_size__ (16)));
typedef int __v850_v4si __attribute__ ((__vector_size__ (16)));
typedef unsigned int __v850_v4su __attribute__ ((__vector_size__ (16)));

typedef __v850_v4sf __ev128_f32__;

static __inline__ __attribute__ ((__always_inline__)) __ev128_f32__
__ev128_create_f32 (float __a, float __b, float __c, float __d)
{
  return (__ev128_f32__) { __a, __b, __c, __d };
}

static __inline__ __attribute__ ((__always_inline__)) __ev128_f32__
__ev128_set_f32 (__ev128_f32__ __v, float __x, int __i)
{
  __v[__i] = __x;
  return __v;
}

static __inline__ __attribute__ ((__always_inline__)) float
__ev128_get_f32 (__ev128_f32__ __v, int __i)
{
  return __v[__i];
}

static __inline__ __attribute__ ((__always_inline__)) __ev128_f32__
__ev128_addfs (__ev128_f32__ __a, __ev128_f32__ __b)
{
  return __builtin_v850_addf_s4 (__a, __b);
}

#endif
