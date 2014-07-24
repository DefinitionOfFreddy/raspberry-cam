#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "imp_exp.h"
#include "cercle.h"

int main (int argc, char* argv[])
{
    int export,nlig,ncol;
    int nlig2, ncol2;
    img I=NULL;
    img J=NULL;
    char* f;
    f="../banque/angle_noir_50x50.pbm";

    I = import_1(f, &nlig, &ncol); //Allocation de I et lecture du fichier nommé f
    if (!I) return 0;
    printf("Importation ok\n");
    printf("IMAGE 1 \n");
    afficheimg_1(I,nlig,ncol);
    //printf("ok\n");
    f="../banque/centre_noir_50x50.pbm";
    J = import_1(f, &nlig2, &ncol2); //Allocation de I et lecture du fichier nommé f
    printf("IMAGE 2 \n");
    afficheimg_1(J,nlig2,ncol2);
    coordonne vecteur;
    vecteur = compar_cercle(I,J,nlig, ncol, nlig2, ncol2, 1);
    printf ("%d vers le bas \n", vecteur.y);
    printf ("%d vers la droite \n", vecteur.x);
    export = export_1(I,"essai.pbm",0,nlig,ncol);
    if (!export) return 0;

    printf("Exportation ok\n");
    desallocation_1(I,nlig);
    desallocation_1(J,nlig2);
    return 0;
}
