#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"
#include "victoire.h"

/**
 * \file victoire.c
 * \author Hajir Mohammed Amine
 * \date 3 Janvier 2015
 * \brief ce fichier source contient les définitions des fonctions booloéenne qui permettent de detecter une victoire d'un joueur.
 * \details Il existe trois cas possible pour une vctoire : 1er cas : 4 pions(ou plus) alignés horizontalement |
 * 	    2eme cas : 4 pions au min alignés verticalement | 3eme cas : 4 pions au minimum alignés en diagonale
 *	    N.B. un joueur gagne s'il aligne au minimum 4 pions verticalement ou horizontalement ou en diagonale
 * 	    mais peut bien gagner en alignant les pions vertiacalement et horizontalement et en diagonale en meme temps
*/

/**
 * \fn booleen case_du_joueur(pion T[N][M], int player, int ligne, int colonne)
 * \brief fonction qui indique si une case de la grille appartient à un joueur donné.
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice ou le joueur a placer son pion
 * \param colonne indice de la colonne de la case de la matrice ou le joueur a placer son pion
 * \return VRAI si la cette case appartient ou joueur, faux sinon
*/
booleen case_du_joueur(pion T[N][M], int player, int ligne, int colonne)
{
	if( (T[ligne][colonne].bloc == player) || (T[ligne][colonne].creux == player) || (T[ligne][colonne].plein == player) )
	{
		return VRAI; // si le joueur a placé un pion (n'importe lequel) dans la case de coordonnées ligne/colonne 
	}		     // alors cette case lui appartient ( N.B : une case peut appartenir à deux joueurs au max ) 
	else		     // on retourne donc VRAI	
	{
		return FAUX; // si cette case n'appartient au joueur, on retourne FAUX
	}
}

/**
 * \fn booleen horizontal_win(pion T[N][M], int player, int ligne, int colonne)
 * \brief fonction booleenne permettant de déceler un alignement horizontal de 4 pions du joueur en question
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice ou le joueur a placer son pion
 * \param colonne indice de la colonne de la case de la matrice ou le joueur a placer son pion
 * \return VRAI si une victoire horizontale est detectée, FAUX sinon
*/
booleen horizontal_win(pion T[N][M], int player, int ligne, int colonne)
{
	int i=1; // variable qui va parcourir les cases voisines qui se trouvent à droite de la case ou le pion a été placé
	int j=1; // variable qui va parcourir les cases voisines qui se trouvent à gauche de la case ou le pion a été placé
	int cpt_droite=0; // compte le nombre de case voisines droites appartenant au joueur qui vient de placer son pion 
	int cpt_gauche=0; // compte le nombre de case voisines gauches appartenant au joueur qui vient de placer son pion 
	
	// on cherche à droite s'il y a des cases qui appartiennent au joueur au question et on les dénombre 
	while( colonne+i < M ) // tant qu'on est pas arrivé à la bordure droite de la grille
	{
		if( case_du_joueur(T,player, ligne, colonne+i) ) // si la case voisine appartient au joueur
		{
			cpt_droite++; // on incrémente le compteur des cases voisines droites
			i++; // et on va chercher si la case suivante appartient aussi au joueur
		}
		else // dès qu'on tombe sur une case qui n'appartient pas au joueur
		{
			i=M; // on force la sortie de la boucle en affectant le nbre de colonne de la grille à i. 
			     // on simule un depassement de la taille de la matrice (colonne+M > 6 qlq soit la valeur de colonne)
		}	
	}
	// on cherche à gauche s'il y a des cases qui appartiennent au joueur au question et on les dénombre 
	while( colonne-j >= 0 ) // tant qu'on est pas arrivé à la bordure droite de la grille
	{
		if( case_du_joueur(T,player, ligne, colonne-j) ) // si case appartient o joueur
		{
			cpt_gauche++; // on incrémente le cpt de voisine gauche appartenant o meme joueur
			j++;
		}
		else // sinon, on force la sortie de la boucle 
		{
			j=M;
		}
	}
	if( (cpt_droite+cpt_gauche) >= 3 ) // si le nombre de voisine horizontale (gauche et droite) de la case ou le joueur a déposé son pion
	{ 				    // est >=3 alors il y le joueur a gagné.
		return VRAI;
	}
	else // si inferieur à 3 alors il n'y a pas de victoire horizontale
	{
		return FAUX;
	}
}

booleen vertical_win(pion T[N][M], int player, int ligne, int colonne)
{
	int i=1; // variable qui va parcourir les cases voisines qui se trouvent en dessous de la case ou le pion a été placé
	int j=1; // variable qui va parcourir les cases voisines qui se trouvent au dessus de la case ou le pion a été placé
	int cpt_bas=0; // compte le nombre de case voisines d'en dessous appartenant au joueur qui vient de placer son pion 
	int cpt_haut=0; // compte le nombre de case voisines du dessus appartenant au joueur qui vient de placer son pion 
	
	while( ligne+i < N )
	{
		if( case_du_joueur(T,player, ligne+i, colonne) )
		{
			cpt_bas++;
			i++;
		}
		else
		{
			i=N;
		}
	}
	
	while( ligne-j >= 0 ) // tant qu'on est pas arrivé à la bordure droite de la grille
	{
		if( case_du_joueur(T,player, ligne-j, colonne) ) // si case appartient o joueur
		{
			cpt_haut++; // on incrémente le cpt de voisine gauche appartenant o meme joueur
			j++;
		}
		else // sinon, on force la sortie de la boucle 
		{
			j=N;
		}
	}
	
	if( (cpt_bas+cpt_haut) >= 3 ) // si le nombre de voisine horizontale (gauche et droite) de la case ou le joueur a déposé son pion
	{ 				    // est >=3 alors il y le joueur a gagné.
		return VRAI;
	}
	else // si inferieur à 3 alors il n'y a pas de victoire horizontale
	{
		return FAUX;
	}
}		
	
	
	
	
	


			
		
	
	