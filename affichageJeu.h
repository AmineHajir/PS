/**
 * \file affichageJeu.h
 * \author Hajir Mohammed Amine
 * \date 19 Décembre 2014
 * \brief ce fichier contient les en-tete des fonctions définies dans le fichier source affichageJeu.c
 * \details ce fichier contient aussi la déclaration, des variables globales et des structures de données utilisées (matrcie,typedef,tableau...)
 * */

/**
 * \def N nombre de lignes de la matrice qui modélise le jeu puissance 4++.
 * \brief représente le nombre de lignes de la grille du jeu puissance 4++.
 */
#define N 6

/**
 * \def M nombre de colonnes de la matrice qui modélise le jeu puissance 4++.
 * \brief représente le nombre de colonnes de la grille du jeu puissance 4++.
 */
#define M 7

/**
 * \def BLOCANTE 
 * \brief une pièce blocante du jeu est représentée par le caractère 'B'.
 * \details on peut aussi représenter ce pion par une croix X. 
 */
#define BLOCANTE 'B'

/**
 * \def CREUSE 
 * \brief une pièce creuse du jeu est représentée par le caractère 'C'.
 * \details on peut aussi représenter ce pion par le caractère dont le code ASCII est 169. (logo droit d'auteur)
 */
#define CREUSE   'C'

/**
 * \def PLEINE 
 * \brief une pièce pleine du jeu est représentée par le caractère 'P'. 
 * \details on peut aussi représenter ce pion par le caractère dont le code ASCII est 216(ou248). (logo ensemble vide, zéro barré)
 */
#define PLEINE   'P'

/**
 * \def VIDE 
 * \brief constante pour désigner qu'un champ d'une case de la matrice ne contient aucun pion. 
 */
#define VIDE      ' '

/**
 * \struct pion affichageJeu.h
 * \brief Définition de la structure pion contenant les différents types de pièces nécessaire pour jouer au puissance4++.
 */
typedef struct
{
	char bloc;  // champ de la structure qui représente une pièce bloquante
	char creux; // champ de la structure qui représente une pièce creuse
	char plein; // champ de la structure qui représente une pièce pleine
}pion;

/**
 * \var pion grille[N][M];
 * \brief structure de données utilisé pour le jeu puissance4++
 * \details matrice de type pion et de taille N*M (6*7=42 cases dans le cas de deux joueurs). 
 *          chaque case de la matrice peut contenir deux pièces(pions) au maximum. 
 *          une case peut contenir une pièce "bloquante" ou "pleine" ou "creuse" ou deus pièces "creuse/pleine" ou peut etre vide(espace). 
 * 	    on distingue donc 5 cas possibles pour une case de la matrice.	
*/
pion grille[N][M];

/**
 * \var hauteurColonne[M];
 * \brief structure de données utilisé pour mémoriser la hauteur (ou profondeur ou niveau) de chaque colonne de la grille du jeu.
 * \details la taille de ce tableau est égale au nombres de colonnes de la grille (constante M)
 * 	    ce tableau permet de stocker dans chacune de ses cases l'indice de la première case vide de la colonne correspondante 
 * 	    dans le cas ou la colonne est pleine, la valeur de la case correspondante à cette colonne dans le tableau est égale à 0. 
 * 	    au début du jeu toutes les cases du tableau sont initialisées à N-1(5) car l'indice de la premiere case vide de chaque colonne 
 *    	    est égale à l'indice de la dernière ligne de la grille.  
*/
int hauteurColonne[M];

void afficher_titre_jeu();
void initialiser_jeu(pion T[N][M]);
void initialiser_hauteurColonne(int V[M]);
void afficher_jeu(pion T[N][M]);
void afficher_numColonne_jeu(int nbre_colonne);
