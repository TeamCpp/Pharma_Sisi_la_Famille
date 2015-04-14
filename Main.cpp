#include <iostream>
#include "Pharmacie.hpp"
#include "Histogramme.hpp"
int main()
{

	Pharmacie p ("./ListeMedicaments.txt");
	p.recherche();
	Histogramme hist;
	hist.calculHist(p);
	hist.affichageHist();
	return 0;
}
