#ifndef listemini_h
#define listemini_h

typedef struct element {
    int val;
    struct element *suivant;
} element;

typedef struct liste {
    element *premier;
} liste;

liste ajoutTete(liste l, int val);
liste ajoutQueue(liste l, int val);
void afficherListe(liste l);
liste creerListe(int taille);
void diviser(liste l);


#endif /* listemini_h */