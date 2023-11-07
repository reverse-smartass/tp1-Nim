/******************************************************************
   Par  :   Fazil Boudjerada    (https://github.com/Pokefaz)
        :   Duc Minh Nguyen     (https://github.com/reverse-smartass)
   Date :   12 novembre 2023

   Ce projet consiste à créer une implémentation du jeu de Nim en
   utilisant le langage de programmation C. Le jeu doit permettre
   à un joueur d'affronter une IA et d'interagir avec l'interface
   en ligne de commande.
*******************************************************************/


#define _CRT_SECURE_NO_WARNINGS

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

/* Le nombre maximum de bits utilisés pour le codage des objets */
#define CODAGE_NB_BITS 8

/* #define EPS_DOUBLE 0.00000001 */

/* Valeur ASCII de la touche "flèche gauche" */
#define FLECHE_GAUCHE 75

/* Valeur ASCII de la touche "flèche droite" */
#define FLECHE_DROITE 77