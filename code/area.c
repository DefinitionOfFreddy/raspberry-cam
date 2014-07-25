#include "area.h"

int debut_area_1(img I, int nlig, int ncol, int c, double seuil)
{
	int i,j;
	int compt=0;
	for (i=0;i<ncol;i++)
	{
		for (j=0;j<nlig;j++)
		{
			if (I[i][j].couleur == c) compt++;
		}
		if (compt/nlig>=seuil) return i;
	}
	return -1;
}

int fin_area_1(img I, int nlig, int ncol, int c, double seuil, int debut)
{

}
