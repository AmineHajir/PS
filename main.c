#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

int main()
{
	
	afficher_titre_jeu();
	printf("\n");
	initialiser_jeu(grille);
	afficher_jeu(grille);
	printf("\n\n");
	
	return 0;
}
		
		


