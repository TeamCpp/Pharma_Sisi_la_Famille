#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Histogramme.hpp"

using namespace std;

Histogramme::Histogramme(){
  freq;
}
//Donne le nombre d'occurence de chaque effet existant dans la pharmacie
void Histogramme::calculHist(Pharmacie& pharma){
  map<string, vector<string> > meds = pharma.meds;
  freq.erase(freq.begin(),freq.end());
  map<string, vector<string> >::iterator im;
  for (im = meds.begin(); im != meds.end(); im++){
    vector<string> effets = (*im).second;
    vector<string>::iterator iv;
    for (iv = effets.begin(); iv != effets.end(); iv++){
      freq[*iv]++;
    }
  }
}
//Réalise l'affiche de l'histogramme
void Histogramme::affichageHist(){
  cout << "=============================Histogramme=============================" << endl;
  map<string, int>::iterator im;
  for (im = freq.begin(); im != freq.end(); im++){
    cout << "|";
    int i (0);
    while (i < (*im).second){
      cout << "X";
      i++;
    }
    int espaces = 25 - i;
    while (espaces > 0){
      cout << ".";
      espaces = espaces - 1;
    }
    cout << (*im).first << "(" << i << ")" << endl;
  }
  cout << "\E[30;1mAppuyez sur 'c' pour continuer\E[m" << endl;
  string passer;
  while (passer != "c"){
    cin >> passer;
  }
}
