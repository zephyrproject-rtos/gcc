/* Test that TLS access is allowed with -mslow-flash-data.
   While -mslow-flash-data disables literal pools for performance,
   TLS access requires literal pools and is therefore allowed as
   an exception.  */

/* { dg-do compile } */
/* { dg-require-effective-target tls_native } */
/* { dg-require-effective-target arm_cortex_m } */
/* { dg-require-effective-target arm_thumb2_ok } */
/* { dg-skip-if "-mslow-flash-data and -mword-relocations incompatible" { *-*-* } { "-mword-relocations" } } */
/* { dg-options "-O2 -mthumb -mslow-flash-data" } */

__thread int tls_var = 0;

int
test_tls_read (void)
{
  return tls_var;
}

void
test_tls_write (int val)
{
  tls_var = val;
}

int
test_tls_modify (int val)
{
  tls_var += val;
  return tls_var;
}

/* TLS access should use literal pool with TLS relocation (tpoff).  */
/* { dg-final { scan-assembler "\\(tpoff\\)" } } */
