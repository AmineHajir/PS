#include <stdlib.h>
#include <stdio.h>
#include "affichageJeu.h"
#include "affichageMenus.h"

/**
 * \file affichageMenus.c
 * \author Hajir Mohammed Amine
 * \date 20 Décembre 2014
 * \brief ce fichier source contient les définitions des fonctions d'affichage des menus du jeu.
 * 
*/

/**
 * \fn void viderBuffer()
 * \brief fonction qui vide le buffer (stdin) grace à la fonction getchar() si le joueur saisis plus qu'un seul caractère.
*/
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF) // tant que le buffer n'est pas vide on boucle 
    {
        c = getchar(); // fonction qui permet de lire dans le buffer caractère par caractère
    }
}

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
		printf(" Tapez b pour jouer la piece bloquante \n");
		printf(" Tapez c pour jouer la piece creuse \n");
		printf(" Tapez p pour jouer la piece pleine \n");
		printf(" votre choix : ");
		//scanf(" %c",&piece);
		piece=fgetc(stdin); // fgetc au lieu de scanf pour sécuriser la saisie et éviter un dépassement du tampon (buffer overflow)
		viderBuffer(); // vider le buffer (fichier standart stdin) si plusieurs caractères on été saisis
		system("clear");
		
		if( piece!='b' && piece!='c' && piece!='p' ) 
		{
			printf("\n MESSAGE D'ERREUR: saisie incorrecte!! \n");
		}
		
	}while( piece!='b' && piece!='c' && piece!='p'); // controle de la saisie du joueur
	system("clear"); // effacer l'ecran
	return piece;
}

/**
 * \fn int menuChoixPion()
 * \brief fonction qui affiche le menu pour un joueur afin de choisir la colonne ou il souhaite jouer le pion.
 * \brief cette fonction retourne le numéro de la colonne (entier compris entre 1 et M) choisis par le joueur.
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
		scanf("%i",&colonne);
		viderBuffer(); // nécessaire pour éviter un bug si le joueur saisis un caractère au lieu d'un entier
		system("clear"); // pour ne pas encombrer l'écran
		
		if( colonne<1 || colonne>7 ) 
		{
			printf("\n MESSAGE D'ERREUR: saisie incorrecte!! \n");
		}
		
	}while( colonne<1 || colonne>7 ); // controle de la saisie du joueur
	system("clear");
	return colonne;
}