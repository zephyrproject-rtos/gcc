/* { dg-do preprocess } */
/* { dg-options "-mfxu" } */

#if !defined __V850_FXU__ || !defined __V850_G4MH2__ || !defined __V850_G4__ || !defined __v850e3v5__
#error -mfxu does not imply -mg4mh2, -mg4 and v850e3v5
#endif
