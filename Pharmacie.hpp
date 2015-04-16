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
//#include "Histogramme.hpp"

using namespace std;

class Pharmacie{
  friend class Histogramme;
private:
  map <string, vector <string> > meds;
public:
  Pharmacie(string);
  void parsePharma(ifstream&); // parse le fichier d'entrée
  void parseMed(string, Medicament&); // parse un médicament
  vector<string> recherche();
  void recherche_avancee();
  void ajouter();
  void supprimer();
  vector<string> saisie_verite_terrain();
};

#endif
