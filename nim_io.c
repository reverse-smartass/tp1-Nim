#include "WinConsole.H"
#include "nim_io.h"
#include<conio.h>




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
        printf("%i", l);
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

static int choisir_colonne(int plateau[], int nb_colonnes)
{
    int colonne = 0;
    unsigned char input;

    while(input != 13){
        input = getch();

        if(input == 0 || input == 224){
            input = getch();
            
            switch (input)
            {
            case (75):
                /* code */
                break;
            case (77):
                /* code */
                break;
            default:
                break;
            }
        }
    }

}