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

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select){

    gotoxy(0,5);

    for(int k = PLATEAU_MAX_COLONNES; k>=1; k--){
        printf("%i\n\n", k);
    }

    int posy = PLATEAU_MAX_COLONNES + 5;
    int posxtmp= 2;

    for(int l = 0; l < nb_colonnes; l++){
        gotoxy(posxtmp, posy+2);
        prinf("%i", l);
        posxtmp +=2;
    }

    for(int i = 0; i < nb_colonnes; i++){
        int posx = i*2+2;
        gotoxy(posx, posy);
        for(int j = 0; j < plateau[i]; i++){
            printf("*");
            gotoxy(posx, posy-2*(j+1));
        }
    }



}


