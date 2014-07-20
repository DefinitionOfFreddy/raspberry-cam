#ifndef IMPORT_EXPORT
#define IMPORT_EXPORT

#include <stdio.h>
#include <stdlib.h>

#include "type.h"

img import_1(char* f, int*, int*);     // .pbm (noir & blanc) ou .pgm (niveau gris)-> matrice
void desallocation_1(img I, int lig);
int export_1(img , char* f, int ext, int lig , int col); //Matrice -> .pbm ou .pbm
imgRGB import_RGB(char* f, int*, int* );         //.ppm (couleur) -> matrice RGB
int export_RGB(imgRGB Irgb, char* f, int lig , int col); //Matrice -> .ppm

#endif

