#define BASEADDR 0xF0000000ULL
int main ()
{
  unsigned long long start;
  start = (unsigned long long) BASEADDR;
  return 0;
}
/* { dg-final { scan-assembler "addik\tr(\[0-9]\|\[1-2]\[0-9]\|3\[0-1]),r0,0x00000000" } } */
/* { dg-final { scan-assembler "addik\tr(\[0-9]\|\[1-2]\[0-9]\|3\[0-1]),r0,0xf0000000" } } */
