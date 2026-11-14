/* { dg-do compile } */
/* { dg-options "-mfxu -O2" } */

#include <v850_fxu.h>

typedef __v850_v4sf vf;
typedef __v850_v4si vi;

vf a, b, c, rf;
vi m, ri;
int r;
float fl[4];
short hs[4];

void
t_addf_s4 (void)
{
  rf = __builtin_v850_addf_s4 (a, b);
}

void
t_subf_s4 (void)
{
  rf = __builtin_v850_subf_s4 (a, b);
}

void
t_mulf_s4 (void)
{
  rf = __builtin_v850_mulf_s4 (a, b);
}

void
t_divf_s4 (void)
{
  rf = __builtin_v850_divf_s4 (a, b);
}

void
t_maxf_s4 (void)
{
  rf = __builtin_v850_maxf_s4 (a, b);
}

void
t_minf_s4 (void)
{
  rf = __builtin_v850_minf_s4 (a, b);
}

void
t_addsubf_s4 (void)
{
  rf = __builtin_v850_addsubf_s4 (a, b);
}

void
t_addsubnf_s4 (void)
{
  rf = __builtin_v850_addsubnf_s4 (a, b);
}

void
t_subaddf_s4 (void)
{
  rf = __builtin_v850_subaddf_s4 (a, b);
}

void
t_subaddnf_s4 (void)
{
  rf = __builtin_v850_subaddnf_s4 (a, b);
}

void
t_addxf_s4 (void)
{
  rf = __builtin_v850_addxf_s4 (a, b);
}

void
t_subxf_s4 (void)
{
  rf = __builtin_v850_subxf_s4 (a, b);
}

void
t_mulxf_s4 (void)
{
  rf = __builtin_v850_mulxf_s4 (a, b);
}

void
t_addsubxf_s4 (void)
{
  rf = __builtin_v850_addsubxf_s4 (a, b);
}

void
t_addsubnxf_s4 (void)
{
  rf = __builtin_v850_addsubnxf_s4 (a, b);
}

void
t_subaddxf_s4 (void)
{
  rf = __builtin_v850_subaddxf_s4 (a, b);
}

void
t_subaddnxf_s4 (void)
{
  rf = __builtin_v850_subaddnxf_s4 (a, b);
}

void
t_addrf_s4 (void)
{
  rf = __builtin_v850_addrf_s4 (a, b);
}

void
t_subrf_s4 (void)
{
  rf = __builtin_v850_subrf_s4 (a, b);
}

void
t_mulrf_s4 (void)
{
  rf = __builtin_v850_mulrf_s4 (a, b);
}

void
t_maxrf_s4 (void)
{
  rf = __builtin_v850_maxrf_s4 (a, b);
}

void
t_minrf_s4 (void)
{
  rf = __builtin_v850_minrf_s4 (a, b);
}

void
t_absf_s4 (void)
{
  rf = __builtin_v850_absf_s4 (a);
}

void
t_negf_s4 (void)
{
  rf = __builtin_v850_negf_s4 (a);
}

void
t_sqrtf_s4 (void)
{
  rf = __builtin_v850_sqrtf_s4 (a);
}

void
t_recipf_s4 (void)
{
  rf = __builtin_v850_recipf_s4 (a);
}

void
t_rsqrtf_s4 (void)
{
  rf = __builtin_v850_rsqrtf_s4 (a);
}

void
t_fmaf_s4 (void)
{
  rf = __builtin_v850_fmaf_s4 (a, b, c);
}

void
t_fmsf_s4 (void)
{
  rf = __builtin_v850_fmsf_s4 (a, b, c);
}

void
t_fnmaf_s4 (void)
{
  rf = __builtin_v850_fnmaf_s4 (a, b, c);
}

void
t_fnmsf_s4 (void)
{
  rf = __builtin_v850_fnmsf_s4 (a, b, c);
}

void
t_ceilf_sw4 (void)
{
  ri = __builtin_v850_ceilf_sw4 (a);
}

void
t_ceilf_suw4 (void)
{
  ri = __builtin_v850_ceilf_suw4 (a);
}

void
t_floorf_sw4 (void)
{
  ri = __builtin_v850_floorf_sw4 (a);
}

void
t_floorf_suw4 (void)
{
  ri = __builtin_v850_floorf_suw4 (a);
}

void
t_roundf_sw4 (void)
{
  ri = __builtin_v850_roundf_sw4 (a);
}

void
t_roundf_suw4 (void)
{
  ri = __builtin_v850_roundf_suw4 (a);
}

void
t_trncf_sw4 (void)
{
  ri = __builtin_v850_trncf_sw4 (a);
}

void
t_trncf_suw4 (void)
{
  ri = __builtin_v850_trncf_suw4 (a);
}

void
t_cvtf_sw4 (void)
{
  ri = __builtin_v850_cvtf_sw4 (a);
}

void
t_cvtf_suw4 (void)
{
  ri = __builtin_v850_cvtf_suw4 (a);
}

void
t_cvtf_sh4 (void)
{
  ri = __builtin_v850_cvtf_sh4 (a);
}

void
t_cvtf_ws4 (void)
{
  rf = __builtin_v850_cvtf_ws4 (m);
}

void
t_cvtf_uws4 (void)
{
  rf = __builtin_v850_cvtf_uws4 (m);
}

void
t_cvtf_hs4 (void)
{
  rf = __builtin_v850_cvtf_hs4 (m);
}

void
t_cmpf_s4 (void)
{
  ri = __builtin_v850_cmpf_s4 (a, b, 6);
}

void
t_cmovf_w4 (void)
{
  rf = __builtin_v850_cmovf_w4 (m, a, b);
}

void
t_cmovf_w4i (void)
{
  ri = __builtin_v850_cmovf_w4i (m, m, ri);
}

