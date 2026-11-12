/* { dg-do preprocess } */
/* { dg-options "-mg4" } */
/* { dg-skip-if "tests the code without -mg4mh2" { *-*-* } { "-mg4mh2" } { "" } } */

#ifdef __V850_G4MH2__
#error __V850_G4MH2__ without -mg4mh2
#endif
