#include"codage_numerique.h"

int inverser_tab_bits(int tab_bits[], int nb_bits){

       int time = nb_bits/2;
    int finalvalue = nb_bits-1;
    int temp;

    for(int i = 0; i < time; i++){
        temp = tab_bits[i];
        tab_bits[i] = tab_bits[finalvalue-i];
        tab_bits[finalvalue-i] = temp;
    }
    return nb_bits>8? 0 : 1;
}


int codage_dec2bin(int nombre, int resultat[]){

    int i;
    int holder = nombre;
    for(i = CODAGE_NB_BITS-1; i < 0; i--){
        int powe = pow(2,i); 
        resultat[i] = holder/pow(2,i);
        holder = nombre%powe;
    }
    
}
void afficher_tab_bits(const int tab_bits[], int nb_bits);
int codage_bin2dec(const int tab_bits[]);
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]);
int position_premier_impaire(const int tab[]);
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces); 
