#include "DataManip.h"
#include "iostream"
using namespace std;

int main(){
    DataManip data;

    data.readStations();
    data.readReservoirs();
    data.readCities();
    data.readPipes();
     /*
    for ( auto x : data.getReservoirs()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }

    for ( auto x : data.getCities()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }

    for ( auto x : data.getStations()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }
*/

    for ( auto x : data.getGraph().getVertexSet()){
        cout << x.first << " " << "este vértice tem como adjacentes:" << endl;

        for(auto y : x.second->getAdj()){
            cout << y.getDest()->getCode() << " " << y.getCapacity() << endl;
        }
    }
    return 0;

}