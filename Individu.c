#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"

//variables globales pour Qualité
#define A -1
#define B 1
#define longIndivQ 8


//Création d'un individu
Individu *creerIndividu(int longIndiv) {
    Individu *indiv = (Individu *) malloc(sizeof(Individu));
    indiv->bits = (Bit *) malloc(longIndiv * sizeof(Bit));
    indiv->longIndiv = longIndiv;
    return indiv;
}

//initialiser aléatoirement la liste des bits
//itérativement
void initIndividu(Individu *indiv) {
    int i;
    for (i = 0; i < indiv->longIndiv; i++) {
        indiv->bits[i] = rand() % 2;
    }
}

//récursivement
void initIndividuRec(Individu *indiv, int i) {
    if (i < indiv->longIndiv) {
        indiv->bits[i] = rand() % 2;
        return initIndividuRec(indiv, i + 1);
    }
    else {
        return;
    }
}

//afficher la liste des bits ( Individu)
void afficherIndividu(Individu *indiv) {
    int i;
    for (i = 0; i < indiv->longIndiv; i++) {
        printf("%d", indiv->bits[i]);
    }
    printf("\n ");
}

//décoder la liste de bits associer à un individu
int decodeIndividu(Individu *indiv) {
    int i, val = 0;
    for (i = 0; i < indiv->longIndiv; i++) {
        val = val * 2 + indiv->bits[i];
    }
    return val;
}

//calculer la qualité d'un individu
float calculQualiteIndividu(Individu *indiv,int x) {
    float fct = (x/puissance(2,longIndivQ))*(B-A)+A;
    float Qualite = -(puissance(fct,2));
    return Qualite;
}

//fonction puissance nécessaire pour qualité
float puissance(float x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * puissance(x, n - 1);
    }
}


