#define _CRT_SECURE_NO_WARNINGS
#include "winconsole.h"
#include "nim_io.h"
#include "m_distributions.h"

// NIM.C
void plateau_init(int plateau[], int nb_colonnes);
// NIM.C
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);
// NIM.C
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]);
// NIM.C
int position_premier_impaire(const int tab[]);


void plateau_init(int plateau[], int nb_colonnes)
{
    // Pour toute les colonnes entre 0 et le nombre de colonnes définit (5)
    for (int i = 0; i < nb_colonnes; i++) {
        // Générateur de nombre aléatoire de pièces entre 0 et PLATEAU_MAX_PIECES
        plateau[i] = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);           //Ask the question of if we could leave it that way
    }
}