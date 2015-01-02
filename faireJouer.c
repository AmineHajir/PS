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

/**
 * \file affichageJeu.c
 * \author Hajir Mohammed Amine
 * \date 19 Décembre 2014
 * \brief ce fichier source contient les définitions des fonctions d'affichage du titre et de la grille du jeu.
 * \details ce fichier contient aussi la définition de la fonction d'initialisation de la grille du jeu.
 *          il contient également la définition de la fonction d'initialisation du tableau qui stocke la hauteur de chaque colonne.
 * */

void faireJouer(int *player)
{
	char piece; // variable qui stocke la pièce choisie par le joueur ('b', 'c' ou 'p')
	int colonne; // variable qui stocke le numéro de la colonne ou le joueur a choisi de mettre son pion
	booleen jouer; // variable qui reçoit vrai si le joueur a bien placer son pion, faux sinon
	
	jouer=FAUX;
			
	piece=menuChoixPion(joueurs[*player-1].nom);
	while(!jouer) // tant que le joueur1 n'a pas placer son pion
	{
		colonne=menuChoixColonne(joueurs[*player-1].nom);
		while(colonne==0 || colonne==8)
		{
			if(colonne==0)
			{
				piece=menuChoixPion(joueurs[*player-1].nom);
				colonne=menuChoixColonne(joueurs[*player-1].nom);
			}
			else
			{
				if(colonne==8)
				{
					couleur(ROUGEGRAS);
					printf("\n RAPPEL : %s, vous jouez avec des pions %s \n\n",joueurs[*player-1].nom,convert(joueurs[*player-1].couleur));
					couleur(DEFAULT);
					colonne=menuChoixColonne(joueurs[*player-1].nom);
				}		
			}
		}
			switch(piece)
			{
				case 'b' : 
				{
					jouer=placerBlocante(grille, hauteurColonne, colonne, *player,joueurs[*player-1].nom);
				}break;
					
				case 'c' :
				{
					jouer=placerCreuse(grille, hauteurColonne, colonne, *player,joueurs[*player-1].nom);
				}break;
					
				case 'p' : 
				{
					jouer=placerPleine(grille, hauteurColonne, colonne, *player,joueurs[*player-1].nom);
				}break;
			}
	}
	if( (*player) == 1 )
	{
		(*player)++; // quand le joueur1 aura bien placé son pion, on incrémente pour que le joueur2 puisse jouer à son tour
	}
	else
	{
		(*player)--; // on decrémente cette fois pour revenir au premier joueur
	}
}
	