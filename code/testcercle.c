#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "imp_exp.h"
// Test import/export fichier _1 ok
/*
int main (int argc, char* argv[])
{
	int export,nlig,ncol;
	img I=NULL;
	char* f;
	f=argv[1];

	I = import_1(f, &nlig, &ncol); //Allocation de I et lecture du fichier nommé f
	if (!I) return 0;
	printf("Importation ok\n");

	//afficheimg_1(I,nlig,ncol);
	//printf("ok\n");
	//export = export_1(I,"../banque/essai.pbm",0,nlig,ncol);
	//if (!export) return 0;

	printf("Exportation ok\n");
	desallocation_1(I,nlig);

}*/
// Test import/export fichier _RGB ok
/*
int main(int argc, char* argv[])
{
	int export,nlig,ncol;
	img_RGB Irgb=NULL;
	char* f;
	f=argv[1];

	Irgb = import_RGB(f, &nlig, &ncol); //Allocation de I et lecture du fichier nommé f
	if (!Irgb) return 0;

	printf("Importation ok\n");
	afficheimg_RGB(Irgb,nlig,ncol);
	export = export_RGB(Irgb,"../banque/essai.ppm",nlig,ncol);
	if (!export) return 0;
	if (export) printf("exportation ok\n");
	desallocation_RGB(Irgb, nlig);

}*/
//Test proche_RGB ok
int main(int argc, char* argv[])
{
	pixel_RGB p1;
	pixel_RGB* np2=NULL;
	pixel_RGB p0; //Pixel noir
	p0.R = 255;
	p0.G = 255;
	p0.B = 255;

	int nlig,ncol,i,j;
	img_RGB Irgb=NULL;
	img_RGB Jrgb=NULL;
	double eps;

	Irgb = import_RGB(argv[1], &nlig, &ncol);

	//Pixel test et erreur admise
	//scanf("%d %d %d %lf",&(p2.R), &(p2.G), &(p2.B), &eps);

	(p1.R)= 21;
	(p1.G)= 245;
	(p1.B)= 14;
	eps = 40;
	Jrgb = calloc( nlig,sizeof(*Jrgb) );

	for(i=0;i<nlig;i++)
	{	Jrgb[i] = calloc(ncol, sizeof(**Jrgb));
		for(j=0;j<ncol;j++)
		{
			np2= &( Irgb[i][j] );
			(Jrgb[i][j]).R = p0.R;
			(Jrgb[i][j]).G = p0.G;
			(Jrgb[i][j]).B = p0.B;
			//printf("%d %d %d\n", )

			if( abs(np2->G-p1.G)<5 && proche_RGB(&p1, np2, eps) )
			{
				(Jrgb[i][j]).R = np2->R;
				(Jrgb[i][j]).G = np2->G;
				(Jrgb[i][j]).B = np2->B;
			}
		}
	}
	//afficheimg_RGB(Jrgb, nlig, ncol);
	export_RGB(Jrgb, "../banque/resproche.ppm", nlig , ncol);

	//printf("%d\n", proche_RGB(&p1,&p2,40));
	return 0;

}
