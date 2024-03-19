#include "DataManip.h"
#include "iostream"
using namespace std;

int main(){
    DataManip data;
    data.readStations();
    data.readReservoirs();
    data.readCities();

    for ( auto x : data.getReservoirs()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }

    for ( auto x : data.getCities()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }

    for ( auto x : data.getStations()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }

    return 0;

}