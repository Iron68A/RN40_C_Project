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


/**
 * Fichier main_program.c, contient le main du programme final
 * @author Alexandre BARTHELME
 * @date 16 12 2022
 * @brief exécution du programme selon les paramètres de l'algo génétique aléatoire entre les bornes définies
 * 
*/


int main(){
    //Definition des paramètres de l'algo génétique aléatoire entre les bornes définies
    srand(time(NULL));
    int PSELECT = rand() % (MAX_SELECT - MIN_SELECT + 1) + MIN_SELECT;
    int TAILLEPOP = rand() % (MAX_GEN_POP - MIN_GEN_POP + 1) + MIN_GEN_POP;
    int NBGEN = rand() % (MAX_GEN_POP - MIN_GEN_POP + 1) + MIN_GEN_POP;   
   
    Population pop = creerPopulation(TAILLEPOP, LGINDIV);       //initialisation de la population                                      
    for(int i=0; i<NBGEN; i++){                                 //boucle de génération
        printf("===================================Generation %d  : \n", i+1);

        pop = croisementPop(pop, PCROISE, TAILLEPOP);        //croisement de la population

        pop = quicksort(pop);                            //tri de la population 

        pop = meilleur(pop,PSELECT,TAILLEPOP);          //sélection des meilleurs individus
    }
    printf("*------------------*\n");
    //afficherPopulation(pop);
    printf("Meilleur individu GENERAL : \n");
    meilleurIndividu(pop);                        //affichage du meilleur individu de la dernière génération
    printf("Infos : \n");
    printf("PSELECT : %d , NBGEN : %d, TAILLEPOP : %d \n", PSELECT, NBGEN, TAILLEPOP);
    return 0;
}