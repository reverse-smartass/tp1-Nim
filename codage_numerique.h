#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define CODAGE_NB_BITS 8
/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

int inverser_tab_bits(int tab_bits[], int nb_bits);
int codage_dec2bin(int nombre, int resultat[]);
void afficher_tab_bits(const int tab_bits[], int nb_bits);
int codage_bin2dec(const int tab_bits[]);

