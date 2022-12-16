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

/**
 * Primitives des listes chainées
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

//Création d'une population aléatoire de taille taillePop avec des individus de longueur longIndiv
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

int estVidePop(Population pop){
    if(pop.premierPop == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/**
 * Fonctions d'affichage de la population
*/

//Affichage d'une population (Tous les individus, leur valeur décimale et leur qualité)
void afficherPopulation(Population pop){
    if(estVidePop(pop)){
        printf("La population est vide\n");
    }
    else{
        elementPop *actuel = pop.premierPop;
        int i=0;
        while(actuel != NULL){
            printf(" \n");
            printf("Individu %d :  \n", i);
            afficherIndividu(actuel->indiv);
            //printf("Sa valeur decimale est (MSB a droite) : %d ", decode(actuel->indiv));
            printf(" \n");
            actuel = actuel->suivant;
            i++;
        }
    }
}

//Affichage de la qualité de chaque individu de la population (Uniquement pour les tests et conforts de lecture)
void affqualite(Population pop){
    if(estVidePop(pop)){
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

//Affichage de l'individu de la population ayant la meilleure qualité
void meilleurIndividu(Population pop){
    if(estVidePop(pop)){
        printf("La population est vide\n");
    }
    else {
        pop = quicksort(pop);
        printf("Le meilleur individu est : \n");
        afficherIndividu(pop.premierPop->indiv);  
    }
}

/**
 * Fonctions de manipulation de la population
*/

/**
 * QUICKSORT : 
 * Fonction qui trie une population en fonction de la qualité de chaque individu, 
 * créant ainsi une population triée en divisant la population en deux sous-populations de manière récursive
 * Puis concaténantion les deux sous-populations triées
*/
Population quicksort(Population pop){
    if(estVidePop(pop)|| pop.premierPop->suivant == NULL){
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
        pop1 = quicksort(pop1);
        pop2 = quicksort(pop2);
        if(estVidePop(pop1)){
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

//Fonction qui creer une population constitué des "select" meilleurs individus de la population, 
//qui se repète jusqu'à atteindre la taille de la population

Population meilleur(Population pop, int select, int taillePop){
    Population pop1;
    pop1.premierPop = NULL;
    if(estVidePop(pop)){
        return pop1;
    }
    else{
        elementPop *actuel = pop.premierPop;
        int i=0;
        while(actuel != NULL && i<select){
            pop1 = AjoutqueuePop(pop1, actuel->indiv);
            actuel = actuel->suivant;
            i++;
        }
        actuel = pop1.premierPop;
        while(i<taillePop){
            pop1 = AjoutqueuePop(pop1, actuel->indiv);
            actuel = actuel->suivant;
            i++;
        }
        return pop1;
    }
}


//Fonction qui crée une population constitué d'individus de la premiere, croisés entre eux. (a partir d'une population triée)
Population croisementPop(Population pop,float pCroise, int taillePop){
    Population pop1;
    pop1.premierPop = NULL;
    if(estVidePop(pop)){
        printf("La population est vide\n");
    }
    else{
        int i=0;
        while(i<taillePop){
            int alea1 = rand()%taillePop;  
            int alea2 = rand()%taillePop;  
            while(alea1 == alea2){
                alea2 = rand()%taillePop;
            }
            elementPop *actuel1 = pop.premierPop;
            elementPop *actuel2 = pop.premierPop;
            int j=0;
            while(j<alea1 && actuel1->suivant != NULL){
                actuel1 = actuel1->suivant;
                j++;
            }
            j=0;
            while(j<alea2 && actuel2->suivant != NULL){
                actuel2 = actuel2->suivant;
                j++;
            }
            
            Individu indiv1 = croisementIndividu(actuel1->indiv, actuel2->indiv,pCroise);
            
            pop1 = AjoutTetePop(pop1, indiv1);
            i++;
        }
        return pop1;
    }
}



