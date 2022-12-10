
main : main.c Individu.o Population.o
	gcc -o main main.c Individu.o Population.o


Individu.o : Individu.c Individu.h
	gcc -c Individu.c Individu.h

Population.o : Population.c Population.h
	gcc -c Population.c Population.h
clean :
	rm -f *.o *.exe 