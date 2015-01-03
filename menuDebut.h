
/**
 * \file menuDebut.h
 * \author Hajir Mohammed Amine
 * \date 31 Décembre 2014
 * \brief ce fichier contient les en-tete des fonctions définies dans le fichier source menuDebut.c
**/

/**
 * \struct joueur menuDebut.h
 * \brief définition du type joueur qui caractérise chaque joueur par son nom et sa couleur de pion 
 */
typedef struct
{
	char couleur; // variable qui stocke la couleur des pions choisis par le joueur
	char nom[12]; // tableau de caractère qui stocke le nom du joueur. (ce dernier ne peut dépasser 10 caractère)
}joueur;	      // on déclare un tableau de taille 12 car les deux dernieres case sont reservé au caractère '\n' et '\0'.

/**
 * \var joueurs[2]
 * \brief tableau contenant les informations sur les joueurs. 
 * \details la taille de ce tableau est égale au nombre de joueurs de la partie.
 * 	    ce tableau permet de stocker dans chacune de ses cases la couleur et le nom du joueur en question.
 */ 	    
joueur joueurs[4];


void menuDebut(int numJoueur,joueur V[12]);