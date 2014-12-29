
/**
 * \file 
 * \author Hajir Mohammed Amine
 * \date 25 Décembre 2014
 * \brief header d'affichage des couleurs et nettoyage d'ecran.
**/

#ifndef COULEURS
#define COULEURS

#include <stdio.h>

// efface l'ecran (clrscr = clearScrean)
#define clrscr() printf("\033[H\033[2J") 

// selectionne les couleur du texte est de 
#define couleur(param) printf("\033[%sm",param)

#endif



