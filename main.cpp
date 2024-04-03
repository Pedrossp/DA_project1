#include "DataManip.h"
#include "iostream"
#include "Menu.h"

void funcOla(string basicString);

using namespace std;

int main(){
    DataManip data;

    //Smal data set
    data.readStations();
    data.readReservoirs();
    data.readCities();
    data.readPipes();


    //Large data set
    //data.readStationsL();
    //data.readReservoirsL();
    //data.readCitiesL();
    //data.readPipesL();

    //Menu menu = Menu(data);
    //menu.MainMenu();

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


    /*
    for(auto x : data.getGraph().getVertexSet()){
        cout << x.first  << " " << "este vértice tem como adjacentes: " << endl;
        for(auto y: x.second->getAdj()){
            cout << y->getDest()->getCode()<< "com fluxo " << y->getFlow()<<endl;
        }
    }*/

    //data.maxFLowTotalCity(0,"");
    //data.maxFlowEdmonds();
    //data.getAverageDifference();
   //data.getDeficit();
    /*for(auto x: data.getReservoirs()){
        int sum=0;
        for(auto y:data.getGraph().getVertexSet()[x.first]->getAdj()){
            sum+=y->getFlow();
        }
        cout << x.first <<" fluxo:" << sum << endl;
        cout << "capacidade: "<< x.second->getMaxDelivery()<<endl<< endl;
    }
    data.BalanceFlow();
    cout << "..............................."<< endl;
    for(auto x: data.getReservoirs()){
        int sum=0;
        for(auto y:data.getGraph().getVertexSet()[x.first]->getAdj()){
            sum+=y->getFlow();
        }
        cout << x.first <<" fluxo:" << sum << endl;
        cout << "capacidade: "<< x.second->getMaxDelivery()<<endl<< endl;
    }
    data.getAverageDifference();
    //data.getDeficit();*/

    //data.reservoirOutOfCommission("Ribeiro Frio");
    data.stationRemoved("PS_1");
    return 0;

}