void
t_shflv_w4 (void)
{
  rf = __builtin_v850_shflv_w4 (a, b, 2643);
}

void
t_shflv_w4i (void)
{
  ri = __builtin_v850_shflv_w4i (m, ri, 4095);
}

void
t_flpv_s4 (void)
{
  rf = __builtin_v850_flpv_s4 (a, 3);
}

void
t_trfsrv_w4 (void)
{
  r = __builtin_v850_trfsrv_w4 (m, 5);
}

void
t_ldv_w (void)
{
  rf = __builtin_v850_ldv_w (a, fl, 9);
}

void
t_ldv_dw (void)
{
  rf = __builtin_v850_ldv_dw (a, fl, 2);
}

void
t_ldv_qw (void)
{
  rf = __builtin_v850_ldv_qw (fl);
}

void
t_ldvz_h4 (void)
{
  ri = __builtin_v850_ldvz_h4 (hs);
}

void
t_stv_w (void)
{
  __builtin_v850_stv_w (fl, a, 3);
}

void
t_stv_dw (void)
{
  __builtin_v850_stv_dw (fl, a, 1);
}

void
t_stv_qw (void)
{
  __builtin_v850_stv_qw (fl, a);
}

void
t_stvz_h4 (void)
{
  __builtin_v850_stvz_h4 (hs, m);
}

/* { dg-final { scan-assembler {\taddf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubf\.s4 } } } */
/* { dg-final { scan-assembler {\tmulf\.s4 } } } */
/* { dg-final { scan-assembler {\tdivf\.s4 } } } */
/* { dg-final { scan-assembler {\tmaxf\.s4 } } } */
/* { dg-final { scan-assembler {\tminf\.s4 } } } */
/* { dg-final { scan-assembler {\taddsubf\.s4 } } } */
/* { dg-final { scan-assembler {\taddsubnf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubaddf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubaddnf\.s4 } } } */
/* { dg-final { scan-assembler {\taddxf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubxf\.s4 } } } */
/* { dg-final { scan-assembler {\tmulxf\.s4 } } } */
/* { dg-final { scan-assembler {\taddsubxf\.s4 } } } */
/* { dg-final { scan-assembler {\taddsubnxf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubaddxf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubaddnxf\.s4 } } } */
/* { dg-final { scan-assembler {\taddrf\.s4 } } } */
/* { dg-final { scan-assembler {\tsubrf\.s4 } } } */
/* { dg-final { scan-assembler {\tmulrf\.s4 } } } */
/* { dg-final { scan-assembler {\tmaxrf\.s4 } } } */
/* { dg-final { scan-assembler {\tminrf\.s4 } } } */
/* { dg-final { scan-assembler {\tabsf\.s4 } } } */
/* { dg-final { scan-assembler {\tnegf\.s4 } } } */
/* { dg-final { scan-assembler {\tsqrtf\.s4 } } } */
/* { dg-final { scan-assembler {\trecipf\.s4 } } } */
/* { dg-final { scan-assembler {\trsqrtf\.s4 } } } */
/* { dg-final { scan-assembler {\tfmaf\.s4 } } } */
/* { dg-final { scan-assembler {\tfmsf\.s4 } } } */
/* { dg-final { scan-assembler {\tfnmaf\.s4 } } } */
/* { dg-final { scan-assembler {\tfnmsf\.s4 } } } */
/* { dg-final { scan-assembler {\tceilf\.sw4 } } } */
/* { dg-final { scan-assembler {\tceilf\.suw4 } } } */
/* { dg-final { scan-assembler {\tfloorf\.sw4 } } } */
/* { dg-final { scan-assembler {\tfloorf\.suw4 } } } */
/* { dg-final { scan-assembler {\troundf\.sw4 } } } */
/* { dg-final { scan-assembler {\troundf\.suw4 } } } */
/* { dg-final { scan-assembler {\ttrncf\.sw4 } } } */
/* { dg-final { scan-assembler {\ttrncf\.suw4 } } } */
/* { dg-final { scan-assembler {\tcvtf\.sw4 } } } */
/* { dg-final { scan-assembler {\tcvtf\.suw4 } } } */
/* { dg-final { scan-assembler {\tcvtf\.sh4 } } } */
/* { dg-final { scan-assembler {\tcvtf\.ws4 } } } */
/* { dg-final { scan-assembler {\tcvtf\.uws4 } } } */
/* { dg-final { scan-assembler {\tcvtf\.hs4 } } } */
/* { dg-final { scan-assembler {\tcmpf\.s4 6,} } } */
/* { dg-final { scan-assembler {\tcmovf\.w4} } } */
/* { dg-final { scan-assembler {\tshflv\.w4 2643,} } } */
/* { dg-final { scan-assembler {\tshflv\.w4 4095,} } } */
/* { dg-final { scan-assembler {\tflpv\.s4 3,} } } */
/* { dg-final { scan-assembler {\ttrfsrv\.w4 5,} } } */
/* { dg-final { scan-assembler {\tldv\.w 9,} } } */
/* { dg-final { scan-assembler {\tldv\.dw 2,} } } */
/* { dg-final { scan-assembler {\tldv\.qw 0\[r} } } */
/* { dg-final { scan-assembler {\tldvz\.h4} } } */
/* { dg-final { scan-assembler {\tstv\.w 3,} } } */
/* { dg-final { scan-assembler {\tstv\.dw 1,} } } */
/* { dg-final { scan-assembler {\tstvz\.h4} } } */
/* { dg-final { scan-assembler-times {\tcmovf\.w4 } 2 } } */
/* { dg-final { scan-assembler {\ttrfsrv\.w4 5, wr[0-9]+ ; setf z, r[0-9]+} } } */
