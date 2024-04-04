#ifndef DA_PROJECT1_DATAMANIP_H
#define DA_PROJECT1_DATAMANIP_H

#include <cmath>
#include <unordered_map>
#include <string>
#include <limits>
#include <queue>
#include <algorithm>
#include "Graph.h"
#include "City.h"
#include "Station.h"
#include "Reservoir.h"

using namespace std;


class DataManip {

    Graph graph_;
    map<string, City*> citiesC_;
    map<string, Station*> stations_;
    map<string, Reservoir*> reservoirs_;
    map<string, City*> citiesN_;

public:
    DataManip();
    void readCities();
    void readStations();
    void readReservoirs();
    void readPipes();

    void readCitiesL();
    void readStationsL();
    void readReservoirsL();
    void readPipesL();

    map<string, City*> getCitiesC();
    map<string, City*> getCitiesN();
    map<string, Station*> getStations();
    map<string, Reservoir*> getReservoirs();
    Graph getGraph();

    //edmonds karp
    string  verifyCityCode(string cityCodeOrName);  //ir buscar code com nome ou code
    void normalizeGraph(); //adicionar super source
    bool findAugmentingPath(Vertex *s, Vertex *t);
    void testAndVisit(queue<Vertex*> &q, Edge *e, Vertex *w, double residual);
    double findMinResidualAlongPath(Vertex* s, Vertex* t);
    void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

    void maxFlowEdmonds();
    void maxFLowTotalCity(int choose, string cityCodeOrName);

    void getDeficit();

    void getAverageDifference();
    void BalanceFlow();

    string verifyReservoirCode(string reservoirNameOrCode);
    void reservoirOutOfCommission(vector<string> codeOrName);
    void stationRemoved(string code);
    void pipelineRemoved(vector<pair<string, string>> p );


    //Auxiliar
    void citiesFlow();



};


#endif //DA_PROJECT1_DATAMANIP_H
