/* { dg-do compile } */
/* { dg-options "-mv850e2v3" } */
/* { dg-skip-if "tests the base targets" { *-*-* } { "-mfxu" "-mg4" "-mg4mh2" "-mv850e3v5" } { "" } } */

void __attribute__ ((interrupt ("EI"))) a (void) { }	/* { dg-error "argument of the 'interrupt' attribute needs '-mv850e3v5' or later" } */
