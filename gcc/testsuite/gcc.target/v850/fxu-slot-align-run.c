/* { dg-do run } */
/* { dg-options "-O0 -mfxu" } */
/* { dg-require-effective-target v850_fxu_hw } */


typedef char v16qi __attribute__ ((vector_size (16)));
typedef unsigned int v4si __attribute__ ((vector_size (16)));
struct S { v16qi a, b; } s;
union U { char f[16]; v4si v; } data;

__attribute__ ((noinline)) v4si
conv (struct S *p)
{
  return (v4si) p->b;
}

int
main (void)
{
  for (int i = 0; i < 16; i++)
    s.b[i] = 'm' + i;
  data.v = conv (&s);
  if (data.f[0] != 'm' || data.f[15] != 'm' + 15)
    __builtin_abort ();
  return 0;
}
