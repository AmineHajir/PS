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

char* convert(char x)
{
	switch(x)
	{
		case 'n' : return "noir";   break;
		case 'r' : return "rouge";  break;
		case 'v' : return "vert";   break;
		case 'j' : return "jaune";  break;
		case 'b' : return "bleu";   break;
		case 'p' : return "violet"; break;
		case 'c' : return "cyan";   break;
		case 'w' : return "blanc";  break; 
		default  : return "system"; 
	}
}
int main()
{
	int i;
	char piece;
	int colonne;
	int player=1;  // variable qui permet d'alterner le tour des joueurs
	booleen jouer; // variable qui reçoit vrai si le joueur a bien placer son pion, faux sinon
	
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
			jouer=FAUX;
			
			piece=menuChoixPion(joueurs[0].nom);
			while(!jouer) // tant que le joueur1 n'a pas placer son jeton
			{
				colonne=menuChoixColonne(joueurs[0].nom);
				while(colonne==0 || colonne==8)
				{
					if(colonne==0)
					{
						piece=menuChoixPion(joueurs[0].nom);
						colonne=menuChoixColonne(joueurs[0].nom);
					}
					else
					{
						if(colonne==8)
						{
							couleur(ROUGEGRAS);
							printf("\n RAPPEL : %s, vous jouez avec des pions %s \n\n",joueurs[0].nom,convert(joueurs[0].couleur));
							couleur(DEFAULT);
							colonne=menuChoixColonne(joueurs[0].nom);
						}		
					}
				}
				switch(piece)
				{
					case 'b' : 
					{
						jouer=placerBlocante(grille, hauteurColonne, colonne, player,joueurs[0].nom);
					}break;
					
					case 'c' :
					{
						jouer=placerCreuse(grille, hauteurColonne, colonne, player,joueurs[0].nom);
					}break;
					
					case 'p' : 
					{
						jouer=placerPleine(grille, hauteurColonne, colonne, player,joueurs[0].nom);
						
					}break;
				}
			}
			player++; // quand le joueur1 aura bien placé son pion, on incrémente pour que le joueur2 puisse jouer à son tour
		}
		else
		{
			if(player==2)
			{
				jouer=FAUX;
				
				piece=menuChoixPion(joueurs[1].nom);
				while(!jouer) // meme commentaire que précédemment
				{
					colonne=menuChoixColonne(joueurs[1].nom);
					while(colonne==0 || colonne==8)
					{
						if(colonne==0)
						{
							piece=menuChoixPion(joueurs[1].nom);
							colonne=menuChoixColonne(joueurs[1].nom);
						}
						else
						{
							if(colonne==8)
							{
								couleur(ROUGEGRAS);
								printf("\n RAPPEL : %s, vous jouez avec des pions %s \n\n",joueurs[1].nom,convert(joueurs[1].couleur));
								couleur(DEFAULT);
								colonne=menuChoixColonne(joueurs[1].nom);
							}		
						}
					}
					switch(piece)
					{
						case 'b' : 
						{
							jouer=placerBlocante(grille, hauteurColonne, colonne, player,joueurs[1].nom);
						}break;
						
						case 'c' :
						{
							jouer=placerCreuse(grille, hauteurColonne, colonne, player,joueurs[1].nom);
						}break;
						
						case 'p' : 
						{
							jouer=placerPleine(grille, hauteurColonne, colonne, player,joueurs[1].nom);
							
						}break;
					}
				}
			}
			player--; // on decrémente cette fois pour revenir au premier joueur
		}
		
	}while(grillePleine(grille,hauteurColonne) == FAUX);
			
	
	afficher_jeu(grille);
	
	printf("\n\n");
	return 0;
}
		
		


