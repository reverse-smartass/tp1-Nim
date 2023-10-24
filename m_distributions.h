/*==========================================================*/
// Pour et par l'�quipe du DEG
/*==========================================================*/
/* 
	Ce module simple 

	1-) offre une interface n�cessaire au g�n�rateur pseudo-al�atoire  de stdlib 

	2-) assure un acc�s fonctionnel  correct � diverses distributions classiques dont
		des uniformes diverses, la distribution normale et la distribution exponentielle

	3-) Les 9 fonctions pr�sentes assurent
		l'initialisation du g�n�rateur 
			( sous 2 formes, implicite et explicite avec une valeur enti�re en param�tre )
		
		l'�mission d'une entier dans une distribution uniforme
			( sous 2 formes, entre 1 et N  et entre deux bornes )
		
		l'�mission d'une r�el dans une distribution uniforme 
			( sous 2 formes, entre 0 et 1 et entre deux bornes)
		
		l'�mission d'une r�el dans une distribution normale 
			( sous 2 formes, dans Z (0,1) et � partir de mu et sigma)

		l'�mission d'une r�el dans une distribution exponentielle 
			(1 forme avec un lambda explicite)

*/
/*==========================================================*/


/*==========================================================*/

#ifndef _M_RAND_458221_H_
#define _M_RAND_458221_H_
/*==========================================================*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

/*==========================================================*/

/*==========================================================*/
// un epsilon r�el sert � mesurer la proximit� du 0
#define EPS_DOUBLE 0.00000001


/*==========================================================*/

/* VOICI UNE INTERFACE MODULAIRE STANDARD POUR NOS �TUDIANTS */

/*==========================================================*/
/*  D'abord l'offre de deux fonctions d'initialisation du g�n�rateur. Un g�n�rateur 
	non-initialis� s'initialise en fait � 0 et �met la m�me s�quence ce qui fait 
	douter du caract�re al�atoire.... 
	C'est au client de l'initialiser
	MAIS JUSTE UNE FOIS dans tout le programme

	r�initialiser dans  une fonction appell�e en boucle fera 
	d�finitivement perdre toute qualit� au g�n�rateur 
	(surtout que rand de stdlib n'en a d�j� pas beaucoup hs)
*/

/*==========================================================*/
/* La fonction md_srand 
 la forme d'initialisation la plus classique d'un g�n�rateur  
 � partir d'un entier quelconque, la s�quence pseudo al�atoire 
 � venir est totalement d�termin�e par la valeur re�ue en param�tre

PARAMETRE(s): s, un entier positif quelconque

SORTIE: aucune

SPECS: aucune
*/
void md_srand(unsigned int s);

/*==========================================================*/


/*==========================================================*/
/* la fonction md_srand_interne 
 une forme alternative d'initialisation du g�n�rateur � partir 
 de l'horloge interne de la machine,  l'horloge donne un entier
 qui sert de param�tre � la fonction pr�c�dente. 
 Cette valeur est retourn�e pour des motifs de possible reproduction
 des conditions initiales d'une simulation num�rique.

PARAMETRE(s): Aucun

SORTIE: l'entier qui a v�ritablement initialis� le g�n�rateur

SPECS: aucune
*/
unsigned int md_srand_interne(void);
/*==========================================================*/

/* LES FONCTIONS D'�MISSION DANS LES DISTRIBUTIONS SP�CIFI�ES */

/*==========================================================*/
/* La fonction md_rand   
L'�mission d'un nombre r�el dans la distribution uniforme 0,1 

PARAMETRE(s): Aucun

SORTIE : la valeur r�elle �mise dans cette distribution

SPECS : aucune
*/
double md_rand(void);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randf
L'�mission d'un nombre r�el dans une  uniforme [b1, b2] 

PARAMETRE(s): deux valeurs r�elles quelconques qui serviront 
               de bornes � l'intervalle

SORTIE : la valeur r�elle �mise dans cette distribution

SPECS : l'ordre des param�tres n'a aucune importance
*/
double md_randf(double b1, double b2);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randi
L'�mission d'un nombre entier  dans une uniforme[1, borne]

PARAMETRE(s): une valeur enti�re quelconque

SORTIE : la valeur entiere positive �mise dans cette distribution

SPECS :  si le param�tre effectif est n�gatif, c'est sa valeur absolue
		 qui sera consid�r�e 
		 recevant 0, retour automatique de 0 (le seul 0 possible)
*/
int md_randi(int borne);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randint
L'�mission dans la distribution uniforme obtenue des deux param�tres

PARAMETRE(s) : les deux valeurs enti�res quelconques  servent 
               de bornes � l'intervalle

SORTIE : la valeur entiere �mise dans cette distribution

SPECS :peu importe l'ordre des param�tres
*/
int md_randint(int b1, int b2);
/*==========================================================*/

/*==========================================================*/
/* La fonction md_randZ
L'�mission d'un nombre r�el dans la distribution normale Z,
	la plus classique  de moyenne 0 et d'�cart type 1

PARAMETRE(s) : Aucun

SORTIE : la valeur r�elle �mise dans cette distribution

SPECS : celle-ci a une parit� d'�mission
	ce qui peut d�concerter si on r�initialise le g�n�rateur
	en cours d'ex�cution de la simulation ( ce qui en r�alit� ne doit JAMAIS �tre fait)
*/
double md_randZ(void);
/*==========================================================*/
/*==========================================================*/
/* La fonction md_randnormal
L'�mission d'un nombre r�el dans une distribution normale quelconque, 
   de moyenne mu  et d'�cart-type sigma donn�s en param�tres

PARAMETRE(s) : mu d�finit la moyenne voulue et sigma l'�cart-type

SORTIE : la valeur r�elle �mise dans cette distribution

SPECS : m�mes que la pr�c�dente et retour automatique de mu si sigma est n�gatif
*/
double md_randnormal(double mu, double sigma);

/*==========================================================*/
/*==========================================================*/
/* La fonction md_randexpo
   L'�mission d'un temps d'attente dans une distribution exponentielle 
   le temps d'attente  moyen est donn� par l'inverse du param�tre

PARAMETRE(s) : lambda un r�el positif 

SORTIE : la valeur r�elle �mise dans cette distribution

SPECS : retour automatique de 0 si lambda <= 0 
*/
double md_randexpo(double lambda);
/*==========================================================*/

/*==========================================================*/
// 	C'EST FINI 
/*==========================================================*/

/*==========================================================*/
#endif	
/*==========================================================*/

