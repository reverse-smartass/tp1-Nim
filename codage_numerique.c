#include"codage_numerique.h"

// Pour l'affichage des bits dans le bonne ordre (valeur binaire switcher)
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

// Fonction qui permet la conversion de nombres décimaux en nombres binaires
int codage_dec2bin(int nombre, int resultat[]){

    int i;
    int holder = nombre;
    int powe;

    // Pour la valeur décimale, division par 2 et sauvegarde de son modulo jusqu'à une valeur nulle
    for(i = CODAGE_NB_BITS-1; i > 0; i--){
        powe = pow(2,i); 
        resultat[i] = holder/pow(2,i);
        holder = nombre-powe;
    }
}
