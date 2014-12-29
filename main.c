#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "affichageMenus.h"
#include "contenuCase.h"
#include "placerPion.h"

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
	char piece;
	int colonne;
	int joueur=1;
	
	printf("\n");
	initialiser_jeu(grille);
	initialiser_hauteurColonne(hauteurColonne);
	
	do
	{	piece=menuChoixPion();
		colonne=menuChoixColonne();
		
		switch(piece)
		{
			case 'b' : 
			{
				placerBlocante(grille, hauteurColonne, colonne, joueur);
			}break;
			
			case 'c' :
			{
				placerCreuse(grille, hauteurColonne, colonne, joueur);
			}break;
			
			case 'p' : 
			{
				placerPleine(grille, hauteurColonne, colonne, joueur);
				
			}break;
		}
	}while(grillePleine(grille,hauteurColonne) == FAUX);
			
	
	afficher_jeu(grille);
	
	printf("\n\n");
	return 0;
}
		
		


