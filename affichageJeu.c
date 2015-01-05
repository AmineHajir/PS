#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "contenuCase.h"
#include "couleurs.h"
#include "menuDebut.h"
#include "boiteOutil.h"

/**
 * \file affichageJeu.c
 * \author Hajir Mohammed Amine
 * \date 19 Décembre 2014
 * \brief ce fichier source contient les définitions des fonctions d'affichage du titre et de la grille du jeu.
 * \details ce fichier contient aussi la définition de la fonction d'initialisation de la grille du jeu.
 *          il contient également la définition de la fonction d'initialisation du tableau qui stocke la hauteur de chaque colonne.
 * */

/**
 * \fn void afficher_titre_jeu()
 * \brief affiche le titre du jeu (ASCII art).
*/
void afficher_titre_jeu()
{
	couleur(GRAS);
	printf("\n");
	printf("                         68b                                                                       \n");
	printf("                         Y89                                                                       \n");
	printf("     __ ____   ___   ___ ___   ____     ____      ___    ___  __     ____     ____                 \n");
	printf("     `M6MMMMb  `MM    MM `MM  6MMMMb  6MMMMb    6MMMMb   `MM 6MMb   6MMMMb.  6MMMMb              M \n");
	printf("      MM'  `Mb  MM    MM  MM MM'    ` MM'    ` 8M'  `Mb   MMM9 `Mb 6M'   Mb 6M'  `Mb           ,dM \n");
	printf("      MM    MM  MM    MM  MM YM.      YM.          ,oMM   MM'   MM MM    `' MM    MM          ,dMM \n");
	printf("      MM    MM  MM    MM  MM  YMMMMb   YMMMMb  ,6MM9'MM   MM    MM MM       MMMMMMMM         ,d MM \n");
	printf("      MM    MM  MM    MM  MM      `Mb      `Mb MM'   MM   MM    MM MM       MM              ,d  MM       MM        MM\n");
	printf("      MM.  ,M9  YM.   MM  MM L    ,MM L    ,MM MM.  ,MM   MM    MM YM.   d9 YM    d9       ,d   MM       MM        MM\n");
	printf("      MMYMMM9    YMMM9MM__MM_MYMMMM9  MYMMMM9  `YMMM9'Yb._MM_  _MM_ YMMMM9   YMMMM9        MMMMMMMM   MMMMMMMM  MMMMMMMM\n");
	printf("      MM                                                                                        MM       MM        MM\n");
	printf("      MM                                                                                        MM       MM        MM\n");
	printf("     _MM_                                                                                       MM \n");
	printf("\n");
	couleur(DEFAULT);
}

/**
 * \fn void initialiser_jeu(pion T[N][M])
 * \brief procédure qui initialise les cases de la grille à vide (des espaces).
 * \param T matrcie de taille N(lignes)*M(colonnes) qui représente la grille du jeu.
*/
void initialiser_jeu(pion T[N][M])
{
	int i,j;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			T[i][j].bloc=VIDE; // on initialise chaque champ d'une case de la matrice par vide (des espaces)
			T[i][j].creux=VIDE;
			T[i][j].plein=VIDE;
		}
	}
}

/**
 * \fn initialiser_hauteurColonne(int V[M])
 * \brief procédure qui initialise le vecteur qui stocke les hauteurs des colonnes de la grille.
 * \param V tableau dont la taille est égale au nombre de colonnes de la grille.
*/
void initialiser_hauteurColonne(int V[M])
{
	int i;
	
	for(i=0;i<M;i++)
	{
		V[i]=N-1; // au début du jeu toute les colonnes sont vides --> hauteur = indice de la dernière ligne de la grille.
	}
}

/**
 * \fn void afficher_numColonne_jeu(int nbre_colonne)
 * \brief procédure qui affiche les numéros des colonnes de la grille du jeu. 
 * \param nbre_colonne nombre de colonnes de la grille du jeu.
*/
void afficher_numColonne_jeu(int nbre_colonne)
{
	int i;
	
	couleur(GRAS);
	for(i=0;i<nbre_colonne;i++)
	{
		if(i==0)
		{
			printf("     	             	     %i",i+1); // on affiche le numéro de la première colonne (1)
		}						       // on traite ce cas à part pour bien centrer l'affichage au dessus de la colonne
		else
		{
			printf("       %i",i+1); // on affiche le numéro des autres colonnes (de 2 à M)S
		}
	}
	couleur(DEFAULT);
}

