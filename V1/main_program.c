#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"

#define LGINDIV 8
#define PCROISE 0.5
#define TAILLEPOP 20
#define SELECT 5
#define NBGEN 20

int main(){
    srand(time(NULL));
    Population pop = creerPopulation(TAILLEPOP, LGINDIV);               //initialisation de la population
    //afficherPopulation(pop);                        //affichage de la population
    //affqualite(pop);                                //affichage de la qualité de la population(utile pour les tests)
    int i;
    for(i=0; i<NBGEN; i++){                         //boucle de génération 
        pop = croisementPop(pop, PCROISE, LGINDIV);   //croisement de la population
        pop = quicksort(pop);                      //tri de la population
        printf("Generation %d  : \n", i+1);
        meilleurIndividu(pop);
        printf("- \n");
    }
    printf("*------------------*\n");
    printf("Meilleur individu GENERAL : \n");
    meilleurIndividu(pop);
    return 0;
}