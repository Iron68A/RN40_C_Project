#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"

//main pour test
int main() {
    Individu indiv = creerIndividu(8);
    initIndividu(indiv);
    afficherIndividu(indiv);
    printf("Qualité de l'individu : %f\n", calculQualiteIndividu(indiv, 2));
    return 0;
}