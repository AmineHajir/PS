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
 * \brief procédure qui positionne la pièce pleine au bon emplacement (case) de la grille.(ou pas!! si colonne pleine).
 * \param T la grille du jeu puissance4++.
 * \param V le tableau ou sont stockées les hauteurs des colonnes.
 * \param colonne numéro de la colonne saisis par le joueur.
 * \param player le numéro du joueur(1 ou 2 si 2joueurs dans la partie) qui a choisis de jouer la piece pleine.
 * \param nom tableau de 12 caractères ou est stocké le nom du joueur.(10 carac. pr le nom car 2 dernieres cases reservées pr '\n' et '\0'.  
 * \return VRAI si le joueur a bien placer son pion FAUX sinon.
*/
booleen placerPleine(pion T[N][M], int V[M], int colonne, int player, char nom[12], int* p_ligne)
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
			printf("\n ATTENTION : %s, vous ne pouvez jouer que la piece creuse dans la colonne %i \n\n",nom,colonne);
			couleur(DEFAULT);// pour remettre la couleur par default du systeme
			
		}
		else
		{	
			couleur(ROUGEGRAS);// on affiche les messages en rouge et en gras pour alerter le joueur
			//le joueur ne peut plus jouer dans la colonne si la première case contient une bloquante
			printf("\n ATTENTION : %s, la colonne %i est pleine, choisissez en une autre \n\n",nom,colonne);
			couleur(DEFAULT);
			
		}
		return FAUX; // le joueur n'a pas jouer car il n'a pas pu placer son pion dans la colonne choisie, on retourne donc faux
		
		
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
		/* on place la pièce pleine dans la bonne case (en fait c'est le numéro du joueur qui est stocké en mémoire
		   et non pas le type de pièce)*/
		T[indice][colonne-1].plein = player; 
		(*p_ligne)=indice;
								
		if( (V[colonne-1] > 0) && (caseVide(T,V[colonne-1],colonne-1) == FAUX) ) 
		{
			V[colonne-1]--; // on ne decrémente pas la hauteur de la colonne si la première case libre est la première case de la colonne
		}			// on ne decrémente pas la hauteur de la colonne si une creuse est passée dessus une pièce pleine	
					// ou si une pièce pleine est passée au travers une pièce creuse
					// car la première case libre reste la meme
		return VRAI; // le pion a bien été placé dans la bonne case, on retourne donc vrai 
	}
}

/**
 * \fn void placerCreuse(pion T[N][M], int V[M], int colonne)
 * \brief procédure qui positionne la pièce creuse au bon emplacement (case) de la grille.(ou pas!! si colonne pleine).
 * \param T la grille du jeu puissance4++.
 * \param V le tableau ou sont stockées les hauteurs des colonnes.
 * \param colonne numéro de la colonne saisis par le joueur.
 * \param player le numéro du joueur qui a choisis de jouer la piece creuse.
 * \param nom tableau de 12 caractères ou est stocké le nom du joueur.
 * \return VRAI si le joueur a bien placer son pion FAUX sinon.
*/
// meme principe que pour la pièce pleine
booleen placerCreuse(pion T[N][M], int V[M], int colonne,int player,char nom[12], int* p_ligne)
{
	int indice=V[colonne-1];
	int i=indice+1;
	booleen caseTrouve=FAUX;
	
	if( (indice == 0) && (casePleine(T,indice,colonne-1) == FAUX) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( caseCreuse(T,indice,colonne-1) )
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : %s, vous ne pouvez jouer que la piece pleine dans la colonne %i \n\n",nom,colonne);
			couleur(DEFAULT);
			
		}
		else
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : %s, la colonne %i est pleine, choisissez en une autre \n\n",nom,colonne);
			couleur(DEFAULT);
		}
		return FAUX;
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
		T[indice][colonne-1].creux = player; // voir première fonction
		(*p_ligne)=indice;
								
		if( (V[colonne-1] > 0) && (caseVide(T,V[colonne-1],colonne-1) == FAUX) )
		{
			V[colonne-1]--;
		}
		return VRAI;
	}
}

/**
 * \fn void placerBlocante(pion T[N][M], int V[M], int colonne)
 * \brief procédure qui positionne la pièce bloquante au bon emplacement (case) de la grille.(ou pas!! si colonne pleine).
 * \param T la grille du jeu puissance4++.
 * \param V le tableau ou sont stockées les hauteurs des colonnes.
 * \param colonne numéro de la colonne saisis par le joueur.
 * \param player le numéro du joueur qui a choisis de jouer la piece bloquante.
 * \param nom tableau de 12 caractères ou est stocké le nom du joueur.
 * \return VRAI si le joueur a bien placer son pion FAUX sinon.
*/
booleen placerBlocante(pion T[N][M], int V[M], int colonne, int player, char nom[12],int* p_ligne)
{
	int indice=V[colonne-1];
	
	// si on est arrivé à la première case d'une colonne et que cette case n'est pas vide il reste trois cas possible:
	if( (indice == 0) && (caseVide(T,indice,colonne-1) == FAUX) )
	{
		if( casePleine(T,indice,colonne-1) ) // soit cette dernière case contient une pleine dans quel cas on ne peut jouer qu'une creuse
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : %s, vous ne pouvez jouer que la piece creuse dans la colonne %i \n\n",nom,colonne);
			couleur(DEFAULT);
		}
		else
		{
			if( caseCreuse(T,indice,colonne-1) ) // soit cette dernière case contient une creuse dans quel cas on ne peut jouer
			{				     // qu'une pleine	
				couleur(ROUGEGRAS);
				printf("\n ATTENTION : %s, vous ne pouvez jouer que la piece pleine dans la colonne %i \n\n",nom,colonne);
				couleur(DEFAULT);
			}
			else
			{	// cas ou cette case une blocante ou deux pièce(creuse et pleine)
				couleur(ROUGEGRAS);
				printf("\n ATTENTION : %s, la colonne %i est pleine, choisissez en une autre \n\n",nom,colonne);
				couleur(DEFAULT);
			}
		}
		return FAUX;
	}
	else
	{
		T[indice][colonne-1].bloc = player;
		(*p_ligne)=indice;
	
		if(indice > 0) // pour éviter que la hauteur d'une colonne soit négative
		{
			V[colonne-1]--;
		}
		return VRAI;
	}
}
	
