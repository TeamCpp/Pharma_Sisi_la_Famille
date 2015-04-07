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
	Medicament(string nom, vector <string> effets);
};
#endif 