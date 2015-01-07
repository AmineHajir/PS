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


/**
 * \file main.c
 * \author Hajir Mohammed Amine
 * \date 26 Décembre 2014
 * \brief PROGRAMME PRICIPAL DU JEU PUISSANCE4++.
* */


int main()
{
	int player;  // variable qui permet d'alterner le tour des joueurs
	int nbJoueur; // nombre de joueurs de la partie saisis dans le menu principal
	booleen winner; // variable booleenne qui permet de détecter une victoire
	
	printf("\n");
	initialiser_jeu(grille); // on initialise la grille du jeu à vide.
	initialiser_hauteurColonne(hauteurColonne); // on initialise le tableau des hauteurs de colonne. ( détail --> affichageJeu.h)
	nbJoueur=menuPrincipal(); // la fonction menuPrincipal renvoi le nombre de joueur de la partie.
	
	for(player=1;player<=nbJoueur;player++)
	{
		menuDebut(player,joueurs); // on affiche le menu du début du jeu à tout les joueurs.
	}
	printf("\n");
	
	do
	{	
		for(player=1;player<=nbJoueur;player++)
		{
			winner=faireJouer(player); // faire jouer renvoi vrai si une victoire est detectée
			if(winner==VRAI)
			{
				break; // en cas de victoire, on sort de la boucle for
			}
		}
	
	}while( (grillePleine(grille,hauteurColonne) == FAUX) && (winner == FAUX) ); // on continue de jouer tant que la grille n'est pas remplie
										       // et qu'il n y a pas de victoire
	
	printf("\n\n");
	afficher_jeu(grille);
	
	couleur(ROUGEGRAS); // on affiche le résultat de la partie
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
		
		


