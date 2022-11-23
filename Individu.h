#ifndef INDIVIDU_H
#define INDIVIDU_H

typedef unsigned char Bit;


typedef struct element {
    Bit bits;
    struct element *suivant;
} element;

typedef struct Individu {
    element *premier;
    int longIndiv;
} Individu;


Individu AjoutTete(Individu indiv, Bit bit);
Individu creerIndividu(int longIndiv);
void initIndividu(Individu indiv, int longIndiv);
void afficherIndividu(Individu indiv);


float calculQualiteIndividu(Individu indiv, int x);
float puissance(float x, int n);
#endif // INDIVIDU_H

