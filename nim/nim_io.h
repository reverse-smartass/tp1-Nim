#include <stdio.h>
#include <stdlib.h>
#include "nim.h"
#include "winconsole.h"

/* Valeur ASCII de la touche "flèche gauche" */
#define FLECHE_GAUCHE 75

/* Valeur ASCII de la touche "flèche droite" */
#define FLECHE_DROITE 77

/* Niveau de difficulté du tour de l'ordinateur */
enum difficulte {-----, FACILE, MOYEN, DIFFICILE, QUITTER};

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

int lire_entier(int min, int max);
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select);
static int choisir_colonne(int plateau[], int nb_colonnes);
void tour_humain(int plateau[], int nb_colonnes);
void tour_ia(int plateau[], int nb_colonnes, double difficulte);
void demarrer_jeu(int niveau);