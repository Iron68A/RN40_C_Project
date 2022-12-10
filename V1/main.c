#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
#define NBINDIV 6
#define PCROISE 0.5
//main pour test
int main() {
    srand(time(NULL));//srand à chaque itération pour avoir des bits différents
    /**
     * INDIVIDU
    */
    Individu indiv = creerIndividuT(NBINDIV);
    //Individu indiv2 = creerIndividuT(NBINDIV);
    afficherIndividu(indiv);
    //afficherIndividu(indiv2);
    //Individu indiv3 = croisement(indiv, indiv2, PCROISE);
    //printf("individu 3 (croise) : \n");
    //afficherIndividu(indiv3);
    //int tab[NBINDIV];
    //IndivToTab(indiv, tab);
    //AfficherIndivMSB_Gauche(tab, NBINDIV);
    //printf("decode : %d\n", decode(indiv));
    //printf("Qualite : %f\n", calculQualiteIndividu(indiv));

    /**
     * POPULATION
    */
    //Population pop = creerPopulation(5, NBINDIV);
    //afficherPopulation(pop);
    //affqualite(pop);
    //faire le quicksort de pop :
    
    //Population P1 = diviser(pop);
    printf("--P1 triee  \n");
    //affqualite(P1);
    //afficherPopulation(P1);


    return 0;
}