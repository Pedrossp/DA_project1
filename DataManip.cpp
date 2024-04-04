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

map<string, City *> DataManip::getCitiesC() {
    return citiesC_;
}

map<string, City *> DataManip::getCitiesN() {
    return citiesN_;
}

map<string, Station *> DataManip::getStations() {
    return stations_;
}

map<string, Reservoir *> DataManip::getReservoirs() {
    return reservoirs_;
}

Graph DataManip::getGraph() {
    return graph_;
}



//Edmonds
string DataManip::verifyCityCode(string cityNameOrCode) {

    string cityCode = "";

    for (auto city: citiesC_){
        if (city.second->getName() == cityNameOrCode){
            cityCode = city.first;
            return cityCode;
        }
    }

    if (cityCode == ""){
        return cityNameOrCode;
    }
}

void DataManip::normalizeGraph() {    //esta a mudar no grafo original

    graph_.addVertex(0, "SS"); // super source
    graph_.addVertex(-1, "SSK"); //super sink

    for (auto reser: getReservoirs()){
        graph_.addEdge("SS",reser.first, reser.second->getMaxDelivery());
    }

    for (auto city: getCitiesC()){
        graph_.addEdge(city.first,"SSK", city.second->getDemand());
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

void DataManip::maxFlowEdmonds() {

    normalizeGraph();

    Vertex* s = graph_.findVertex("SS");
    Vertex* t = graph_.findVertex("SSK");

    if (s == nullptr || t == nullptr || s == t) {        // verificar se é preciso msm
        throw std::logic_error("Invalid source and/or target vertex");
    }

    for (auto vertex : graph_.getVertexSet()) {
        for (auto e: vertex.second->getAdj()) {
            e->setFlow(0);
        }
    }

    while(findAugmentingPath(s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }

    citiesFlow();

    graph_.removeVertex("SS");
    graph_.removeVertex("SSK");
}

void DataManip::maxFLowTotalCity(int choose, string cityCodeOrName) {

    maxFlowEdmonds();

    switch (choose) {
        case 0: {   //total

            cout << "Maximum amount of water per cities:" << endl << endl;
            int sumT = 0;

            for(auto city: citiesC_){
                int sumC =0;
                for(auto edge : graph_.getVertexSet()[city.first]->getIncoming()){
                        sumT+=edge->getFlow();
                        sumC+= edge->getFlow();
                }
                cout << city.first << "(" << citiesC_[city.first]->getName() << "): " << sumC << " m³/sec" << endl;
            }
            cout << endl << "Total maximum water flow is " << sumT << " m³/sec."<< endl;
            break;
        }
        case 1: {
            string cityCode = verifyCityCode(cityCodeOrName);
            int sumC=0;
            for(auto edge:graph_.getVertexSet()[cityCode]->getIncoming()){
                sumC+= edge->getFlow();
            }
            cout << "Maximum amount of water that reaches " << citiesC_[cityCode]->getName() << " is " <<sumC << " m³/sec." << endl;
            break;
        }
    }
    cout << endl << endl;
}

void DataManip::getDeficit() {

    maxFlowEdmonds();
    cout << "The deficit of water per city:" << endl << endl;

    for (auto city: citiesC_) {

        int demand = city.second->getDemand();
        int flow = city.second->getFlow();
        int deficit = demand - flow;

        if (deficit > 0){
            cout << city.first << "(" << city.second->getName() << "): " << deficit << " m³/sec" << endl
                 << "  (Demand: " << demand << ", Actual flow: " << flow << ")" << endl << endl;
        }
    }
}


void DataManip::getAverageDifference() {
    int count = 0;
    int sum = 0;
    int maxDiff = 0;
    int diff = 0;
    vector<int> differences; // Armazenar as diferenças

    for (auto vertex : graph_.getVertexSet()) {
        for (auto edge : vertex.second->getAdj()) {
            count++;
            diff = edge->getCapacity() - edge->getFlow();
            differences.push_back(diff); // Armazenar a diferença
            sum += diff;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
    }

    int average = sum / count;
    int variance = 0;

    for (int d : differences) {
        variance += pow(d - average, 2); // Acumular as diferenças ao quadrado
    }

    variance /= count; // Dividir pela contagem total de diferenças

    cout << endl << "Average difference is " << average << endl;
    cout << "Max difference is " << maxDiff << endl;
    cout << "Variance is " << variance<<endl;
}

void DataManip::BalanceFlow() { // valores do fluxo podem aumentar 1 ou 2 em alguns pq???
    for(auto v: graph_.getVertexSet()) {
        double totalCapacity = 0.0;
        double totalFlow = 0.0;

        for(auto e: v.second->getAdj()) {
            totalCapacity += e->getCapacity();
            totalFlow += e->getFlow();
        }

        double diff = totalCapacity - totalFlow; // o que sobrou do vertice

        for(auto e : v.second->getAdj()) {
            double proportion = (totalCapacity != 0) ? e->getCapacity() / totalCapacity : 0.0;
            double additionalFlow = diff * proportion;

            if(additionalFlow > (e->getCapacity() - e->getFlow())) {
                additionalFlow = e->getCapacity() - e->getFlow();
            }

            e->setFlow(e->getFlow() + additionalFlow);

            if(v.first.substr(0, 1) == "R") {
                unsigned int maxDelivery = reservoirs_[v.first]->getMaxDelivery();
                double totalReservoirFlow = 0.0;
                int numEdges = 0;

                // Calcular totalFlow apenas dos vértices adjacentes ao reservatório
                for(auto edge : v.second->getAdj()) {
                    totalReservoirFlow += edge->getFlow();
                    numEdges++;
                }

                // Verificar se totalFlow excede maxDelivery
                if(totalReservoirFlow > maxDelivery) {
                    double excessFlow = totalReservoirFlow - maxDelivery;
                    double reduceProportion = excessFlow / numEdges;

                    // Aplicar o fator de redução apenas aos vértices adjacentes ao reservatório
                    for(auto edge : v.second->getAdj()) {
                        edge->setFlow(edge->getFlow() - reduceProportion);
                    }
                }
            }
        }
    }
}

void DataManip::citiesFlow() {

    for (auto city: citiesC_){
        int sumC = 0;
        for (auto edge: graph_.getVertexSet()[city.first]->getIncoming()){
            sumC += edge->getFlow();
        }
        city.second->setFlow(sumC);
    }
}

string DataManip::verifyReservoirCode(string reservoirNameOrCode) {

    string reserCode = "";

    for (auto reser: reservoirs_){
        if (reser.second->getName() == reservoirNameOrCode){
            reserCode = reser.first;
            return reserCode;
        }
    }

    if (reserCode == ""){
        return reservoirNameOrCode;
    }
}

void DataManip::reservoirOutOfCommission(vector<string> vec) { //3.1

    maxFlowEdmonds();
    map<string, int>  oldFlowMap;
    map<Reservoir*,unsigned int > oldMaxDelivery;

    for (auto city: citiesC_){
        oldFlowMap.insert({city.first, city.second->getFlow()});
    }

    for(auto codeOrName : vec ) {
        string code = verifyReservoirCode(codeOrName);
        unsigned int oldDelivery = reservoirs_[code]->getMaxDelivery();
        oldMaxDelivery.insert({reservoirs_[code],oldDelivery});
        reservoirs_[code]->setMaxDelivery(0);
    }


    maxFlowEdmonds();

    cout << "Affected cities by the removal of ";

    auto it = vec.begin();
    for(auto codeOrName : vec){
        cout << codeOrName;
        if(++it != vec.end() ){
            cout << ", ";
        }
    }

    cout << ": " << endl << endl;
    bool affected = false;

    for (auto city: citiesC_){

        int oldFlowC = oldFlowMap[city.first];
        int newFlowC = city.second->getFlow();

        if ( oldFlowC > newFlowC){
            affected = true;
            cout << city.first << "(" << city.second->getName() << "): " << newFlowC << "/" << oldFlowC << " (new flow/old flow)" << endl;
            city.second->setFlow(oldFlowC);
        }
    }

    if (!affected){
        cout << "No cities affected." << endl << endl;
    }

    for (auto  r : oldMaxDelivery){
        r.first->setMaxDelivery(r.second);
    }
    cout<<endl<<endl;
}

void DataManip::stationRemoved(vector<string> sCodes) {

    maxFlowEdmonds();
    map<string, int>  oldFlowMap;

    for (auto city: citiesC_){
        oldFlowMap.insert({city.first, city.second->getFlow()});
    }

    map<Edge*,int> edgMap;

    for (auto code: sCodes){

        Vertex *vert = graph_.findVertex(code);
        for ( auto in: vert->getIncoming()){
            edgMap.insert({in, in->getCapacity()});
            in->setCapacity(0);
        }

        for ( auto out: vert->getAdj()){
            edgMap.insert({out, out->getCapacity()});
            out->setCapacity(0);
        }

    }

    maxFlowEdmonds();

    cout << "Affected cities by the removal of ";
    int sCount = sCodes.size();
    int i = 0;

    for(auto code: sCodes){

        cout << code;
        if (++i < sCount){
            cout << ", ";
        }
    }
    cout << ": " << endl << endl;
    bool affected = false;

    for (auto city: citiesC_){

        int oldFlowC = oldFlowMap[city.first];
        int newFlowC = city.second->getFlow();

        if ( oldFlowC > newFlowC){
            affected = true;
            cout << city.first << "(" << city.second->getName() << "): " << newFlowC << "/" << oldFlowC << " (new flow/old flow)" << endl;
            city.second->setFlow(oldFlowC);
        }
    }

    if (!affected){
        cout << "No cities affected." << endl << endl;
    }


    for( auto pair: edgMap){
        Edge* edge = pair.first;
        edge->setCapacity(pair.second);

    }

    cout << endl << endl;
}

void DataManip::pipelineRemoved(vector<pair<string, string>> vector) {
    maxFlowEdmonds();
    map<string, int>  oldFlowMap;
    map<Edge*,int > oldCapacity;
    for (auto city: citiesC_){
        oldFlowMap.insert({city.first, city.second->getFlow()});
    }
    for(auto p: vector){

        Edge* edge =graph_.findEdge(p.first,p.second);
        if(edge!= nullptr) {
            oldCapacity.insert({edge, edge->getCapacity()});
            edge->setCapacity(0);
        }

        Edge* edge1 =graph_.findEdge(p.second,p.first);
        if(edge1!= nullptr) {

            oldCapacity.insert({edge1, edge1->getCapacity()});
            edge1->setCapacity(0);
        }
    }

    maxFlowEdmonds();

    bool affected= false;
    for (auto city: citiesC_){

        int oldFlowC = oldFlowMap[city.first];
        int newFlowC = city.second->getFlow();

        if ( oldFlowC > newFlowC){
            affected = true;
            cout << city.first << "(" << city.second->getName() << "): " << newFlowC << "/" << oldFlowC << " (new flow/old flow)" << endl << endl;
            city.second->setFlow(oldFlowC);
        }
    }

    if (!affected){
        cout << "No cities affected." << endl << endl;
    }

    for(auto e: oldCapacity){
        e.first->setCapacity(e.second);
    }

}

