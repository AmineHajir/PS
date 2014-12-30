#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"
#include "placerPion.h"
#include "couleurs.h"

/**
 * \file placerPion.c
 * \brief ce fichier source contient les définitions des fonctions qui permettent de placer un pion dans la bonne case de la grille du jeu.
 * \author Hajir Mohammed Amine
 * \date 23 Décembre 2014
 * \details On définit trois fonctions puisqu'il y trois types de pions différents : une procèdure pour placer la pièce pleine,
 * 	    une deuxième pour placer la pièce creuse et une troisième pour placer la bloquante.
 *	    N.B: ces procédures affichent des messages si la colonne choisis est pleine....     
*/

/**
 * \fn void placerPleine(pion T[N][M], int V[M], int colonne)
 * \brief procédure qui positionne la pièce pleine au bon emplacement (case) de la grille.
 * \param T la grille du jeu puissance4++.
 * \param V le tableau ou sont stockées les hauteurs des colonnes.
 * \param colonne numéro de la colonne saisis par le joueur.
 * \param joueur le numéro du player qui a choisis de joueur la piece pleine.
*/
void placerPleine(pion T[N][M], int V[M], int colonne, int joueur)
{
	int indice=V[colonne-1]; // on récupère la valeur de la première case vide et on la stocke dans la variable indice. 
	int i=indice+1; // variable qui parcourt les case inférieure à la case vide
	booleen caseTrouve=FAUX; // permet de sortir de la boucle while
	
	// si on est arrivé à la première case d'une colonne, et que cette case n'est pas vide et ne contient pas une pièce creuse   
	if( (indice == 0) && (caseCreuse(T,indice,colonne-1) == FAUX) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( casePleine(T,indice,colonne-1) )
		{
			couleur(ROUGEGRAS);// on affiche les messages en rouge et en gras pour alerter le joueur
			// le joueur ne peut pas jouer une pleine si la prmière case contient une pleine
			printf("\n ATTENTION : Vous ne pouvez jouer que la piece creuse dans la colonne %i \n\n",colonne);
			couleur(DEFAULT);// pour remettre la couleur par default du systeme
		}
		else
		{	
			couleur(ROUGEGRAS);// on affiche les messages en rouge et en gras pour alerter le joueur
			//le joueur ne peut plus jouer dans la colonne si la première case contient une bloquante
			printf("\n ATTENTION : la colonne %i est pleine, choisissez en une autre \n\n",colonne);
			couleur(DEFAULT);
		}
	}
	// dans tous les autres cas
	else
	{
	
		while( i<=N-1 && !caseTrouve ) // tant que la case correspendante à l'indice i contient une creuse et qu'on est pas arrivé à 
		{				// la dernière ligne on boucle	
			if( caseCreuse(T,i,colonne-1) ) // tant qu'on trouve une creuse dans la case inférieure, on déscend dans la colonne
			{
				indice = i;
				i++;
			}
			else
			{
				caseTrouve = VRAI; // si une case contient une pleine ou une bloquante on sort de la boucle
			}
		}
		T[indice][colonne-1].plein = joueur; // on place la pièce pleine dans la bonne case
								
		if( (V[colonne-1] > 0) && (caseVide(T,V[colonne-1],colonne-1) == FAUX) ) 
		{
			V[colonne-1]--; // on ne decrémente pas la hauteur de la colonne si la première case libre est la première case de la colonne
		}			// on ne decrémente pas la hauteur de la colonne si une creuse est passée dessus une pièce pleine	
	}				// ou si une pièce pleine est passée au travers une pièce creuse
					// car la première case libre reste la meme
	
}

/**
 * \fn void placerCreuse(pion T[N][M], int V[M], int colonne)
 * \brief procédure qui positionne la pièce creuse au bon emplacement (case) de la grille.
 * \param T la grille du jeu puissance4++.
 * \param V le tableau ou sont stockées les hauteurs des colonnes.
 * \param colonne numéro de la colonne saisis par le joueur.
 * \param joueur le numéro du player qui a choisis de joueur la piece creuse.
*/
// meme principe que pour la pièce pleine
void placerCreuse(pion T[N][M], int V[M], int colonne,int joueur)
{
	int indice=V[colonne-1];
	int i=indice+1;
	booleen caseTrouve=FAUX;
	
	if( (indice == 0) && (casePleine(T,indice,colonne-1) == FAUX) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( caseCreuse(T,indice,colonne-1) )
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : Vous ne pouvez jouer que la piece pleine dans la colonne %i \n\n",colonne);
			couleur(DEFAULT);
			
		}
		else
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : la colonne %i est pleine, choisissez en une autre \n\n",colonne);
			couleur(DEFAULT);
		}
	}
	else
	{
	
		while( i<=N-1 && !caseTrouve )
		{
			if( casePleine(T,i,colonne-1) )
			{
				indice = i;
				i++;
			}
			else
			{
				caseTrouve = VRAI;
			}
		}
		T[indice][colonne-1].creux = joueur;
								
		if( (V[colonne-1] > 0) && (caseVide(T,V[colonne-1],colonne-1) == FAUX) )
		{
			V[colonne-1]--;
		}
	}
}

/**
 * \fn void placerBlocante(pion T[N][M], int V[M], int colonne)
 * \brief procédure qui positionne la pièce bloquante au bon emplacement (case) de la grille.
 * \param T la grille du jeu puissance4++.
 * \param V le tableau ou sont stockées les hauteurs des colonnes.
 * \param colonne numéro de la colonne saisis par le joueur.
 * \param joueur le numéro du player qui a choisis de joueur la piece bloquante.
*/
void placerBlocante(pion T[N][M], int V[M], int colonne, int joueur)
{
	int indice=V[colonne-1];
	
	// si on est arrivé à la première case d'une colonne et que cette case n'est pas vide il reste trois cas possible:
	if( (indice == 0) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( casePleine(T,indice,colonne-1) ) // soit cette dernière case contient une pleine dans quel cas on ne peut jouer qu'une creuse
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : Vous ne pouvez jouer que la piece creuse dans la colonne %i \n\n",colonne);
			couleur(DEFAULT);
		}
		else
		{
			if( caseCreuse(T,indice,colonne-1) ) // soit cette dernière case contient une creuse dans quel cas on ne peut jouer
			{				     // qu'une pleine	
				couleur(ROUGEGRAS);
				printf("\n ATTENTION : Vous ne pouvez jouer que la piece pleine dans la colonne %i \n\n",colonne);
				couleur(DEFAULT);
			}
			else
			{	// cas ou cette case une blocante ou deux pièce(creuse et pleine)
				couleur(ROUGEGRAS);
				printf("\n ATTENTION : la colonne %i est pleine, choisissez en une autre \n\n",colonne);
				couleur(DEFAULT);
			}
		}
	}
	else
	{
		T[indice][colonne-1].bloc = joueur;
	
		if(indice > 0) // pour éviter que la hauteur d'une colonne soit négative
		{
			V[colonne-1]--;
		}
	}
}
	
