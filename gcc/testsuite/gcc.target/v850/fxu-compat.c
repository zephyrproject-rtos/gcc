/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

#include <v850_fxu.h>

__ev128_f32__ x;
float r;

__ev128_f32__
f (void)
{
  __ev128_f32__ vx = __ev128_create_f32 (-1.0f, 2.2f, -3.3f, 4.5f);
  __ev128_f32__ vy = __ev128_set_f32 (vx, 1.0f, 1);
  r = __ev128_get_f32 (vy, 1);
  return __ev128_addfs (x, vy);
}

/* { dg-final { scan-assembler {\taddf\.s4 } } } */
