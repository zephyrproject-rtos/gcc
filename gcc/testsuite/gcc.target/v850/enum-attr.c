/* { dg-do compile } */
/* { dg-options "-O2" } */


enum e { E_OLD __attribute__ ((deprecated)) = 1, E_NEW = 1 };

int
f (void)
{
  return E_NEW;
}
