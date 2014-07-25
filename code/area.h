#ifndef AREA_
#define AREA_

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "imp_exp.h"

int debut_area_1(img I, int nlig, int ncol, int c, double seuil);
//Balaie l'image de gauche à droite et renvoie le numéro de la première colonne où l'on a plus de seuil% de couleur c,
//ou -1 si on netrouve pas suffisamment de couleur

int fin_area_1(img I, int nlig, int ncol, int c, double seuil, int debut);
//Balaie l'image à partir de debut_area_1 et renvoie le numéro de la première colonne où l'on a moins de seuil% de couleur c

#endif
