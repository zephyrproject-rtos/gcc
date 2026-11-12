/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */


#define R32(a) (*(volatile unsigned int *) (a))
#define R16(a) (*(volatile unsigned short *) (a))

void and_si (void) { R32 (0xff981180) &= ~1u; }
void ior_si (void) { R32 (0xff981180) |= 1u << 9; }
void xor_si (void) { R32 (0xff981180) ^= 1u << 17; }
void and_hi (void) { R16 (0xff981184) &= (unsigned short) ~2u; }
void ior_hi (void) { R16 (0xff981184) |= 1u << 9; }
void xor_hi (void) { R16 (0xff981184) ^= 1u << 3; }

/* { dg-final { scan-assembler-not {\m(set1|clr1|not1)\M} } } */
