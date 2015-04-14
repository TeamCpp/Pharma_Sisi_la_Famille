#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include "Pharmacie.hpp"

using namespace std;

Pharmacie::Pharmacie(string s){
  //vérification que le fichier est valide
  ifstream input(s.c_str());
  if(input.good()) //vérifie que le fichier est valide
    parsePharma(input);
  else
    throw runtime_error("file not good");
  //retourne une exception
}

void Pharmacie::parsePharma(ifstream& in){
  string s;
  while(in.good()){ // tant que le fichier n'est pas vide
    s = '\0';
    getline(in,s,'\n');//récupère la ligne jusqu'à \n
    parseMed(s);
  }
}

void Pharmacie::parseMed(string s){
  if (s.length()>0){
    s=s.replace(s.end()-2, s.end()-1,"");
    size_t z = s.find(':');
    size_t t = 0;
    string name = s.substr(0, z-1); // nom du médicament (de la position 0 dans le string à z-1, vu qu'il y a un espace avant ':')
    vector<string> effects;  // liste d'effets secondaires
    z = s.find(':',z+2);
    int i = z+2; // position du premier caractère après les ':'
    int premier_mot=0;
    while(i < s.length()){ // boucle jusqu'à la fin de la ligne
      t = s.find(",", i);
      size_t t_tmp = 0;
      //if (t==-1)
      //{
      string pattern=", et ";
      t_tmp=s.find(pattern,i);
      if (t==-1){
	pattern=" et ";
	t=s.find(pattern,i);
      }
      if (t==-1 && premier_mot==0){
	i=i-2;
      }
      //}
      if( t >= s.length()){ // pas de virgule trouvée, on en est donc au dernier effet secondaire
	effects.push_back(s.substr(i+2,s.length()-i-3));
	break;
      }
      else{ // il y a plusieurs effets secondaires à traiter encore
	effects.push_back(s.substr(i, t-i));
	i = t+2;	// on fait avancer i de la taille de la chaine + l'espace et la virgule
	if (t_tmp==t && t_tmp!=std::string::npos){
	  i++;
	}
      }
      premier_mot=1;
    }
    //Affichage du vecteur
    /*$vector<string>::iterator effetsI;
      for (effetsI=effects.begin(); effetsI != effects.end();effetsI++)
      {
      std::cout<<*effetsI<<std::endl;
      //std::cout<<(*effetsI).length()<<std::endl;
      }*/
    Medicament med_tmp (name,effects);
    meds[med_tmp.nom()]=med_tmp.effets();
  }
}

void Pharmacie::recherche(){
  std::cout<<"Entrez un symptome"<<std::endl;
  string choix;
  std::getline (std::cin,choix,'\n');
  std::cout<<"Entrez un symptome"<<std::endl;
  map<string, vector<string> >::iterator effetsI;
  for (effetsI=meds.begin(); effetsI != meds.end();effetsI++)
    {
      vector <string> liste=(*effetsI).second;
      vector <string>::iterator parcoursListe;
      for (parcoursListe=liste.begin(); parcoursListe != liste.end();++parcoursListe)
	{
	  if ((*parcoursListe).find(choix)!=std::string::npos)
	    {
	      std::cout<<(*effetsI).first<<std::endl;
	    }
	}
    }
}
void Pharmacie::recherche_avancee(string choix, vector<string> effets){
  map<string, vector<string> >::iterator effetsI;
  for (effetsI=meds.begin(); effetsI != meds.end();effetsI++)
    {
      vector <string> liste=(*effetsI).second;
      vector <string>::iterator parcoursListe;
      for (parcoursListe=effets.begin(); parcoursListe != effets.end();parcoursListe++)
	{
	  std::cout<<(*effetsI).first<<std::endl;
	  break;}
    }
}

//void Pharmacie::rechercheAnalogue(Medicament choix)

