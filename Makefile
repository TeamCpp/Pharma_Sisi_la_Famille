PHARM=Pharmacie
MED=Medicament
HIST=Histogramme
MAIN=main
projet: PHARM MED HIST
	g++ Main.cpp Pharmacie.o Histogramme.o Medicament.o -o TestPharm

PHARM:
	g++ -c $(PHARM).cpp -o $(PHARM).o

MED:
	g++ -c $(MED).cpp -o $(MED).o

HIST:
	g++ -c $(HIST).cpp -o $(HIST).o
