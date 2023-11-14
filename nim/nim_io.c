
#include "nim_io.h"

// Fonction qui demande un entier entre max et min
int lire_entier(int min, int max)
{
    int j = 1;

    printf("Saisir une valeur entière entre %i et %i: ", min, max);
    scanf("%i", &j);
    
    while(j > max | j < min){
        printf("Erreur! Saisir une valeur entière entre %i et %i: ", min, max);
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
    gotoxy(0, 6);

    // Affichage de toutes les valeurs de colonne dans l'axe des y
    for (int k = PLATEAU_MAX_PIECES; k >= 1; k--) {
        printf("%i\n", k);
    }

    // Affichage de toutes les valeurs de colonne dans l'axe des x
    int posY = posy + 2;
    for (int l = 0; l < nb_colonnes; l++) {
        gotoxy(posxtmp, posY);
        printf("%i", l);
        posxtmp += 3;
    }
    
    for (int i = 0; i < nb_colonnes; i++) {
        int posx = i * 3 + 4;

        //Si la colonne est selectionnée, on change l'affichage pour la couleur RED
        //Si la colonne n'est pas selectionnée, on change l'affichage pour la couleur BLACK
        if (i == col_select) {
            textbackground(RED);
            gotoxy(col_select * 3 + 4, posY);
            printf("%i", col_select);
        }
        else {
            textbackground(BLACK);
        }

        gotoxy(posx, posy);

        // Affichage des colonnes de *
        for (int j = 0; j <= plateau[i]; j++) {
            if (plateau[i] > 0) {
                printf("*");
                gotoxy(posx, posy - j);
            }
        }
    }
    gotoxy(0, posy + 3);
    textbackground(BLACK);
}

// Fonction qui permet de choisir une colonne parmi les colonnes disponibles
static int choisir_colonne(int plateau[], int nb_colonnes)
{
    int colonne = 0;
    unsigned char input;
    static int choix = 0;

    plateau_afficher(plateau, nb_colonnes, choix);

    input = 71;

    while (input != 13) {
        input = _getch();

        if (input == 0 || input == 224) {
            input = _getch();

            switch (input)
            {
            case (FLECHE_GAUCHE):
                choix = (choix - 1) < 0 ? choix = (nb_colonnes - 1) : choix - 1;
                break;
            case (FLECHE_DROITE):
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

// Fonction qui permet de jouer un tour de l'humain
void tour_humain(int plateau[], int nb_colonnes)
{
    printf("****** Tour Joueur ******\n\n==> Veuillez choisir la colonne souhaitee\n\n    <-, ->, <ESPACE> : Changer la selection  <ENTER> : Valider");

    // Appel à la fonction qui choisit la colonne sélectionné par l'humain
    int choix = choisir_colonne(plateau, plateau_defragmenter(plateau, nb_colonnes));

    // Appel à la fonction qui choisit le nombre de pièces à retirer dans la colonne
    clrscr();
    gotoxy(0, 6);
    plateau_afficher(plateau, plateau_defragmenter(plateau, nb_colonnes), choix);
    gotoxy(0, 0);
    printf("****** Tour Joueur ******\n\n==> Nombre de pieces: ");
    
    int nb_pieces = lire_entier(1, plateau[choix]);

    // Appel à la fonction qui joue le tour
    int result = nim_jouer_tour(plateau, nb_colonnes, choix, nb_pieces);
}

// Fonction qui permet de jouer un tour de l'ordinateur (selon le niveau de difficulté)
void tour_ia(int plateau[], int nb_colonnes, int difficulte)
{
	int choix_colonne;
	int choix_nb_pieces;

    //Appel à la fonction qui effectue les choix intelligents décidées par l'ordinateur
    
    /* Appel à la fonction (plateau_defragmenter) au lieu de (nb_colonnes) pour avoir le nombre
    courant de colonnes restantes au lieu du nombre initial. */
	nim_choix_ia(plateau, plateau_defragmenter(plateau, nb_colonnes), difficulte, &choix_colonne, &choix_nb_pieces);

    gotoxy(0, 0);

    printf("****** Tour Ordinateur *******\n\nOrdinateur va prendre %i piece de la colonne %i", choix_nb_pieces, choix_colonne);

    plateau_afficher(plateau, plateau_defragmenter(plateau, nb_colonnes), choix_colonne);

    system("pause");

    int result = nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}

// Fonction qui permet le démarrage de l'interface graphique et de l'exécution du jeu
void demarrer_jeu(int niveau) {

    printf("***** NOUVELLE PARTIE *****\nNombre de colonnes: \n");
    
    int nb_colonnes = lire_entier(2,20); 
    int* plateau = malloc(sizeof(int) * nb_colonnes);

    plateau_init(plateau, nb_colonnes);
    clrscr();

    int status = 0;

    while(plateau_defragmenter(plateau,nb_colonnes) != NULL) {

        if (status == 0) {
            tour_humain(plateau, nb_colonnes);
            status = 1;
        }

        else if (status == 1) {
            tour_ia(plateau, nb_colonnes, niveau);
            status = 0;
        }
    }

    clrscr();
    gotoxy(3, 0);

    if (status == 1) {
        printf("L'humain a gagne!\n");
    }

    else if (status == 0) {
        printf("L'IA a gagne!\n");
    }

    system("pause");
    free(plateau);
}