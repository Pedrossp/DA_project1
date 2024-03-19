#ifndef DA_PROJECT1_DATAMANIP_H
#define DA_PROJECT1_DATAMANIP_H

#include <unordered_map>
#include <string>
#include "Graph.h"
#include "City.h"



using namespace std;

template <class T>
class DataManip {

private:
    Graph<T> graph_;
    unordered_map<string, City> cities_;

public:
    DataManip();
    void readCities();
    void readStations();
    void readReservoirs();
    void readPipes();
};


#endif //DA_PROJECT1_DATAMANIP_H
