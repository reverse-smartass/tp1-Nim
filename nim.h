/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM */
/*******************************************************************************/
#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

#include "codage_numerique.h"
#include "m_distributions.h"

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/
/*
PLATEAU_INIT
Codée par Fazil Boudjerada

Cette fonctions reçois le tableau "plateau" (l'emplacement future au étoile "*")
 et le nombre de colonne, mais ne retourne aucune fonction puisque la fonction
 permet l'initialisation de l'image graphique du jeu (le plateau de jeu) en
 remplissant le tableau de valeurs avec un nombre aléatoire de pièces situé entre
 la valeur minimal (1) et la valeur maximal du tabeau (35) afin de remplir
 initialement chaque colonne.

PARAMÈTRES :
    - plateau[ ] : Le tableau, initialement vide, du plateau utilisé pour insérer
                les valeurs aléatoires de pièces dans chaque colonne
                (type : int).
    - nb_colonnes : Le nombre de colonne à remplir de pièces
                (type : int).

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void plateau_init(int plateau[], int nb_colonnes);
/*
NIM_JOUER_TOUR
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau du plateau, le nombre de colonnes dans le tableau,
la colonne retourné par la fonction ..., le nombre de pièce contenue dans chaque
colonne et retourne l'autorisation de continuer le jeu tant que le nombre de pièces
dans le jeu est supérieur au nombre de pièce à enlevé, décidé par l'humain. Cette
fonction permet de jouer le tour de l'humain en décidant le nombre de pièce à
enlever dans une colonne selectionnée.

PARAMÈTRES :
    - plateau[ ] : Le tableau du plateau contenant le nombre de pièce initial dans
                chaque colonne
                (type : int).
    - nb_colonnes : Le nombre de colonne dans le tableau du plateau
                (type : int).
    - colonne   : La colonne choisi par l'humain où le nombre de pièce diminuera
                (type : int).
    - nb_pieces : Le nombre de pièce à enlever dans le tableau
                (type : int).

HYPOTHÈSE :
    - On suppose que le nombre de pièce à enlever ne dépassera pas le nombre de
        pièce initial au tableau.
    - On suppose aussi que toute les variables auront une valeur entière supérieur
        à une valeur nulle.

VALEUR DE RETOUR : Les constantes de confirmation (TRUE(1) et FALSE(0)) (type : #define)

EXEMPLE D'APPEL :
    - Si plateau[1] = 12, alors nb_pieces < 12
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
/*
PLATEAU_SUPPRIMER_COLONNE
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau du plateau, le nombre de colonnes dans le tableau,
la colonne vide qui doit être supprimé par le programme et retourne aucune variable,
car la fonction permet de supprimer une colonne avec une valeur nulle

PARAMÈTRES :
    - plateau[ ] : Le tableau du plateau contenant le nombre de pièce dans
                chaque colonne
                (type : int).
    - nb_colonnes : Le nombre de colonne dans le tableau du plateau
                (type : int).
    - col_a_supprimer : Toute les colonnes ayant une valeur nulle
                (type : int).

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
/*
PLATEAU_DEFRAGMENTER
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau du plateau, le nombre de colonnes dans le tableau,
et retourne le nombre totale de pièces restant dans chaque colonne. Cette fonction
permet de défragmenter toute les colonnes de pièce en utilisant la fonction
"plateau_supprimer_colonne()". Pour toute les colonnes plus petit au nombr de colonne
totale du plateau, si la valeur d'une des colonnes est nulles, alors la fonction va
faire appel à la fonction plateau_supprimer_colonne() pour supprimer la colonne.

PARAMÈTRES :
    - plateau[ ] : Le tableau du plateau contenant le nombre de pièce initial dans
                chaque colonne
                (type : int).
    - nb_colonnes : Le nombre de colonne dans le tableau du plateau
                (type : int).

HYPOTHÈSE :
    - On suppose que si une colonne est supprimée, le jeu continuera avec un nombre de
    colonne de n-1 jusqu'à la dernière colonne.

VALEUR DE RETOUR : le nombre totale de pièces restant dans chaque colonne (type : int)

EXEMPLE D'APPEL : Aucune.
*/
int plateau_defragmenter(int plateau[], int nb_colonnes);
/*
NIM_CHOIX_IA_ALÉATOIRE
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau du plateau, le nombre de colonnes dans le tableau,
le nombre de pièce que doit enlever l'ordinateur, la colonne choisi et retourne 
aucune variable parce que cette fonction permet de jouer le tour de l'ordinateur
de façon aléatoire en générant des valeurs aléatoire pour le choix de la colonne
à enlever ses pièces et le choix du nombre de pièces à enlever dans cette colonne.
En prenant compte du nombre de colonne disponible dans le plateau et le nombre de
pièce disponible dans chaque colonne.

PARAMÈTRES :
    - plateau[ ] : Le tableau du plateau contenant le nombre de pièce initial dans
                chaque colonne
                (type : const int).
    - nb_colonnes : Le nombre de colonne dans le tableau du plateau
                (type : int).
    - *choix_colonne : Le pointeur du choix de colonne, pris par l'ordinateur
                (type : int).
    - *choix_nb_pieces : Le pointeur du choix de nombre de pièce que l'ordinateur
                        doit enlever dans une colonne choisi
                (type : int).

HYPOTHÈSE :
    - Le nombre de pièce à enlever, aléatoirement choisi, devra être inférieur au
    nombre de pièce actuellement présent dans la colonne choisi.
    - La colonne choisi devra se situer parmi le nombre de colonne présent dans le
    plateau

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces);
/*
NIM_CHOIX_IA
Codée par Fazil Boudjerada

Cette fonctions reçois le tableau du plateau, le nombre de colonnes dans le tableau,
le niveau de difficulté de l'ordinateur,le nombre de pièce que doit enlever
l'ordinateur, la colonne choisi et retourne aucune variable parce que cette fontion
permet de jouer le tour de l'ordinateur de façon à toujours suivre la logique
mathématique du jeu. Donc, la fonction devra être sûre que le niveau de difficulté
est de MOYEN ou DIFFICILE.

PARAMÈTRES :
    - plateau[ ] : Le tableau du plateau contenant le nombre de pièce initial dans
                chaque colonne
                (type : const int).
    - nb_colonne : Le nombre de colonne dans le tableau du plateau
                (type : int).
    - niveau    : Le niveau de difficulté selectionnée préalablement par le joueur
                (type : int).
    - *choix_colonne : Le pointeur du choix de colonne, pris par l'ordinateur
                (type : int).
    - *choix_nb_pieces : Le pointeur du choix de nombre de pièce que l'ordinateur
                        doit enlever dans une colonne choisi
                (type : int).

HYPOTHÈSE :
    - On suppose que si une colonne est supprimée, le jeu continuera avec un nombre de
    colonne de n-1 jusqu'à la dernière colonne.
    - On suppose aussi que les valeurs reçu qui sont différent de MOYEN(2) et
    DIFFICILE(3) seront retournés à la fonction nim_tour_ia().

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces);
/*
CONSTRUIRE_MAT_BINAIRE
Codée par Fazil Boudjerada

Cette fonctions reçois le tableau du plateau, le nombre de colonnes dans le tableau,
la matrice à deux dimension renvoyé au plateau plus tard et retourne aucune variable
puisque la fonction permet de construire la matrice binaire qui sera utilisé au tour
de l'ordinateur et permet d'instaurer les valeurs binaire dans une matrice avec un
nombre maximal de colonne (CODAGE_NB_BITS), sachant que l'appel à la fonction
codage_bin2dec va convertir les valeurs binaires en valeurs décimales.

PARAMÈTRES :
    - plateau[ ] : Le tableau du plateau contenant le nombre de pièce initial dans
                chaque colonne
                (type : const int).
    - nb_colonne : Le nombre de colonne dans le tableau du plateau
                (type : int).
    - matrice [ ][ ] : La matrice représentant les nombres binaires du plateau
                (type : int).

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);
/*
SOMME_MAT_BINAIRE
Codée par Fazil Boudjerada

Cette fonctions reçois la matrice à deux dimension représentant les nombres
binaires, le nombre de lignes présente dans le tableau, la somme de tout les
tableaux du plateau et retourne aucune variable car cette fonction permet de
calculer les sommes des valeurs binaires de chaque colonne de la matrice et
stocker ses valeurs (les sommes) dans le tableau somme[].

PARAMÈTRES :
    - matrice[ ][ ] : La matrice à deux dimension qui stocke toute les valeurs
                    binaire du tableau du plateau
                    (type : const int).
    - nb_lignes     : Le nombre de lignes présentement dans la matrice
                    (type : int).
    - somme[ ]      : Les sommes de tous les nombres binaires (1) d'une colonne
                    (type : int).

HYPOTHÈSE :
    - On suppose que 

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]);
/*
POSITION_PREMIER_IMPAIRE
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau utilisé pour contenir les premiers impaire de
chaque colonne et retourne plusieurs valeurs, dont l'indice du premier impaire
et la valeur "-1" en cas d'invalidité de la valeur (si la valeur est nulle).
Cette fonction permet de déterminer les premiers impaires du tableau en calculant
le modulo de chaque valeur pour savoir s'il y a un reste (donc valeur impaire) ou
sans reste (dont valeur pair).

PARAMÈTRES :
    - tab[ ] : Le tableau contenant toute les valeurs impaires
                (type : const int).

HYPOTHÈSE :
    - On suppose que la valeur du résultat du modulo doit être de 1 pour permettre
    à une certaine valeur d'être stocker dans le tableau.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
int position_premier_impaire(const int tab[]);










#endif