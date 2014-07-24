#include "cercle.h"

coordonne coord_centre(img I, int nb_ligne, int nb_colone, pixel* p, int c)
{
    //trouver le plus gros segment noir, prendre le  milieu
    coordonne point;
    int ligne_seg = 0;
    int deb_seg = -1;
    int fin_seg = 0;
    int i,j;
    for (i=0; i<nb_ligne;i++)
    {
        int cur_deb_seg =-1;
        int cur_fin_seg = -1;
        for (j=0; j< nb_colone; j++)
        {
            if (I[i][j].couleur == c){
                if(cur_deb_seg == -1){
                    cur_deb_seg = j;
                }
                cur_fin_seg = j;
            }
        }
        if ((fin_seg - deb_seg) <(cur_fin_seg - cur_deb_seg)) {
            fin_seg = cur_fin_seg;
            deb_seg = cur_deb_seg;
            ligne_seg = i;
        }
    }
    point.y = ligne_seg;
    point.x = (fin_seg - deb_seg)/2 +1 ;
    return point;
}

coordonne compar_cercle(img I, img J, int nlig, int ncol, int nlig2, int ncol2, int c)
{   coordonne point, point2, vecteur;
    point = coord_centre(I, nlig, ncol, NULL, 1);
    point2 = coord_centre(J, nlig2, ncol2, NULL, 1);
    vecteur.y = point2.y - point.y;
    vecteur.x = point2.x - point.x;
    return vecteur;
}
