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
Individu creerIndividuR(int longIndiv);
Individu creerIndividuT(int longIndiv);
void afficherIndividu(Individu indiv);
void IndivToTab(Individu indiv, int *tab);
void AfficherIndivMSB_Gauche(int *tab, int longIndiv);
int decode(Individu Indiv);
float calculQualiteIndividu(Individu indiv);
float puissance(float x, int n);
#endif // INDIVIDU_H

