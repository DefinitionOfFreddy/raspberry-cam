#ifndef AREA_2_
#define AREA_2

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "imp_exp.h"

int debut_area_1_gauche_droite(img I, int nlig, int ncol, int c, double seuil);
//Balaie l'image de gauche à droite et renvoie le numéro de la première colonne où l'on a plus de seuil% de couleur c,
//ou -1 si on ne trouve pas suffisamment de couleur


int debut_area_1_haut_bas(img I, int nlig, int ncol, int c, double seuil);
//Balaie de haut en bas


int fin_area_1_gauche_droite(img I, int nlig, int ncol, int c, double seuil, int debut_haut);
//Balaie l'image à partir de debut_area_1 et renvoie le numéro de la première colonne où l'on a moins de seuil% de couleur c
int fin_area_1_haut_bas(img I, int nlig, int ncol, int c, double seuil, int debut_haut);

coordonne coin_haut_gauche_1(img I, int nlig, int ncol, int c, double seuil_haut, double seuil_gauche);

coordonne coin_bas_droite_1(img I, int nlig, int ncol, int c, double seuil_bas, double seuil_droite, coordonne coin_h_g);
//int debut_area_RGB(img I, int nlig, int ncol, pixel_RGB ptest, double seuil);
//Balaie l'image de gauche à droite et renvoie le numéro de la première colonne où l'on a plus de seuil% de pixels proche de ptest,
//ou -1 si on ne trouve pas suffisamment de pixel

coordonne centre_area_1(coordonne coin_h_g, coordonne coin_b_d);

#endif
