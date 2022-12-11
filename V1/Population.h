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
Population AjoutqueuePop(Population pop, Individu indiv);
int estVidePop(Population pop);
void afficherPopulation(Population pop);
Population quicksort(Population population);
void affqualite(Population pop);
Population meilleur(Population popTriee, int select, int taillePop);





#endif // POPULATION_H