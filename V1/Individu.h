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
    float qualite;
} Individu;

//Primitives des listes chainées
Individu AjoutTete(Individu indiv, Bit bit);
Individu creerIndividuR(int longIndiv);
Individu creerIndividuT(int longIndiv);
int estVide(Individu indiv);
//Fonctions d'affichage (pour le débugage et la vérification)
void afficherIndividu(Individu indiv);
void IndivToTab(Individu indiv, int *tab);
void AfficherIndivMSB_Gauche(int *tab, int longIndiv);
//fonctions de manipulation
int decode(Individu Indiv);
float calculQualiteIndividu(Individu indiv);
float puissance(float x, int n);
Individu croisement(Individu indiv1, Individu indiv2, float pcroise);
#endif // INDIVIDU_H

