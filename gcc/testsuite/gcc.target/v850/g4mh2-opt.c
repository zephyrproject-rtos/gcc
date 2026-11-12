/* { dg-do preprocess } */
/* { dg-options "-mg4mh2" } */

#if !defined __V850_G4MH2__ || !defined __V850_G4__ || !defined __v850e3v5__
#error -mg4mh2 does not imply -mg4 and v850e3v5
#endif
