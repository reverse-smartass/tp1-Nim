
#include "nim.h"

// Fonction qui sélectionne un nombre aléatoire entre 0 et le nombre de pièces maximales pour chaque colonnes
void plateau_init(int plateau[], int nb_colonnes)
{
    srand(time(NULL));
    // Pour toute les colonnes entre 0 et le nombre de colonnes définit (5)
    for (int i = 0; i < nb_colonnes; i++) {
        // Générateur de nombre aléatoire de pièces entre 0 et PLATEAU_MAX_PIECES
        plateau[i] = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
    }
}

// Fonction qui permet de jouer le tour de l'humain
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
{
    //bool truefalse = FALSE;
    gotoxy(0, 6);

    system("cls");

    nb_colonnes = plateau_defragmenter(plateau, nb_colonnes);
    plateau[colonne] -= nb_pieces;

    // Si le nombre de pièce choisi est supérieur au nombre de pièce dans la colonne choisie et que le nombre de pièce choisi est positif
    if (nb_pieces <= plateau[colonne] && nb_pieces >= 0) {
        //return plateau[colonne] - nb_pieces;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// Fonction qui supprime une colonne nulle
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
    // Pour toutes les colonnes entre la colonne choisie et la colonne juste avant la colonnes maximum (5)
    for (int i = col_a_supprimer; i < nb_colonnes - 1; i++) {

        // Les colonnes du plateau décale vers la gauche et la colonne à droite = 0
        plateau[i] = plateau[i + 1];
        plateau[i + 1] = 0;
    }
}

// Fonction qui supprime toutes les pieces dans la colonne choisie
int plateau_defragmenter(int plateau[], int nb_colonnes)
{
    // Initialisation du compteur de pieces supprimees dans la colonne
    int count = 0;

    // Pour toutes les colonnes entre 0 et le nombre de colonnes définit
    for (int i = 0; i < nb_colonnes; i++) {
        if (plateau[i] == 0) {
            plateau_supprimer_colonne(plateau, nb_colonnes, i);
        }
    }

    //Compter le nombre de colonnes restantes
    for (int i = 0; i < nb_colonnes; i++) {
        if (plateau[i] > 0) {
            count++;
        }
    }

    //Retourner le nombre de colonnes restantes si c'est pas 0, NULL si c'est 0 
    //(pas vraiment de raison spécifique pour NULL)
    return count = 0 ? NULL : count;
}

// Fonction qui effectue les changements dans le plateau en fonction des choix de l'IA
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
    srand(time(NULL));
    // Générateur de nombre aléatoire de colonnes entre 0 et PLATEAU_MAX_COLONNES
    *choix_colonne = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_COLONNES + 1);
    *choix_nb_pieces = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
}

// Fonction qui détermine le choix de jeu de l'ordinateur (en fonction du niveau de difficulté)
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
    srand(time(NULL));

    int r = rand()%2;

    int matrice[PLATEAU_MAX_COLONNES][CODAGE_NB_BITS];

    int sommes[CODAGE_NB_BITS];

    // Si le choix de niveau est erroné
    if (niveau < 1 || niveau > 3) {
        *choix_colonne = -1;
        *choix_nb_pieces = -1;
        return;
    }
    else if (niveau == 1 || niveau == 2 && r == 0) {
        nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
    }
    else if (niveau == 2 && r == 1 || niveau == 3) {

        //Construire la matrice binaire
        construire_mat_binaire(plateau, nb_colonnes, matrice);


        //Trouver la somme de toutes les colonnes de la matrice binaire
        sommes_mat_binaire(matrice, nb_colonnes, sommes);

        //Trouver la premiere indice impaire dans la matrice des sommes
        int colonneImpair = position_premier_impaire(sommes);

        
        //Trouver la premiere ligne qui a contribue a la valeur de la somme impaire
        int ligne = 0;

        while (matrice[ligne][colonneImpair] != 1) {
            ligne++;
        }

        //(Trouver les nombres impairs dans le tableau de sommes) et (inverser les bits 
        // dans les indices correspondants de la ligne choisie)

        int i;
        int nouvelleValeur = 0;
        //Pour toute les valeurs dans le tableau (sommes[])
        for ( i = 0; i < CODAGE_NB_BITS; i++)
        {
            //Si la valeur est impair
            if (sommes[i] % 2 == 1) {
                //Si la valeur est egale a 0, remplacer par 1
                if (matrice[ligne][i] == 0) {
                    matrice[ligne][i] = 1;
                }//Si la valeur est egale a 1, remplacer par 0;
                else if (matrice[ligne][i] == 1) {
                    matrice[ligne][i] = 0;
                }
            }
            //Calculer la nouvelle valeur de (plateau[*choix_colonne]) avec les changements effectues a
            //sa matrice binaire
            nouvelleValeur += matrice[ligne][i] * pow(2, CODAGE_NB_BITS - 1 - i);
        }
        *choix_colonne = ligne;
        *choix_nb_pieces = plateau[*choix_colonne] - nouvelleValeur;
    }
}

// Fonction qui construit la matrice binaire 
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS])
{
    int d = 0;
    // Pour toutes les colonnes inférieur au nb de colonne dans le plateau
    for (int i = 0; i < nb_colonnes; i++) {
        d = codage_bin2dec(plateau[i], matrice[i]);
        for (int j = 0; j < CODAGE_NB_BITS; j++) {
            // Remplir la matrice en utilisant la représentation binaire du nombre de pièces
            matrice[i][j] = (plateau[i] > j) & 1;
        }
    }
}

// Fonction qui calcule les sommes des valeurs binaires de chaque colonne de la matrice
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[])
{
    // Pour toutes les colonnes inférieur au 8 bits max de codage des objets
    for (int colonne = 0; colonne < CODAGE_NB_BITS; colonne++){
        //Initialiser la somme à zéro pour obtenir la somme correcte
        sommes[colonne] = 0;
        // Pour toutes les lignes inférieur au nb de lignes dans la matrice
        for (int ligne = 0; ligne < nb_lignes; ligne++){
            // Somme des valeurs binaires
            sommes[colonne] += matrice[ligne][colonne];
        }
    }
}

// Fonction qui détermine les premiers impaires du tableau (avec le tableau des sommes)
int position_premier_impaire(const int tab[])
{
    // Modulo pour savoir si le modulo est égal à 1
    int modulo = 0;
    // Valeurs du tableau
    int i = 0;

    // Tant que modulo n'est pas égal à 1 et qu'on n'est pas a la fin du tableau
    while (modulo != 1 && i < 8) {
       
        modulo = tab[i] % 2;

        // Pour tout les éléments du tableau
        i++;
    }
    // Si modulo = 1, retourne 1, si modulo = 0, retourne -1
    return (modulo == 1 ? (i-1) : -1);
}
