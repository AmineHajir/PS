CC = gcc
OBJ = affichageJeu.o affichageMenus.o contenuCase.o placerPion.o main.o
OPT = -g -W -Wall

all: exe

exe : $(OBJ)
	$(CC) $(OBJ) -o exe

main.o : main.c affichageJeu.h affichageMenus.h contenuCase.h
	$(CC) -c main.c $(OPT)
	
affichageJeu.o : affichageJeu.c affichageJeu.h
	$(CC) -c affichageJeu.c $(OPT)
	
affichageMenus.o : affichageMenus.c affichageMenus.h	
	$(CC) -c affichageMenus.c $(OPT)

contenuCase.o : contenuCase.c contenuCase.h
	$(CC) -c contenuCase.c $(OPT)

placerPion.o : placerPion.c placerPion.h
	$(CC) -c placerPion.c $(OPT)



clean:
	rm -f *.o *~ exe
