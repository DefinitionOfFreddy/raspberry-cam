#include "area2.h"
#include "type.h"

int debut_area_1_gauche_droite(img I, int nlig, int ncol, int c, double seuil)
{
		int i,j;
		int compt;
		for (i=0;i<ncol;i++)
		{
				compt=0;
				for (j=0;j<nlig;j++)
				{
						if (I[i][j].couleur == c) compt++;
				}
				if ((double)compt/(double) nlig >= seuil)
				{
						return i; }
		}
		printf("compt %d \n", compt);
		return -1;
}


int debut_area_1_haut_bas(img I, int nlig, int ncol, int c, double seuil)
{
		int i,j;
		int compt;
		for (i=0;i<nlig;i++)
		{
				compt=0;
				for (j=0;j<ncol;j++)
				{
						if (I[i][j].couleur == c) compt++;
				}
				if ((double)compt/(double) ncol >= seuil)
				{
						return i; }
		}
		return -1;
}
/*
int debut_area_RGB(img I, int nlig, int ncol, pixel_RGB ptest, double seuil)
{
		int i,j;
		int compt;
		for (i=0;i<ncol;i++)
		{
				compt=0;
				for (j=0;j<nlig;j++)
				{
						if ( proche_RGB(&(I[i][j]),&ptest, 40) ) compt++;
				}
				if (compt/(double) nlig >= seuil) return i;
		}
		return -1;
}
*/


int fin_area_1_gauche_droite(img I, int nlig, int ncol, int c, double seuil, int debut_gauche)
{
		if (debut_gauche != -1){
		int i,j;
		int compt;
		if (debut_gauche != -1) {
				for (i=debut_gauche;i<ncol;i++)
				{
						compt=0;
						for (j=0;j<nlig;j++)
						{
								if (I[i][j].couleur == c) compt++;
						}
						if ((double)compt/(double) nlig < seuil)
						{
								return i-1 ; }
				}
		}

		return i;
		}
		return -1;
}


int fin_area_1_haut_bas(img I, int nlig, int ncol, int c, double seuil, int debut_haut)
{
		int i,j;
		int compt;
		if (debut_haut != -1) {
				for (i=debut_haut;i<nlig;i++)
				{
						compt=0;
						for (j=0;j<ncol;j++)
						{
								if (I[i][j].couleur == c) compt++;
						}
						if ((double)compt/(double) ncol < seuil)
						{
								return i-1 ; }
				}
		}

		return i;
}

coordonne coin_haut_gauche_1(img I, int nlig, int ncol, int c, double seuil_haut, double seuil_gauche)
{
	coordonne coin;
	coin.x = debut_area_1_gauche_droite(I, nlig, ncol, c, seuil_gauche);
	coin.y = debut_area_1_haut_bas(I, nlig, ncol, c, seuil_haut);
	return coin;
}
coordonne coin_bas_droite_1(img I, int nlig, int ncol, int c, double seuil_bas, double seuil_droite, coordonne coin_h_g)
{
	coordonne coin;
	coin.x = fin_area_1_gauche_droite(I, nlig, ncol, c, seuil_droite, coin_h_g.x);
	coin.y = fin_area_1_haut_bas(I, nlig, ncol, c, seuil_bas, coin_h_g.y);
	return coin;
}


coordonne centre_area_1(coordonne coin_h_g, coordonne coin_b_d)
{
	coordonne point;
	point.x = (coin_h_g.x + coin_b_d.x)/2;
	point.y = (coin_h_g.y + coin_b_d.y)/2;
	return point;
}
