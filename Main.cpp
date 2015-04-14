#include <iostream>
#include "Pharmacie.hpp"
#include "Histogramme.hpp"
int main()
{

	Pharmacie p ("./ListeMedicaments.txt");
	p.recherche("diplopie");
	Histogramme hist;
	hist.calculHist(p);
	hist.affichageHist();
	return 0;
}
