#include "nim.h"



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

