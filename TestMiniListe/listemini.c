#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listemini.h"

liste ajoutTete(liste l, int val){
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->val = val;
    nouveau->suivant = l.premier;
    l.premier = nouveau;
    return l;
}

liste ajoutQueue(liste l, int val){
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->val = val;
    nouveau->suivant = NULL;
    if(l.premier == NULL){
        l.premier = nouveau;
    }
    else{
        element *actuel = l.premier;
        while(actuel->suivant != NULL){
            actuel = actuel->suivant;
        }
        actuel->suivant = nouveau;
    }
    return l;
}

liste creerListe(int taille){
    srand(time(NULL));
    liste l;
    l.premier = NULL;
    int i;
    for(i=0; i<taille; i++){
        l = ajoutTete(l, rand()%100);
    }
    return l;
}

void afficherListe(liste l){
    if(l.premier == NULL){
        printf("La liste est vide\n");
    }
    else{
        element *actuel = l.premier;
        int i=0;
        while(actuel != NULL){
            printf("Element %d : %d \n", i, actuel->val);
            actuel = actuel->suivant;
            i++;
        }
    }
}

void diviser(liste l){
    liste l1, l2;
    if(l.premier == NULL){
        printf("La liste est vide\n");
    }
    else{
        while(l.premier != NULL){
            int a = l.premier->val;
            int b = l.premier->suivant->val;
            //printf("a = %d et b = %d \n", a, b);
            if(a >= b){
                printf("a > b , a= %d b= %d\n", a, b);
            }
            else{
                printf("a < b , a= %d b= %d\n", a, b);
            }
            l.premier = l.premier->suivant;
        }
    }

}

int main(){
    liste l = creerListe(10);
    afficherListe(l);
    printf("---------------------\n");
    printf("Liste divisee : \n");
    diviser(l);
    printf("---------------------\n");
    return 0;

}