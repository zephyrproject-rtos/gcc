/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O3 -ffast-math" } */


#define N 16
float a[N] __attribute__ ((aligned (16)));
static const float in[N] = { 5.0f, -47.0f, 11.0f, 8.0f, -24.0f, 12.0f, 24.0f, 4.0f, -50.0f, -32.0f, 34.0f, 17.0f, 21.0f, -6.0f, 14.0f, 35.0f };

__attribute__ ((noipa)) float
sum (void)
{
  float s = 0.0f;
  for (int i = 0; i < N; i++)
    s += a[i];
  return s;
}

__attribute__ ((noipa)) float
smax (void)
{
  float s = a[0];
  for (int i = 0; i < N; i++)
    s = s > a[i] ? s : a[i];
  return s;
}

__attribute__ ((noipa)) float
smin (void)
{
  float s = a[0];
  for (int i = 0; i < N; i++)
    s = s < a[i] ? s : a[i];
  return s;
}

int
main (void)
{
  for (int i = 0; i < N; i++)
    a[i] = in[i];
  if (sum () != 26.0f || smax () != 35.0f || smin () != -50.0f)
    __builtin_abort ();
  return 0;
}
