

#include "WinConsole.H"

#include "nim_io.h"


int main(void){

    int j = lire_entier(2, 20);

    int* arr = malloc(sizeof(int) * j);

    //int arr[6] = { 0,34,6,0,4,0 };

    plateau_init(arr, j);

    //plateau_afficher(arr, i, 1);

    //int k = choisir_colonne(arr, i);

    /*while (plateau_defragmenter(arr, j) != NULL) {
        tour_humain(arr, j);
        //printf("j= %i\n", j);
        system("pause");
    }*/

    for (int i = 0; i < j; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");

    //int i = plateau_defragmenter(arr, 6);*/ 

    /*int resultat[CODAGE_NB_BITS];

    int i = codage_dec2bin(137, resultat);

    for (int n = 0; n < 8; n++) {
        printf("%i ", resultat[n]);
    }
    printf("\n");
    system("pause");

    int s = codage_bin2dec(resultat);
    printf("%i\n", s);

    system("pause");*/

    int** matrice = (int*)malloc(sizeof(int) * j);

    for (int m = 0; m < j; m++) {
        matrice[m] = malloc(sizeof(int) * CODAGE_NB_BITS);        
    }

    
    construire_mat_binaire(arr, j, matrice);
    

    
    

    /*for (int m = 0; m < j; m++) {
        for (int k = 0; k < CODAGE_NB_BITS; k++) {
            printf("%i ", matrice[m][k]);
        }
        printf("\n");
    }*/

    

    system("pause");

    

    /*for (int i = 0; i < j; i++) {
        for (int n = 0; n < CODAGE_NB_BITS; n++) {
            printf("%i ", matrice[i][n]);
        }
    }*/
    
    free(arr);
}

