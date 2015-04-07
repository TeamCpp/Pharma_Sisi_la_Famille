#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Histogramme.hpp"

using namespace std;
//Rajouter constructeur par défaut pour set les meds NULL
Histogramme::Histogramme(map <string, vector<string> > meds){
  map <string, vector<string> >::iterator im;
  for (im = meds.begin(); im != meds.end(); im++){
    vector <string> effets = (*im).second;
    vector <string>::iterator iv;
    for (iv = effets.begin(); iv != effets.end(); iv++){
      if (freq.count(*iv)>0){
	freq[*iv] = freq[*iv] + 1;
      }
      else{
	freq[*iv] = 1;
      }
    }
  }
}
//Histogramme::affichageHist();{}
