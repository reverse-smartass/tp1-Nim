#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>           //For the functions somme, pwr() and shit
#include "nim.h"
#include "codage_numerique.h"

#define PLATEAU_MAX_PIECES 35
#define PLATEAU_MIN_COLONNES 2
#define PLATEAU_MAX_COLONNES 20	
#define TRUE   1
#define FALSE  0

// Fonction qui sélectionne un nombre aléatoire entre 0 et le nombre de pièces maximales pour chaque colonnes
void plateau_init(int plateau[], int nb_colonnes)
{
    srand(time(NULL));
    // Pour toute les colonnes entre 0 et le nombre de colonnes définit (5)
    for (int i = 0; i < nb_colonnes; i++) {
        // Générateur de nombre aléatoire de pièces entre 0 et PLATEAU_MAX_PIECES
        plateau[i] = (rand() / ((double)RAND_MAX + 1)) * (PLATEAU_MAX_PIECES) + 1;  
        //printf("%i ", plateau[i]);
    }
    //printf("\n");
}




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

    // Now, count the number of non-empty columns
    for (int i = 0; i < nb_colonnes; i++) {
        if (plateau[i] > 0) {
            count++;
        }
    }
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

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
    int pf = rand() % 2;

    if (niveau == 1) {
        // Use random choice function (nim_choix_ia_aleatoire) when niveau is less than 2
        nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
    }
    else if(niveau == 2)
    {
        static int status = 0;
        // Implement your intelligent algorithm here
        // Ensure that you set the chosen column and number of pieces in choix_colonne and choix_nb_pieces.
        // If an error occurs, set both references to -1.
        // Your implementation should adhere to the rules of the Nim game.
    }
    else if (niveau == 3) {

    }
}




// Fonction reçoit le plateau des valeurs pour remplir la matrice binaire (nb binaire)
// une boucle FOR pour chaque position du plateau, appel à la fonction codage_dec2bin (...)
// matrice = adresse au tableau de valeur, matrice[] = adresse à la ligne indiqué
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS])
{
    /*    int pos = position_premier_impaire;
        // Pour toutes les colonnes inférieur au nb de colonne dans le plateau
        for (int i = 0; i < nb_colonnes; i++)
        {
            // Construction de la matrice avec les valeurs décimales traduit du binaire
            codage_dec2bin(plateau[pos], matrice[pos]);
        }
        afficher_tab_bits(tab_bits[], nb_bits);
    */
    // Pour toutes les colonnes inférieur au nb de colonne dans le plateau

    int d = 0;
    //int temp[CODAGE_NB_BITS];
    
    for (int i = 0; i < nb_colonnes; i++) {
        d = codage_dec2bin(plateau[i], matrice[i]);
       
        for (int j = 0; j < CODAGE_NB_BITS; j++) {
            //matrice[i][j] = 1;
            printf("%i ", matrice[i][j]);
        }
        printf("\n");
    }
}

// Fonction qui calcule les sommes des valeurs binaires de chaque colonne de la matrice
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[])
{
    // Pour toutes les colonnes inférieur au 8 bits max de codage des objets
    for (int colonne = 0; colonne < CODAGE_NB_BITS; colonne++) {
        // Pour toutes les lignes inférieur au nb de lignes dans la matrice
        for (int ligne = 0; ligne < nb_lignes; ligne++) {
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

    // Tant que modulo n'est pas égal à 1
    while(modulo != 1 && i < 8) {
        // Pour tout les éléments du tableau
        modulo = tab[i] % 2;
        i++;   
    }
    /* Si modulo = 1, retourne la valeur
    if (modulo == 1) {
        return i;
    }
    // Si modulo = 0, retourne -1
    else if (tab[i] == 0) {
        return -1;
    }*/

    return modulo == 1 ? 1 : -1;
}