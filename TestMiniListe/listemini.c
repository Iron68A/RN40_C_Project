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

//trier la liste chainée en utilisant la méthode de tri quicksort (diviser pour régner)
liste trie(liste l){
    if(l.premier == NULL || l.premier->suivant == NULL){
        return l;
    }
    else{
        element *pivot = l.premier;
        liste l1, l2;
        l1.premier = NULL;
        l2.premier = NULL;
        element *actuel = l.premier->suivant;
        while(actuel != NULL){
            if(actuel->val < pivot->val){
                l1 = ajoutTete(l1, actuel->val);
            }
            else{
                l2 = ajoutTete(l2, actuel->val);
            }
            actuel = actuel->suivant;
        }
        l1 = trie(l1);
        l2 = trie(l2);
        if(l1.premier == NULL){
            l1.premier = pivot;
            pivot->suivant = l2.premier;
            return l1;
        }
        else{
            element *actuel = l1.premier;
            while(actuel->suivant != NULL){
                actuel = actuel->suivant;
            }
            actuel->suivant = pivot;
            pivot->suivant = l2.premier;
            return l1;
        }
    }
}



int main(){
    liste l = creerListe(10);
    afficherListe(l);
    printf("---------------- \n");
    liste l1 = trie(l);
    afficherListe(l1);
    return 0;

}






