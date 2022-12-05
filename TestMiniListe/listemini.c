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

//quick sort with linked list as input and 2 linked list as output (one for the smaller values and one for the bigger values)
void quickSort(liste *l, liste *l1, liste *l2){
    if(l->premier != NULL){
        element *pivot = l->premier;
        element *actuel = l->premier;
        while(actuel != NULL){
            if(actuel->val < pivot->val){
                *l1 = ajoutQueue(*l1, actuel->val);
            }
            else if(actuel->val > pivot->val){
                *l2 = ajoutQueue(*l2, actuel->val);
            }
            actuel = actuel->suivant;
            pivot = l->premier;
        }
    }
}

int main(){
    liste l = creerListe(10);
    afficherListe(l);
    liste l1;
    l1.premier = NULL;
    liste l2;
    l2.premier = NULL;
    quickSort(&l, &l1, &l2);
    printf("Liste 1 \n");
    afficherListe(l1);
    printf("-Liste2 \n");
    afficherListe(l2);
    return 0;
}






