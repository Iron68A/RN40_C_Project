#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"

//main pour test
int main() {
    srand(time(NULL));
    Individu *indiv = creerIndividu(rand() % 10 + 1);
    initIndividu(indiv);
    afficherIndividu(indiv);
    printf("valeur = %d\n", decodeIndividu(indiv));
    return 0;
}