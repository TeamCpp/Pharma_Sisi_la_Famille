#include "Medicament.hpp"
Medicament::Medicament(string nom, vector <string> effets)
{
  nom_effets=make_pair(nom,effets);
}
string Medicament::nom() const
{
  return nom_effets.first;
}
vector<string> Medicament::effets() const
{
  return nom_effets.second;
};


