#include <WinConsole.H>
#include "nim.h"

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select);
static int choisir_colonne(int plateau[], int nb_colonnes);
void tour_humain(int plateau[], int nb_colonnes);
void tour_ia(int plateau[], int nb_colonnes, double difficulte);
void demarrer_jeu(int niveau);