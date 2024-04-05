#include "Station.h"

Station::Station(unsigned int id, string &code) {
    id_=id;
    code_=code;
}

unsigned int Station::getId() {
    return id_;
}

string Station::getCode() {
    return code_;
}

void Station::setId(unsigned int id) {
    id_=id;
}

void Station::setCode(string code) {
    code_=code;
}

