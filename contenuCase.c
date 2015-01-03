#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"

/**
 * \file contenuCase.c
 * \author Hajir Mohammed Amine
 * \date 21 Décembre 2014
 * \brief ce fichier source contient les définitions des fonctions booloéenne qui permettent d'identifier le contenu d'une case de la grille du jeu.
 * \brief il contient également la définition de la fonction qui pesrmet de savoir si la grille du jeu est entièrement remplie.
 * \details Il existe cinq cas possible pour le contenu d'une case :
 * 	    1er cas : case vide | 2eme cas : case contient une pièce pleine | 3eme cas : case contient une pièce creuse
 *          4eme cas : case contient une pièce blocante | 5eme cas : case contient deux pièce (une creuse et une pleine)
 * 	    on va donc définir 5 fonctions 
*/

/**
 * \fn booleen caseVide(pion T[N][M], int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille est vide "ne contient aucun pion" (ou pas!!).
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice qu'on souhaite tester si vide ou pas
 * \param colonne indice de la colonne de la case de la matrice qu'on souhaite tester si vide 
 * \return VRAI si la case est vide FAUX sinon
*/
booleen caseVide(pion T[N][M], int ligne, int colonne)
{	
	// si la case ne contient ni blocante ni creuse ni pleine
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
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice qu'on souhaite tester si elle contient que la piece pleine
 * \param colonne indice de la colonne de la case de la matrice qu'on souhaite tester ...
 * \return VRAI si la case contient uniquement une pièce pleine FAUX sinon
*/
booleen casePleine(pion T[N][M], int ligne, int colonne)
{
	// si la case ne contient ni creuse ni blocante mais une pleine
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
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice qu'on souhaite tester si elle contient que la pièce blocante 
 * \param colonne indice de la colonne de la case de la matrice ...
 * \return VRAI si la case contient uniquement une pièce bloquante FAUX sinon
*/
booleen caseBlocante(pion T[N][M], int ligne, int colonne)
{
	//si la case ne contient ni creuse ni pleine mais une blocante
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
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice qu'on souhaite tester si elle contient que la pièce creuse 
 * \param colonne indice de la colonne de la case de la matrice ...
 * \return VRAI si la case contient uniquement une pièce creuse FAUX sinon
*/
booleen caseCreuse(pion T[N][M], int ligne, int colonne)
{
	// si la case ne contient ni blocante ni pleine mais une creuse
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
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice qu'on souhaite tester si elle contient les deux pièces : creuse et pleine
 * \param colonne indice de la colonne de la case de la matrice ...
 * \return VRAI si la case contient uniquement une pièce pleine FAUX sinon
*/
booleen casePleineCreuse(pion T[N][M], int ligne, int colonne)
{
	// si la case contient exactement une creuse et une pleine mais pas de blocante
	if( (T[ligne][colonne].bloc == VIDE) && (T[ligne][colonne].creux != VIDE) && (T[ligne][colonne].plein != VIDE) )
	{
		return VRAI;
	}
	
	else
	{
		return FAUX;
	}
}

/**
 * \fn booleen grillePleine(pion T[N][M], int V[M])
 * \brief fonction qui indique si la grille du jeu est pleine.
 * \details la grille est pleine ssi chaque case de la matrice contient soit : une blocante, soit une creuse et une pleine.
 * \param pion la grille du jeu.
 * \param V tableau des hauteurs des colonnes de la grille du jeu.
 * \return VRAI si la grille est remplie FAUX sinon
*/
booleen grillePleine(pion T[N][M], int V[M])
{
	int i;
	
	for(i=0;i<M;i++) 
	{
		// premier cas V[i]!=0 : s'il existe une case du tableau de hauteurs de colonnes dont la valeur est différente de 0 
		// ceci voudra dire qu'il existe tjrs une colonne qui n'est pas entièrement pleine, par conséquent la grille n'est pas pleine.
		// deuxième cas : si toutes les case du tableau de hauteurs de colonnes ont une valeur égale à 0,
		// et si de plus toutes les cases de la premières ligne de la matrice ne ne contiennent ni blocante ni pleine/creuse
		// alors ceci voudra dire que malgè qu'on est arrivé a la première ligne de la matrice, il existe tjrs une case qui n'est
		// pas entièrement pleine, et par conséquent la matrice n'est pas pleine, on retourne donc faux.
		if( (V[i]!=0) || (V[i]==0 && caseBlocante(T,0,i)==FAUX && casePleineCreuse(T,0,i)==FAUX) )
		{
			return FAUX;
		}
	}
	// si toutes les cases du tableau hauteur contiennent la valeur 0 et si de plus toutes les cases de la première ligne de la matrice
	// sont remplie, alors la matrice et pleine, on retourne donc vrai.
	return VRAI;
}
