
/**
 * \file 
 * \brief ce fichier contient les en-tete des fonctions définies dans le fichier source affichageJeu.c
**/

/**
 * \enum booleen contenuCase.h
 * \brief le type booleen.
 */
typedef enum{FAUX,VRAI}booleen;

booleen caseVide(pion T[N][M], int colonne, int ligne);
booleen casePleine(pion T[N][M], int colonne, int ligne);
booleen caseBlocante(pion T[N][M], int colonne, int ligne);
booleen caseCreuse(pion T[N][M], int colonne, int ligne);
booleen casePleineCreuse(pion T[N][M], int colonne, int ligne);