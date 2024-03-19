#ifndef DA_PROJECT1_DATAMANIP_H
#define DA_PROJECT1_DATAMANIP_H

#include <unordered_map>
#include <string>
#include "Graph.h"
#include "City.h"
#include "Station.h"
#include "Reservoir.h"

using namespace std;


class DataManip {

private:
    Graph graph_;
    unordered_map<string, City*> cities_;
    unordered_map<string, Station*> stations_;
    unordered_map<string, Reservoir*> reservoirs_;

public:
    DataManip();
    void readCities();
    void readStations();
    void readReservoirs();
    void readPipes();

    unordered_map<string, City*> getCities();
    unordered_map<string, Station*> getStations();
    unordered_map<string, Reservoir*> getReservoirs();
};


#endif //DA_PROJECT1_DATAMANIP_H
