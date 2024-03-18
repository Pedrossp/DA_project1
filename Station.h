#ifndef DA_PROJECT1_STATION_H
#define DA_PROJECT1_STATION_H

#include <string>

using namespace std;
class Station {
private:
    unsigned int id_;
    string code_;

public:
    Station(unsigned int id,string& code);
    unsigned int getId();
    string getCode();

    void setId(unsigned int id);
    void setCode(string code);
};


#endif //DA_PROJECT1_STATION_H
