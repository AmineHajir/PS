#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "affichageJeu.h"
#include "affichageMenus.h"
#include "contenuCase.h"
#include "placerPion.h"
#include "couleurs.h"

booleen grillePleine(pion T[N][M], int V[M])
{
	int i;
	
	for(i=0;i<M;i++)
	{
		if( (V[i]!=0) || (V[i]==0 && caseBlocante(T,0,i)==FAUX && casePleineCreuse(T,0,i)==FAUX) )
		{
			return 0;
		}
	}
	return 1;
}


int lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	
	if (fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		viderBuffer();
		return 0;
	}
}
		
int main()
{
	char piece;
	int colonne;
	int joueur=1;
	char joueur1[10];
	char joueur2[10];
	
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	printf(" Binevenu sur Puissance 4++ \n");
	printf(" joueur 1, quel est votre nom ");
	lire(joueur1,10);
	printf(" joueur 2, quel est votre nom ");
	lire(joueur2,10);
	clrscr();
	
	
	do
	{	
		if(joueur==1)
		{
			piece=menuChoixPion(joueur1);
			colonne=menuChoixColonne(joueur1);
			
			switch(piece)
			{
				case 'b' : 
				{
					placerBlocante(grille, hauteurColonne, colonne, joueur);
				}break;
				
				case 'c' :
				{
					placerCreuse(grille, hauteurColonne, colonne, joueur);
				}break;
				
				case 'p' : 
				{
					placerPleine(grille, hauteurColonne, colonne, joueur);
					
				}break;
			}
			joueur++;
		}
		else
		{
			if(joueur==2)
			{
				piece=menuChoixPion(joueur2);
				colonne=menuChoixColonne(joueur2);
				
				switch(piece)
				{
					case 'b' : 
					{
						placerBlocante(grille, hauteurColonne, colonne, joueur);
					}break;
					
					case 'c' :
					{
						placerCreuse(grille, hauteurColonne, colonne, joueur);
					}break;
					
					case 'p' : 
					{
						placerPleine(grille, hauteurColonne, colonne, joueur);
						
					}break;
				}
			}
			joueur--;
		}
		
	}while(grillePleine(grille,hauteurColonne) == FAUX);
			
	
	afficher_jeu(grille);
	
	printf("\n\n");
	return 0;
}
		
		


