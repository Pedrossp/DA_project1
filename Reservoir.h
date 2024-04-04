/**
 * @file Reservoir.h
 * @brief Definition of reservoir class.
 */
#ifndef DA_PROJECT1_RESERVOIR_H
#define DA_PROJECT1_RESERVOIR_H

#include <string>

using namespace std;

/**
 * @brief Reservoir class representing a water reservoir.
 */
class Reservoir {
private:
    string name_;
    string municipality_;
    unsigned int id_;
    string code_;
    unsigned int maxDelivery_;

public:

    /**
     * @brief Constructor for Reservoir class.
     *
     * Initializes a Reservoir object with the given parameters.
     *
     * @param name The name of the reservoir.
     * @param municipality The municipality where the reservoir is located.
     * @param id The unique identifier of the reservoir.
     * @param code The code associated with the reservoir.
     * @param maxDelivery The maximum delivery capacity of the reservoir.
     */
    Reservoir(string& name,string& municipality,unsigned int id,string& code,unsigned int maxDelivery);

    /**
     * @brief Get the name of the reservoir.
     *
     * @return The name of the reservoir.
     */
    string getName();

    /**
     * @brief Get the municipality where the reservoir is located.
     *
     * @return The municipality where the reservoir is located.
     */
    string getMunicipality();

    /**
     * @brief Get the unique identifier of the reservoir.
     *
     * @return The unique identifier of the reservoir.
     */
    unsigned int getId();

    /**
     * @brief Get the code associated with the reservoir.
     *
     * @return The code associated with the reservoir.
     */
    string getCode();

    /**
     * @brief Get the maximum delivery capacity of the reservoir.
     *
     * @return The maximum delivery capacity of the reservoir.
     */
    unsigned int getMaxDelivery();

    /**
     * @brief Set the name of the reservoir.
     *
     * @param name The new name of the reservoir.
     */
    void setName(string name);

    /**
     * @brief Set the municipality where the reservoir is located.
     *
     * @param municipality The new municipality where the reservoir is located.
     */
    void setMunicipality(string municipality);

    /**
     * @brief Set the unique identifier of the reservoir.
     *
     * @param id The new unique identifier of the reservoir.
     */
    void setId(unsigned int id);

    /**
    * @brief Set the code associated with the reservoir.
    *
    * @param code The new code associated with the reservoir.
    */
    void setCode(string code);

    /**
     * @brief Set the maximum delivery capacity of the reservoir.
     *
     * @param maxDelivery The new maximum delivery capacity of the reservoir.
     */
    void setMaxDelivery(unsigned int maxDelivery);
};


#endif //DA_PROJECT1_RESERVOIR_H
