/* { dg-do preprocess } */
/* { dg-options "-mg4mh2" } */
/* { dg-skip-if "tests the code without -mfxu" { *-*-* } { "-mfxu" } { "" } } */

#ifdef __V850_FXU__
#error __V850_FXU__ without -mfxu
#endif
