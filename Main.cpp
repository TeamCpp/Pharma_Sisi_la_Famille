#include <iostream>
#include "Pharmacie.hpp"
#include "Histogramme.hpp"
int main()
{
  Pharmacie p ("./ListeMedicaments.txt");// Création de la pharmacie par parsage du fichier donné en paramètre
  Histogramme hist;
  int choix=1;
  while(choix>0)
    {
      std::cout<< "Pharmacie"<<std::endl;
      std::cout<<"1 : ajouter un médicament"<<std::endl;
      std::cout<<"2 : supprimer un médicament"<<std::endl;
      std::cout<<"3 : rechercher un médicament"<<std::endl;
      std::cout<<"4 : recherche avancé d'un médicament"<<std::endl;
      std::cout<<"5 : construction histogramme"<<std::endl;
      std::cout<<"6 : afficher les médicaments"<<std::endl;
      std::cin>>choix;
      switch (choix)
	{
	case 1:	
	  p.ajouter();//Ajouter un élément à la pharmacie
	  break;
	case 2:	
	  p.supprimer();//Supprimer un élément de la pharmacie
	  break;
	case 3:	
	  p.recherche();//Liste des médicament possédant l'effet donné par l'utilisateur
	  break;
	case 4:	
	  p.recherche_avancee();//Liste des médicaments partageant un/des effet(s) en commun
	  break;
	case 5:
	  hist.calculHist(p);//Remplit l'histogramme
	  hist.affichageHist();
	  break;
	case 6:
	  p.afficher();// affiche la liste des médicaments de la pharmacie
	  break;
	}
    }
}
