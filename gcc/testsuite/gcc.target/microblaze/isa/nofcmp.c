/* { dg-options "-O3 -mcpu=v6.00.a " } */

volatile float f1, f2, f3;

void float_func () 
{
    /* { dg-final { scan-assembler-not "fcmp" } } */
    if (f2 <= f3)
        f1 = f3;
    else if (f2 == f3) 
        f1 = f3;
    else if (f2 < f3) 
        f1 = f3;
    else if (f2 > f3) 
        f1 = f3;
    else if (f2 >= f3) 
        f1 = f3;
    else if (f2 != f3) 
        f1 = f3;
    
}
