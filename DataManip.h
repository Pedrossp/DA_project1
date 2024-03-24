#ifndef DA_PROJECT1_DATAMANIP_H
#define DA_PROJECT1_DATAMANIP_H

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
    unordered_map<string, City*> citiesC_;
    unordered_map<string, Station*> stations_;
    unordered_map<string, Reservoir*> reservoirs_;
    unordered_map<string, City*> citiesN_;

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

    unordered_map<string, City*> getCitiesC();
    unordered_map<string, City*> getCitiesN();
    unordered_map<string, Station*> getStations();
    unordered_map<string, Reservoir*> getReservoirs();
    Graph getGraph();

    //edmonds karp
    string  verefyCityCode(string cityCodeOrName);  //ir buscar code com nome ou code
    void normalizeGraph(); //adicionar super source
    bool findAugmentingPath(Vertex *s, Vertex *t);
    void testAndVisit(queue<Vertex*> &q, Edge *e, Vertex *w, double residual);
    double findMinResidualAlongPath(Vertex* s, Vertex* t);
    void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

    unsigned int maxFlowEdmonds(string cityCodeOrName);
};


#endif //DA_PROJECT1_DATAMANIP_H
