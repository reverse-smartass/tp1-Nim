#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include "nim.h"

#define PLATEAU_MAX_PIECES 35
#define PLATEAU_MIN_COLONNES 2
#define PLATEAU_MAX_COLONNES 20	
#define TRUE   1
#define FALSE  0


void plateau_init(int plateau[], int nb_colonnes)
{
    int i;

    for (i = 0; i < nb_colonnes; i++)
    {
        plateau[i] = (random() / ((double) RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);           //Ask the question of if we could leave it that way
    }
}

void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
    int i;

    for (i = col_a_supprimer; i < nb_colonnes - 1; i++)
    {
        plateau[i] = plateau[i + 1];
        plateau[i + 1] = 0;
    }
}

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces)
{
    * choix_colonne = (random() / ((double) RAND_MAX + 1)) * (PLATEAU_MAX_COLONNES + 1);
    * choix_nb_pieces = (random() / ((double) RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
}

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){

    //bool truefalse = FALSE;

    if(nb_pieces <= plateau[colonne] && nb_pieces >= 0){
        //return plateau[colonne] - nb_pieces;
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
    int i;

    for (i = col_a_supprimer; i < nb_colonnes - 1; i++)
    {
        plateau[i] = plateau[i + 1];
        plateau[i + 1] = 0;
    }
}


int plateau_defragmenter(int plateau[], int nb_colonnes){

    int count = 0;

    for (int i = 0; i < nb_colonnes; i++)
    {
        if(plateau[i] == 0){
            plateau_supprimer_colonne(plateau, nb_colonnes, plateau[i]);
            count++;
        }
    }
    return nb_colonnes - count;
}

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces)
{
    int choix_colonne = 0;
    int choix_nb_pieces = 0;
    int i;

    for (i = 0; i < nb_colonnes; i++)
    {
        
    }
}

