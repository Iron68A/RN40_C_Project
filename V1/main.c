#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
#define NBINDIV 6
//main pour test
int main() {
    //Individu indiv = creerIndividuT(NBINDIV);
    //afficherIndividu(indiv);
    //int tab[NBINDIV];
    //IndivToTab(indiv, tab);
    //AfficherIndivMSB_Gauche(tab, NBINDIV);
    //printf("decode : %d\n", decode(indiv));
    //printf("Qualite : %f\n", calculQualiteIndividu(indiv));
    Population pop = creerPopulation(5, NBINDIV);
    afficherPopulation(pop);
    //affqualite(pop);
    //faire le quicksort de pop :
    
    Population P1 = diviser(pop);
    printf("--------------P1  \n");
    //affqualite(P1);
    afficherPopulation(P1);


    return 0;
}