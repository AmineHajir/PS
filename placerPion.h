
/**
 * \file placerPion.h
 * \author Hajir Mohammed Amine
 * \date 23 Décembre 2014
 * \brief ce fichier contient les en-tete des fonctions définies dans le fichier source placerPion.c
* */

booleen placerPleine(pion T[N][M], int V[M], int colonne, int player,char nom[11], int* ligne);
booleen placerCreuse(pion T[N][M], int V[M], int colonne, int player,char nom[11], int* ligne);
booleen placerBlocante(pion T[N][M], int V[M], int colonne, int player,char nom[11], int* ligne);