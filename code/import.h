#ifndef IMPORT
#define IMPORT

#include "type.h"

void import_bin(img* I,char* f);         // .pbm (noir & blanc)-> matrice
void import_niveaugris(img* I,char* f);  // .pgm -> matrice
void import_c(imgRGB* I,char* f);        // .ppm (couleur) -> matrice RGB

#endif

