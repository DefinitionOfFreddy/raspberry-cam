#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "imp_exp.h"
#include "cercle.h"
#include "area.h"

//Argument : fichier, couleur, seuil
int main(int argc, char* argv[])
{	int nlig,ncol;
	int darea; //darea pour début area
 	img I=NULL;

	//Lecture des arguments
 	char* f;
 	int c; // La couleur
 	double seuil;

	f=argv[1];
	sscanf(argv[2], "%d", &c);     //conversion de argv[2] (la couleur recherchée en int)
	sscanf(argv[3], "%lf", &seuil);//conversion de argv[3] (le seuil recherché en int)

	if ( !(I = import_1(f, &nlig, &ncol)) ) return 0;

	printf("Importation ok\n");
	afficheimg_1(I,nlig,ncol);

	darea = debut_area_1(I, nlig, ncol, c, seuil);

	if (darea == -1)
	{
		printf("Couleur %d non trouvée dans %s\n",c,f);
		return 0;
	}

	printf("Début Aera :%d\n", darea);
	int farea = fin_area_1(I, nlig, ncol, c, seuil, darea);

	printf("Fin Aera :%d\n", farea);

	return 0;
}
