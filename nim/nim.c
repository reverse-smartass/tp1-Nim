#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "nim.h"

#define PLATEAU_MAX_PIECES 35
#define PLATEAU_MIN_COLONNES 2
#define PLATEAU_MAX_COLONNES 20	
#define TRUE   1
#define FALSE  0

// Fonction qui sélectionne un nombre aléatoire entre 0 et le nombre de pièces maximales pour chaque colonnes
void plateau_init(int plateau[], int nb_colonnes)
{
    // Pour toute les colonnes entre 0 et le nombre de colonnes définit (5)
    for (int i = 0; i < nb_colonnes; i++) {
        // Générateur de nombre aléatoire de pièces entre 0 et PLATEAU_MAX_PIECES
        plateau[i] = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);           //Ask the question of if we could leave it that way
    }
}





int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
{
    //bool truefalse = FALSE;

    // Si le nombre de pièce choisi est supérieur au nombre de pièce dans la colonne choisie et que le nombre de pièce choisi est positif
    if (nb_pieces <= plateau[colonne] && nb_pieces >= 0) {
        //return plateau[colonne] - nb_pieces;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// Fonction qui supprime les pieces choisies dans la colonne choisie
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
    // Pour toutes les colonnes entre la colonne choisie et la colonne juste avant la colonnes maximum (5)
    for (int i = col_a_supprimer; i < nb_colonnes - 1; i++) {
        plateau[i] = plateau[i + 1];
        plateau[i + 1] = 0;
    }
}

// Fonction qui supprime toutes les pieces dans la colonne choisie
int plateau_defragmenter(int plateau[], int nb_colonnes)
{
    // Initialisation du compteur de pieces supprimees dans la colonne
    int count = 0;

    // Pour toutes les colonnes entre 0 et le nombre de colonnes définit (5)
    for (int i = 0; i < nb_colonnes; i++) {
        if (plateau[i] == 0) {
            plateau_supprimer_colonne(plateau, nb_colonnes, plateau[i]);
            count++;
        }
    }
    return nb_colonnes - count;
}

// Fonction qui effectue les changements dans le plateau en fonction des choix de l'IA
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
    // Générateur de nombre aléatoire de colonnes entre 0 et PLATEAU_MAX_COLONNES
    *choix_colonne = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_COLONNES + 1);
    *choix_nb_pieces = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
}

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
    if (niveau == 1) {
        // Use random choice function (nim_choix_ia_aleatoire) when niveau is less than 2
        nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
    }
    else {
        // Implement your intelligent algorithm here
        // Ensure that you set the chosen column and number of pieces in choix_colonne and choix_nb_pieces.
        // If an error occurs, set both references to -1.
        // Your implementation should adhere to the rules of the Nim game.
    }
}