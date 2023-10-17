#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include "nim.h"
#define PLATEAU_MAX_PIECES 35

int lire_entier(int min, int max){

    int i;

    printf("Saisir une valeur entière entre 1 et 4: ");
    scanf("%i", &i);
    while(i > 4 | i < 1){
        printf("Saisir une valeur entière entre 1 et 4: ");
        scanf("%i", &i);
    }
    return i;
}

void plateau_init(int plateau[], int nb_colonnes)
{
    int i;

    for (i = 0; i < nb_colonnes; i++)
    {
        plateau[i] = (random() / ((double) RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
    }
}

void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
    int i;
    for (i = col_a_supprimer; i < nb_colonnes; i++)
    {

}