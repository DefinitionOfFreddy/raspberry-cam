#include "type.h"
#include <math.h>

void afficheimg_1(img I, int lig, int col)
{ int i,j;
	for(i=0;i<lig;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",I[i][j].couleur);
		}
		printf("\n");
	}
	printf("\n");
}

void afficheimg_RGB(img_RGB Irgb, int lig, int col)
{
	int i,j;
	for(i=0;i<lig;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("|%d %d %d",Irgb[i][j].R,Irgb[i][j].G,Irgb[i][j].B);
		}
		printf("|\n");
	}
	printf("\n");
}

int proche_RGB(pixel_RGB* p1, pixel_RGB* p2, double eps)
{
	double normep1 =   pow(p1->R,2) + pow(p1->G,2) + pow(p1->B,2);
	double normep2 =   pow(p2->R,2) + pow(p2->G,2) + pow(p2->B,2);


	//printf("%lf\n",x); return 1;
	//printf("Norme p1: %lf\nNorme p2: %lf\n",normep1, normep2);

	if (normep1>normep2) return (normep1 - normep2 < eps);
	else return ( normep2 - normep1 < eps );
}
