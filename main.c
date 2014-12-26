#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

	
int main()
{
	char piece;
	int colonne;
	//afficher_titre_jeu();
	printf("\n");
	initialiser_jeu(grille);
	piece=menuJouerPion();
	
	
 	printf("\n Dans quelle colonne vous jouez ? ");
	scanf("%i",&colonne);
	
	if(piece=='b')
		grille[0][colonne].bloc=BLOCANTE;
	
	//printf(" Dans quelle
	afficher_jeu(grille);
	
	
		
	printf("\n\n");
	return 0;
}
		
		


