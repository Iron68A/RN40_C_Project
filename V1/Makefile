
main : main.c Individu.o Population.o
	gcc -o main main.c Individu.o Population.o -g

Individu.o : Individu.c Individu.h
	gcc -c Individu.c Individu.h   -g 

Population.o : Population.c Population.h 
	gcc -c Population.c Population.h -g
clean :
	rm -f *.o *.exe 
