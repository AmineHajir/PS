#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "boiteOutil.h"
#include "couleurs.h"

/**
 * \file boiteOutil.c
 * \author Hajir Mohammed Amine
 * \date 31 Décembre 2014
 * \brief ce fichier source contient les définitions de quelques fonctions dont on aura besoin dans un ou plusieurs autre fichiers sources du projet.
 */

/**
 * \fn void viderBuffer()
 * \brief fonction qui vide le buffer (stdin) grace à la fonction getchar() si le joueur saisis plus de caractères qu'il n'est demandé.
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
 * \fn int lire(char *chaine, int longueur)
 * \brief on définit notre propre fonction de saisie qu'on appele lire pour éviter les problèmes de saisie causé par scanf. 
 * \details cette fonction permet la saisie sécurisée pour le joueur en évitant un dépassement du tampon grace à fgets d'une part.
 * 	    elle permet aussi d'éliminer le retour à la ligne récupéré par fgets et de le remplacer par '\0', d'autre part.
 * 	    si le caract de retour n'a pas été trouvé dans la chaine, ceci voudra dire que le joueur a saisi plus de caractères 
 *          qu'il n'est demandé la fonction retourne donc 0 pour indiquer que la saisie est incorrecte, elle retourne 1 sinon.
 * \param *chaine  un pointeur vers un tableau alloué en mémoire où la fonction va pouvoir écrire le texte entré par l'utilisateur.
 * \param longueur la taille du tableau envoyé en premier paramètre.
 * \return 1 si tout s'est bien passé, 0 sinon.
*/
int lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	
	fgets(chaine, longueur, stdin); //on lit le texte saisis au clavier
	
		positionEntree = strchr(chaine, '\n'); //on recherche l'entrée \n
		if (positionEntree != NULL) // si on trouve le retour à la ligne
		{
			*positionEntree = '\0'; // on remplace ce caractère par \0
			return 1; // si on trouve le \n, ceci veut dire qu'il n'y a pas eu d'erreur de saisie
		}		  // l'utilisateur n'a pas saisi plus de caractères qu'il n'était autorisé. on retourne donc 1 (saisie correcte)	
		else
		{
			viderBuffer(); // si l'utilisateur saisie plus de cacrtère qu'il n'était autorisé, on vide le buffer
			return 0;      // et on retourne 0 pour indiquer qu'il y a eu une erreur de saisie
		}
}

/**
 * \fn char* codage(char x)
 * \brief fonction qui prend en paramètre le caractère qui représente une couleur et renvoi la chaine de caractère (séquence d'échappement)
 * \brief de cette couleur. 
 * \details quand le joueur choisis la couleur de ses pions, il saisit un seul caractère représentant cette couleur,
 *	    (par exemple, il saisit n pour la couleur noir) ce caractère est stockés dans le tableau joueurs.
 *	    cette fonction permet donc de convertir le caractère saisis en une chaine de caractère (par exemple n est converti en NOIR)
 * 	    NOIR n'est pas la chaine "NOIR" c'est une variable qui représente la séquence d'échappement de la couleur noir.
 *	    cette fonction est appelé par la fonction afficherJeu qui se situe dans le fichier source affichagejeu.c. 
 * \param x le caractère qui représente une couleur saisis par le joueur.
 * \return une chaine de caractère qui permet d'afficher un texte en une couleur donnée.
*/
char* codage(char x)
{ 
	switch(x)
	{
		case 'n' : return NOIR;   break;
		case 'r' : return ROUGE;  break;
		case 'v' : return VERT;   break;
		case 'j' : return JAUNE;  break;
		case 'b' : return BLEU;   break;
		case 'p' : return VIOLET; break;
		case 'c' : return CYAN;   break;
		case 'w' : return WHITE;  break;
		default  : return DEFAULT;
	}
}

/**
 * \fn char* convert(char x)
 * \brief fonction qui prend en paramètre le caractère qui représente une couleur et renvoi le non de cette couleur. 
 * \brief cette fonction est très semblable à celle du dessus.
 * \details meme détail qu ci dessus à la différence que cette fonction renvoi le nom de la couleur en question et non pas son code ASCII.
 * \param x le caractère qui représente une couleur saisis par le joueur.
 * \return pointeur sur un tableau contenant le nom de la couleur en question.
*/
char* convert(char x)
{
	switch(x)
	{
		case 'n' : return "noir";   break;
		case 'r' : return "rouge";  break;
		case 'v' : return "vert";   break;
		case 'j' : return "jaune";  break;
		case 'b' : return "bleu";   break;
		case 'p' : return "violet"; break;
		case 'c' : return "cyan";   break;
		case 'w' : return "blanc";  break; 
		default  : return "system"; 
	}
}
