#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "imp_exp.h"
#include "cercle.h"
#include "area2.h"
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

		if (argc >= 4){
				f=argv[1];
				sscanf(argv[2], "%d", &c);     //conversion de argv[2] (la couleur recherchée en int)
				sscanf(argv[3], "%lf", &seuil);//conversion de argv[3] (le seuil recherché en int)

				if ( !(I = import_1(f, &nlig, &ncol)) ) return 0;

				printf("Importation ok\n");
				afficheimg_1(I,nlig,ncol);
				if (argc == 4) {
						darea = debut_area_1(I, nlig, ncol, c, seuil);

						if (darea == -1)
						{
								printf("Couleur %d non trouvée dans %s\n",c,f);
								return 0;
						}

						printf("Début Aera :%d\n", darea);
						int farea = fin_area_1(I, nlig, ncol, c, seuil, darea);

						printf("Fin Aera :%d\n", farea);


				}
				else {
				/*		
					int darea_gauche = debut_area_1_gauche_droite(I, nlig, ncol,c, seuil);
					printf(" haut : %d, \n", darea_gauche);
					int darea_haut = debut_area_1_haut_bas(I, nlig, ncol,c, seuil);
					printf(" gauche : %d, \n", darea_haut);
					int farea_gauche = fin_area_1_gauche_droite(I, nlig, ncol,c, seuil, darea_gauche);
					printf(" bas : %d, \n", farea_gauche);
					int farea_bas = fin_area_1_gauche_droite(I, nlig, ncol,c, seuil, darea_haut);
					printf("droite : %d, \n", farea_bas);
					*/
				coordonne coin_gh, coin_bd;
				coin_gh = coin_haut_gauche_1(I, nlig, ncol, c, seuil, seuil);
				coin_bd = coin_bas_droite_1(I, nlig, ncol, c, seuil, seuil, coin_gh);
				printf("Coin Haut Gauche : (%d,%d) \n", coin_gh.x, coin_gh.y);
				printf("Coin Bas Droite : (%d,%d) \n", coin_bd.x, coin_bd.y);
				coordonne centre = centre_area_1(coin_gh, coin_bd);
				printf("Coordonnée Centre : (%d, %d) \n", centre.x, centre.y);
				}
		}

		return 0;
}
