#include "Medicament.hpp"
Medicament::Medicament(string nom, vector <string> effets)
{
	nom_effets=make_pair(nom,effets);
	std::cout<<nom_effets.first<<std::endl;
}

