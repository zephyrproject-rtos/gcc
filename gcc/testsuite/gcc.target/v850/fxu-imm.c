/* { dg-do compile } */
/* { dg-options "-mfxu" } */

#include <v850_fxu.h>

__v850_v4sf a, b;
__v850_v4si m;
int k;

void
f (void)
{
  m = __builtin_v850_cmpf_s4 (a, b, 16);	/* { dg-error "constant in the range 0 to 15" } */
  a = __builtin_v850_flpv_s4 (a, k);		/* { dg-error "constant in the range 0 to 3" } */
  a = __builtin_v850_shflv_w4 (a, b, 4096);	/* { dg-error "constant in the range 0 to 4095" } */
  k = __builtin_v850_trfsrv_w4 (m, 6);		/* { dg-error "constant in the range 0 to 5" } */
}
