#define _CRT_SECURE_NO_WARNINGS
#include "WinConsole.H"
#include "nim_io.h"
#include <conio.h>


// Fonction qui demande un entier entre max et min
int lire_entier(int min, int max)
{
    int i;

    printf("Saisir une valeur entière entre %i et %i: ", min, max);
    scanf("%i", &i);
    
    while(i > max | i < min){
        printf("Erreur! Saisir une valeur entière entre %i et %i: ", min, max);
        scanf("%i", &i);
    }
    return i;
}

// Fonction qui affiche le plateau de jeu
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select)
{
    int posy = PLATEAU_MAX_COLONNES + 5;
    int posxtmp = 2;
    int YColonneChoisie = (2 + col_select * 3);
    int j;

    // Séparation de l'espace de texte (Affichage du plateau après les 5 premières lignes)
    gotoxy(0,5);

    // Affichage de toutes les valeurs de colonne dans l'axe des y
    for(int k = PLATEAU_MAX_COLONNES; k >= 1; k--){
        printf("%i\n\n", k);
    }

    // Affichage de toutes les valeurs de ligne dans l'axe des x
    int posY = posy + 4;
    for(int l = 0; l < nb_colonnes; l++){
        gotoxy(posxtmp, posY);
        printf("%i", l);
        posxtmp += 3;
    }

    // Affichage des colonnes de *
    for(int i = 0; i < nb_colonnes; i++){
        int posx = i * 3 + 2;
        gotoxy(posx, posy);
        for(int j = 0; j < plateau[i]; i++){
            printf("*");
            gotoxy(posx, posy-2*(j+1));
        }
    }

    // Affichage des couleurs durant la prise de décision d'une colonne à selectionner
    gotoxy(YColonneChoisie, posY);
    textbackground(RED);
    gotoxy(YColonneChoisie, posy);
    
    // Pour chaque changement de selection de colonne, on change l'affichage pour la couleur ROUGE
    for(j = 1; j <= plateau[col_select]; j++){
        textbackground(RED);
        gotoxy(YColonneChoisie,posy-j);
    }
}

// Fonction qui permet de choisir une colonne parmi les colonnes disponibles
static int choisir_colonne(int plateau[], int nb_colonnes)
{
    int colonne = 0;
    unsigned char input ;
    int choix = 0;

    input = _getch();
    
    while (input != 13){
        input = _getch();

        if (input == 0 || input == 224){
            input = _getch();
            
            switch (input){
            case (75):
                choix = (choix - 1) < 0 ? choix = (nb_colonnes - 1) : choix--;
                break;
            case (77):
                choix = (choix + 1) > (nb_colonnes - 1) ? choix = 0 : choix++;
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
    // Appel à la fonction qui choisit la colonne sélectionné par l'humain
    int choix = choisir_colonne(plateau, nb_colonnes);

    // Appel à la fonction qui choisit le nombre de pièces à retirer dans la colonne
    int nb_pieces = lire_entier(1, plateau[choix]);

    // Appel à la fonction qui joue le tour
    int result = nim_jouer_tour(plateau, nb_colonnes, choix, nb_pieces);
    plateau_supprimer_colonne(plateau, nb_colonnes, nb_pieces);

    // Appel à la fonction qui mets à jour le plateau (avec plateau_defragmenter(plateau,nb))
    int d = plateau_defragmenter(plateau,nb_colonnes);
    nb_colonnes -= d;
    plateau_afficher(plateau, nb_colonnes, choix);
}

// Fonction qui permet de jouer un tour de l'ordinateur (selon le niveau de difficulté)
void tour_ia(int plateau[], int nb_colonnes, double difficulte)
{
	int choix_colonne = 0;
	int choix_nb_pieces = 0;

    // Appel à la fonction qui effectue les choix intelligents décidées par l'ordinateur
	nim_choix_ia(plateau, nb_colonnes, difficulte, &choix_colonne, &choix_nb_pieces);

	int result = nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);

	switch (difficulte){
	case FACILE: nim_choix_ia_aleatoire; break;
	case MOYEN: double md_rand(void); break;        //Si =1, alors choix_ia_aleatoire, sinon choix_ia
	case DIFFICILE: nim_choix_ia; break;
	case QUITTER: EXIT_SUCCESS; break;
	}
}

// Fonction qui permet le démarrage de l'interface graphique et de l'exécution du jeu
void demarrer_jeu(int niveau) {

    int plateau[PLATEAU_MAX_COLONNES];
    int nb_colonnes = lire_entier(2,20); 

    plateau_init(plateau, nb_colonnes);

    while(nb_colonnes > 0) {
        tour_humain(plateau, nb_colonnes);
        tour_ia();
        //Appel à la fonction plateau_defragmenter pour défragmenter le plateau (board's update)
        plateau_defragmenter(plateau, nb_colonnes, 0);
    }    
}