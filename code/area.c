#include "area.h"

int debut_area_1(img I, int nlig, int ncol, int c, double seuil)
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
		if (compt/(double) nlig >= seuil) return i;
	}
	return -1;
}

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

int fin_area_1(img I, int nlig, int ncol, int c, double seuil, int debut)
{
	return ncol;
}
