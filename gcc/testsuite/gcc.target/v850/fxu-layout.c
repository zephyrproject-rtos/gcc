/* { dg-do compile } */
/* { dg-options "-mfxu" } */

typedef float vf __attribute__ ((vector_size (16)));
struct s { int i; vf v; };
struct d { char c; double x; long long l; };

_Static_assert (__alignof__ (vf) == 16, "vector alignment");
_Static_assert (__builtin_offsetof (struct s, v) == 16, "vector field");
_Static_assert (__alignof__ (double) == 4, "double alignment");
_Static_assert (__alignof__ (long long) == 4, "long long alignment");
_Static_assert (__builtin_offsetof (struct d, x) == 4, "double field");
_Static_assert (sizeof (struct d) == 20, "struct size");
