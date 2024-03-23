#ifndef DA_PROJECT1_CITY_H
#define DA_PROJECT1_CITY_H

#include <string>

using namespace std;

class City {

private:
    string name_;
    string code_;
    string population_;
    unsigned int id_;
    double demand_;

public:
    City(string& name, string& code, unsigned int id, string population, double demand);

    string getName();
    string getCode();
    string getPopulation();
    unsigned int getId();
    double getDemand();

    void setName(string& name);
    void setCode(string& code);
    void setPopulation(string& population);
    void setId(unsigned int id);
    void setDemand(double demand);
};


#endif //DA_PROJECT1_CITY_H
