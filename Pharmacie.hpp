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
  void recherche();
  void recherche_avancee();
  void ajouter();
  void supprimer();
  map<string, vector<string> > saisie_param();
  double rappel(vector<string>&, map<string, vector<string> >&);
  double precision(vector<string>&, map<string, vector<string> >&);
  void afficher();
  void passer_affichage();
};

#endif
