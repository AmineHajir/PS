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
 * \file faireJouer.c
 * \author Hajir Mohammed Amine
 * \date 01 Janvier 2015
 * \brief ce fichier source contient la fonction qui fait jouer un joueur.
* */

/**
 * \fn void faireJouer(int player)
 * \brief procédure qui fait jouer une joueur en faisant appel au fonctions d'affichage des menu du jeu et les fonctions qui permettent
 * \brief de ranger le pion choisis par le joueur dans la bon emplacement.
 * \param player le joueur qui doit jouer 1 ou 2 ....
*/
void faireJouer(int player)
{
	char piece; // variable ou l'on stocke la pièce choisie par le joueur ('b', 'c' ou 'p')
	int colonne; // variable ou l'on stocke le numéro de la colonne ou le joueur a choisi de mettre son pion
	booleen jouer; // variable qui reçoit vrai si le joueur a bien placer son pion, faux sinon
	
	jouer=FAUX;
			
	piece=menuChoixPion(joueurs[player-1].nom); // on affiche le menu du choix du pion, et on range le pion choisix dans la variable piece
	while(!jouer) // tant que le joueur1 n'a pas placer son pion
	{
		colonne=menuChoixColonne(joueurs[player-1].nom); //on afich menu choix de colonn, on range la colonn choisie dans la variable colonne 
		while(colonne==0 || colonne==8) // tant que le joueur choisis de retourner en arrière pour changer de pion
		{				 // ou choisis d'afficher sa couleur de pions
			if(colonne==0) // s'il choisis de change de pion
			{
				piece=menuChoixPion(joueurs[player-1].nom); // on réaffiche le menu du choix du pion
				colonne=menuChoixColonne(joueurs[player-1].nom); // puis à nouveau le menu du choix de colonne
			}
			else
			{
				if(colonne==8) // si le joueur choisis d'afficher sa couleur de pion 
				{       // pour la fonction convert, voir détail dans le fichier boiteOutil.c
					couleur(ROUGEGRAS); // on affiche sa couleur en l'appelant par son nom 
					printf("\n  RAPPEL : %s, vous jouez avec des pions %s ",joueurs[player-1].nom,convert(joueurs[player-1].couleur));
					couleur(DEFAULT);
					colonne=menuChoixColonne(joueurs[player-1].nom); // tout affichant le menu de choix de colonne
				}		
			}
		}
		switch(piece) // une fois les choix de la colonne et du pion sont fait 
		{
			// si le joueur choisis une blocante, on range cette dernière au bon emplacement dans la grille et on jouer reçoit VRAI
			// si le choix de la colonne n'est pas bon (joueur qui essaye de placer un pion dans une colonne pleine par exemple)
			// on affiche un message d'erreur et jouer reçoit FAUX
			case 'b' : jouer=placerBlocante(grille, hauteurColonne, colonne, player,joueurs[player-1].nom); break;
			
			// meme commentaire ....( cette fois pour la creuse)
			case 'c' : jouer=placerCreuse(grille, hauteurColonne, colonne, player,joueurs[player-1].nom); break;
					
			case 'p' : jouer=placerPleine(grille, hauteurColonne, colonne, player,joueurs[player-1].nom); break;
		}
	}
	
}
	