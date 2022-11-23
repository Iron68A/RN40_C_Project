#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"

//variables globales pour Qualité
#define A -1
#define B 1
#define longIndivQ 8



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

//afficher la liste des bits
void afficherIndividu(Individu *indiv) {
    int i;
    for (i = 0; i < indiv->longIndiv; i++) {
        printf("%d", indiv->bits[i]);
    }
    printf("\n ");
}

int decodeIndividu(Individu *indiv) {
    int i, val = 0;
    for (i = 0; i < indiv->longIndiv; i++) {
        val = val * 2 + indiv->bits[i];
    }
    return val;
}

float calculQualiteIndividu(Individu *indiv,int x) {
    float fct = (x/puissance(2,longIndivQ))*(B-A)+A;
    float Qualite = -(puissance(fct,2));
    return Qualite;
}

float puissance(float x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * puissance(x, n - 1);
    }
}


int main() {
    srand(time(NULL));
    Individu *indiv = creerIndividu(rand() % 10 + 1);
    initIndividu(indiv);
    afficherIndividu(indiv);
    printf("valeur = %d\n", decodeIndividu(indiv));
    return 0;
}

/*



*/