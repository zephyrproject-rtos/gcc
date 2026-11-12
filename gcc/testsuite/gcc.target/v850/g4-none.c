/* { dg-do preprocess } */
/* { dg-options "-mv850e3v5" } */
/* { dg-skip-if "tests the code without -mg4" { *-*-* } { "-mg4" } { "" } } */

#ifdef __V850_G4__
#error __V850_G4__ without -mg4
#endif
