/*==========================================================*/
// Pour et par l'�quipe  du DEG
/*==========================================================*/

#include "m_distributions.h"


/*==========================================================*/

/* impl�mentation des fonctions  pour nos �tudiants */
/*==========================================================*/
// STRAT�GIE 
// appel direct au srand de stdlib
void md_srand(unsigned int s){
	srand(s); 
	// obligatoire pour que le g�n�rateur de stdlib active le germe
	rand();
}

/*==========================================================*/
// STRAT�GIE 
// obtenir l'horloge interne et appel de la pr�c�dente
unsigned int md_srand_interne(void){
	unsigned int w ;
	w = (unsigned)time(NULL);
	md_srand(w);
	return w;
}

/*==========================================================*/
// STRAT�GIE 
// un exemple parfait d'usage de l'aide classique
// cet exemple est partout
double md_rand(void){
	return (1.0*rand())/(RAND_MAX + EPS_DOUBLE);
}

/*==========================================================*/
// STRAT�GIE 
// additioner � une borne une part del'�cart(sign�) entre les param�tres
double md_randf(double b1, double b2){
	return b1 + (md_rand()*(b2 - b1));
}

/*==========================================================*/
// STRAT�GIE 
// choisir un r�el al�atoire entre 0 et borne-1
// on lui ajoute 1
int md_randi(int borne){
	borne = abs(borne);
	// j'utilise l'op�rateur ? : pour r�soudre borne == 0
	return borne == 0 ? 0: (int)(1 + md_rand()* borne);
}

/*==========================================================*/

int md_randint(int b1, int b2) {
	// ajouter 1 � la distance entre les bornes
	// c'est pour laisser la m�me chance � la borne sup�rieure
	double distance_plus = 1.0 + abs(b2 - b1);
	// on trouve la borne minimum
	int mini = (b1 < b2) ? b1 : b2;
	int ajout;
	// on va  ajouter au minimum une part al�atoire de cette distance_plus
	ajout = (int)(md_rand() * distance_plus);

	return  mini + ajout;
}

/*==========================================================*/
// STRAT�GIE 
/* 
    obtenu de la Marsaglia�s polar method 
    telle que d�crite sur wiki
*/
double md_randZ(void) {
    // un calcul  assure la g�n�ration de deux valeurs
	static int test_regener = 1;
	static double v1;
	static double v2;
	static double w;
	static double discriminant;
	double sortie;

    // recalcul n�cessaire � tous les 2 usages
	if (test_regener) {
        //boucle de controle
		do {
			v1 = md_randf(-1, 1);
			v2 = md_randf(-1, 1);
            // calcul de la valeur control�e
			w = v1*v1 + v2*v2;

		} while (w >= 1); // tant que le piont n'est pas dans le cercle de rayon 1

		discriminant = sqrt(-2 * log(w) / w);
		sortie = v1*discriminant; // premiere valeur calcul�e 
	}
	else {
		sortie = v2*discriminant; // seconde valeur calcul�e 
	}

    // passage du test aux valeurs 1,0,1,0,1,0.... successivement
	test_regener = (test_regener + 1) % 2;
	return sortie;
}


/*==========================================================*/
// STRAT�GIE 
// obtenue d'une simple transformation lin�aire de la normale Z
// consultez au besoin un cours tr�s �l�mentaire de stats
double md_randnormal(double mu, double sigma){

	// j'utilise l'op�rateur ? : pour r�soudre si sigma <= 0
	return (sigma<=0)? mu : mu + md_randZ()*sigma;
}

/*==========================================================*/
// STRAT�GIE 
// inverser la fonction de r�partition d'une distributon exponentielle
// qui n'implique qu'un exp se fait naturellement avec le log
// c'est un calcul simple et direct.
// consultez au besoin un cours tr�s �l�mentaire de stats
double md_randexpo(double lambda){

	double repartition = md_rand();
	double inverse_repartition = (-log(1.0 - repartition) / lambda);
	if (inverse_repartition < EPS_DOUBLE) inverse_repartition = 0;
	// j'utilise l'op�rateur ? : pour r�soudre si lambda <= 0
	return (lambda <= 0) ? 0 : inverse_repartition;
}

/*==========================================================*/
