#include <WinConsole.H>
#include "nim.h"


int lire_entier(int min, int max){

    int i;

    printf("Saisir une valeur entière entre 1 et 4: ");
    scanf("%i", &i);
    while(i > 4 | i < 1){
        printf("Saisir une valeur entière entre 1 et 4: ");
        scanf("%i", &i);
    }
    return i;
}