/******************************************************************
   Par  :   Fazil Boudjerada    (lien-vers-le-compte-GitHub-1)
        :   Duc Minh Nguyen     (lien-vers-le-compte-GitHub-2)
   Date :   12 novembre 2023

   Ce projet consiste à créer une implémentation du jeu de Nim en
   utilisant le langage de programmation C. Le jeu doit permettre
   à un joueur d'affronter une IA et d'interagir avec l'interface
   en ligne de commande.
*******************************************************************/


#include <nim_io.h>
#include <winconsole.h>
#include <m_distributions.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/******************************************************************
                            CONSTANTES
******************************************************************/

#define MANIP_PLATEAU_H_

/* Le nombre maximum de colonnes pour le plateau de jeu */
#define PLATEAU_MAX_COLONNES 20

/* Le nombre maximum de pièces pour chaque colonne du jeu */
#define PLATEAU_MAX_PIECES 35

/* L'affirmation si la contrainte est respectée */
#define TRUE   1

/* L'affirmation si la contrainte n'est pas respectée */
#define FALSE  0

/* Le nombre maximum de bits utilisés pour le codage des objets */
#define CODAGE_NB_BITS 8

/*  */
#define EPS_DOUBLE 0.00000001
