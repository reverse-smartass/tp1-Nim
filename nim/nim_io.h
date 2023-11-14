/*******************************************************************************
   Par  :   Fazil Boudjerada
        :   Duc Minh Nguyen
   Date :   12 novembre 2023

   Ce programme inclut des fonctions qui permettent l'initialisation du plateau,
   ainsi que le stockage de nombre de ligne et colonne dans les tableaux, la
   défragmentation et mise à jours du plateau du jeu et d'autre fonctionnalité
   relié à la gestion du système du jeu, sans afficher de symbole ou valeurs.
   On y retrouve les sous-programmes suivants :
    - lire_entier
    - plateau_afficher
    - choisir_colonne
    - tour_humain
    - tour_ia
    - demarrer_jeu
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "nim.h"
#include "winconsole.h"

/*******************************************************************************/
/*                                CONSTANTES                                   */
/*******************************************************************************/


/* Valeur ASCII de la touche "flèche gauche" */
#define FLECHE_GAUCHE 75

/* Valeur ASCII de la touche "flèche droite" */
#define FLECHE_DROITE 77

/* Niveau de difficulté du tour de l'ordinateur */
enum difficulte {VIDE, FACILE, MOYEN, DIFFICILE, QUITTER};


/*******************************************************************************/
/*                   DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/
/*
LIRE_ENTIER
Codée par Duc Minh Nguyen

Cette fonctions reçois les bornes minimum et maximum de l'entier saisis par
l'humain et retourne la valeur entière qui respecte les bornes maximales. Cette
fonction permet de saisir le nombre de pièce que la personne décidera d'enlever
décidé par l'utilisateur et permet la validation de cet entier entre des bornes
définit préalablement. Tant que la valeur entière ne respectera pas cette
condition, l'ordinateur lui redemandera un autre nombre de pièces.

PARAMÈTRES :
    - min : La valeur minimale de l'intervalle acceptable de la fonction
            (type : int).
    - max : La valeur maximale de l'intervalle acceptable de la fonction
            (type : int).

HYPOTHÈSE : On suppose que la fonction ne pourra retourner une valeur entière,
            tant que l'entier ne respectera pas les bornes imposées.

VALEUR DE RETOUR : Le nombre de pièces à enlever dans une colonne (type : int)

EXEMPLE D'APPEL : Aucune.
*/
int lire_entier(int min, int max);
/*
PLATEAU_AFFICHER
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau du plateau du jeu, le nombre de colonne
présent dans le jeu, la colonne sélectionnée par le(la) joueur(euse)
(la position où les flèches se sont dirigées) et retourne aucune variable
parce que cette fonction permet d'afficher l'interface graphique du jeu
(le plateau de jeu) en affichant l'état initiale du tableau de colonne et
de pièce. Sachant que, par exemple, la fonction sera en charge de générer
la couleur ROUGE à la position d'une colonne que l'utilisateur(trice) va
se situé.

PARAMÈTRES :
    - plateau[ ] : Le tableau du jeu initialement affiché dans la console
                (type : const int).
    - nb_colonnes : Le nombre de colonnes présent dans le tableau
                (type : int).
    - col_select : La colonne de jeu selectionnée et représenté par un fond ROUGE
                (type : int).

HYPOTHÈSE :
    - On suppose que la couleur de fond ROUGE devra être limité en terme d'espace
    dans le tableau puisque le menu du jeu ne devra pas contenir de couleur
    d'affichage ROUGE.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select);
/*
CHOISIR_COLONNE
Codée par Duc Minh Nguyen

Cette fonctions reçois le tableau du plateau du jeu, le nombre de colonne
présent dans le jeu et retourne le choix de la colonne, choisi en parcourant
le plateau avec les curseurs FLÈCHE_GAUCHE(75) et FLÈCHE_DROITE(77). Cette
fonction permet de choisir une colonne, parmi les colonnes disponibles,
pour enlever un nombre de pièces par la suite.

PARAMÈTRES :
    - plateau[ ] : Le tableau du jeu initialement affiché dans la console
                (type : int).
    - nb_colonnes : Le nombre de colonnes présent dans le tableau
                (type : int).
    - colonne    : La colonne sélectionnée en parcourant le plateau du jeu
                (type : int)
    - input      : La valeur en entrée qui va déclenchée la confirmation de
                la selection d'une colonne
                (type : unsigned char)
    - choix      : La valeur de retour, le choix définitif de colonne
                (type : int)

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Le choix de la colonne à enlever un nombre de pièces (type : int)

EXEMPLE D'APPEL : Aucune.
*/
static int choisir_colonne(int plateau[], int nb_colonnes);
/*
TOUR_HUMAIN
Codée par Fazil Boudjerada

Cette fonctions reçois le tableau du plateau du jeu, le nombre de colonne
présent dans le jeu et retourne aucune variable parce que cette fonction
permet de jouer le tour de l'humain en appelant les fonctions comme
lire_entier (le nombre de pièces à enlever de la colonne), choisir_colonne
(la colonne sélectionné pour la baisse de pièce) et nim_jouer_tour
(nombre de pièce restant dans la colonne).

PARAMÈTRES :
    - plateau[ ] : Le tableau du jeu composée de pièces aligné aux colonnes
                (type : int).
    - nb_colonnes : Le nombre de colonnes présent dans le tableau
                (type : int).
    - choix      : Variable représentant le nombre de pièce à retirer
                (type : int).
    - nb_pieces  : Variable représentant la colonne sélectionné pour choix
                (type : int).
    - result     : Variable représentant le nombre de pièces restant à la colonne
                (type : int).
    - d          : Variable représentant la mise à jour du plateau
                (type : int).

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void tour_humain(int plateau[], int nb_colonnes);
/*
TOUR_IA
Codée par Fazil Boudjerada

Cette fonctions reçois le tableau du plateau du jeu, le nombre de colonne
présent dans le jeu, le niveau de difficulté préselectionnée de l'ordinateur
et retourne aucune variable parce que cette fonction permet de jouer le tour
de l'ordinateur en prenant une décision par rapport à son niveau de difficulté.
En prenant compte que les trois niveaux de difficulté sont FACILE, MOYEN et
DIFFICILE et que les deux possibilités de jeux sont de façon aléatoire ou de
façon mathématique.

PARAMÈTRES :
    - plateau[ ] : Le tableau du jeu initialement affiché dans la console
                (type : int).
    - nb_colonnes : Le nombre de colonnes présent dans le tableau
                (type : int).
    - difficulte : Le niveau de difficulté de l'ordinateur
                (type ; int).
    - choix_colonne : La décision de l'ordinateur sur la colonne à choisir
                (type : int).
    - choix_nb_pieces : La décision de l'ordinateur sur le nombre de pièces
                (type : int).
    - result     : La valeur du nombre de pièces restants

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void tour_ia(int plateau[], int nb_colonnes, double difficulte);
/*
DEMARRER_JEU
Codée par Duc Minh Nguyen

Cette fonctions reçois le niveau de difficulté, le tableau du plateau du
jeu (de maximum de 20 colonnes), le nombre de colonne présent dans le jeu
et reçoit aucune variable puisque cette fonction permet le démarrage de
l'interface graphique et de l'exécution du jeu en faisant l'appel aux
fonctions lire_entier, plateau_init, puis les fonctions de milieu de jeu
tour_humain, tour_ia et plateau_defragmenter.

PARAMÈTRES :
    - niveau : Le niveau de difficulté
                (type : int).
    - plateau[ ] : Le tableau du jeu, composé de maximum 20 colonnes et 35 pièces
                (type : int).
    - nb_colonnes : La variable représente le nombre de pièces saisi à la fonction
                    lire_entier
                (type : int).

HYPOTHÈSE : Aucune.

VALEUR DE RETOUR : Aucune.

EXEMPLE D'APPEL : Aucune.
*/
void demarrer_jeu(int niveau);