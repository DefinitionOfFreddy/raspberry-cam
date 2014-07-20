#include "imp_exp.h"
#include <stdlib.h>
#include <stdio.h>

img import_1(char* f, int* plig, int* pcol)
{
	int i,j; //Indices
	pixel** I;
	FILE *fichier;
	fichier = fopen(f,"r");
	// Ouverture du fichier
	if (fichier==NULL) printf("Erreur ouverture image\n");
	else
	{
		int lecture;

		int color;
		char stri[3];

		fgets(stri,3,fichier); //lire la première ligne
		
		lecture = fscanf(fichier,"%d %d",plig,pcol);
		if (lecture != 2 ) return NULL;
		//Allocation mémoire
		I = calloc(*plig,sizeof(*I));
		if (I==NULL) printf("/!\ Erreur allocation\n");
		else
		{
			for(i=0;i<*plig;i++)
			{
				I[i] = calloc(*pcol,sizeof(**I));
			}
			//Lecture des pixels du fichier
			for(i=0;i<*plig;i++)
			{
				for(j=0;j<*pcol;j++)
				{
					fscanf(fichier, "%d", &color);
					I[i][j].couleur=color;
					I[i][j].etat=0;
				}
			}


		}
		fclose(fichier);

	}
	return I;
}

void desallocation_1(img I, int lig)
{
	int i;
	for(i=0;i<lig;i++)
	{
		free(I[i]);
	}
	free(I);
}


int export_1(img I, char* f, int ext, int lig , int col)
{
	int i,j,ecriture;
	FILE* fichier;
	fichier = fopen(f,"w");
	if (  fichier == NULL ) return 0;
	else
	{

	if (ext==0) fprintf(fichier,"P1\n");
	if (ext==1) fprintf(fichier,"P3\n");

	fprintf(fichier,"%d %d\n",lig, col);

	for(i=0;i<lig;i++)
	{
		for(j=0;j<col;j++)
		{
			fprintf(fichier,"%d ",I[i][j].couleur);
		}
		fprintf(fichier,"\n");
	}
	}
	fclose(fichier);
	return 1;
}

imgRGB import_RGB(char* f, int* plig, int* pcol)
{
	int i,j;
	imgRGB Irgb;
	FILE *fichier;
	fichier = fopen(f,"r");
	if (fichier==NULL) printf("Erreur ouverture image\n");
	else
	{

		int lecture;
		int lig = *plig;
		int col = *pcol;

		int red,green,blue;
		char stri[3];

		fgets(stri,3,fichier);
		// lecture = fscanf(fichier,"%s", stri);
		lecture = fscanf(fichier,"%d %d",&lig,&col);

		printf("lignes: %d colonnes: %d\n",lig,col);

		Irgb = calloc(lig,sizeof(*Irgb));
		if (Irgb ==NULL) printf("Erreur allocation\n");
		else
		{
			for(i=0;i<lig;i++)
			{
				Irgb[i] = calloc(col,sizeof(**Irgb));
			}
			for(i=0;i<lig;i++)
			{
				for(j=0;j<col;j++)
				{
					fscanf(fichier, "%d %d %d", &red, &green, &blue);
					Irgb[i][j].R=red;
					Irgb[i][j].G=green;
					Irgb[i][j].B=blue;

					Irgb[i][j].etat=0;
				}
			}
			*plig=lig;
			*pcol=col;
			fclose(fichier);

		}
 }
	return Irgb;
}

int export_RGB(imgRGB Irgb, char* f, int lig , int col) //Matrice -> .ppm
{
	int i,j,ecriture;
	FILE* fichier;
	fichier = fopen(f,"w");
	if (  fichier == NULL  ) return 0;
	else
	{
		fprintf(fichier,"P5\n");

	fprintf(fichier,"%d %d\n",lig, col);

	for(i=0;i<lig;i++)
	{
		for(j=0;j<col;j++)
		{
			fprintf(fichier,"%d %d %d ",Irgb[i][j].R, Irgb[i][j].G, Irgb[i][j].B );
		}
		printf("\n");
	}
	}
	return 1;
}
