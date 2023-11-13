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
    return nb_bits>CODAGE_NB_BITS ? 0 : 1;
}

// Fonction qui permet la conversion de nombres décimaux en nombres binaires
int codage_dec2bin(int nombre, int resultat[])
{
    int i;
    // 
    int holder = nombre;
    // Résultat du calcul de la puissance
    int powe;
    // 
    int digit = 0;

    // Tant que la valeur est positive, on divise par deux et on augmente le compteur de digits
    while (nombre > 0) {
        nombre /= 2;
        digit++;
    }

    if (digit > CODAGE_NB_BITS) {
        return 0;
    }

    for (i = 0; i < CODAGE_NB_BITS; i++) {
        resultat[i] = 0;
    }

    for (i = CODAGE_NB_BITS - digit; i < CODAGE_NB_BITS; i++) {

        powe = pow(2, CODAGE_NB_BITS - 1 - i);
        resultat[i] = holder / powe;
        if (resultat[i] == 1) {
            holder -= powe;
        }
    }

    return digit;
}


// Fonction qui permet l'affichage des bits dans le bonne ordre (valeur binaire switcher)
void afficher_tab_bits(const int tab_bits[], int nb_bits)
{
    int i = 0;

    for (i = 0; i < nb_bits; i++) {
        printf("%i ", tab_bits[i]);
    }
    printf("\n");
}
// Fonction codage_dec2bin utilisant tab_bits[] pour stocker les valeurs binaires
int codage_bin2dec(const int tab_bits[])
{
    int i = 0;
    int j;
    // Résultat de 
    int somme = 0;

    while (tab_bits[i] == 0) {
        i++;
    }

    // Boucle qui permet de calculer la somme des bits
    for (j = i; j < CODAGE_NB_BITS; j++) {
        
        somme += tab_bits[j] * pow(2, (CODAGE_NB_BITS - 1) - j);
    }

    return somme;
}