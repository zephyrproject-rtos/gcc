/* { dg-do compile } */
/* { dg-require-effective-target tls_native } */
/* { dg-require-effective-target arm_cortex_m } */
/* { dg-require-effective-target arm_thumb2_ok } */
/* { dg-options "-mpure-code" } */

__thread int x = 0;

int
bar ()
{
  return x; /* { dg-message "sorry, unimplemented: accessing thread-local storage is not currently supported with -mpure-code" } */
}

