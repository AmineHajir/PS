#include <stdlib.h>
#include <stdio.h>
#include "affichage.h"

/**
 * \file affichage.c
 * \brief ce fichier source contient les définitions des fonctions d'affichage du titre et de la grille du jeu.
 * \brief il contient également la fonction d'initialisation de la grille du jeu.
 * */


void afficher_titre_jeu()
{
	printf("\n");
	printf("                           68b                                                                       \n");
	printf("                           Y89                                                                       \n");
	printf("       __ ____   ___   ___ ___   ____     ____      ___    ___  __     ____     ____                 \n");
	printf("       `M6MMMMb  `MM    MM `MM  6MMMMb  6MMMMb    6MMMMb   `MM 6MMb   6MMMMb.  6MMMMb              M \n");
	printf("        MM'  `Mb  MM    MM  MM MM'    ` MM'    ` 8M'  `Mb   MMM9 `Mb 6M'   Mb 6M'  `Mb           ,dM \n");
	printf("        MM    MM  MM    MM  MM YM.      YM.          ,oMM   MM'   MM MM    `' MM    MM          ,dMM \n");
	printf("        MM    MM  MM    MM  MM  YMMMMb   YMMMMb  ,6MM9'MM   MM    MM MM       MMMMMMMM         ,d MM \n");
	printf("        MM    MM  MM    MM  MM      `Mb      `Mb MM'   MM   MM    MM MM       MM              ,d  MM       MM        MM\n");
	printf("        MM.  ,M9  YM.   MM  MM L    ,MM L    ,MM MM.  ,MM   MM    MM YM.   d9 YM    d9       ,d   MM       MM        MM\n");
	printf("        MMYMMM9    YMMM9MM__MM_MYMMMM9  MYMMMM9  `YMMM9'Yb._MM_  _MM_ YMMMM9   YMMMM9        MMMMMMMM   MMMMMMMM  MMMMMMMM\n");
	printf("        MM                                                                                        MM       MM        MM\n");
	printf("        MM                                                                                        MM       MM        MM\n");
	printf("       _MM_                                                                                       MM \n");
	printf("\n");
}

/**
 * \fn void initialiser_jeu(pion T[N][M])
 * \brief procédure qui initialise les cases de la grille à vide (des espaces).
 * \param T[N][M] matrcie de taille N(lignes)*M(colonnes) qui représente la grille du jeu.
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
 * \fn void afficher_numColonne_jeu(int nbre_colonne)
 * \brief procédure qui affiche les numéros des colonnes de la grille du jeu. 
 * \param nbre_colonne nombre de colonnes de la grille du jeu.
*/
void afficher_numColonne_jeu(int nbre_colonne)
{
	int i;
	
	for(i=0;i<nbre_colonne;i++)
	{
		if(i==0)
		{
			printf("     	             	     %i",i+1); // on affiche le numéro de la première colonne (1)
		}						       // on traite ce cas à part pour bien centrer l'affichage au dessus de la colonne
		else
		{
			printf("       %i",i+1);
		}
	}
}

/**
 * \fn void afficher_bordure_grille(int nbre_colonne)
 * \brief procédure qui affiche les bordures de la grille du jeu. 
 * \param nbre_colonne nombre de colonnes de la grille du jeu.
*/

void afficher_bordure_grille(int nbre_colonne)
{
	int i;
	
	printf("			||");
	for(i=0;i<nbre_colonne;i++)
	{
		printf("=======|");
	}
	printf("|\n");
}
	

/**
 * \fn void afficher_jeu(pion T[N][M])
 * \brief procédure qui affiche la grille du jeu. 
 * \param T[N][M] matrice de type pion de taille N*M à afficher.
*/
void afficher_jeu(pion T[N][M])
{
	int i,j,k;
	
	printf("			 	        _      _  _  _  _  _       \n");
	printf("				       |_|| |||_ |_ |_|| ||_  |_|   \n");
	printf("				       |  |_|| _| _|| || ||_    | ++\n\n");  
				          
						
	
	
	afficher_numColonne_jeu(M); // on commence par afficher les numéro des colonnes.
	
	printf("\n");
	
	afficher_bordure_grille(M); // on affiche ensuite la bordure supérieure de la grille.
	
	for(i=0;i<N;i++)
	{
		printf("			||"); // affiche la bordure gauche de chaque ligne.
		for(j=0;j<M;j++)
		{
			printf(" %c %c %c |",T[i][j].bloc,T[i][j].creux,T[i][j].plein); // affiche une ligne.
		}
		printf("|"); // affiche la bordure droite chaque ligne
		if(i<N-1) // tant qu'on a pas afficher la dernière ligne, on affiche des séparateur de lignes.
		{	
			printf("\n			||"); // bordure gauche.
			for(k=0;k<M;k++)
			{
				printf("-------|"); // séparateur de ligne.
			}
			printf("|\n"); // bordure driote.
		}
	}
	
	printf("\n");
	afficher_bordure_grille(M); // on affiche la bordure inférieure après avoir afficher la dernière ligne.
	
}


	
