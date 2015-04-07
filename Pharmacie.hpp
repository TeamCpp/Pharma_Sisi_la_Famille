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
		vector <Medicament> meds; // A adapter à l'architecture choisie
		//Medicament med_tmp;

	
	public:
		Pharmacie(string);
		void parsePharma(ifstream&); // parse le fichier d'entrée
		void parseMed(string); // parse un médicament
		// rajoutez vos méthodes
	
};

#endif
