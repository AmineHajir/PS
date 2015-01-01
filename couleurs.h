/**
 * \file 
 * \author Hajir Mohammed Amine
 * \date 25 Décembre 2014
 * \brief header de définition des couleurs et de l'arrière plan du texte + fonction d'affichage de couleur + fonction nettoyage d'ecran ...
**/

#ifndef COULEURS
#define COULEURS
#include <stdio.h>

// defintion des couleurs 
#define DEFAULT  "0" // system color (réinitialise le système de couleur).
#define NOIR    "30" 
#define ROUGE   "31" 
#define VERT    "32" 
#define JAUNE   "33" 
#define BLEU    "34" 
#define VIOLET  "35" 
#define CYAN    "36" 
#define WHITE   "37" 

//definition des couleurs en gras
#define NOIRGRAS    "30;1" 
#define ROUGEGRAS   "31;1" 
#define VERTGRAS    "32;1" 
#define JAUNEGRAS   "33;1" 
#define BLEUGRAS    "34;1" 
#define VIOLETGRAS  "35;1" 
#define CYANGRAS    "36;1" 
#define BLANCGRAS   "37;1" 

//definition de l'arrière plan (facultatif)
#define BLACK   "40" 
#define RED     "41" 
#define YELLOW  "42" 
#define GREEN   "43" 
#define BLUE    "44" 
#define PURPLE  "45" 
#define CYANE   "46" 
#define BLANC   "47" 

// autre deifnitions
#define BLINK  "5" // faire clignoter le texte.( ne fonctionne pas dans la console ubuntu!! faut-il modifier le bash!! )
#define GRAS   "1" // active la haute intensité des caractères.
#define INVERT "7" // inverse la sélection de couleurs.(facultatif)
#define STRESS "4" // souligne le texte.(facultatif)

// efface l'ecran (clrscr = clearScrean) ~ system("clear")
#define clrscr() printf("\033[H\033[2J") 

// selectionne les couleurs du texte et de l'arrière plan 
#define couleur(param) printf("\033[%sm",param)

#endif



