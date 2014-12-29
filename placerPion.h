
/**
 * \file placerPion.h
 * \author Hajir Mohammed Amine
 * \date 23 Décembre 2014
 * \brief ce fichier contient les en-tete des fonctions définies dans le fichier source placerPion.c
* */

void placerPleine(pion T[N][M], int V[M], int colonne, int joueur);
void placerCreuse(pion T[N][M], int V[M], int colonne, int joueur);
void placerBlocante(pion T[N][M], int V[M], int colonne, int joueur);