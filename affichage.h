/**
 * \file affichage.h
 * \brief ce fichier contient les en-tete des fonctions définies dans le fichier source affichage.c
 * \brief ce fichier contient aussi la déclaration, des variables globales et des structures de données utilisées (matrcie,typedef)
 * */

/**
 * \def N nombre de lignes de la grille qui représente le jeu puissance 4++.
 * \brief représente le nombre de lignes de la grille qui représente le jeu puissance 4++.
 */
#define N 6

/**
 * \def M nombre de colonens de la grille qui représente le jeu puissance 4++.
 * \brief représente le nombre de colonnes de la grille qui représente le jeu puissance 4++.
 */
#define M 7

/**
 * \def BLOCANTE 
 * \brief une pièce blocante du jeu est représentée par le caractère 'X'.
 */
#define BLOCANTE 'X'

/**
 * \def CREUSE 
 * \brief une pièce creuse du jeu est représentée par le caractère ASCII dont le code décimal est 169.
 */
#define CREUSE    169

/**
 * \def PLEINE 
 * \brief une pièce pleine du jeu est représentée par le caractère ASCII dont le code décimal est 216.
 */
#define PLEINE    216

/**
 * \def VIDE 
 * \brief une case libre de la grille est représentée par la variable VIDE(espace).
 */
#define VIDE      ' '

/**
 * \struct pion affichage.h
 * \brief Définition du type pion contenant les différents types de pièces nécessaire pour jouer au puissance4++.
 */
typedef struct
{
	char bloc; // pièce bloquante
	char creux; // pièce creuse
	char plein; // pièce pleine
}pion;

/**
 * \var pion grille[N][M];
 * \brief structure de données utilisé pour le jeu puissance4++
 * \brief matrice de type pion et de taille N*M (6*7=42 cases dans le cas de deux joueurs). 
 * \brief chaque case de la matrice peut contenir deux pièces(pions) au maximum. 
 * \brief une case peut contenir une pièce "bloquante" ou "pleine" ou "creuse" ou deus pièces "creuse/pleine" ou peut etre vide(espace). 
*/
pion grille[N][M];

void afficher_titre_jeu();
void initialiser_jeu(pion T[N][M]);
void afficher_jeu(pion T[N][M]);
void afficher_numColonne_jeu(int nbre_colonne);