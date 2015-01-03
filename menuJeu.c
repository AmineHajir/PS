#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "affichageJeu.h"
#include "menuJeu.h"
#include "couleurs.h"
#include "boiteOutil.h"

/**
 * \file menuJeu.c
 * \author Hajir Mohammed Amine
 * \date 20 Décembre 2014
 * \brief ce fichier source contient les définitions des fonctions d'affichage des menus du jeu.
 * 
*/

/**
 * \fn char menuJouerPion(char nom[12])
 * \brief fonction qui affiche le menu pour un joueur afin de choisir le pion à jouer. 
 * \brief cette fonction retourne le pion (caractère) choisis par le joueur.
 * \param nom le nom du joueur à afficher dans le message d'erreur en cas de mauvaise saisie
 * \return le type de pion choisis par le joueur ('b' ou 'c' ou 'p')
*/
char menuChoixPion(char nom[12])
{
	char piece; // variable qui reçoit le choix du pion à jouer ('b' ou 'c' ou 'p')
	int i;
	int lg=strlen(nom); // on récupère la longueur du nom du joueur dans la variable lg
	
	printf("\n\n");
	do
	{	
		afficher_jeu(grille);
		couleur(GRAS);
		printf("\n\n                        ");
		for(i=1;i<=(42-lg)/2;i++) // pour que le titre du menu ne dépasse pas la largeur de la grille
		{
			printf("-");
		}
		printf(" %s à vous de jouer ",nom); // on affiche le nom du joueur qui a le tour
		if(lg%2!=0)
		{
			for(i=1;i<=(42-lg)/2;i++)
			{
				printf("-");
			}
		}
		else
		{
			if(lg%2==0)
			{
				for(i=1;i<=(41-lg)/2;i++) // de meme, on boucle pour afficher des "-" sans dépasser la largeur de la grille
				{
					printf("-");
				}
			}
		}
		printf("\n");
		printf("  Tapez b pour jouer la piece bloquante \n");
		printf("  Tapez c pour jouer la piece creuse \n");
		printf("  Tapez p pour jouer la piece pleine \n");
		printf("  votre choix : ");
		couleur(DEFAULT);
		//scanf(" %c",&piece);
		piece=fgetc(stdin); // fgetc au lieu de scanf pour sécuriser la saisie et éviter un dépassement du tampon (buffer overflow)
		viderBuffer(); // vider le buffer (fichier standart stdin) si plusieurs caractères on été saisis
		//system("clear");
		clrscr(); // pour effacer le menu
		
		if( piece!='b' && piece!='c' && piece!='p' ) 
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
			printf("\n  MESSAGE D'ERREUR: %s, veuillez saisir une valeur correcte!! \n\n",nom);
			couleur(DEFAULT); // pour remettre la couleur de base du terminal
		}
		
	}while( piece!='b' && piece!='c' && piece!='p'); // controle de la saisie du joueur
	//system("clear"); 
	clrscr(); // effacer l'ecran
	return piece;
}

/**
 * \fn int menuChoixPion()
 * \brief fonction qui affiche le menu pour un joueur afin de choisir la colonne ou il souhaite jouer le pion.
 * \details cette fonction retourne le numéro de la colonne (entier compris entre 1 et M) choisis par le joueur.
 * 	    retourne 0 si le joueur choisis de revenir au menu précédant pour changer de pion.
 *\param nom le nom du joueur pour l'afficher dans le menu ou dans les messages d'erreurs.	
 * \return le numéro de la colonne choisis (0 pour changer de pion / entre 1 et 7 pour placer le pion dans une colonne).
*/	
int menuChoixColonne(char nom[12])	
{
	
	int colonne; // variable qui reçoit le choix de la colonne (entier compris entre 1 et 7)
	int i;
	int lg=strlen(nom);
	int s; // pour récupérer la valeur retourner par scanf (ça va servir à controler la saisie)
	
	printf("\n\n");
	do
	{	
		afficher_jeu(grille);
		couleur(GRAS);
		printf("\n\n                        ");
		for(i=1;i<=(42-lg)/2;i++) // meme commentaire que pour le menu du choix du pion
		{
			printf("-");
		}
		printf(" %s à vous de jouer ",nom);
		if(lg%2!=0)
		{
			for(i=1;i<=(42-lg)/2;i++)
			{
				printf("-");
			}
		}
		else
		{
			if(lg%2==0)
			{
				for(i=1;i<=(41-lg)/2;i++)
				{
					printf("-");
				}
			}
		}
		printf("\n");
		//printf("\n\n                        ------------------- %s a vous de jouer -------------------\n",nom);
		printf("  Tapez un chiffre entre 1 et 7 pour choisir la colonne \n");
		printf("  Tapez 8 si vous avez oublié la couleur de vos pions \n");
		printf("  Tapez 0 pour changer de pion \n");
		printf("  votre choix : ");
		couleur(DEFAULT);
		s=scanf("%i",&colonne); // la fonction scanf retourne 1 si la saisie s'est bien passé, 0 sinon
       		if(s==0) // si le joueur saisis un caractère (ou plusieurs) au lieu d'un entier 
		{
			colonne = 9; // on donne la valeur 9 à la variable colonne afin d'afficher un message d'erreur
		}
		//colonne=fgetc(stdin);
		viderBuffer(); // nécessaire pour éviter un bug (boucle infini d'affichage!!!) si le joueur saisis un caractère au lieu d'un entier
		clrscr(); // pour ne pas encombrer l'écran
		
		if( colonne<0 || colonne>8 ) // si le choix de la colonne dépasse la taille de la matrice ==> message d'erreur
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge et en gras (ALERTE!!!)
			printf("\n  MESSAGE D'ERREUR: %s, veuillez saisir une valeur correcte!! \n\n",nom);
			couleur(DEFAULT); // pour remettre la couleur de base du terminal
		}
		
	}while( colonne<0 || colonne>8 ); // controle de la saisie du joueur
	clrscr(); // clearScreen
	
	return colonne;
}