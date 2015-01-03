#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menuDebut.h"
#include "boiteOutil.h"
#include "couleurs.h"
#include "affichageJeu.h"

/**
 * \file menuJeu.c
 * \author Hajir Mohammed Amine
 * \date 05 Janvier 2015
 * \brief ce fichier source contient la définition des fonctions d'affichage du menu principal et du menu du début du jeu.
 * \details la fonction d'affichage du menu du début permettra de faire saisir à chaque joueur son nom(ou pseudo) et sa couleur de préférence 
 * 	    de ses pions qui seront stockés dans le tableau des joueurs.
 * 	    la fonction d'affichage du menu principal permet de faire saisir le nombre de joueurs de la partie.
 * 
*/

int menuPrincipal()
{
	int nbJoueur; // le nombre de joueur de la partie du jeu
	int saisieCorrect; // pour controler a saisie
	int s; // pour récupérer la valeur retourné pas la focntion scanf
	
	clrscr();
	printf("\n");
	do
	{
		saisieCorrect=1;
		afficher_titre_jeu();
		printf("\n\n");
		couleur(GRAS);
		printf("\n                    ------------------ BIENVENUE SUR PUISSANCE4++ ------------------\n");
		printf("   Tapez 2 pour jouer en mode deux joueurs \n");
		printf("   Tapez 3 pour jouer en mode trois joueurs \n");
		printf("   Tapez 4 pour jouer en mode quatre joueurs \n");
		printf("   Votre choix : ");
		s=scanf("%i",&nbJoueur); // la fonction scanf retourne 1 si la saisie s'est bien passé, 0 sinon
		if( s==0 || (nbJoueur!=2 && nbJoueur!=3 && nbJoueur!=4) ) // si le joueur saisis un caractère (ou plusieurs) au lieu d'un entier 
		{
			saisieCorrect = 0; // on donne la valeur 9 à la variable colonne afin d'afficher un message d'erreur
		}
		viderBuffer(); // nécessaire pour éviter un bug (boucle infini d'affichage!!!) si le joueur saisis un caractère au lieu d'un entier
		clrscr();
		if( saisieCorrect == 0 ) // si saisie incorrecte --> message d'erreur
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge et en gras (ALERTE!!!)
			printf("\n    MESSAGE D'ERREUR: veuillez saisir une valeur correcte!! \n\n");
			couleur(DEFAULT); // pour remettre la couleur de base du terminal
		}
	}while( saisieCorrect == 0 ); // on boucle tant que le joueur n'a pas saisis une valeur correcte
	
	return nbJoueur;
}
	
