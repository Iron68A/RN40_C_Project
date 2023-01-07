#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"

/**
 * Fichier main_program.c, contient le main du programme final
 * @author Alexandre BARTHELME
 * @date 16 12 2022
 * @brief exécution du programme selon les paramètres de l'algo génétique aléatoire entre les bornes définies
 * 
*/


int main(){
    //Definition des paramètres de l'algo génétique aléatoire entre les bornes définies
    srand(time(NULL));
    //demande de saisie des paramètres de l'algo génétique
    int PSELECT, NBGEN, TAILLEPOP,LGINDIV;
    float PCROISE, A, B;
    printf("Saisir les parametres de l'algo genetique, TOUJOURS > 0 : \n");
    do{
        printf("PSELECT (generalement entre 10 et 90 pour entre 20 et 200 individus): ");
        scanf("%d", &PSELECT);
    } while(PSELECT <=0);
    
    do{
        printf("NBGEN (generalement entre 10 et 100 ): ");
        scanf("%d", &NBGEN);
    }while(NBGEN <=0);
    
    do{
        printf("TAILLEPOP (generalement entre 20 et 200 ): ");
        scanf("%d", &TAILLEPOP);
    } while(TAILLEPOP <=0);
    
    do{
        printf("PCROISE (generalement entre 0.5 et 1.0 ): ");
        scanf("%f", &PCROISE);
    } while(PCROISE <=0);
    
    do{
        printf("LGINDIV (generalement entre 8 et 16 ): ");
        scanf("%d", &LGINDIV);
    } while(LGINDIV <=0);
    

    Population pop = creerPopulation(TAILLEPOP, LGINDIV);       //initialisation de la population   
    printf("Population initiale =============== : \n");       
    afficherPopulation(quicksort(pop));                         
    for(int i=0; i<NBGEN; i++){                                 //boucle de génération
        printf("===================================Generation %d  : \n", i+1);

        pop = croisementPop(pop, PCROISE, TAILLEPOP);        //croisement de la population

        pop = quicksort(pop);                            //tri de la population 

        pop = meilleur(pop,PSELECT,TAILLEPOP);          //sélection des meilleurs individus
        meilleurIndividu(pop);                        
    }
 
    printf("*------------------*\n");
    //afficherPopulation(pop);
    printf("Meilleur individu GENERAL : \n");
    meilleurIndividu(pop);                        //affichage du meilleur individu de la dernière génération
    printf("Infos : \n");
    printf("PSELECT : %d , NBGEN : %d, TAILLEPOP : %d \n", PSELECT, NBGEN, TAILLEPOP);

    return 0;

}