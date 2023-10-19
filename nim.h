/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM */
/*******************************************************************************/
#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

//#include "codage_numerique.h"
#include "m_distributions.h"

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/


int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
void plateau_init(int plateau[], int nb_colonnes);
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
int plateau_defragmenter(int plateau[], int nb_colonnes);
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, 
                            int * choix_colonne, int * choix_nb_pieces);
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, 
                  int * choix_colonne, int * choix_nb_pieces); 







#endif