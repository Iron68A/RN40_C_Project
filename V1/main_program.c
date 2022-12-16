#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"


#define MAX_SELECT 90
#define MIN_SELECT 10
#define MAX_GEN_POP 200
#define MIN_GEN_POP 20
#define PCROISE 0.5
#define LGINDIV 8

int main(){
    //Definition des paramètres de l'algo génétique aléatoire entre les bornes définies
    srand(time(NULL));
    int PSELECT = rand() % (MAX_SELECT - MIN_SELECT + 1) + MIN_SELECT;
    printf("select : %d \n", PSELECT);
    int TAILLEPOP = rand() % (MAX_GEN_POP - MIN_GEN_POP + 1) + MIN_GEN_POP;
    printf("taillePop : %d \n", TAILLEPOP);
    int NBGEN = rand() % (MAX_GEN_POP - MIN_GEN_POP + 1) + MIN_GEN_POP;
    printf("nb_gen : %d \n", NBGEN);
    
   
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
    meilleurIndividu(pop);                          //affichage du meilleur individu de la population
    return 0;
}