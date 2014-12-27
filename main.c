#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "affichageMenus.h"

	
int main()
{
	char piece;
	int colonne;
	//afficher_titre_jeu();
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	
	do
	{	piece=menuChoixPion();
		colonne=menuChoixColonne();
		
		switch(piece)
		{
			case 'b' : 
			{
				grille[hauteurColonne[colonne-1]][colonne-1].bloc=BLOCANTE;
			}break;
			
			case 'c' :
			{
				grille[hauteurColonne[colonne-1]][colonne-1].creux=CREUSE;
			}break;
			
			case 'p' : 
			{
				grille[hauteurColonne[colonne-1]][colonne-1].plein=PLEINE;
			}break;
		}
	}while(colonne!=8);
			
	
	
	
	
	afficher_jeu(grille);
	
	
		
	printf("\n\n");
	return 0;
}
		
		


