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


void faireJouer(int *player)
{
	char piece;
	int colonne;
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
	
int main()
{
	int i;
	//char piece;
	//int colonne;
	int player=1;  // variable qui permet d'alterner le tour des joueurs
	//booleen jouer; // variable qui reçoit vrai si le joueur a bien placer son pion, faux sinon
	
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	
	for(i=1;i<=2;i++)
	{
		menuDebut(i,joueurs);
	}
	printf("\n");
	
	do
	{	
		if(player==1)
		{
			faireJouer(&player);
		}
		else
		{
			if(player==2)
			{
				faireJouer(&player);
			}
		}
	}while(grillePleine(grille,hauteurColonne) == FAUX);
			
	
	afficher_jeu(grille);
	
	printf("\n\n");
	return 0;
}
		
		


