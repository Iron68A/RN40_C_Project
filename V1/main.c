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
    Population pop = creerPopulation(4, NBINDIV);
    afficherPopulation(pop);
    //faire le quicksort de pop :
    
    Population L1, L2 = diviser(pop);
    printf("--------------L1  \n");
    afficherPopulation(L1);
    printf("----------------- L2 :\n");
    afficherPopulation(L2);
    printf("--------- \n");

    return 0;
}