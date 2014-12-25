#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

/*void affficher_jeu(pion T[N][M])
{
	int i,j,k;
	
	for(i=0;i<M;i++)
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
	printf("\n");
	
	printf("			||");
	for(k=0;k<M;k++)
	{
		printf("=======|");
	}
	printf("|\n");
	
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
	printf("\n			||");
	for(k=0;k<M;k++)
	{
		printf("=======|");
	}
	printf("|\n");
}*/
	
int main()
{
	pion grille[N][M];
	
	printf("\n\n");
	initialiser_jeu(grille);
	afficher_jeu(grille);
	printf("\n\n");
	
	return 0;
}
		
		


