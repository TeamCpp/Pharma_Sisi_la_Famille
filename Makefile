PHARM=Pharmacie
MED=Medicament
#HIST=Histogramme
MAIN=main
projet: PHARM MED #HIST
	#g++ $(PHARM).o -o $(PHARM)
	g++ $(PHARM).o $(MED).o -o $(MAIN)
	#g++ $(PHARM).o $(MED).o $(HIST).o $(MAIN)

PHARM:
	g++ -c $(PHARM).cpp -o $(PHARM).o

MED:
	g++ -c $(MED).cpp -o $(MED).o

#HIST:
#	g++ -c $(HIST).cpp -o $(HIST).o
