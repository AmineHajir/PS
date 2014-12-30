#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "affichageJeu.h"
#include "affichageMenus.h"
#include "couleurs.h"


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
 * \param nom le nom du joueur à afficher dans le message d'erreur en cas de mauvaise saisie
 * \return le type de pion choisis par le joueur ('b' ou 'c' ou 'p')
*/
char menuChoixPion(char nom[10])
{
	char piece; // variable qui reçoit le choix du pion à jouer ('b' ou 'c' ou 'p')
	int i;
	int lg=strlen(nom); // on récupère la longueur du nom du joueur dans la variable lg
	
	do
	{	
		afficher_jeu(grille);
		couleur(GRAS);
		printf("\n\n                        ");
		for(i=1;i<=(42-lg)/2;i++) // pour que le titre du menu ne dépasse pas la largeur de la grille
		{
			printf("-");
		}
		printf(" %s a vous de jouer ",nom); // on affiche le nom du joueur qui a le tour
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
		printf(" Tapez b pour jouer la piece bloquante \n");
		printf(" Tapez c pour jouer la piece creuse \n");
		printf(" Tapez p pour jouer la piece pleine \n");
		printf(" votre choix : ");
		couleur(DEFAULT);
		//scanf(" %c",&piece);
		piece=fgetc(stdin); // fgetc au lieu de scanf pour sécuriser la saisie et éviter un dépassement du tampon (buffer overflow)
		viderBuffer(); // vider le buffer (fichier standart stdin) si plusieurs caractères on été saisis
		//system("clear");
		clrscr(); // pour effacer le menu
		
		if( piece!='b' && piece!='c' && piece!='p' ) 
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
			printf("\n MESSAGE D'ERREUR: %s, veuillez saisir une valeur correcte!! \n\n",nom);
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
 * \brief cette fonction retourne le numéro de la colonne (entier compris entre 1 et M) choisis par le joueur.
 * \return le numéro de la colonne choisis 
*/	
int menuChoixColonne(char nom[10])	
{
	
	int colonne; // variable qui reçoit le choix de la colonne (entier compris entre 1 et 7)
	int i;
	int lg=strlen(nom);
	
	do
	{	
		afficher_jeu(grille);
		couleur(GRAS);
		printf("\n\n                        ");
		for(i=1;i<=(42-lg)/2;i++) // meme commentaire que pour le menu du choix du pion
		{
			printf("-");
		}
		printf(" %s a vous de jouer ",nom);
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
		printf(" Tapez un chiffre entre 1 et 7 pour choisir la colonne \n");
		printf(" votre choix : ");
		couleur(DEFAULT);
		scanf("%i",&colonne);
		viderBuffer(); // nécessaire pour éviter un bug (boucle infini d'affichage!!!) si le joueur saisis un caractère au lieu d'un entier
		//system("clear"); 
		clrscr(); // pour ne pas encombrer l'écran
		
		if( colonne<1 || colonne>7 ) 
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge et en gras (ALERTE!!!)
			printf("\n MESSAGE D'ERREUR: %s, veuillez saisir une valeur correcte!! \n\n",nom);
			couleur(DEFAULT); // pour remettre la couleur de base du terminal
		}
		
	}while( colonne<1 || colonne>7 ); // controle de la saisie du joueur
	//system("clear");
	clrscr(); // clearScreen
	
	return colonne;
}