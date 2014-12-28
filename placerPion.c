#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"
#include "placerPion.h"

void placerPleine(pion T[N][M], int V[M], int colonne)
{
	int indice=V[colonne-1];
	int i=indice+1;
	booleen caseTrouve=FAUX;
	
	if( (indice == 0) && (caseCreuse(T,indice,colonne-1) == FAUX) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( casePleine(T,indice,colonne-1) )
		{
			printf("\n ATTENTION : Vous ne pouvez jouer que la pièce creuse dans la colonne %i \n\n",colonne);
		}
		else
		{
			printf("\n ATTENTION : la colonne %i est pleine, choisissez en une autre \n\n",colonne);
		}
	}
	else
	{
	
		while( i<=N-1 && !caseTrouve )
		{
			if( caseCreuse(T,i,colonne-1) )
			{
				indice = i;
				i++;
			}
			else
			{
				caseTrouve = VRAI;
			}
		}
		T[indice][colonne-1].plein = PLEINE;
								
		if( (V[colonne-1] > 0) && (caseVide(T,V[colonne-1],colonne-1) == FAUX) )
		{
			V[colonne-1]--;
		}
	}
	
}

void placerCreuse(pion T[N][M], int V[M], int colonne)
{
	int indice=V[colonne-1];
	int i=indice+1;
	booleen caseTrouve=FAUX;
	
	if( (indice == 0) && (casePleine(T,indice,colonne-1) == FAUX) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( caseCreuse(T,indice,colonne-1) )
		{
			printf("\n ATTENTION : Vous ne pouvez jouer que la pièce pleine dans la colonne %i \n\n",colonne);
		}
		else
		{
			printf("\n ATTENTION : la colonne %i est pleine, choisissez en une autre \n\n",colonne);
		}
	}
	else
	{
	
		while( i<=N-1 && !caseTrouve )
		{
			if( casePleine(T,i,colonne-1) )
			{
				indice = i;
				i++;
			}
			else
			{
				caseTrouve = VRAI;
			}
		}
		T[indice][colonne-1].creux = CREUSE;
								
		if( (V[colonne-1] > 0) && (caseVide(T,V[colonne-1],colonne-1) == FAUX) )
		{
			V[colonne-1]--;
		}
	}
}

void placerBlocante(pion T[N][M], int V[M], int colonne)
{
	int indice=V[colonne-1];
	
	if( (indice == 0) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( casePleine(T,indice,colonne-1) )
		{
			printf("\n ATTENTION : Vous ne pouvez jouer que la pièce creuse dans la colonne %i \n\n",colonne);
		}
		else
		{
			if( caseCreuse(T,indice,colonne-1) )
			{
				printf("\n ATTENTION : Vous ne pouvez jouer que la pièce pleine dans la colonne %i \n\n",colonne);
			}
			else
			{
				printf("\n ATTENTION : la colonne %i est pleine, choisissez en une autre \n\n",colonne);
			}
		}
	}
	else
	{
		T[indice][colonne-1].bloc = BLOCANTE;
	
		if(indice > 0)
		{
			V[colonne-1]--;
		}
	}
}
	
