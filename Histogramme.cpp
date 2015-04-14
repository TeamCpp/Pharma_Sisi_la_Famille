#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Histogramme.hpp"

using namespace std;

Histogramme::Histogramme(){
  freq;
  cout<<"Constructeur Histogramme à vide"<<endl;
}
void Histogramme::calculHist(Pharmacie& pharma){
  map<string, vector<string> > meds = pharma.meds;
  map<string, vector<string> >::iterator im;
  for (im = meds.begin(); im != meds.end(); im++){
    vector<string> effets = (*im).second;
    vector<string>::iterator iv;
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
void Histogramme::affichageHist(){
  map<string, int>::iterator im;
  for (im = freq.begin(); im != freq.end(); im++){
    cout << "|";
    int i (0);
    while (i <= (*im).second){
      cout << "O";
      i++;
    }
    cout << (*im).first << endl;
  }
}
