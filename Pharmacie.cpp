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
  Medicament m;
  while(in.good()){ // tant que le fichier n'est pas vide
    s = '\0';
    getline(in,s,'\n');//récupère la ligne jusqu'à \n
    parseMed(s,m);
    meds[m.nom()]=m.effets();
  }
}
void Pharmacie::parseMed(string s, Medicament& med_tmp){
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
      if (t==-1)
	{pattern=" et ";
	  t=s.find(pattern,i);
	}
      if (t==-1 && premier_mot==0)
	{i=i-2;
	}
      //std::replace( s.begin(), s.end(), "  ", " ");
      //}
      if( t >= s.length()){ // pas de virgule trouvée, on en est donc au dernier effet secondaire
	effects.push_back(s.substr(i+2,s.length()-i-3));
	break;
      }
      else{ // il y a plusieurs effets secondaires à traiter encore
	effects.push_back(s.substr(i, t-i));
	i = t+2;	// on fait avancer i de la taille de la chaine + l'espace et la virgule
	if (t_tmp==t && t_tmp!=std::string::npos)
	  {i++;}
      }
      premier_mot=1;
    }
    //Affichage du vecteur
    /*vector<string>::iterator effetsI;
      for (effetsI=effects.begin(); effetsI != effects.end();effetsI++)
      {
      std::cout<<*effetsI<<std::endl;
      //std::cout<<(*effetsI).length()<<std::endl;
      }*/
    Medicament m_tmp(name,effects);
    med_tmp=m_tmp;
  }
}
vector<string> Pharmacie::recherche()
{
  std::cout<<"Entrez un symptome"<<std::endl;
  string choix;
  std::cin>>choix;
  std::cout<<"Les médicaments pouvant provoquer ce symptomes sont:"<<std::endl;
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
void Pharmacie::recherche_avancee(){
  Medicament comparaison;
  string input;
  std::cout<<"Veuillez entrer un médicament en respectant la contrainte: \nNom_medicament :effets indésirables notoires : liste_des effets secondaires."<<std::endl;
  std::cin>>input;
  cout<<"J'ai lu "<<input<<endl;
  getline(std::cin,input,'\n');
  input=input+'\n';
  int nombre=0;
  std::cout<<"Nombre d'effets secondaires partagés:"<<std::endl;
  std::cin>>nombre;
  parseMed(input,comparaison);
  vector <string> listeInput=comparaison.effets();
  std::cout<<listeInput[0]<<std::endl;
  map<string, vector<string> >::iterator effetsI;
  for (effetsI=meds.begin(); effetsI != meds.end();effetsI++)  //Parcours de la map
    {
      vector <string> liste=(*effetsI).second;
      vector <string>::iterator parcoursListe;
      int nombre_tmp=nombre;
      for (parcoursListe=liste.begin(); parcoursListe != liste.end();++parcoursListe)//Parcours des effets d'un médicament de la map
	{
	  vector <string>::iterator parcoursListeInput;
	  for (parcoursListeInput=listeInput.begin(); parcoursListeInput!=listeInput.end();parcoursListeInput++)
	    {
	      string choix=*parcoursListeInput;
	      if ((*parcoursListe).find(choix)!=std::string::npos)
		{
		  nombre_tmp--;
		  if (nombre_tmp<=0)
		    {std::cout<<(*effetsI).first<<std::endl;
		      break;
		    }
		}
	      
	    }
	}
    }
}
void Pharmacie::ajouter(){
  Medicament ajout;
  string input;
  std::cout<<"Veuillez entrer un médicament en respectant la contrainte: \nNom_medicament : effets indésirables notoires : liste_de_medicaments."<<std::endl;
  std::cin>>input;
  getline(std::cin,input,'\n');
  std::cout<<input<<endl;
  parseMed(input,ajout);
  meds[ajout.nom()]=ajout.effets();
}
void Pharmacie::supprimer(){
  std::cout<<"Veuillez entrer un médicament à supprimer"<<std::endl;
  map<string, vector<string> >::iterator effetsI;
  string aSupprimer;
  std::cin>>aSupprimer;
  if (meds.erase(aSupprimer)!=0){
    std::cout<<"Element "<< aSupprimer <<" supprimé"<<std::endl;
  }
  else
    {
      std::cout<<"Element "<< aSupprimer <<" introuvable"<<std::endl;
    }
}
vector<string> Pharmacie::saisie_verite_terrain(){
  vector<string> ground_truth;
  string elem_gt;
  cout << "Entrez les éléments de vérité terrain (Q pour quitter)"<< endl;
  while(true){
    cin >> elem_gt;
    if (elem_gt == "Q"){
      break;
    }
    else{
      ground_truth.push_back(elem_gt);
    }
  }
  return ground_truth;
}
/*
int Pharmacie::rappel(vector<string>resultat_requete, vector<string>verite_terrain){
  
}
int Pharmacie::precision(){
}
*/
