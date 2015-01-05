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
 * \brief fonction booleenne permettant de déceler un alignement horizontal de 4 pions(ou plus) du joueur en question
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice ou le joueur a placer son pion
 * \param colonne indice de la colonne de la case de la matrice ou le joueur a placer son pion
 * \return VRAI si une victoire horizontale est detectée, FAUX sinon
*/
booleen horizontal_win(pion T[N][M], int player, int ligne, int colonne)
{
	int i=1; // variable qui va nous permettre de parcourir les cases voisines qui se trouvent à droite de la case ou le pion a été placé
	int j=1; // variable qui va nous permettre de parcourir les cases voisines qui se trouvent à gauche de la case ou le pion a été placé
	int cpt_droite=0; // compte le nombre de case voisines droites appartenant au joueur qui vient de placer son pion 
	int cpt_gauche=0; // compte le nombre de case voisines gauches appartenant au joueur qui vient de placer son pion 
	
	// on cherche à droite s'il y a des cases qui appartiennent au joueur en question et on les dénombre 
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
	{ 				    // est >=3 alors le joueur a gagné.
		return VRAI;
	}
	else // si inferieur à 3 alors il n'y a pas de victoire horizontale
	{
		return FAUX;
	}
}

/**
 * \fn booleen vertical_win(pion T[N][M], int player, int ligne, int colonne)
 * \brief fonction booleenne permettant de déceler un alignement vertical de 4 pions (ou plus) du joueur en question
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice ou le joueur a placer son pion
 * \param colonne indice de la colonne de la case de la matrice ou le joueur a placer son pion
 * \return VRAI si une victoire verticale est detectée, FAUX sinon
*/
// meme principe que la fonction victoire horizontale, ici on parcourt les cases verticales au lieu des cases horizontales
booleen vertical_win(pion T[N][M], int player, int ligne, int colonne)
{
	int i=1; // variable qui va nous permettre de parcourir les cases voisines qui se trouvent en dessous de la case ou le pion a été placé
	int j=1; // variable qui va nous permettre de parcourir les cases voisines qui se trouvent au dessus de la case ou le pion a été placé
	int cpt_bas=0; // compte le nombre de case voisines d'en dessous appartenant au joueur qui vient de placer son pion 
	int cpt_haut=0; // compte le nombre de case voisines du dessus appartenant au joueur qui vient de placer son pion 
	
	// on cherche en dessous s'il y a des cases qui appartiennent au joueur en question et on les dénombre 
	while( ligne+i < N )// tant qu'on est pas atteint l'extrémité inférieure de la grille
	{
		if( case_du_joueur(T,player, ligne+i, colonne) ) // si la case voisine appartient au joueur 
		{
			cpt_bas++; // on incrémente le compteur des cases voisines inférieures
			i++; // et on va chercher si la case inférieure suivante appartient aussi au joueur
		}
		else // dès qu'on tombe sur une case qui n'appartient pas au joueur
		{
			i=N; // on force la sortie de la boucle en affectant le nbre de lignes de la grille à i. 
			     // on simule un depassement de la taille de la matrice (ligne+M > 5 qlq soit la valeur de ligne)
		}
	}
	// on cherche au dessus s'il y a des cases qui appartiennent au joueur en question et on les dénombre
	while( ligne-j >= 0 ) // tant qu'on a pas atteint l'extremité supérieure de la grille
	{
		if( case_du_joueur(T,player, ligne-j, colonne) ) // si case appartient o joueur
		{
			cpt_haut++; // on incrémente le cpt des cases voisines supérieures appartenant o meme joueur
			j++; // on verifie si la case supérieure suivante appartient également o joueur
		}
		else // sinon, on force la sortie de la boucle 
		{
			j=N;
		}
	}
	
	if( (cpt_bas+cpt_haut) >= 3 ) // si le nombre de cases voisines verticales (du dessus et d'en d'en dessous) de la case ou le joueur 
				       // a déposé son pion est >=3 alors le joueur a gagné.
	{ 				    
		return VRAI;
	}
	else // si inferieur à 3 alors il n'y a pas de victoire verticale
	{
		return FAUX;
	}
}		

