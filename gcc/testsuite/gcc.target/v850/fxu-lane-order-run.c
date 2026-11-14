/* { dg-do run { target v850_fxu_hw } } */
/* { dg-options "-mfxu -O2" } */


typedef float vf __attribute__ ((vector_size (16)));

static unsigned int in[4] __attribute__ ((aligned (16)))
  = { 0x11111111, 0x22222222, 0x33333333, 0x44444444 };
static unsigned int out[4] __attribute__ ((aligned (16)));
static unsigned int w[4];

#define ONE(i)								\
  do									\
    {									\
      __asm__ volatile ("ldv.w 15, 0[%1], %0" : "=w" (v) : "r" (&in[0])	\
			: "memory");					\
      __asm__ volatile ("ldv.w %2, 0[%1], %0" : "+w" (v)			\
			: "r" (&in[3]), "i" (1 << (i)) : "memory");	\
      __asm__ volatile ("stv.qw %0, 0[%1]" : : "w" (v), "r" (out)		\
			: "memory");					\
      for (int j = 0; j < 4; j++)					\
	if (out[j] != (j == (i) ? in[3] : in[0]))			\
	  __builtin_abort ();						\
    }									\
  while (0)

int
main (void)
{
  vf v;
  int i;

  __asm__ volatile ("ldv.qw 0[%1], %0" : "=w" (v) : "r" (in) : "memory");
  __asm__ volatile ("stv.w 0, %0, 0[%1]\n\tstv.w 1, %0, 4[%1]\n\t"
		    "stv.w 2, %0, 8[%1]\n\tstv.w 3, %0, 12[%1]"
		    : : "w" (v), "r" (w) : "memory");
  for (i = 0; i < 4; i++)
    if (w[i] != in[i])
      __builtin_abort ();

  ONE (0);
  ONE (1);
  ONE (2);
  ONE (3);
  return 0;
}
