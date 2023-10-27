
#define PLATEAU_MAX_COLONNES 35
#include "WinConsole.H"
#include <stdio.h>
#include <stdlib.h>

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select);

int main(void){

    const int arr[] = {1,2,4,5,6,7};

    plateau_afficher(arr, 6, 3);
}

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
    int posy = PLATEAU_MAX_COLONNES + 5;
    int posxtmp = 2;
    int YColonneChoisie = (2 + col_select * 3);
    int j;

    // Séparation de l'espace de texte (Affichage du plateau après les 5 premières lignes)
    gotoxy(0,5);

    //print axe Y
    for(int k = PLATEAU_MAX_COLONNES; k >= 1; k--){
        printf("%i\n\n", k);
    }

    //print axe X 
    int posY = posy + 4;
    for(int l = 0; l < nb_colonnes; l++){
        gotoxy(posxtmp, posY);
        printf("%i", l);
        posxtmp += 3;
    }
    //print colonnes de *
    for(int i = 0; i < nb_colonnes; i++){
        int posx = i * 3 + 2;
        gotoxy(posx, posy);
        for(int j = 0; j < plateau[i]; i++){
            printf("*");
            gotoxy(posx, posy-2*(j+1));
        }
    }

    //positionner a la colonne choisie
    gotoxy(YColonneChoisie, posY);
    textbackground(RED);
    gotoxy(YColonneChoisie, posy);
    
    for(j = 1; j <= plateau[col_select]; j++){
        textbackground(RED);
        gotoxy(YColonneChoisie,posy-j);
    }
}