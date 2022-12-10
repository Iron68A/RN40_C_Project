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
 * @date 07 12 2022
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

void affqualite(Population pop){
    if(pop.premierPop == NULL){
        printf("La population est vide\n");
    }
    else{
        elementPop *actuel = pop.premierPop;
        int i=0;
        while(actuel != NULL){
            printf("Individu %d :  \n", i);
            printf("Sa qualite est : %f ", calculQualiteIndividu(actuel->indiv));
            printf("\n");
            actuel = actuel->suivant;
            i++;
        }
    }
}

Population diviser(Population pop){
    if(pop.premierPop == NULL || pop.premierPop->suivant == NULL){
        return pop;
    }
    else{
        elementPop *pivot = pop.premierPop;
        Population pop1, pop2;
        pop1.premierPop = NULL;
        pop2.premierPop = NULL;
        elementPop *actuel = pop.premierPop->suivant;
        while(actuel != NULL){
            if(actuel->indiv.qualite < pivot->indiv.qualite){
                pop1 = AjoutTetePop(pop1, actuel->indiv);
            }
            else{
                pop2 = AjoutTetePop(pop2, actuel->indiv);
            }
            actuel = actuel->suivant;
        }
        pop1 = diviser(pop1);
        pop2 = diviser(pop2);
        if(pop1.premierPop == NULL){
            pop1.premierPop = pivot;
        }
        else{
            elementPop *actuel = pop1.premierPop;
            while(actuel->suivant != NULL){
                actuel = actuel->suivant;
            }
            actuel->suivant = pivot;
        }
        pivot->suivant = pop2.premierPop;     
        return pop1;
    }
}


