#ifndef MEDICAMENT_H
#define MEDICAMENT_H 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Medicament
{
protected:
  pair <string,vector <string> > nom_effets;

public:
  Medicament()
  {
    //cout<<"constructeur Medicament à vide"<<endl;
  };
  Medicament(string nom, vector <string> effets);
  string nom() const;
  vector<string> effets() const;
};
#endif 
