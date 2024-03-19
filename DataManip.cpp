#include <iostream>
#include <fstream>
#include "DataManip.h"
#include <sstream>
#include "Station.h"
#include "Reservoir.h"

using namespace std;
DataManip::DataManip() {}


void DataManip::readCities() {
return;
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
    return;
}

unordered_map<string, City *> DataManip::getCities() {
    return cities_;
}

unordered_map<string, Station *> DataManip::getStations() {
    return stations_;
}

unordered_map<string, Reservoir *> DataManip::getReservoirs() {
    return reservoirs_;
}
