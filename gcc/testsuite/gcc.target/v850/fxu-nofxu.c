/* { dg-do compile } */
/* { dg-options "-mg4mh2" } */
/* { dg-skip-if "tests the code without -mfxu" { *-*-* } { "-mfxu" } { "" } } */

typedef float vf __attribute__ ((vector_size (16)));
vf a, b;

void
f (void)
{
  a = __builtin_v850_addf_s4 (a, b);	/* { dg-error "implicit declaration|incompatible types" } */
}
