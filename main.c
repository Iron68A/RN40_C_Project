#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"

//main pour test
int main() {
    srand(time(NULL));
    int alea = rand()%10+1;
    Individu indiv = creerIndividuT(alea);
    afficherIndividu(indiv);
    int tab[alea];
    IndivToTab(indiv, tab);
    AfficherIndivMSB_Gauche(tab, alea);
    printf("decode : %d\n", decode(indiv));
    printf("Qualite : %f\n", calculQualiteIndividu(indiv));


    return 0;
}