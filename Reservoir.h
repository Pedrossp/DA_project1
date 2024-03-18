#ifndef DA_PROJECT1_RESERVOIR_H
#define DA_PROJECT1_RESERVOIR_H

#include <string>

using namespace std;
class Reservoir {
private:
    string name_;
    string municipality_;
    unsigned int id_;
    string code_;
    unsigned int maxDelivery_;

public:
    Reservoir(string& name,string& municipality,unsigned int id,string& code,unsigned int maxDelivery);
    string getName();
    string getMunicipality();
    unsigned int getId();
    string getCode();
    unsigned int getMaxDelivery();

    void setName(string name);
    void setMunicipality(string municipality);
    void setId(unsigned int id);
    void setCode(string code);
    void setMaxDelivery(unsigned int maxDelivery);
};


#endif //DA_PROJECT1_RESERVOIR_H
