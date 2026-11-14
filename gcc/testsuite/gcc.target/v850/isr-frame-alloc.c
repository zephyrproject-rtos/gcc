/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */


volatile int buf[16];

void __attribute__ ((interrupt_handler))
h (void)
{
  volatile int a[4];
  int x0 = buf[0], x1 = buf[1], x2 = buf[2], x3 = buf[3], x4 = buf[4];
  int x5 = buf[5], x6 = buf[6], x7 = buf[7], x8 = buf[8], x9 = buf[9];
  a[0] = x0 * x5;
  a[1] = x1 * x6;
  a[2] = x2 * x7;
  a[3] = x3 * x8;
  buf[10] = a[0] + a[1] + a[2] + a[3] + x4 * x9 + x0 + x9;
}

/* { dg-final { scan-assembler "addi -32,sp,sp" } } */
/* { dg-final { scan-assembler "add -16,sp" } } */
/* { dg-final { scan-assembler "addi 48,sp,sp" } } */
