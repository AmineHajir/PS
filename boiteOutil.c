#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "boiteOutil.h"

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
 * 	    elle permet aussi d'éliminer le retour à la ligne '\n' récupéré par fgets et de le remplacer par '\0', d'autre part.
 * 	    si '\n' n'a pas été trouvé dans la chaine, ceci voudra dire que le joueur a saisi plus de caractères qu'il n'est demandé
 * 	    la fonction retourne donc 0 pour indiquer que la saisie est incorrecte, elle retourne 1 sinon.
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


