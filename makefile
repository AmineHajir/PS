CC = gcc
OBJ = affichage.o main.o
OPT = -g -W -Wall

all: exe

exe : $(OBJ)
	$(CC) $(OBJ) -o exe

main.o : main.c affichage.h 
	$(CC) -c main.c $(OPT)
	
affichage.o : affichage.c affichage.h
	$(CC) -c affichage.c $(OPT)
	
	
clean:
	rm -f *.o *~ exe
