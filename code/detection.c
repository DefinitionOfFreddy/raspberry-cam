#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "imp_exp.h"

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

	(p1.R)= 120;
	(p1.G)= 160;
	(p1.B)= 80;
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

			if(  abs(np2->G-p1.G)<25 && abs(np2->R-p1.R)<25 && abs(np2->B-p1.B)<25 /*proche_RGB(&p1, np2, eps)*/ )
			{
				(Jrgb[i][j]).R = 255 /*np2->R*/;
				(Jrgb[i][j]).G = 0 /* np2->G*/;
				(Jrgb[i][j]).B = 0 /* np2->B*/;
			}
		}
	}
	//afficheimg_RGB(Jrgb, nlig, ncol);
	printf("%s",argv[1]);
	printf("%s",argv[2]);
	export_RGB(Jrgb, argv[2], nlig , ncol);

	//printf("%d\n", proche_RGB(&p1,&p2,40));
	return 0;

}
