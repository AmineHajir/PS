#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

void afficher_titre_jeu()
{
	printf("                           68b                                                                       \n");
	printf("                           Y89                                                                       \n");
	printf("       __ ____   ___   ___ ___   ____     ____      ___    ___  __     ____     ____                 \n");
	printf("       `M6MMMMb  `MM    MM `MM  6MMMMb  6MMMMb    6MMMMb   `MM 6MMb   6MMMMb.  6MMMMb              M \n");
	printf("        MM'  `Mb  MM    MM  MM MM'    ` MM'    ` 8M'  `Mb   MMM9 `Mb 6M'   Mb 6M'  `Mb           ,dM \n");
	printf("        MM    MM  MM    MM  MM YM.      YM.          ,oMM   MM'   MM MM    `' MM    MM          ,dMM \n");
	printf("        MM    MM  MM    MM  MM  YMMMMb   YMMMMb  ,6MM9'MM   MM    MM MM       MMMMMMMM         ,d MM \n");
	printf("        MM    MM  MM    MM  MM      `Mb      `Mb MM'   MM   MM    MM MM       MM              ,d  MM       MM        MM\n");
	printf("        MM.  ,M9  YM.   MM  MM L    ,MM L    ,MM MM.  ,MM   MM    MM YM.   d9 YM    d9       ,d   MM       MM        MM\n");
	printf("        MMYMMM9    YMMM9MM__MM_MYMMMM9  MYMMMM9  `YMMM9'Yb._MM_  _MM_ YMMMM9   YMMMM9        MMMMMMMM   MMMMMMMM  MMMMMMMM\n");
	printf("        MM                                                                                        MM       MM        MM\n");
	printf("        MM                                                                                        MM       MM        MM\n");
	printf("       _MM_                                                                                       MM \n");
	printf("\n\n\n");
}

void initialiser_jeu(pion T[N][M])
{
	int i,j;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			T[i][j].bloc=VIDE;
			T[i][j].creux=VIDE;
			T[i][j].plein=VIDE;
		}
	}
}

void afficher_numColonne_jeu(int nbre_colonne)
{
	int i;
	
	for(i=0;i<nbre_colonne;i++)
	{
		if(i==0)
		{
			printf("     	             	     %i",i+1);
		}
		else
		{
			printf("       %i",i+1);
		}
	}
}

void afficher_bordure_grille(int nbre_colonne)
{
	int i;
	
	printf("			||");
	for(i=0;i<nbre_colonne;i++)
	{
		printf("=======|");
	}
	printf("|\n");
}
	

void afficher_jeu(pion T[N][M])
{
	int i,j,k;
	
	afficher_numColonne_jeu(M);
	
	printf("\n");
	
	afficher_bordure_grille(M);
	
	for(i=0;i<N;i++)
	{
		printf("			||");
		for(j=0;j<M;j++)
		{
			printf(" %c %c %c |",T[i][j].bloc,T[i][j].creux,T[i][j].plein);
		}
		printf("|");
		if(i<N-1)
		{	
			printf("\n			||");
			for(k=0;k<M;k++)
			{
				printf("-------|");
			}
			printf("|\n");
		}
	}
	
	printf("\n");
	afficher_bordure_grille(M);
	
}

