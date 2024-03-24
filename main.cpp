#include "DataManip.h"
#include "iostream"
using namespace std;

int main(){
    DataManip data;

    /*//Smal data set
    data.readStations();
    data.readReservoirs();
    data.readCities();
    data.readPipes();*/

    //Large data set
    data.readStationsL();
    data.readReservoirsL();
    data.readCitiesL();
    data.readPipesL();

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

    /*for ( auto x : data.getGraph().getVertexSet()){
        cout << x.first << " " << "este vértice tem como adjacentes:" << endl;

        for(auto y : x.second->getAdj()){
            cout << y.getDest()->getCode() << " " << y.getCapacity() << endl;
        }
    }*/
    /*data.normalizeGraph();
    for (auto ola: data.getGraph().getVertexSet()){
        cout << "Este vertice" << ola.second->getCode() << endl;

        for (auto oo: ola.second->getAdj()){
            cout << "   " << oo->getDest()->getCode() << " " << "com capacidade = " << oo->getCapacity() << endl;
        }
    }*/
    //data.maxFLowTotalCity(0, "Lisboa");
    data.getDeficit();
    return 0;

}