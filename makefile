CC = gcc
OBJ = affichage.o am.o
OPT = -g -W -Wall

all: exe

exe : $(OBJ)
	$(CC) $(OBJ) -o exe

am.o : am.c affichage.h 
	$(CC) -c am.c $(OPT)
	
affichage.o : affichage.c affichage.h
	$(CC) -c affichage.c $(OPT)
	
	
clean:
	rm -f *.o *~ exe
