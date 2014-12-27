
typedef enum{FAUX,VRAI}booleen;

booleen caseVide(pion T[N][M], int colonne, int ligne);
booleen casePleine(pion T[N][M], int colonne, int ligne);
booleen caseBlocante(pion T[N][M], int colonne, int ligne);
booleen caseCreuse(pion T[N][M], int colonne, int ligne);
booleen casePleineCreuse(pion T[N][M], int colonne, int ligne);