/* { dg-do preprocess } */
/* { dg-options "-mg4" } */

#if !defined __V850_G4__ || !defined __v850e3v5__
#error -mg4 does not imply v850e3v5
#endif
