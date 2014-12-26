#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

void menu()
{
	char piece;
	printf("\n\n                         ---------------------- Pion à jouer ---------------------\n");
	printf(" Tapez b pour la pièce bloquante \n");
	printf(" Tapez c pour la pièce creuse \n");
	printf(" Tapez p pour la pièce pleine \n");
	printf(" votre choix : ");
	scanf("%c",&piece);
		
	system("clear");
}
	
int main()
{
	
	//afficher_titre_jeu();
	printf("\n");
	initialiser_jeu(grille);
	afficher_jeu(grille);
	menu();
	afficher_jeu(grille);
	
	/*char piece;
	
	printf("\n\n                         ---------------------- Pion à jouer ---------------------\n");
	printf(" Tapez b pour la pièce bloquante \n");
	printf(" Tapez c pour la pièce creuse \n");
	printf(" Tapez p pour la pièce pleine \n");
	printf(" votre choix : ");
	scanf("%c",&piece);
		
	system("clear");*/
		
	printf("\n\n");
	return 0;
}
		
		


