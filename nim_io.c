#include "WinConsole.H"
#include "nim_io.h"
#include<conio.h>



// Fonction qui lit un entier entre min et max (between 1 and 4)
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

// Fonction qui affiche le plateau de jeu
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select){

    gotoxy(0,5);
    //print axe Y
    for(int k = PLATEAU_MAX_COLONNES; k>=1; k--){
        printf("%i\n\n", k);
    }

    int posy = PLATEAU_MAX_COLONNES + 5;
    int posxtmp= 2;

    //print axe X 
    int posY = posy+4;
    for(int l = 0; l < nb_colonnes; l++){
        gotoxy(posxtmp, posY);
        printf("%i", l);
        posxtmp +=3;
    }
    //print colonnes de *
    for(int i = 0; i < nb_colonnes; i++){
        int posx = i*3+2;
        gotoxy(posx, posy);
        for(int j = 0; j < plateau[i]; i++){
            printf("*");
            gotoxy(posx, posy-2*(j+1));
        }
    }

    //positionner a la colonne choisie
    int YColonneChoisie = 2+col_select*3;
    gotoxy(YColonneChoisie, posY);
    textbackground(RED);
    gotoxy(YColonneChoisie, posy);
    
    int j;
    for(j = 1; j <= plateau[col_select]; j++){
        textbackground(RED);
        gotoxy(YColonneChoisie,posy-j);
    }


}

// Fonction qui permet de choisir une colonne parmi les colonnes disponibles
static int choisir_colonne(int plateau[], int nb_colonnes)
{
    int colonne = 0;
    unsigned char input;
    int choix = 0;
    
    while(input != 13){
        input = getch();

        if(input == 0 || input == 224){
            input = getch();
            
            switch (input)
            {
            case (75):
                choix = choix-1 < 0 ? choix = nb_colonnes-1 : choix--;
                break;
            case (77):
                choix = choix+1 > nb_colonnes-1 ? choix = 0 : choix++;
                break;
            default:
                break;
            }
            plateau_afficher(plateau, nb_colonnes, choix);
        }
    }

}

void tour_humain(int plateau[], int nb_colonnes)
{
    // Call to the function that choose a column
    choisir_colonne (plateau, nb_colonnes);
    // Call to the function that remove pieces from the chosen column
    // Call to the function that update the plateau
    nim_jouer_tour (plateau, nb_colonnes);
}