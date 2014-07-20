#ifndef TYPE_
#define TYPE_

#include <stdio.h>



typedef struct {int couleur; int etat;} pixel;


typedef pixel** img;

typedef struct {
  int R;
  int G;
  int B;
  int etat;
}** imgRGB;

void afficheimg_1(img I, int lig, int col);



#endif


