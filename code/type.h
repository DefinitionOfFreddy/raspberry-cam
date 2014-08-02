#ifndef TYPE_
#define TYPE_

#include <stdio.h>


typedef struct {int couleur; int etat;} pixel;

typedef struct {int x; int y;} coordonne;

typedef pixel** img;

typedef struct {
  int R;
  int G;
  int B;
  int etat;
} pixel_RGB;

typedef pixel_RGB** img_RGB;

void afficheimg_1(img I, int lig, int col);
void afficheimg_RGB(img_RGB I, int lig, int col);

int proche_RGB(pixel_RGB* p1, pixel_RGB* p2, double eps); //Condition: | |p1|-|p2| |<eps
//Renvoie 1 si | |p1| - |p2| |<eps , 0 sinon



#endif


