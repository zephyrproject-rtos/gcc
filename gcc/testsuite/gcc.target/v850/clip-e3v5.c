/* { dg-do compile } */
/* { dg-options "-O2 -mv850e3v5" } */
/* { dg-skip-if "tests the code without -mg4" { *-*-* } { "-mg4" "-mg4mh2" } { "" } } */

int sb (int x) { return x > 127 ? 127 : x < -128 ? -128 : x; }
unsigned ub (unsigned x) { return x > 255 ? 255 : x; }

/* { dg-final { scan-assembler-not "\tclip\\." } } */
