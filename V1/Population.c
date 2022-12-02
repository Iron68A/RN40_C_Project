#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
#define TRUE 1
#define FALSE 0

/**
 * @brief Fichier population.c, contient les fonctions de manipulation et de création des populations
 * @file population.c
 * @author Alexandre BARTHELME 
 * @date 28 11 2022 
 * 
*/

Population AjoutTetePop(Population pop, Individu indiv){
    elementPop *nouveau = (elementPop *)malloc(sizeof(elementPop));
    nouveau->indiv = indiv;
    nouveau->suivant = pop.premierPop;
    pop.premierPop = nouveau;
    return pop;
}
Population AjoutqueuePop(Population pop, Individu indiv){
    elementPop *nouveau = (elementPop *)malloc(sizeof(elementPop));
    nouveau->indiv = indiv;
    nouveau->suivant = NULL;
    if(pop.premierPop == NULL){
        pop.premierPop = nouveau;
    }
    else{
        elementPop *actuel = pop.premierPop;
        while(actuel->suivant != NULL){
            actuel = actuel->suivant;
        }
        actuel->suivant = nouveau;
    }
    return pop;
}

Population creerPopulation(int taillePop, int longIndiv){
    Population pop;
    pop.premierPop = NULL;
    srand(time(NULL));
    int i;
    for(i=0; i<taillePop; i++){
        Individu indiv = creerIndividuT(longIndiv);
        pop = AjoutTetePop(pop, indiv);
    }
    return pop;
}

void afficherPopulation(Population pop){
    if(pop.premierPop == NULL){
        printf("La population est vide\n");
    }
    else{
        elementPop *actuel = pop.premierPop;
        int i=0;
        while(actuel != NULL){
            printf("Individu %d :  \n", i);
            afficherIndividu(actuel->indiv);
            printf("Sa valeur decimale est (MSB a droite) : %d ", decode(actuel->indiv));
            printf("\n");
            actuel = actuel->suivant;
            i++;
        }
    }
}

Population diviser(Population pop){
    Population pop1 = creerPopulation(0, 4);
    Population pop2 = creerPopulation(0, 4);
    elementPop *actuel = pop.premierPop;
    while(actuel !=NULL){
        if(actuel->indiv.qualite < pop.premierPop->suivant->indiv.qualite){
            pop1 = AjoutTetePop(pop1, actuel->indiv);
        }
        else{
            pop2 = AjoutTetePop(pop2, actuel->indiv);
        }
        actuel = pop.premierPop->suivant;
    }
    return pop1;
    return pop2;
}