#ifndef DA_PROJECT1_CITY_H
#define DA_PROJECT1_CITY_H

#include <string>

using namespace std;

class City {

private:
    string name_;
    string code_;
    unsigned int id_;
    unsigned int population_;
    float demand_;

public:
    City(string& name, string& code, unsigned int id, unsigned int population, float demand);

    string getName();
    string getCode();
    unsigned int getId();
    int getPopulation();
    float getDemand();

    void setName(string& name);
    void setCode(string& code);
    void setId(unsigned int id);
    void setPopulation(unsigned int population);
    void setDemand(float demand);
};


#endif //DA_PROJECT1_CITY_H
