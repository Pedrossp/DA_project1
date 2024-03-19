//
// Created by pedrosspedro on 18-03-2024.
//

#include <fstream>
#include "DataManip.h"
#include <sstream>
#include "Station.h"
#include "Reservoir.h"
template<class T>
DataManip<T>::DataManip() {}

template<class T>
void DataManip<T>::readCities() {
return;
}

template<class T>
void DataManip<T>::readStations() {
    ifstream in("../Project1DataSetSmall/Stations_Madeira.csv");
    unsigned int id;
    string code,line;

    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);
            iss>>id;
            iss.ignore();
            getline(iss, code, ',');

           //graph_.addVertex(Station(id,code));
        }

    } else cout << "Could not open the file\n";
}

template<class T>
void DataManip<T>::readReservoirs() {
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
            cout<< reservoir <<" " << municipality << " " << id <<" " << code << " " <<maxDelivery <<endl;
            Reservoir *r = new Reservoir(reservoir,municipality,id,code,maxDelivery);
            //graph_.addVertex(r);
        }

    } else cout << "Could not open the file\n";
}

template<class T>
void DataManip<T>::readPipes() {
    return;
}