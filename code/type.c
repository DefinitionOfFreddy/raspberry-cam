#include "type.h"

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
}
