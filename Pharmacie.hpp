#ifndef __PHARMACIE_HPP
#define __PHARMACIE_HPP
#include "Medicament.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Pharmacie{
	private:
		map <string, vector <string> > meds; // A adapter à l'architecture choisie

	
	public:
		Pharmacie(string);
		void parsePharma(ifstream&); // parse le fichier d'entrée
		void parseMed(string); // parse un médicament
		void recherche(string) ;
		// rajoutez vos méthodes
	
};

#endif
