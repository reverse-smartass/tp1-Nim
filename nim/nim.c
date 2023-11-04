
#include "MAIN_TP1.h"
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

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
{
    //bool truefalse = FALSE;

    // Si le nb_pieces est inférieur ou égal au nombre de pièce dans le jeu et nb_pieces est un nombre entier
    if (nb_pieces <= plateau[colonne] && nb_pieces >= 0) {
        // retour TRUE (1) au jeu
        return TRUE;
    }
    else {
        // Aussi non, retour FALSE (0) au jeu
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
    // Si niveau = 1, utiliser la fonction nim_choix_ia_aleatoire
    if (niveau == 1) {
        nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
    }

    // Si niveau = 2-3, activaion de l'algorithme de l'ordinateur à 50% et 100%
    else if (niveau == 2 || niveau == 3){
        // Implement your intelligent algorithm here
        // Ensure that you set the chosen column and number of pieces in choix_colonne and choix_nb_pieces.
        // If an error occurs, set both references to -1.
        // Your implementation should adhere to the rules of the Nim game.
    }
    else{
        EXIT_SUCCESS;
    }
}

// Fonction reçoit le plateau des valeurs pour remplir la matrice binaire (nb binaire)
// une boucle FOR pour chaque position du plateau, appel à la fonction codage_dec2bin (...)
// matrice = adresse au tableau de valeur, matrice[] = adresse à la ligne indiqué
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS])
{
    int pos = position_premier_impaire;

    // Pour toutes les colonnes inférieur au nb de colonne dans le plateau
    /*for (int i = 0; i < nb_colonnes; i++)
    {
        // Construction de la matrice avec les valeurs décimales traduit du binaire
        codage_dec2bin(plateau[pos], matrice[pos]);
    }
    afficher_tab_bits(tab_bits[], nb_bits);
*/
    for (int i = 0; i < nb_colonnes; i++) {
        int nombre_pieces = plateau[i];
        for (int j = 0; j < CODAGE_NB_BITS; j++) {
            // Remplir la matrice en utilisant la représentation binaire du nombre de pièces
            matrice[i][j] = (plateau[i] >> j) & 1;
        }
    }
}

// Fonction qui reçoit la somme des nombres de * (1)
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[])
{
    for (int colonne = 0; colonne < CODAGE_NB_BITS; colonne++)
    {
        for (int ligne = 0; ligne < nb_lignes; ligne++)
        {
            sommes[colonne] += matrice[ligne][colonne];
        }
    }
}

// Fonction qui, avec tableau des sommes, détermine les premiers impaires du tableau
int position_premier_impaire(const int tab[])
{
    int modulo;
    int i;

    while (modulo != 1)
    {
        for (i = 0; i < tab; i++)
        {
            modulo = tab[i] % 2;
        }
    }
    if (modulo == 1)
    {
        return i;
    }
    else (tab[i] == 0)
    {
        return -1;
    }
}

// NOT FOR TODAY (31/11/2023)
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces)
{
    // Move it to the first nim_choix_ia
}