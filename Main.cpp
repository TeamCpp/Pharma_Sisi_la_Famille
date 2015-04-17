#include <iostream>
#include "Pharmacie.hpp"
#include "Histogramme.hpp"
int main()
{
  Pharmacie p ("./ListeMedicaments.txt");
  Histogramme hist;
  int choix=1;
  while(choix>0)
    {
      std::cout<<"Pharmacie"<<std::endl;
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
	  p.ajouter();
	  break;
	case 2:	
	  p.supprimer();
	  break;
	case 3:	
	  p.recherche();
	  break;
	case 4:	
	  p.recherche_avancee();
	  break;
	case 5:
	  hist.freq.clear();
	  hist.calculHist(p);
	  hist.affichageHist();
	  break;
	case 6:
	  p.afficher();
	  break;
	}
    }
}
