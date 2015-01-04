CC = gcc
OBJ = affichageJeu.o menuJeu.o contenuCase.o placerPion.o boiteOutil.o menuDebut.o faireJouer.o victoire.o main.o
OPT = -g -W -Wall

all: exe

exe : $(OBJ)
	$(CC) $(OBJ) -o exe

main.o : main.c faireJouer.h affichageJeu.h menuJeu.h contenuCase.h boiteOutil.h menuDebut.h placerPion.h
	$(CC) -c main.c $(OPT)

faireJouer.o : faireJouer.c faireJouer.h affichageJeu.h menuJeu.h contenuCase.h boiteOutil.h menuDebut.h placerPion.h
	$(CC) -c faireJouer.c $(OPT)
	
affichageJeu.o : affichageJeu.c affichageJeu.h contenuCase.h
	$(CC) -c affichageJeu.c $(OPT)
	
menuJeu.o : menuJeu.c menuJeu.h boiteOutil.h
	$(CC) -c menuJeu.c $(OPT)

contenuCase.o : contenuCase.c contenuCase.h boiteOutil.h
	$(CC) -c contenuCase.c $(OPT)

placerPion.o : placerPion.c placerPion.h 
	$(CC) -c placerPion.c $(OPT)

boiteOutil.o : boiteOutil.c boiteOutil.h
	$(CC) -c boiteOutil.c $(OPT)
	
menuDebut.o : menuDebut.c menuDebut.h boiteOutil.h
	$(CC) -c menuDebut.c $(OPT)
	
victoire.o : victoire.c victoire.h 
	$(CC) -c victoire.c $(OPT)


clean:
	rm -f *.o *~ tst exe
