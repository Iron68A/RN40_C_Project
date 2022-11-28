
main: main.o Individu.o Population.o
	g++ -o main.exe main.o Individu.o Population.o

main.o: main.c
	g++ -c main.c

Individu.o: Individu.c Individu.h
	g++ -c Individu.c Individu.h
Population.o: Population.c Population.h
	g++ -c Population.c Population.h