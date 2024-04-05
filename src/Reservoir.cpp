#include "Reservoir.h"

Reservoir::Reservoir(string &name, string &municipality, unsigned int id, string &code, unsigned int maxDelivery) {
    name_=name;
    municipality_=municipality;
    id_=id;
    code_=code;
    maxDelivery_= maxDelivery;
}

string Reservoir::getName() {
    return name_;
}

string Reservoir::getMunicipality() {
    return municipality_;
}

unsigned int Reservoir::getId() {
    return id_;
}

string Reservoir::getCode() {
    return code_;
}

unsigned int Reservoir::getMaxDelivery() {
    return maxDelivery_;
}

void Reservoir::setName(string name) {
    name_=name;
}

void Reservoir::setMunicipality(string municipality) {
    municipality_=municipality;
}

void Reservoir::setId(unsigned int id) {
    id_=id;
}

void Reservoir::setCode(string code) {
    code_=code;
}

void Reservoir::setMaxDelivery(unsigned int maxDelivery) {
    maxDelivery_= maxDelivery;
}


