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
	piece=menuChoixPion();
	colonne=menuChoixColonne();
	
	if(piece=='b')
		grille[5][colonne].bloc=BLOCANTE;
	
	
	afficher_jeu(grille);
	
	
		
	printf("\n\n");
	return 0;
}
		
		


