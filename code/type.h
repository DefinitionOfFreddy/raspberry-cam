#ifndef TYPE
#define TYPE

#include <stdint.h>
#include <stdio.h>



typedef pixel {uint8 couleur; uint8 statut};


typedef img pixel**;

typedef imgRGB {
  pixel*** R;
  pixel*** G;
  pixel*** B;
};

#endif


