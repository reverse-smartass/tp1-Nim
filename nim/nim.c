
#include "nim_io.h"
#include "codage_numerique.h"

// Fonction qui sélectionne un nombre aléatoire entre 0 et le nombre de pièces maximales pour chaque colonnes
void plateau_init(int plateau[], int nb_colonnes)
{
    // Pour toute les colonnes entre 0 et le nombre de colonnes définit (5)
    for (int i = 0; i < nb_colonnes; i++) {
        // Générateur de nombre aléatoire de pièces entre 0 et PLATEAU_MAX_PIECES
        plateau[i] = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
    }
}

// 
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

// Fonction qui supprime les pieces choisies dans la colonne choisie
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

    // Pour toutes les colonnes inférieur au nombre de colonnes maximum (5)
    for (int i = 0; i < nb_colonnes; i++) {
        
        // Si colonne = 0, supprimer la colonne (plateau_supprimer_colonne)
        if (plateau[i] == 0) {
            plateau_supprimer_colonne(plateau, nb_colonnes, plateau[i]);
            count++;
        }
    }
    // Retourne le nombre de colonnes supprimées
    return nb_colonnes - count;
}

// Fonction qui effectue les changements dans le plateau en fonction des choix de l'IA
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
    // Générateur de nombre aléatoire de colonnes entre 0 et PLATEAU_MAX_COLONNES
    *choix_colonne = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_COLONNES + 1);
    *choix_nb_pieces = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES + 1);
}

// Fonction qui détermine le choix de jeu de l'ordinateur (en fonction du niveau de difficulté)
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
    // Si le choix de niveau est erroné
    if (niveau < 1 || niveau > 3) {
        *choix_colonne = -1;
        *choix_nb_pieces = -1;
        return;
    }
    else {
        // Pour des niveau MOYEN et DIFFICILE
        for (int i = 0; i < nb_colonnes; i++) {
            if (plateau[i] > 0) {
                *choix_colonne = i;
                *choix_nb_pieces = 1;
                return;
            }
        }
    }
}

void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS])
{
    int d;
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
    int modulo;
    // Valeurs du tableau
    int i;

    // Tant que modulo n'est pas égal à 1
    while (modulo != 1){
        // Pour tout les éléments du tableau
        for (i = 0; i < tab; i++){
            modulo = tab[i] % 2;
        }
    }
    // Si modulo = 1, retourne la valeur
    if (modulo == 1){
        return i;
    }
    // Si modulo = 0, retourne -1
    else if (tab[i] == 0){
        return -1;
    }
}
