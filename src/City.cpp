#include "City.h"

string City::getCode() {return code_;}

string City::getName() {return name_;}

string City::getPopulation() {return population_;}

double City::getDemand() {return demand_;}

unsigned int City::getId() {return id_;}

int City::getFlow() {return flow_;}

void City::setCode(std::string &code) { code_ = code;}

void City::setDemand(double demand) { demand_ = demand;}

void City::setId(unsigned int id) { id_ = id;}

void City::setName(std::string &name) { name_ = name;}

void City::setPopulation(string &population) { population_ = population;}

City::City(string &name, string &code, unsigned int id, string population, double demand) {
    name_ = name;
    code_ = code;
    id_ = id;
    population_ = population;
    demand_ = demand;
}

void City::setFlow(int flow) {
    flow_ = flow;
}
