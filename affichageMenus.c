#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "affichageMenus.h"

/**
 * \file affichageMenus.c
 * \brief ce fichier source contient les définitions des fonctions d'affichage des menus du jeu.
 * 
*/

/**
 * \fn char menuJouerPion()
 * \brief fonction qui affiche le menu pour un joueur afin de choisir le pion à jouer. 
 * \brief cette fonction retourne le pion (caractère) choisis par le joueur.
 * \return le type de pion choisis par le joueur ('b' ou 'c' ou 'p')
*/
char menuChoixPion()
{
	char piece; // variable qui reçoit le choix du pion à jouer ('b' ou 'c' ou 'p')
	
	do
	{	
		afficher_jeu(grille);
		printf("\n\n                        ---------------------- Choix du pion ----------------------\n");
		printf(" Tapez b pour jouer la pièce bloquante \n");
		printf(" Tapez c pour jouer la pièce creuse \n");
		printf(" Tapez p pour jouer la pièce pleine \n");
		printf(" votre choix : ");
		scanf(" %c",&piece);
		system("clear");
		
		if( piece!='b' && piece!='c' && piece!='p' ) 
		{
			printf("\n MESSAGE D'ERREUR: saisie incorrecte!! \n");
		}
		
	}while( piece!='b' && piece!='c' && piece!='p'); // controle de la saisie du joueur
	system("clear");
	return piece;
}

/**
 * \fn int menuChoixPion()
 * \brief fonction qui affiche le menu pour un joueur afin de choisir la colonne ou il souhaite jouer le pion.
 * \brief cette fonction retourne le numéro de la colonne (entier compris entre 1 et 7) choisis par le joueur.
 * \return le numéro de la colonne choisis 
*/	
int menuChoixColonne()	
{
	
	int colonne; // variable qui reçoit le choix de la colonne (entier compris entre 1 et 7)
	
	do
	{	
		afficher_jeu(grille);
		printf("\n\n                        ------------------- Choix de la colonne -------------------\n");
		printf(" Tapez un chiffre entre 1 et 7 \n");
		printf(" votre choix : ");
		scanf(" %i",&colonne);
		system("clear");
		
		if( colonne<1 || colonne>7 ) 
		{
			printf("\n MESSAGE D'ERREUR: saisie incorrecte!! \n");
		}
		
	}while( colonne<1 || colonne>7 ); // controle de la saisie du joueur
	system("clear");
	return colonne;
}