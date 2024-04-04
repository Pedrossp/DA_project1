/**
 * @file Station.h
 * @brief Definition of Station class.
 */
#ifndef DA_PROJECT1_STATION_H
#define DA_PROJECT1_STATION_H

#include <string>

using namespace std;

/**
 * @class Station
 * @brief Represents a station in a transportation system.
 */
class Station {
private:
    unsigned int id_;
    string code_;

public:

    /**
     * @brief Constructor for Station class.
     * @param id Identifier of the station.
     * @param code Code associated with the station.
     */
    Station(unsigned int id,string& code);

    /**
     * @brief Get the identifier of the station.
     * @return Identifier of the station.
     */
    unsigned int getId();

    /**
     * @brief Get the code associated with the station.
     * @return Code associated with the station.
     */
    string getCode();

    /**
     * @brief Set the identifier of the station.
     * @param id Identifier to be set.
     */
    void setId(unsigned int id);

    /**
     * @brief Set the code associated with the station.
     * @param code Code to be set.
     */
    void setCode(string code);
};


#endif //DA_PROJECT1_STATION_H
