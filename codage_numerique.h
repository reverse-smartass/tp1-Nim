#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Le nombre maximum de bits utilisés pour le codage des objets */
#define CODAGE_NB_BITS 8

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

int inverser_tab_bits(int tab_bits[], int nb_bits);
int codage_dec2bin(int nombre, int resultat[]);
void afficher_tab_bits(const int tab_bits[], int nb_bits);
int codage_bin2dec(const int tab_bits[]);
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]);
int position_premier_impaire(const int tab[]);
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces); 


