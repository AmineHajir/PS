#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"

/**
 * \file contenuCase.c
 * \author Hajir Mohammed Amine
 * \date 21 Décembre 2014
 * \brief ce fichier source contient les définitions des fonctions booloéenne qui permettent d'identifier le contenu d'une case de la grille du jeu.
 * \details Il existe cinq cas possible pour le contenu d'une case :
 * 	    1er cas : case vide | 2eme cas : case contient une pièce pleine | 3eme cas : case contient une pièce creuse
 *          4eme cas : case contient une pièce blocante | 5eme cas : case contient deux pièce (une creuse et une pleine)
 * 	    on va donc définir 5 fonctions
 * 
*/

/**
 * \fn booleen caseVide(pion T[N][M], int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille est vide "ne contient aucun pion" (ou pas!!).
 * \return 1 si la case est vide 0 sinon
*/
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

/**
 * \fn booleen casePleine(pion T[N][M], int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille comporte uniquement la piece pleine.
 * \return 1 si la case contient uniquement une pièce pleine 0 sinon
*/
booleen casePleine(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux == VIDE) && (T[ligne][colonne].plein != VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

/**
 * \fn booleen caseBlocante(pion T[N][M], int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille comporte uniquement la piece bloquante.
 * \return 1 si la case contient uniquement une pièce bloquante 0 sinon
*/
booleen caseBlocante(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc != VIDE) && (T[ligne][colonne].creux == VIDE) && (T[ligne][colonne].plein == VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

/**
 * \fn booleen caseCreuse(pion T[N][M], int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille comporte uniquement la piece creuse.
 * \return 1 si la case contient uniquement une pièce creuse 0 sinon
*/
booleen caseCreuse(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux != VIDE) && (T[ligne][colonne].plein == VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

/**
 * \fn booleen casePleineCreuse(pion T[N][M], int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille comporte exactement les deux pièces pleine et creuse. (non nécessaire) 
 * \return 1 si la case contient uniquement une pièce pleine 0 sinon
*/
booleen casePleineCreuse(pion T[N][M], int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux != VIDE) && (T[ligne][colonne].plein != VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}
