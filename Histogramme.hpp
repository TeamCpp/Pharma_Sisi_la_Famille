#ifndef __HISTOGRAMME_HPP
#define __HISTOGRAMME_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Histogramme{
private:
  Histogramme(map <string, int>)
  map<string, int> freq;
public:
  void affichageHist();
};

#endif
