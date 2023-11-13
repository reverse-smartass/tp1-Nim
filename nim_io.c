#define _CRT_SECURE_NO_WARNINGS
#include "WinConsole.H"
#include "nim_io.h"
#include <conio.h>
#define FFLUSH while(getchar() != '\n') 

// Fonction qui lit un entier entre min et max
int lire_entier(int min, int max)
{
    int j = 1;

    printf("Saisir un nombre entier entre %i et %i: ", min, max);
    //FFLUSH;
    scanf("%i", &j);
    
    while(j > max || j < min){
        printf("Erreur! Saisir un nombre entier entre %i et %i: ", min, max);
        //FFLUSH;
        scanf("%i", &j);
    }
    return j;
}

// Fonction qui affiche le plateau de jeu
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
    int posy = PLATEAU_MAX_PIECES + 5;
    int posxtmp = 4;
    

    // Séparation de l'espace de texte (Affichage du plateau après les 5 premières lignes)
    gotoxy(0,6);

    

    //print axe Y
    for(int k = PLATEAU_MAX_PIECES; k >= 1; k--){
        printf("%i\n", k);
    }

    //print axe X 
    int posY = posy + 2;
    for(int l = 0; l < nb_colonnes; l++){
        gotoxy(posxtmp, posY);
        printf("%i", l);
        posxtmp += 3;
    }
    //print colonnes de *
    
    for(int i = 0; i < nb_colonnes; i++){
        int posx = i*3 + 4;

        if (i == col_select) {
            textbackground(RED);
            gotoxy(col_select * 3 + 4, posY);
            printf("%i", col_select);
        }
        else {
            textbackground(BLACK);
        }

        gotoxy(posx, posy);

        for(int j = 0; j <= plateau[i]; j++){
            if (plateau[i] > 0) {
                printf("*");
                gotoxy(posx, posy - j);
            }
        }
    }

    gotoxy(0, posY + 3);
    

    //positionner a la colonne choisie

    /*int colselX = col_select * 3 + 4;

    textbackground(RED);
    gotoxy(colselX, posY);
    printf("%i", col_select);
    gotoxy(colselX, posy);
    
    for(j = 1; j <= plateau[col_select]; j++){
        printf("*");
        gotoxy(colselX,posy-j);
    }*/
    
    gotoxy(0, posy + 3);
    textbackground(BLACK);
}

// Fonction qui permet de choisir une colonne parmi les colonnes disponibles
static int choisir_colonne(int plateau[], int nb_colonnes)
{
    int colonne = 0;
    unsigned char input ;
    static int choix = 0;

    plateau_afficher(plateau, nb_colonnes, choix);

    input = 71;
    
    while (input != 13){
        input = _getch();

        if (input == 0 || input == 224){
            input = _getch();
            
            switch (input)
            {
            case (75):
                choix = (choix - 1) < 0 ? choix = (nb_colonnes - 1) : choix - 1;
                break;
            case (77):
                choix = (choix + 1) > (nb_colonnes - 1) ? choix = 0 : choix + 1;
                break;
            default:
                break;
            }
            plateau_afficher(plateau, nb_colonnes, choix);
        }
    }
    return choix;
}

void tour_humain(int plateau[], int nb_colonnes)
{
    //gotoxy(0, 6);

    //system("cls");

    //int* l = &nb_colonnes;

    //*l = plateau_defragmenter(plateau, nb_colonnes);


    // Call to the function that choose a column
    int choix = choisir_colonne(plateau, plateau_defragmenter(plateau,nb_colonnes));

    // Call to the function that remove pieces from the chosen column
    int nb_pieces = lire_entier(1, plateau[choix]);
   
    //plateau[choix] -= nb_pieces;

    int result = nim_jouer_tour(plateau, nb_colonnes, choix, nb_pieces);

    
    printf("%i\n", nb_colonnes);
    for (int i = 0; i < nb_colonnes; i++) {
        printf("%i ", plateau[i]);
    }
    printf("\n");
}

void tour_ia(int plateau[], int nb_colonnes, double difficulte) {

    int choix_colonne = 0;
    int choix_nb_pieces = 0;

    nim_choix_ia(plateau, nb_colonnes, difficulte, &choix_colonne, &choix_nb_pieces);

    int result = nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}

void demarrer_jeu(int niveau) {

    printf("***** NOUVELLE PARTIE *****\n");
    printf("Nombre de colonnes: \n");

    int nb_colonnes = lire_entier(2, 20);

    int* plateau = malloc(sizeof(int) * nb_colonnes);

    static int status = 0;

    plateau_init(plateau, nb_colonnes);
    while(plateau_defragmenter(plateau, nb_colonnes) != NULL){
        if (status = 0) {
            tour_humain(plateau, nb_colonnes);
            status++;
        }
        else {
            tour_ia(plateau, nb_colonnes, niveau);
            status = 0;
        }
        
    }    
}