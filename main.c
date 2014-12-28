#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "affichageMenus.h"
#include "contenuCase.h"
#include "placerPion.h"

	
	
int main()
{
	char piece;
	int colonne;
	/*int indice,i;
	booleen caseTrouve;*/
	//afficher_titre_jeu();
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	
	do
	{	piece=menuChoixPion();
		colonne=menuChoixColonne();
		//indice=hauteurColonne[colonne-1];
		
		switch(piece)
		{
			case 'b' : 
			{
				placerBlocante(grille, hauteurColonne, colonne);
			}break;
			
			case 'c' :
			{
				placerCreuse(grille, hauteurColonne, colonne);
			}break;
			
			case 'p' : 
			{
				placerPleine(grille, hauteurColonne, colonne);
				
			}break;
		}
	}while(colonne!=8);
			
	
	
	
	
	afficher_jeu(grille);
	
	
		
	printf("\n\n");
	return 0;
}
		
		


