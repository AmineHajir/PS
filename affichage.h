#define N 6
#define M 7
#define BLOCANTE 'X'
#define CREUSE    169
#define PLEINE    216
#define VIDE      ' '

typedef struct
{
	char bloc;
	char creux;
	char plein;
}pion;

void afficher_titre_jeu();
void initialiser_jeu(pion T[N][M]);
void afficher_jeu(pion T[N][M]);