#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Individu.h"

/**
 * @brief Fichier individu.c, contient les fonctions de manipulation et de création des individus
 * @file individu.c
 * @author Alexandre BARTHELME 
 * @date 28 11 2022 
 * 
*/

//variables globales pour Qualité
#define A 0.1
#define B 5
#define LONGINDIVQ 16
#define TRUE 1
#define FALSE 0
/**
 * Primitives des listes chainées
*/
//Creer les bits d'un individu (un maillon de la chaine)
Individu AjoutTete(Individu indiv, Bit bit){
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->bits = bit;
    nouveau->suivant = indiv.premier;
    indiv.premier = nouveau;
    return indiv;
}
Individu AjoutEnQueue(Individu indiv, Bit bit){
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->bits = bit;
    nouveau->suivant = NULL;
    if(indiv.premier == NULL){
        indiv.premier = nouveau;
    }
    else{
        element *actuel = indiv.premier;
        while(actuel->suivant != NULL){
            actuel = actuel->suivant;
        }
        actuel->suivant = nouveau;
    }
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

int estVide(Individu indiv){
    if(indiv.premier == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

//Permet de s'assurer que les individus sont bien différents (pour le croisement & debugage)
int estIdentique(Individu indiv1, Individu indiv2){
    if(estVide(indiv1) || estVide(indiv2)){
        printf("L'un des individus est vide\n");
    }
    else{
        element *actuel1 = indiv1.premier;
        element *actuel2 = indiv2.premier;
        while(actuel1 != NULL && actuel2 != NULL){
            if(actuel1->bits != actuel2->bits){
                return FALSE;
            }
            actuel1 = actuel1->suivant;
            actuel2 = actuel2->suivant;
        }
        if(actuel1 == NULL && actuel2 == NULL){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}



/**
 * Fonctions d'affichage (pour le débugage et la vérification)
 * Non utilisées dans le programme principal, ni détaillées dans le rapport
*/



/*
//Mettre un individu dans un tableau poour affichage avec MSB à gauche
void IndivToTab(Individu indiv, int *tab){
    if(estVide(indiv)){
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
}*/


//afficher chaque bit d'un individu, sa qualité et sa valeur décodée
void afficherIndividu(Individu indiv){
    if(estVide(indiv)){
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
        printf("sa valeur decodee est : %d\n", decode(indiv));
    }
}



/**
 * Fonctions de manipulation des individus
*/

//fonction de conversion d'un individu en entier (sa valeur )
int decode(Individu indiv){
    int i = 0,res = 0;
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
    float fct = (x/puissance(2,LONGINDIVQ))*(B-A)+A;
    float res = log(fct);
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
Individu croisementIndividu(Individu indiv1, Individu indiv2, float pCroise){
    if(estVide(indiv1) || estVide(indiv2)){
        printf("L'un des individus est vide\n");
    }
    Individu indiv3;
    indiv3.premier = NULL;
    element *actuel1 = indiv1.premier;
    element *actuel2 = indiv2.premier;
    /*if(estIdentique(indiv1, indiv2)){
        //printf("Les individus sont identiques dans indiv\n");
        return indiv1;
    }*/
    while(actuel1 != NULL && actuel2 != NULL){
        //chiffre aleatoire entre 0 et 1 ( proba de croisement )
        float proba = (float)rand()/(float)(RAND_MAX);
        if(proba < pCroise){
            indiv3 = AjoutEnQueue(indiv3, actuel1->bits);
        }
        else{
            indiv3 = AjoutEnQueue(indiv3, actuel2->bits);
        }
        actuel1 = actuel1->suivant;
        actuel2 = actuel2->suivant;
    }
    indiv3.qualite = calculQualiteIndividu(indiv3);
    return indiv3;
    

}
