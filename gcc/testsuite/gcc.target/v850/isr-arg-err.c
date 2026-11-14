/* { dg-do compile } */
/* { dg-options "-mv850e3v5" } */

void __attribute__ ((interrupt ("NMI"))) a (void) { }	/* { dg-error "argument of the 'interrupt' attribute is not 'EI' or 'FE'" } */
void __attribute__ ((interrupt_handler (1))) b (void) { }	/* { dg-error "argument of the 'interrupt_handler' attribute is not 'EI' or 'FE'" } */
void __attribute__ ((interrupt ("EI", "FE"))) c (void) { }	/* { dg-error "wrong number of arguments" } */
