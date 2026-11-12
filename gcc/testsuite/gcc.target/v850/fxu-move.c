/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

typedef float vf __attribute__ ((vector_size (16)));
typedef int vi __attribute__ ((vector_size (16)));

vf g, h;
vi gi;
typedef vf vf4 __attribute__ ((aligned (4)));
struct __attribute__ ((packed)) pb { char c; vf v; } pb;

void copy (void) { g = h; }
void icopy (vi *p) { gi = *p; }
void cst (void) { g = (vf) { 1.0f, 2.0f, 3.0f, 4.0f }; }
vf ld_w (vf4 *p) { return *p; }
void st_w (vf4 *p, vf v) { *p = v; }
void reg (vf a, vf b) { h = b; g = a; }
extern void e2 (vf, vf);
void swap (vf a, vf b) { e2 (b, a); }
vf ld_byte (void) { return pb.v; }

/* { dg-final { scan-assembler {\tmov hilo\(_h\),(r[0-9]+)\n(.*\n)*\tldv\.qw 0\[\1\], wr[0-9]+} } } */
/* { dg-final { scan-assembler {\tstv\.qw wr[0-9]+, 0\[r[0-9]+\]} } } */
/* { dg-final { scan-assembler {\.align 4\n\.LC0:} } } */
/* { dg-final { scan-assembler {\tldv\.dw 3, 0\[r[0-9]+\], wr[0-9]+\n\tldv\.dw 2, 8\[r[0-9]+\], wr[0-9]+} } } */
/* { dg-final { scan-assembler {\tstv\.dw 0, wr[0-9]+, 0\[r[0-9]+\]\n\tstv\.dw 1, wr[0-9]+, 8\[r[0-9]+\]} } } */
/* { dg-final { scan-assembler {\tmovv\.w4 wr[0-9]+, wr[0-9]+} } } */
/* { dg-final { scan-assembler-not {ldv\.qw [^0-9]} } } */
/* { dg-final { scan-assembler-not {stv\.qw wr[0-9]+, [^0-9-]} } } */
