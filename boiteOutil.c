#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "boiteOutil.h"

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

int lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	
	fgets(chaine, longueur, stdin);
	
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
		{
			*positionEntree = '\0';
			return 1;
		}
		else
		{
			viderBuffer();
			return 0;
		}
}


