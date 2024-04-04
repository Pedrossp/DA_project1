/**
 * @file City.h
 * @brief Definition of City class.
 */
#ifndef DA_PROJECT1_CITY_H
#define DA_PROJECT1_CITY_H

#include <string>

using namespace std;
/**
 * @class City
 * @brief Represents a city in a transportation system.
 */
class City {

private:
    string name_;
    string code_;
    string population_;
    unsigned int id_;
    double demand_;
    int flow_;

public:

    /**
     * @brief Constructor for City class.
     * @param name Name of the city.
     * @param code Code associated with the city.
     * @param id Identifier of the city.
     * @param population Population of the city.
     * @param demand Demand of the city.
     */
    City(string& name, string& code, unsigned int id, string population, double demand);

    /**
     * @brief Get the name of the city.
     * @return Name of the city.
     */
    string getName();

    /**
     * @brief Get the code associated with the city.
     * @return Code associated with the city.
     */
    string getCode();

    /**
     * @brief Get the population of the city.
     * @return Population of the city.
     */
    string getPopulation();

    /**
     * @brief Get the identifier of the city.
     * @return Identifier of the city.
     */
    unsigned int getId();

    /**
    * @brief Get the demand of the city.
    * @return Demand of the city.
    */
    double getDemand();

    /**
     * @brief Get the flow of the city.
     * @return Flow of the city.
     */
    int getFlow();

    void setName(string& name);

    /**
     * @brief Set the code associated with the city.
     * @param code Code to be set.
     */
    void setCode(string& code);

    /**
     * @brief Set the population of the city.
     * @param population Population to be set.
     */
    void setPopulation(string& population);

    /**
     * @brief Set the identifier of the city.
     * @param id Identifier to be set.
     */
    void setId(unsigned int id);

    /**
     * @brief Set the demand of the city.
     * @param demand Demand to be set.
     */
    void setDemand(double demand);

    /**
     * @brief Set the flow of the city.
     * @param flow Flow to be set.
     */
    void setFlow(int flow);
};


#endif //DA_PROJECT1_CITY_H
