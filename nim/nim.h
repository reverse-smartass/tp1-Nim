/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions nécessaires à l'implémantation du jeu NIM */
/*******************************************************************************/


#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

#include "codage_numerique.h"
#include "m_distributions.h"

/* Le nombre maximum de pièces pour chaque colonne du jeu */
#define PLATEAU_MAX_PIECES 35

/* Le nombre minimum de colonnes pour le plateau de jeu */
#define PLATEAU_MIN_COLONNES 2

/* Le nombre maximum de colonnes pour le plateau de jeu */
#define PLATEAU_MAX_COLONNES 20

/* L'affirmation si la contrainte est respectée */
#define TRUE   1

/* L'affirmation si la contrainte n'est pas respectée */
#define FALSE  0


/*******************************************************************************/
/*                   DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/


void plateau_init(int plateau[], int nb_colonnes);
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
// Fonction privée (static int) après les tests de programme
int plateau_defragmenter(int plateau[], int nb_colonnes);
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces);
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces); 


#endif