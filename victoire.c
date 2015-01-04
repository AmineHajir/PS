
#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"
#include "victoire.h"


booleen case_du_joueur(pion T[N][M], int player, int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == player) || (T[ligne][colonne].creux == player) || (T[ligne][colonne].plein == player) )
	{
		return VRAI;
	}
	else
	{
		return FAUX;
	}
}

booleen win_right_horizontal(pion T[N][M], int player, int ligne, int colonne)
{
	int i=1;
	int j=1;
	int cpt_droite=0;
	int cpt_gauche=0;
	
	while( colonne+i < M )
	{
		if( case_du_joueur(T,player, ligne, colonne+i) )
		{
			cpt_droite++;
			i++;
		}
		else
		{
			i=M;
		}
	}
	while( colonne-j >= 0 )
	{
		if( case_du_joueur(T,player, ligne, colonne-j) )
		{
			cpt_gauche++;
			j++;
		}
		else
		{
			j=M;
		}
	}
	if( (cpt_droite+cpt_gauche) >= 3 )
	{ 
		return VRAI;
	}
	else
	{
		return FAUX;
	}
	
}

/*int win_left_horizontal(pion T[N][M], int player, int ligne, int colonne)
{
	int i=1;
	int cpt=0;
	
	while( colonne-i >= 0 )
	{
		if( case_du_joueur(T,player, ligne, colonne-i) )
		{
			cpt++;
			i++;
		}
		else
		{
			i=M;
		}
	}
	return cpt;
}*/
			
		
	
	