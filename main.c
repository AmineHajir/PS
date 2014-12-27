#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "affichageMenus.h"
#include "contenuCase.h"

	
int main()
{
	char piece;
	int colonne;
	int indice,i;
	booleen caseTrouve;
	//afficher_titre_jeu();
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	
	do
	{	piece=menuChoixPion();
		colonne=menuChoixColonne();
		indice=hauteurColonne[colonne-1];
		
		switch(piece)
		{
			case 'b' : 
			{
				grille[hauteurColonne[colonne-1]][colonne-1].bloc=BLOCANTE;
				hauteurColonne[colonne-1]--;
			}break;
			
			case 'c' :
			{
				grille[hauteurColonne[colonne-1]][colonne-1].creux=CREUSE;
				hauteurColonne[colonne-1]--;
			}break;
			
			case 'p' : 
			{
				i=indice+1;
				caseTrouve=FAUX;
				
				while( i<=N-1 && !caseTrouve )
				{
					if( caseCreuse(grille,i,colonne-1) )
					{
						indice = i;
						i++;
					}
					else
					{
						caseTrouve = VRAI;
					}
				}
				grille[indice][colonne-1].plein = PLEINE;
				
				if( (hauteurColonne[colonne-1] > 0) && (caseVide(grille,hauteurColonne[colonne-1],colonne-1) == FAUX) )
				{
					hauteurColonne[colonne-1]--;
				}
			}break;
		}
	}while(colonne!=8);
			
	
	
	
	
	afficher_jeu(grille);
	
	
		
	printf("\n\n");
	return 0;
}
		
		


