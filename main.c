#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "affichageJeu.h"
#include "menuJeu.h"
#include "contenuCase.h"
#include "placerPion.h"
#include "couleurs.h"
#include "boiteOutil.h"
#include "menuDebut.h"
#include "faireJouer.h"
#include "victoire.h"

int main()
{
	int player;  // variable qui permet d'alterner le tour des joueurs
	int nbJoueur; // nombre de joueurs de la partie saisis dans le menu principal
	booleen winner; // variable booleenne qui permet de détecter une victoire
	
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	nbJoueur=menuPrincipal();
	
	for(player=1;player<=nbJoueur;player++)
	{
		menuDebut(player,joueurs);
	}
	printf("\n");
	
	do
	{	
		for(player=1;player<=nbJoueur;player++)
		{
			winner=faireJouer(player);
			if(winner==VRAI)
			{
				break;
			}
		}
	
	}while( (grillePleine(grille,hauteurColonne) == FAUX) && (winner == FAUX) ); // on continue de jouer tant que la grille n'est pas remplie
	
	
	printf("\n\n");
	afficher_jeu(grille);
	
	couleur(ROUGEGRAS);
	if( (grillePleine(grille,hauteurColonne) == FAUX) && (winner == VRAI) )
	{
		printf("\n\n                                 Bravo %s, vous avez remportez la partie ",joueurs[player-1].nom);  
	}
	if( (grillePleine(grille,hauteurColonne) == VRAI) && (winner == VRAI) )
	{
		printf("\n\n 				      Bravo %s, vous avez remportez la partie ",joueurs[player-1].nom);
	}
	if( (grillePleine(grille,hauteurColonne) == VRAI) && (winner == FAUX) )
	{
		printf("\n\n 				     La grille est pleine !!! partie nulle ");
	}
		
		
	couleur(DEFAULT);
	
	printf("\n\n");
	return 0;
}
		
		


