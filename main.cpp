#include "DataManip.h"
#include "iostream"
using namespace std;

int main(){
    DataManip data;
    data.readStations();
    data.readReservoirs();

    for ( auto x : data.getReservoirs()){
        cout<< x.second->getId() << " " << x.second->getCode() <<endl;
    }


    return 0;

}