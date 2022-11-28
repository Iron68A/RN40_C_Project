#ifndef POPULATION_H
#define POPULATION_H
#include "Individu.h"

typedef struct elementPop{
    Individu indiv;
    struct elementPop *suivant;
} elementPop;

typedef struct Population{
    elementPop *premierPop;
    int nbrIndiv;
} Population;

Population creerPopulation(int taillePop,int longIndiv);
Population AjoutTetePop(Population pop, Individu indiv);
void afficherPopulation(Population pop);






#endif // POPULATION_H