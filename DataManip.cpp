#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "DataManip.h"
#include "Station.h"
#include "Reservoir.h"

using namespace std;

const int INF = numeric_limits<int>::max();

DataManip::DataManip() {}

//Smal data set
void DataManip::readCities() {
    ifstream in("../Project1DataSetSmall/Cities_Madeira.csv");
    unsigned int id;
    string name,line, code, population;
    double demand;

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

            if (direction == 1){
                graph_.addEdge(service_point_a, service_point_b, capacity);
            }
            else{
                graph_.addEdge(service_point_a, service_point_b, capacity);
                graph_.addEdge(service_point_b, service_point_a, capacity);
            }
        }

    } else cout << "Could not open the file\n";
}

//Large data set
void DataManip::readCitiesL() {
    ifstream in("../Project1LargeDataSet/Cities.csv");
    unsigned int id;
    string name,line, code, population;
    double demand;

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
            iss >> population;

            //cout << name << " " << id << " " << code << " " << demand << " " << population << endl;

            City *city = new City(name, code, id,population, demand);
            citiesC_.insert({code,city}); //adicionar ao map de cities pelo codigo
            citiesN_.insert({name, city}); //adicionar ao map de cities pelo nome
            graph_.addVertex(id,code); //meter no grafo

        }

    } else
        cout << "Could not open the file\n";
}


void DataManip::readStationsL() {
    ifstream in("../Project1LargeDataSet/Stations.csv");
    unsigned int id;
    string code,line;

    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){


            istringstream iss(line);
            iss>>id;
            iss.ignore();
            iss >> code;

            //cout << id << " " << code << endl;

            Station *station = new Station(id,code);
            stations_.insert({code,station}); //adicionar ao map de stations
            graph_.addVertex(id,code); //meter no grafo
        }

    } else
        cout << "Could not open the file\n";
}


void DataManip::readReservoirsL() {
    ifstream in("../Project1LargeDataSet/Reservoir.csv");
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

            //cout << reservoir << " " << municipality << " " <<id << " " << code << " " <<maxDelivery << endl;

            Reservoir *r = new Reservoir(reservoir,municipality,id,code,maxDelivery);
            reservoirs_.insert({code,r});
            graph_.addVertex(id,code);
        }

    } else cout << "Could not open the file\n";
}


void DataManip::readPipesL() {
    ifstream in("../Project1LargeDataSet/Pipes.csv");
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

            if (direction == 1){
                graph_.addEdge(service_point_a, service_point_b, capacity);
            }
            else{
                graph_.addEdge(service_point_a, service_point_b, capacity);
                graph_.addEdge(service_point_b, service_point_a, capacity);
            }
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



//Edmonds
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

void DataManip::normalizeGraph() {    //esta a mudar no grafo original

    graph_.addVertex(0, "SS"); // super source
    graph_.addVertex(-1, "SSK"); //super sink

    for (auto reser: getReservoirs()){
        graph_.addEdge("SS",reser.second->getCode(), INF);
    }

    for (auto city: getCitiesC()){
        graph_.addEdge(city.second->getCode(),"SSK", INF);
    }
}

void DataManip::testAndVisit(queue<Vertex *> &q, Edge *e, Vertex *w, double residual) {

    if (! w->isVisited() && residual > 0) {
// Mark 'w' as visited, set the path through which it was reached, and enqueue it
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

bool DataManip::findAugmentingPath(Vertex *s, Vertex *t) {

    for(auto v : graph_.getVertexSet()) {
        v.second->setVisited(false);
    }

    s->setVisited(true);
    queue<Vertex*> q;
    q.push(s);

    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
// Process outgoing edges
        for(auto edj: v->getAdj()) {
            testAndVisit(q, edj, edj->getDest(), edj->getCapacity() - edj->getFlow());
        }
// Process incoming edges
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}

double DataManip::findMinResidualAlongPath(Vertex *s, Vertex *t) {

    unsigned int f = INF;
// Traverse the augmenting path to find the minimum residual capacity
    for (auto v = t; v != s; ) {
        auto edg = v->getPath();
        if (edg->getDest() == v) {
            f = min(f, edg->getCapacity() - edg->getFlow());
            v = edg->getOrig();
        }
        else {
            f = min(f, edg->getFlow());
            v = edg->getDest();
        }
    }
// Return the minimum residual capacity
    return f;
}

void DataManip::augmentFlowAlongPath(Vertex *s, Vertex *t, double f) {

    // Traverse the augmenting path and update the flow values accordingly
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

unsigned int DataManip::maxFlowEdmonds(string cityNameOrCode) {

    string cityCode = verefyCityCode(cityNameOrCode);  //tirar
    normalizeGraph();

    Vertex* s = graph_.findVertex("SS");
    Vertex* t = graph_.findVertex("SSK");

    /*if (s == nullptr || t == nullptr || s == t) {        // verificar se é preciso msm
        throw std::logic_error("Invalid source and/or target vertex");
    }*/

    for (auto vertex : graph_.getVertexSet()) {
        for (auto e: vertex.second->getAdj()) {
            e->setFlow(0);
        }
    }

    while( findAugmentingPath(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }


    // provisorio
    int soma = 0;
    for (auto edg: graph_.getVertexSet()["SSK"]->getIncoming()){
        soma += edg->getFlow();
    }
    return soma;
}


