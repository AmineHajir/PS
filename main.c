#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "affichageJeu.h"
#include "affichageMenus.h"
#include "contenuCase.h"
#include "placerPion.h"
#include "couleurs.h"

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


int lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	
	if (fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		viderBuffer();
		return 0;
	}
}
		
int main()
{
	char piece;
	int colonne;
	int player=1;  // variable qui permet d'alterner le tour des joueurs
	// le nom du 1er joueur (ne peut dépasser 10 caractères, mais on déclare 11 car fgets reserve la dernière case
	char nom1[11]; // le nom du 1er joueur (ne peut dépasser 10 caractères, mais on déclare 11 car fgets reserve la dernière case
	char nom2[11]; // le nom ou pseudo du deuxième joueur 
	booleen jouer; // variable qui reçoit vrai si le joueur a bien placer son pion, faux sinon
	
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	printf(" Binevenu sur Puissance 4++ \n");
	printf(" joueur 1, quel est votre nom ");
	lire(nom1,11);
	printf(" joueur 2, quel est votre nom ");
	lire(nom2,11);
	clrscr();
	
	do
	{	
		if(player==1)
		{
			jouer=FAUX;
			
			piece=menuChoixPion(nom1);
			while(!jouer) // tant que le joueur1 n'a pas placer son jeton
			{
				colonne=menuChoixColonne(nom1);
				
				switch(piece)
				{
					case 'b' : 
					{
						jouer=placerBlocante(grille, hauteurColonne, colonne, player,nom1);
					}break;
					
					case 'c' :
					{
						jouer=placerCreuse(grille, hauteurColonne, colonne, player,nom1);
					}break;
					
					case 'p' : 
					{
						jouer=placerPleine(grille, hauteurColonne, colonne, player,nom1);
						
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
				
				piece=menuChoixPion(nom2);
				while(!jouer) // meme commentaire que précédemment
				{
					colonne=menuChoixColonne(nom2);
					
					switch(piece)
					{
						case 'b' : 
						{
							jouer=placerBlocante(grille, hauteurColonne, colonne, player,nom2);
						}break;
						
						case 'c' :
						{
							jouer=placerCreuse(grille, hauteurColonne, colonne, player,nom2);
						}break;
						
						case 'p' : 
						{
							jouer=placerPleine(grille, hauteurColonne, colonne, player,nom2);
							
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
		
		


