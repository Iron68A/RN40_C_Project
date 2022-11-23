#ifndef INDIVIDU_H
#define INDIVIDU_H

typedef unsigned char Bit;

typedef struct Individu {
    Bit *bits;
    int longIndiv;
} Individu;

Individu *creerIndividu(int longIndiv);
void initIndividu(Individu *indiv);
void afficherIndividu(Individu *indiv);
void initIndividuRec(Individu *indiv, int i);

int decodeIndividu(Individu *indiv);
float calculQualiteIndividu(Individu *indiv, int x);
float puissance(float x, int n);
#endif // INDIVIDU_H