/**
 * \fn booleen right_diagonal_win(pion T[N][M], int player, int ligne, int colonne)
 * \brief fonction booleenne permettant de déceler un alignement de 4 pions (ou plus) du joueur en question suivant la diagonale droite 
 * \details on l'appelera diagonale droite car elle est inclineé vers la droite 
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice ou le joueur a placer son pion
 * \param colonne indice de la colonne de la case de la matrice ou le joueur a placer son pion
 * \return VRAI si une victoire diagonale droite est detectée, FAUX sinon
*/
// presque le meme principe que les fonctions précedentes : pour acceder aux cases qui se situent dans la diagonale droite il faut :
// 1er cas : decrémenter la ligne de 1 et incrémenter la colonne de 1 à chaque fois ( on monte dans la diagonale )
// 2eme cas : incrémenter la lignes de 1 et decrémenter la colonnes de 1 à chaque fois ( on déscend dans la diagonale )
booleen right_diagonal_win(pion T[N][M], int player, int ligne, int colonne)	
{
	int i=1; // variable qui permet de parcourir les cases voisines qui se situent dans la diagonale et qui sont au dessus de la case jouée
	int j=1; // variable qui permet de parcourir les cases voisines qui se situent dans la diagonale et qui sont en dessous de la case jouée
	int cpt_droite_haut=0; // compte le nombre de cases voisines appartenant o joueur, se situant ds la diagonale et au dessus de la case jouée 
	int cpt_gauche_bas=0; // compte le nombre de cases voisines appartenant o joueur, se situant ds la diagonale et en dessous de la case jouée
	
	// on monte ds la diagonale droite (on l'appel diagonale droite car elle est inclinée vers la droite) 
	// pour monter ds la diagonale on décremente la ligne de 1 et on incrémente la colonne de 1
	while( (ligne-i >= 0) && (colonne+i < M) ) // tant qu'on dépasse pas la taille de la matrice
	{
		if( case_du_joueur(T,player, ligne-i, colonne+i) ) // si la case se situant ds la daiagonale appartient o joueur
		{
			cpt_droite_haut++; // on incrémente le compteur
			i++; // et on passe à la case suivante
		}
		else // sinon, on sort de la boucle en simulant un dépassement de la taille de la matrice
		{
			i=N; // ou i=M
		}
	}
	//on descend ds la diagonale : ici on incrémente la ligne de 1 et on decrémente la colonne de 1
 	while( (ligne+j < N) && (colonne-j >= 0) ) 
	{
		if( case_du_joueur(T,player, ligne+j, colonne-j) ) // meme commentaire ...
		{
			cpt_gauche_bas++;
			j++;
		}
		else
		{
			j=N;
		}
	}
	if( (cpt_droite_haut+cpt_gauche_bas) >= 3 ) // si 4 cases appartiennent o joueur (3 dans la diagonal + celle ou il vient de deposer son pion)
	{ 				    
		return VRAI;
	}
	else // si inferieur à 3 alors il n'y a pas de victoire dans la diagonale droite
	{
		return FAUX;
	}
}
			
/**
 * \fn booleen left_diagonal_win(pion T[N][M], int player, int ligne, int colonne)
 * \brief fonction booleenne permettant de déceler un alignement de 4 pions (ou plus) du joueur en question suivant la diagonale gauche
 * \details on l'appelera diagonale gauche car elle est inclineé vers la gauche
 * \param pion la grille du jeu.
 * \param ligne indice de la ligne de la case de la matrice ou le joueur a placer son pion
 * \param colonne indice de la colonne de la case de la matrice ou le joueur a placer son pion
 * \return VRAI si une victoire diagonale droite est detectée, FAUX sinon
*/			
		
// meme principe que victoire diagonale droite : pour acceder aux cases qui se situent dans la diagonale gauche il faut :
// 1er cas : decrémenter la ligne et la colonne de 1 à chaque fois ( on monte dans la diagonale )
// 2eme cas : incrémenter la ligne et la colonne de 1 à chaque fois ( on déscend dans la diagonale )
booleen left_diagonal_win(pion T[N][M], int player, int ligne, int colonne)	
{
	int i=1; // variable qui permet de parcourir les cases voisines qui se situent dans la diagonale et qui sont au dessus de la case jouée
	int j=1; // variable qui permet de parcourir les cases voisines qui se situent dans la diagonale et qui sont en dessous de la case jouée
	int cpt_gauche_haut=0; // compte le nombre de cases voisines appartenant o joueur, se situant sur la diagonale et au dessus de la case jouée 
	int cpt_droite_bas=0; // compte le nombre de cases voisines appartenant o joueur, se situant sur la diagonale et en dessous de la case jouée
	
	// on monte ds la diagonale gauche 
	// pour monter ds la diagonale on décrémente la ligne et la colonne de 1 à chaque passage ds la boucle
	while( (ligne-i >= 0) && (colonne-i < M) ) // tant qu'on dépasse pas la taille de la matrice
	{
		if( case_du_joueur(T,player, ligne-i, colonne-i) ) // si la case se situant ds la daiagonale appartient o joueur
		{
			cpt_gauche_haut++; // on incrémente le compteur
			i++; // et on passe à la case suivante
		}
		else // sinon, on sort de la boucle en simulant un dépassement de la taille de la matrice
		{
			i=N; // ou i=M
		}
	}
	//on descend ds la diagonale : ici on incrémente la ligne et la colonne de 1
 	while( (ligne+j < N) && (colonne+j >= 0) ) 
	{
		if( case_du_joueur(T,player, ligne+j, colonne+j) ) // meme commentaire ...
		{
			cpt_droite_bas++;
			j++;
		}
		else
		{
			j=N;
		}
	}
	if( (cpt_gauche_haut+cpt_droite_bas) >= 3 ) // si 4 cases appartiennent o joueur (3 dans la diagonal + celle ou il vient de deposer son pion)
	{ 				    
		return VRAI;
	}
	else // si inferieur à 3 alors il n'y a pas de victoire dans la diagonale gauche
	{
		return FAUX;
	}
}	
	


			
		
	
	