/**
 * \fn void menuDebut(int numJoueur,joueur V[12])
 * \brief fonction qui affiche le menu pour un joueur afin de choisir la couleur des pions et un pseudo de jeu (ou son nom).
 * \brief elle permet de faire des controle de saisie si l'utilisateur choisis une couleur ou un pseudo déjà choisis par un autre joueur.
 * \brief des messages d'erreurs seront affichés dans de tels cas et dans le cas ou le joueur saisi plus que 10 caractères pour le nom.
 * \param numJoueur égale à 1 si on s'adresse au premier joueur, 2 si 2eme joueur .....
 * \param v tableau de structure (joueur) ou l'on stocke les informations (couleur,nom). sur les joueurs .
*/
void menuDebut(int numJoueur,joueur V[12])
{
	char coul; // on y stocke la couleur des pions choisie par le joueur
	char nom[12]; // on y stocke le nom ou pseudo choisi par le joueur
	int saisieCorrect; // variable entière qui est égale à 1 si la saisie est correcte 0 sinon
	int i; // pour parcourir le tableau des joueurs
	
	
	clrscr();
	
	printf("\n\n\n"); // pour centrer l'affichage dans le terminal
	do
	{
		couleur(GRAS); // titre du jeu en gras 
		printf("			 	       _      _  _  _  _  _  _       \n");
		printf("				      |_|| |||_ |_ |_|| ||  |_  |_|   \n");
		printf("				      |  |_|| _| _|| || ||_ |_    | ++\n\n");
		
		
		printf("\n                    ------------------ Choix du pseudo du joueur%i ------------------\n",numJoueur);
		printf("  joueur%i, saisissez votre nom ou choisissez un pseudo ",numJoueur);
		couleur(DEFAULT);
		saisieCorrect=lire(nom,12); // lire renvoi 1 si la saisie est correcte, 0 sinon. (pour détail voir fichier boiteOutil.c)
		clrscr();
		if(saisieCorrect==0) // si le joueur saisis un nom composé de plus de 10 caractères on affiche un message d'erreur
		{
			couleur(ROUGEGRAS);
			printf("\n  ATTENTION : joueur%i, votre nom ou pseudo est trop long, 10 caractères au maximum \n\n",numJoueur);
			couleur(DEFAULT);
		}
		else // si la saisie est correcte ...
		{
			for(i=0;i<numJoueur-1;i++) // on verifie dans le tableau des joueurs si le nom ou pseudo choisi existe déjà
			{
				if( strcmp(nom,V[i].nom) == 0 ) // si on trouve le nom dans l'une des cases du tableau ---> message d'erreur
				{
					couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
					printf("\n  ATTENTION: joueur%i, ce nom existe déjà, choisissez en un autre \n\n",numJoueur);
					saisieCorrect=0; // la saisie est incorrecte car ce pseudo est déjà choisis par un autre joueur
					couleur(DEFAULT);
					break;
				}
			}
		}
		if(saisieCorrect == 1)
		{
			strcpy(V[numJoueur-1].nom,nom); // on copie le nom saisie au clavier dans le tableau des joueurs
		}
	}while(saisieCorrect==0); // on boucle tant que la saisie ne s'est pas bien passé
	
	// de meme on affiche le menu du choix de la couleur des pions, on affiche un message d'erreur si saisie incorrect ou si couleur déja prise
	printf("\n\n\n");// pour centrer l'affichage dans la console
	do 
	{
		saisieCorrect=1;
		couleur(GRAS); // titre du jeu en gras 
		printf("			 	             _      _  _  _  _  _  _       \n");
		printf("				            |_|| |||_ |_ |_|| ||  |_  |_|   \n");
		printf("				            |  |_|| _| _|| || ||_ |_    | ++\n\n");
		
		printf("\n                    ----------------- %s choisissez la couleur de vos pions -----------------\n",V[numJoueur-1].nom);
		printf("  Tapez n pour jouer avec des pions noir \n");
		printf("  Tapez r pour jouer avec des");
		couleur(ROUGEGRAS); // on affiche le mot pion avec la couleur proposée 
		printf(" pions");   // si la couleur proposée est rouge le mot pion s'affichera en rouge
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" rouge\n");
		printf("  Tapez v pour jouer avec des");
		couleur(VERTGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" vert \n");
		printf("  Tapez j pour jouer avec des");
		couleur(JAUNEGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" jaune \n");
		printf("  Tapez b pour jouer avec des");
		couleur(BLEUGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" bleu \n");
		printf("  Tapez p pour jouer avec des");
		couleur(VIOLETGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" purple (violet) \n");
		printf("  Tapez c pour jouer avec des");
		couleur(CYANGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" cyan \n");
		printf("  Tapez w pour jouer avec des");
		couleur(BLANCGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" white (blanc) \n");
		printf("  Votre choix : ");
		coul=fgetc(stdin); // fgetc pour eviter un buffer overflow 
		viderBuffer(); // on vide le fichier standard si +sieurs caractère saisie au lieu d'un
		clrscr();
		
		for(i=0;i<numJoueur-1;i++) // on verifie dans le tableau des joueurs si la couleur choisie a deja été prise par un autre joueur
		{
			if(coul==V[i].couleur) // si on trouve la couleur dans l'une des cases du tableau ---> message d'erreur
			{
				couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
				printf("\n  ATTENTION: %s, cette couleur est déjà prise, choisissez en une autre \n\n",V[numJoueur-1].nom);
				saisieCorrect=0; // la saisie est incorrecte --> permet de boucler
				couleur(DEFAULT);
				break;
			}
		}
		
		// si le caractère saisi ne représente aucune couleur proposée ---> saisie incorrecte + message d'erreur
		if( coul!='n' && coul!='r' && coul!='v' && coul!='j' && coul!='b' && coul!='p' && coul!='c' && coul!='w' ) 
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
			printf("\n  MESSAGE D'ERREUR: %s, veuillez saisir une valeur correcte!! \n\n",V[numJoueur-1].nom);
			couleur(DEFAULT); // pour remettre la couleur de base du terminal
		}
		else
		{
			V[numJoueur-1].couleur=coul;
		}
	// le processus se répète tant que le joueur saisie une valeur incorrecte ou choisi une couleur deja utilisé	
	}while( (coul!='n' && coul!='r' && coul!='v' && coul!='j' && coul!='b' && coul!='p' && coul!='c' && coul!='w') || (saisieCorrect == 0) );
	
	
}