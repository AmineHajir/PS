#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"


booleen caseVide(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux == VIDE) && (T[ligne][colonne].plein == VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

booleen casePleine(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux == VIDE) && (T[ligne][colonne].plein == PLEINE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

booleen caseBlocante(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == BLOCANTE) && (T[ligne][colonne].creux == VIDE) && (T[ligne][colonne].plein == VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

booleen caseCreuse(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux == CREUSE) && (T[ligne][colonne].plein == VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

booleen casePleineCreuse(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux == CREUSE) && (T[ligne][colonne].plein == PLEINE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}
