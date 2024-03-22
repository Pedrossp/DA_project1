#include <iostream>
#include <fstream>
#include "DataManip.h"
#include <sstream>
#include "Station.h"
#include "Reservoir.h"

using namespace std;

const int INF = numeric_limits<int>::max();

DataManip::DataManip() {}


void DataManip::readCities() {
    ifstream in("../Project1DataSetSmall/Cities_Madeira.csv");
    unsigned int id;
    string name,line, code, population;
    float demand;

    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);

            getline(iss, name, ',');
            iss >> id;
            iss.ignore();
            getline(iss, code, ',');
            iss >> demand;
            iss.ignore();
            iss.ignore();
            getline(iss, population, '"');


            City *city = new City(name, code, id,population, demand);
            citiesC_.insert({code,city}); //adicionar ao map de cities pelo codigo
            citiesN_.insert({name, city}); //adicionar ao map de cities pelo nome
            graph_.addVertex(id,code); //meter no grafo

        }

    } else
        cout << "Could not open the file\n";
}


void DataManip::readStations() {
    ifstream in("../Project1DataSetSmall/Stations_Madeira.csv");
    unsigned int id;
    string code,line;

    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){

            if (line.front() == ',')
                continue;

            istringstream iss(line);
            iss>>id;
            iss.ignore();
            getline(iss, code, ',');



            Station *station = new Station(id,code);
            stations_.insert({code,station}); //adicionar ao map de stations
            graph_.addVertex(id,code); //meter no grafo
        }

    } else
        cout << "Could not open the file\n";
}


void DataManip::readReservoirs() {
    ifstream in("../Project1DataSetSmall/Reservoirs_Madeira.csv");
    unsigned int id,maxDelivery;
    string reservoir,municipality,code,line;

    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);

            getline(iss, reservoir, ',');
            getline(iss, municipality, ',');
            iss>>id;
            iss.ignore();
            getline(iss, code, ',');
            iss>>maxDelivery;


            Reservoir *r = new Reservoir(reservoir,municipality,id,code,maxDelivery);
            reservoirs_.insert({code,r});
            graph_.addVertex(id,code);
        }

    } else cout << "Could not open the file\n";
}


void DataManip::readPipes() {
    ifstream in("../Project1DataSetSmall/Pipes_Madeira.csv");
    string service_point_a, service_point_b, line;
    unsigned int capacity, direction;

    getline(in, line);

    if(in.is_open()) {
        while(getline(in, line)){
            istringstream iss(line);

            getline(iss, service_point_a, ',');
            getline(iss, service_point_b, ',');
            iss>>capacity;
            iss.ignore();
            iss>>direction;


            graph_.addEdge(service_point_a, service_point_b, capacity);

        }

    } else cout << "Could not open the file\n";
}

unordered_map<string, City *> DataManip::getCitiesC() {
    return citiesC_;
}

unordered_map<string, City *> DataManip::getCitiesN() {
    return citiesN_;
}

unordered_map<string, Station *> DataManip::getStations() {
    return stations_;
}

unordered_map<string, Reservoir *> DataManip::getReservoirs() {
    return reservoirs_;
}

Graph DataManip::getGraph() {
    return graph_;
}

string DataManip::verefyCityCode(string cityNameOrCode) {

    City *city = citiesC_[cityNameOrCode];
    string cityCode;

    if (city == nullptr){
        cityCode = citiesN_[cityNameOrCode]->getCode();
    }
    else{
        cityCode = city->getCode();
    }

    return cityCode;
}

Graph DataManip::normalizeGraph() {

    Graph graph = getGraph();
    graph.addVertex(0, "SS"); // super source

    /*for (auto reser: getReservoirs()){
        newGraph.addEdge("SS",reser.second->getCode(), INF);
    }*/

}

unsigned int DataManip::maxFlowCity(string cityNameOrCode) {

    string cityCode = verefyCityCode(cityNameOrCode);
    Graph newGraph = normalizeGraph();
}


