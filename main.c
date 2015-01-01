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

booleen grillePleine(pion T[N][M], int V[M])
{
	int i;
	
	for(i=0;i<M;i++)
	{
		if( (V[i]!=0) || (V[i]==0 && caseBlocante(T,0,i)==FAUX && casePleineCreuse(T,0,i)==FAUX) )
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	int i;
	char piece;
	int colonne;
	int player=1;  // variable qui permet d'alterner le tour des joueurs
	// le nom du 1er joueur (ne peut dépasser 10 caractères, mais on déclare 11 car fgets reserve la dernière case
	//char nom1[12]; // le nom du 1er joueur (ne peut dépasser 10 caractères, mais on déclare 11 car fgets reserve la dernière case
	//char nom2[12]; // le nom ou pseudo du deuxième joueur 
	booleen jouer; // variable qui reçoit vrai si le joueur a bien placer son pion, faux sinon
	
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	
	for(i=1;i<=2;i++)
	{
		menuDebut(i,joueurs);
	}
	
	/*printf(" joueur 1, quel est votre nom ");
	lire(nom1,11);
	printf(" joueur 2, quel est votre nom ");
	lire(nom2,11);
	clrscr();*/
	
	do
	{	
		if(player==1)
		{
			jouer=FAUX;
			
			piece=menuChoixPion(joueurs[0].nom);
			while(!jouer) // tant que le joueur1 n'a pas placer son jeton
			{
				colonne=menuChoixColonne(joueurs[0].nom);
				while(colonne==0)
				{
					piece=menuChoixPion(joueurs[0].nom);
					colonne=menuChoixColonne(joueurs[0].nom);
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
					while(colonne==0)
					{
						piece=menuChoixPion(joueurs[1].nom);
						colonne=menuChoixColonne(joueurs[1].nom);
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
		
		


