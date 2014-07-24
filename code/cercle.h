#ifndef CERCLE
#define CERCLE


#include <stdio.h>
#include <stdlib.h>
#include "type.h"


coordonne coord_centre(img I, int nb_ligne, int nb_colone, pixel* p, int c);

coordonne compar_cercle(img I, img J, int nlig, int ncol, int nlig2, int ncol2, int c);

#endif
