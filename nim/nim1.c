#include "nim.h"

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces){

    //bool truefalse = FALSE;

    if(nb_pieces <= plateau[colonne] && nb_pieces >= 0){
        //return plateau[colonne] - nb_pieces;
        return TRUE;
    }
    else{
        return FALSE
    }
}
