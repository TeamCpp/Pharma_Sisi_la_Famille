#ifndef __HISTOGRAMME_HPP
#define __HISTOGRAMME_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Pharmacie.hpp"
using namespace std;

class Histogramme{
private:
  map<string, int> freq;
public:
  Histogramme();
  void calculHist(Pharmacie&);
  void affichageHist();
};

#endif
