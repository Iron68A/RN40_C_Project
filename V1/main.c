#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
#define LGINDIV 6
#define PCROISE 0.5
//main pour test
int main() {
    srand(time(NULL));//srand à chaque itération pour avoir des bits différents
    /**
     * INDIVIDU
    */
    Individu indiv = creerIndividuT(LGINDIV);
    //Individu indiv2 = creerIndividuT(LGINDIV);
    afficherIndividu(indiv);
    //afficherIndividu(indiv2);
    //Individu indiv3 = croisement(indiv, indiv2, PCROISE);
    //printf("individu 3 (croise) : \n");
    //afficherIndividu(indiv3);
    int tab[LGINDIV];
    IndivToTab(indiv, tab);
    AfficherIndivMSB_Gauche(tab, LGINDIV);
    //printf("decode : %d\n", decode(indiv));
    //printf("Qualite : %f\n", calculQualiteIndividu(indiv));

    /**
     * POPULATION
    */
    //Population pop = creerPopulation(5, LGINDIV);
    //afficherPopulation(pop);
    //affqualite(pop);
    //faire le quicksort de pop :
    
    //Population P1 = quicksort(pop);
    //printf("--P1 triee  \n");
    //afficherPopulation(P1);
    //affqualite(P1);
    //printf("--Pop meilleur  \n");
    //Population popMeilleur = meilleur(P1,3, LGINDIV);
    //afficherPopulation(popMeilleur);

    return 0;
}