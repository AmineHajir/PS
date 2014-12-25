#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

int main()
{
	pion grille[N][M];
	
	printf("\n\n");
	initialiser_jeu(grille);
	afficher_jeu(grille);
	printf("\n\n");
	
	return 0;
}
		
		


