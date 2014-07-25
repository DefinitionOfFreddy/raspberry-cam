#ifndef AREA_
#define AREA_

#include <stdlib.h>
#include <stdio.h>

int debut_area_1(img I, int nlig, int ncol, int c, double seuil);
//Balaie l'image de gauche à droite et renvoie le numéro de la première colonne où l'on a plus de seuil% de couleur c
int fin_area_1(img I, int nlig, int ncol, int c, double seuil, int debut);
//Balaie l'image à partir de debut_area_1 et renvoie le numéro de la première colonne où l'on a moins de seuil% de couleur c

#endif