/**
 * \fn void afficher_bordure_grille(int nbre_colonne)
 * \brief procédure qui affiche les bordures de la grille du jeu. 
 * \param nbre_colonne nombre de colonnes de la grille du jeu.
*/

void afficher_bordure_grille(int nbre_colonne)
{
	int i;
	
	couleur(GRAS); // des bordures en gras
	printf("			||");
	for(i=0;i<nbre_colonne;i++)
	{
		printf("=======|");
	}
	printf("|\n");
	couleur(DEFAULT);
}

/**
 * \fn void afficher_jeu(pion T[N][M])
 * \brief procédure qui affiche la grille du jeu. 
 * \param T matrice de type pion de taille N*M à afficher.
*/
void afficher_jeu(pion T[N][M])
{
	int i,j,k; // variables pour parcourir les cases de la matrice (grille du jeu)
	
	couleur(GRAS); // titre du jeu en gras (c plus joli!!)
	printf("			 	       _      _  _  _  _  _  _       \n");
	printf("				      |_|| |||_ |_ |_|| ||  |_  |_|   \n");
	printf("				      |  |_|| _| _|| || ||_ |_    | ++\n\n");
	couleur(DEFAULT);
				          
	afficher_numColonne_jeu(M); // on commence par afficher les numéro des colonnes.
	
	printf("\n");
	
	afficher_bordure_grille(M); // on affiche ensuite la bordure supérieure de la grille.
	
	for(i=0;i<N;i++)
	{
		couleur(GRAS);
		printf("			||"); // affiche la bordure gauche de chaque ligne.
		couleur(DEFAULT);
		for(j=0;j<M;j++)
		{
			if( caseVide(T,i,j) ) // si la case est vide on affiche des espaces.
			{
				couleur(GRAS);
				printf("       ");
				couleur(DEFAULT);
			}
			if( caseBlocante(T,i,j) ) // ssi la case contient une blocante (4 cas possible)
			{
				if( T[i][j].bloc == 1 ) // et que cette bloquante appartient au premier joueur
				{
					if( gain[i][j] == 1 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[0].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[0].couleur) ); // on affiche la pièce blocante avec la couleur que le joueur1
						printf("   %c   ",BLOCANTE);		// avait choisis au début du jeu stockée ds le tableau joueurs
						couleur(DEFAULT);
					}
				}
				if( T[i][j].bloc == 2 ) // de meme pour le joueur2
				{
					if( gain[i][j] == 2 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[1].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[1].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
				}
				if( T[i][j].bloc == 3 ) // de meme pour le joueur3 (si partie à 3joueur)
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[2].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
				}
				if( T[i][j].bloc == 4 ) // de meme pour le joueur4 (si partie à 4 joueurs)
				{
					if( gain[i][j] == 4 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[3].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[3].couleur) );
						printf("   %c   ",BLOCANTE);
						couleur(DEFAULT);
					}
				}
			}
			if( caseCreuse(T,i,j) ) // si la case contient uniquement une creuse (encore 4 cas possibles)
			{
				if( T[i][j].creux == 1 ) // et que cette creuse appartient au joueur1
				{
					if( gain[i][j] == 1 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[0].couleur) ); // on affiche la pièce avec la couleur choisie ...
						printf("   %c   ",CREUSE); 
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[0].couleur) ); // on affiche la pièce avec la couleur choisie ...
						printf("   %c   ",CREUSE); 
						couleur(DEFAULT);
					}
						
				}
				if( T[i][j].creux == 2 ) // de meme pour joueur2 ...
				{
					if( gain[i][j] == 2 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[1].couleur) );
						printf("   %c   ",CREUSE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[1].couleur) );
						printf("   %c   ",CREUSE);
						couleur(DEFAULT);
					}
				
				}
				if( T[i][j].creux == 3 ) // de meme pour joueur3 ...
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("   %c   ",CREUSE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[2].couleur) );
						printf("   %c   ",CREUSE);
						couleur(DEFAULT);
					}
						
				}
				if( T[i][j].creux == 4 ) // de meme pour joueur4 ...
				{
					if( gain[i][j] == 4 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[3].couleur) );
						printf("   %c   ",CREUSE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[3].couleur) );
						printf("   %c   ",CREUSE);
						couleur(DEFAULT);
					}
				}
			}
			if( casePleine(T,i,j) ) // meme commentaire que ci dessus (cette fois pr la pièce pleine)
			{
				if( T[i][j].plein == 1 )
				{
					if( gain[i][j] == 1 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[0].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[0].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
				}
				if( T[i][j].plein == 2 )
				{
					if( gain[i][j] == 2 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[1].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[1].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
				}
				if( T[i][j].plein == 3 )
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[2].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
				}
				if( T[i][j].plein == 4 )
				{
					if( gain[i][j] == 4 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[3].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[3].couleur) );
						printf("   %c   ",PLEINE);
						couleur(DEFAULT);
					}
				}
			}
			// (nbreJoueur)² cas possibles (4 cas possibles pr 2joueurs, 9 cas pr 3joueurs, et 16 cas pr 4 joueurs)
			if( casePleineCreuse(T,i,j) ) 
			{
				if( (T[i][j].creux == 1) && (T[i][j].plein == 1) ) // si la creuse et la pleine appartiennent au joueur1
				{
					if( gain[i][j] == 1 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[0].couleur) ); // on affiche les deux pions avec la couleur du joueur1
						printf("  %c %c  ",CREUSE,PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[0].couleur) ); // on affiche les deux pions avec la couleur du joueur1
						printf("  %c %c  ",CREUSE,PLEINE);
						couleur(DEFAULT);
					}
				}
				if( (T[i][j].creux == 2) && (T[i][j].plein == 2) ) // si elles appartiennent au joueur2
				{
					if( gain[i][j] == 2 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[1].couleur) );
						printf("  %c %c  ",CREUSE,PLEINE); // on affiche la couleur du joueur2
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[1].couleur) );
						printf("  %c %c  ",CREUSE,PLEINE); // on affiche la couleur du joueur2
						couleur(DEFAULT);
					}
				}
				if( (T[i][j].creux == 3) && (T[i][j].plein == 3) ) // si elles appartiennent au joueur3
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("  %c %c  ",CREUSE,PLEINE); // on affiche la couleur du joueur3 choisie au début du jeu
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[2].couleur) );
						printf("  %c %c  ",CREUSE,PLEINE); // on affiche la couleur du joueur3 choisie au début du jeu
						couleur(DEFAULT);
					}
				}
				if( (T[i][j].creux == 4) && (T[i][j].plein == 4) ) // si elles appartiennent au joueur4
				{
					if( gain[i][j] == 4 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[3].couleur) );
						printf("  %c %c  ",CREUSE,PLEINE); // on affiche la couleur du joueur4
						couleur(DEFAULT);
					}
					else
					{
						couleur( codage(joueurs[3].couleur) );
						printf("  %c %c  ",CREUSE,PLEINE); // on affiche la couleur du joueur4
						couleur(DEFAULT);
					}
				}
				if( (T[i][j].creux == 1) && (T[i][j].plein == 2) ) // si la creuse appartient au joueur1 et la pleine au joueur2
				{
					if( gain[i][j] == 1 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[0].couleur) ); // on afficher chaque pion avec la couleur correspondante a chak joueur
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[1].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 2 )
						{
							couleur( codage(joueurs[0].couleur) ); // on afficher chaque pion avec la couleur correspondante a chak joueur
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[0].couleur) ); // on afficher chaque pion avec la couleur correspondante a chak joueur
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 2) && (T[i][j].plein == 1) ) // de meme (on inverse)
				{
					if( gain[i][j] == 2 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[1].couleur) );
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[0].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 1 )
						{
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 1) && (T[i][j].plein == 3) ) // la creuse appartient au joueur 1 et la pleine au joueur3
				{						   
					if( gain[i][j] == 1 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[0].couleur) );	// chak pion s'affichera ac la couleur correspondante à chak joueur
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[2].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 3 )
						{
							couleur( codage(joueurs[0].couleur) );	// chak pion s'affichera ac la couleur correspondante à chak joueur
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[2].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[0].couleur) );	// chak pion s'affichera ac la couleur correspondante à chak joueur
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[2].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 3) && (T[i][j].plein == 1) ) // creuse apptien o joueur3 et pleine o joueur 1
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[0].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 1 )
						{
							couleur( codage(joueurs[2].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[2].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 2) && (T[i][j].plein == 3) ) // creuse du joueur2 et pleine du joueur3
				{
					if( gain[i][j] == 2 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[1].couleur) );
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[2].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 3 )
						{
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[2].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[2].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 3) && (T[i][j].plein == 2) ) // creuse du joueur3 et pleine du joueur2
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[1].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 2 )
						{
							couleur( codage(joueurs[2].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[2].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 1) && (T[i][j].plein == 4) ) // creuse du joueur1 et pleine du joueur4
				{
					if( gain[i][j] == 1 )
					{
							couleur(GRAS);
							couleur( codage(joueurs[0].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 4 )
						{
							couleur( codage(joueurs[0].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[0].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 4) && (T[i][j].plein == 1) ) // creuse du joueur4 et pleine du joueur1
				{
					if( gain[i][j] == 4 )
					{
							couleur(GRAS);
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 1 )
						{
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[0].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 2) && (T[i][j].plein == 4) ) // creuse du joueur2 et pleine du joueur4
				{
					if( gain[i][j] == 2 )
					{
							couleur(GRAS);
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 4 )
						{
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[1].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 4) && (T[i][j].plein == 2) ) // creuse du joueur4 et pleine du joueur2
				{
					if( gain[i][j] == 4 )
					{
							couleur(GRAS);
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 2 )
						{
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[1].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 3) && (T[i][j].plein == 4) ) // creuse du joueur3 et pleine du joueur4
				{
					if( gain[i][j] == 3 )
					{
						couleur(GRAS);
						couleur( codage(joueurs[2].couleur) );
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[3].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
					}
					else
					{
						if( gain[i][j] == 4 )
						{
							couleur( codage(joueurs[2].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[2].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[3].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				if( (T[i][j].creux == 4) && (T[i][j].plein == 3) ) // creuse du joueur4 et pleine du joueur 3
				{
					if( gain[i][j] == 4 )
					{
						couleur(GRAS);	
						couleur( codage(joueurs[3].couleur) );
						printf("  %c",CREUSE);
						couleur(DEFAULT);
						couleur( codage(joueurs[2].couleur) );
						printf(" %c  ",PLEINE);
						couleur(DEFAULT);
							
					}
					else
					{
						if( gain[i][j] == 3 )
						{
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur(GRAS);
							couleur( codage(joueurs[2].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
						else
						{
							couleur( codage(joueurs[3].couleur) );
							printf("  %c",CREUSE);
							couleur(DEFAULT);
							couleur( codage(joueurs[2].couleur) );
							printf(" %c  ",PLEINE);
							couleur(DEFAULT);
						}
					}
				}
				
			}
			couleur(GRAS);
			printf("|"); // séparateur de cases de la grille
			couleur(DEFAULT);
		}
		couleur(GRAS);
		printf("|"); // affiche la bordure droite de chaque ligne 
		couleur(DEFAULT);
		
		if(i<N-1) // tant qu'on a pas afficher le contenu de la dernière ligne, on affiche des séparateur de lignes.
		{	
			couleur(GRAS);
			printf("\n			||"); // bordure gauche.
			for(k=0;k<M;k++)
			{
				printf("-------|"); // séparateur de ligne.
			}
			printf("|\n"); // bordure driote.
			couleur(DEFAULT);
		}	
		
	}
	
	printf("\n");
	afficher_bordure_grille(M); // on affiche la bordure inférieure après avoir afficher la dernière ligne.
	
}




	
