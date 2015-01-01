#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menuDebut.h"
#include "boiteOutil.h"
#include "couleurs.h"

void menuDebut(int numJoueur,joueur V[12])
{
	char coul;
	char nom[12];
	int saisieCorrect;
	int i;
	
	
	clrscr();
	printf("\n");
	do
	{
		couleur(GRAS); // titre du jeu en gras (c plus joli!!)
		printf("			 	       _      _  _  _  _  _  _       \n");
		printf("				      |_|| |||_ |_ |_|| ||  |_  |_|   \n");
		printf("				      |  |_|| _| _|| || ||_ |_    | ++\n\n");
		
		
		printf("\n                    ------------------- Choix du pseudo du joueur%i -------------------\n",numJoueur);
		printf(" joueur%i, saisissez votre nom ou choisissez un pseudo ",numJoueur);
		couleur(DEFAULT);
		saisieCorrect=lire(nom,12);
		clrscr();
		if(saisieCorrect==0)
		{
			couleur(ROUGEGRAS);
			printf("\n ATTENTION : joueur%i, votre nom ou pseudo est trop long, 10 caractères au maximum \n\n",numJoueur);
			couleur(DEFAULT);
		}
		else
		{
			strcpy(V[numJoueur-1].nom,nom);
		}
	}while(saisieCorrect==0);
	
	do
	{
		saisieCorrect=1;
		couleur(GRAS); // titre du jeu en gras (c plus joli!!)
		printf("\n			 	              _      _  _  _  _  _  _       \n");
		printf("				             |_|| |||_ |_ |_|| ||  |_  |_|   \n");
		printf("				             |  |_|| _| _|| || ||_ |_    | ++\n\n");
		
		printf("\n                    ------------------- %s choisissez la couleur de vos pions -------------------\n",V[numJoueur-1].nom);
		printf(" Tapez n pour jouer avec des pions noir \n");
		printf(" Tapez r pour jouer avec des");
		couleur(ROUGEGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" rouge\n");
		printf(" Tapez v pour jouer avec des");
		couleur(VERTGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" vert \n");
		printf(" Tapez j pour jouer avec des");
		couleur(JAUNEGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" jaune \n");
		printf(" Tapez b pour jouer avec des");
		couleur(BLEUGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" bleu \n");
		printf(" Tapez p pour jouer avec des");
		couleur(VIOLETGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" purple (violet) \n");
		printf(" Tapez c pour jouer avec des");
		couleur(CYANGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" cyan \n");
		printf(" Tapez w pour jouer avec des");
		couleur(BLANCGRAS);
		printf(" pions");
		couleur(DEFAULT);
		couleur(GRAS);
		printf(" white (blanc) \n");
		printf(" Votre choix : ");
		coul=fgetc(stdin);
		viderBuffer();
		clrscr();
		
		for(i=0;i<numJoueur-1;i++)
		{
			if(coul==V[i].couleur)
			{
				couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
				printf("\n ATTENTION: %s, cette couleur est déjà prise, choisissez en une autre \n\n",V[numJoueur-1].nom);
				saisieCorrect=0;
				couleur(DEFAULT);
				break;
			}
		}
				
		if( coul!='n' && coul!='r' && coul!='v' && coul!='j' && coul!='b' && coul!='p' && coul!='c' && coul!='w' ) 
		{
			couleur(ROUGEGRAS); // les message d'erreurs sont affichés en rouge en gras (ALERTE!!!)
			printf("\n MESSAGE D'ERREUR: %s, veuillez saisir une valeur correcte!! \n\n",V[numJoueur-1].nom);
			couleur(DEFAULT); // pour remettre la couleur de base du terminal
		}
		else
		{
			V[numJoueur-1].couleur=coul;
		}
	}while( (coul!='n' && coul!='r' && coul!='v' && coul!='j' && coul!='b' && coul!='p' && coul!='c' && coul!='w') || (saisieCorrect == 0) );
	
	
}