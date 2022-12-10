#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"

/**
 * @brief Fichier individu.c, contient les fonctions de manipulation et de création des individus
 * @file individu.c
 * @author Alexandre BARTHELME 
 * @date 28 11 2022 
 * 
*/

//variables globales pour Qualité
#define A -1
#define B 1
#define longIndivQ 8

//Creer les bits d'un individu
Individu AjoutTete(Individu indiv, Bit bit){
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->bits = bit;
    nouveau->suivant = indiv.premier;
    indiv.premier = nouveau;
    return indiv;
}

//creer un individu itérativement
Individu creerIndividuT(int longIndiv){
    Individu indiv;
    indiv.premier = NULL;
    int i;
    for(i=0; i<longIndiv; i++){
        int bit = rand()%2;
        indiv = AjoutTete(indiv, bit);
    }
    indiv.qualite = calculQualiteIndividu(indiv);
    return indiv;
}
//creer un individu récursivement
/*
Individu creerIndividuR(int longIndiv){
    Individu indiv;
    srand(time(NULL));
    indiv.premier = NULL;
    if(longIndiv>0){
        int bit = rand()%2;
        indiv = AjoutTete(indiv, bit);
        creerIndividuR(longIndiv - 1);
    }
    return indiv;
}*/

//Mettre un individu dans un tableau poour affichage avec MSB à gauche
void IndivToTab(Individu indiv, int *tab){
    if(indiv.premier == NULL){
        printf("L'individu est vide\n");
    }
    else{
        element *actuel = indiv.premier;
        int i=0;
        while(actuel != NULL){
            tab[i] = actuel->bits;
            actuel = actuel->suivant;
            i++;
        }
    } 
}

//afficher le tableau inverse
void AfficherIndivMSB_Gauche(int *tab, int longIndiv){
    int i;
    printf("L'individu est ( MSB a gauche, inverse de individu) : ");
    for(i=longIndiv-1; i>=0; i--){
        printf("%d", tab[i]);
    }
    printf("\n");
}


//afficher individu
void afficherIndividu(Individu indiv){
    if(indiv.premier == NULL){
        printf("L'individu est vide\n");
    }
    else{
        element *actuel = indiv.premier;
        printf("L'individu est : ");
        while(actuel != NULL){
            printf("%d", actuel->bits);
            actuel = actuel->suivant;
        }
        printf("\n");
        printf("sa qualite est : %f\n", indiv.qualite);
        printf("\n");
    }
}



//fonction de conversion d'un individu en entier
int decode(Individu indiv){
    int i,res = 0;
    element *actuel = indiv.premier;
    while(actuel != NULL){
        res += actuel->bits * puissance(2,i);
        actuel = actuel->suivant;
        i++;
    }
    return res;
}

//calculer la qualité d'un individu
float calculQualiteIndividu(Individu indiv) {
    int x = decode(indiv);
    float fct = (x/puissance(2,longIndivQ))*(B-A)+A;
    float res = fct * fct;
    return -res;
}

//fonction puissance nécessaire pour qualité
float puissance(float x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * puissance(x, n - 1);
    }
}

//intervertir les elements de deux individus selon une probabilité p pour chaque bit (tirage aléatoire avec comparaison à p)
Individu croisement(Individu indiv1, Individu indiv2, float pCroise){
    Individu indiv3;
    indiv3.premier = NULL;
    element *actuel1 = indiv1.premier;
    element *actuel2 = indiv2.premier;
    while(actuel1 != NULL && actuel2 != NULL){
        srand(time(NULL));
        //chiffre aleatoire entre 0 et 1 ( proba de croisement )
        float proba= rand()%2;
        if(proba < pCroise){
            indiv3 = AjoutTete(indiv3, actuel1->bits);
        }
        else{
            indiv3 = AjoutTete(indiv3, actuel2->bits);
        }
        actuel1 = actuel1->suivant;
        actuel2 = actuel2->suivant;
    }
    indiv3.qualite = calculQualiteIndividu(indiv3);
    return indiv3;
    

}

