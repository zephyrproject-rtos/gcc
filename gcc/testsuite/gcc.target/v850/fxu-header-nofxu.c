/* { dg-do preprocess } */
/* { dg-options "-mg4mh2" } */
/* { dg-skip-if "tests the code without -mfxu" { *-*-* } { "-mfxu" } { "" } } */

#include <v850_fxu.h>	/* { dg-error "requires -mfxu" "" { target *-*-* } 0 } */
