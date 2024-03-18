#include "City.h"

string City::getCode() {return code_;}

float City::getDemand() {return demand_;}

unsigned int City::getId() {return id_;}

string City::getName() {return name_;}

int City::getPopulation() {return population_;}

void City::setCode(std::string &code) { code_ = code;}

void City::setDemand(float demand) { demand_ = demand;}

void City::setId(unsigned int id) { id_ = id;}

void City::setName(std::string &name) { name_ = name;}

void City::setPopulation(unsigned int population) { population_ = population;}