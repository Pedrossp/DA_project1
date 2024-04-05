#ifndef DA_PROJECT1_DATAMANIP_H
#define DA_PROJECT1_DATAMANIP_H

#include <cmath>
#include <unordered_map>
#include <string>
#include <limits>
#include <queue>
#include <algorithm>
#include "Graph.h"
#include "City.h"
#include "Station.h"
#include "Reservoir.h"

using namespace std;


class DataManip {

    Graph graph_;
    map<string, City*> citiesC_;
    map<string, Station*> stations_;
    map<string, Reservoir*> reservoirs_;
    map<string, City*> citiesN_;

public:

    /**
    * @brief Constructor for DataManip class.
    *
    * This constructor initializes a DataManip object.
    */
    DataManip();

    /**
     * @brief Read cities data from a CSV file and populate the data structures.
     */
    void readCities();

    /**
     * @brief Read stations data from a CSV file and populate the data structures.
     */
    void readStations();

    /**
     * @brief Read reservoirs data from a CSV file and populate the data structures.
     */
    void readReservoirs();

    /**
     * @brief Read pipes data from a CSV file and populate the data structures.
     */
    void readPipes();

    /**
     * @brief Read cities data from a CSV file in the large data set and populate the data structures.
     */
    void readCitiesL();

    /**
     * @brief Read stations data from a CSV file in the large data set and populate the data structures.
     */
    void readStationsL();

    /**
     * @brief Read reservoirs data from a CSV file in the large data set and populate the data structures.
     */
    void readReservoirsL();

    /**
     * @brief Read pipes data from a CSV file in the large data set and populate the data structures.
     */
    void readPipesL();

    /**
     * @brief Get the map of cities by code.
     *
     * @return Map of cities by code.
     */
    map<string, City*> getCitiesC();

    /**
     * @brief Get the map of cities by name.
     *
     * @return Map of cities by name.
     */
    map<string, City*> getCitiesN();

    /**
     * @brief Get the map of stations.
     *
     * @return Map of stations.
     */
    map<string, Station*> getStations();

    /**
     * @brief Get the map of reservoirs.
     *
     * @return Map of reservoirs.
     */
    map<string, Reservoir*> getReservoirs();

    /**
     * @brief Get the graph representing connections between cities, stations, and reservoirs.
     *
     * @return Graph representing connections.
     */
    Graph getGraph();

    //edmonds karp

    /**
    * @brief Verify city code or name.
    *
    * This function verifies if the given cityNameOrCode is a code or a name of the city.
    * If it's the name its corresponding code is returned.
    * If it's the code, input cityNameOrCode is returned unchanged.
    *
    * @param cityNameOrCode The name or code of the city to verify.
    * @return The city code.
    *
    */
    string  verifyCityCode(string cityCodeOrName);

    /**
    * @brief Normalize the graph.
    *
    * This function modifies the original graph by adding additional vertices and edges
    * to create a normalized version of the graph for certain operations or analyses.
    *
    * Specifically, it adds a super source vertex ("SS") and a super sink vertex ("SSK") to the graph,
    * and connects the super source vertex to each reservoir with an edge representing its maximum delivery capacity,
    * and connects each city to the super sink vertex with an edge representing its demand.
    *
    * @complexity The overall time complexity of this function is O(r + c).
    */
    void normalizeGraph(); //adicionar super source

    /**
    * @brief Find an augmenting path from source 's' to sink 't' in the graph.
    *
    * This function searches for an augmenting path from source vertex 's' to sink vertex 't' in the graph using BFS.
    * It marks vertices as visited during the search process and utilizes the 'testAndVisit' function to enqueue vertices to the BFS queue.
    *
    * @param s The source vertex of the augmenting path.
    * @param t The sink vertex of the augmenting path.
    * @return True if an augmenting path is found from 's' to 't', otherwise false.
    *
    *
    * @complexity The time complexity of this function depends on the size of the graph and the efficiency of the 'testAndVisit' function.
    *       Let n be the number of vertices and m be the number of edges in the graph.
    *       The function performs a BFS traversal from the source vertex 's' to the sink vertex 't', visiting each vertex and edge at most once.
    *       Therefore, the overall time complexity is O(n + m).
    */
    bool findAugmentingPath(Vertex *s, Vertex *t);

    /**
    * @brief Test and visit a vertex.
    *
    * This function tests whether the vertex 'w' has been visited before and if the residual capacity of the edge 'e' to 'w' is greater than 0.
    * If 'w' has not been visited and the residual capacity is positive, 'w' is marked as visited, its path through which it was reached is set, and it is enqueued.
    *
    * @param q The queue to enqueue 'w' if it meets the conditions.
    * @param e The edge through which 'w' is reached.
    * @param w The vertex to test and visit.
    * @param residual The residual capacity of the edge 'e' to 'w'.
    *
    * @complexity The time complexity of this function is O(1) as it performs a constant number of operations regardless of the input size.
    */
    void testAndVisit(queue<Vertex*> &q, Edge *e, Vertex *w, double residual);

    /**
    * @brief Find the minimum residual capacity along an augmenting path from source 's' to sink 't'.
    *
    * This function traverses the augmenting path from sink vertex 't' to source vertex 's' to find the minimum residual capacity.
    * It iterates through the edges along the path and calculates the minimum residual capacity.
    *
    * @param s The source vertex of the augmenting path.
    * @param t The sink vertex of the augmenting path.
    * @return The minimum residual capacity along the augmenting path.
    *
    *
    * @complexity Let k be the length of the augmenting path.
    *       The function iterates through the edges along the path once, performing constant-time operations at each step.
    *       Therefore, the overall time complexity is O(k), where k is the length of the augmenting path.
    */
    double findMinResidualAlongPath(Vertex* s, Vertex* t);

    /**
    * @brief Augment flow along an augmenting path from source 's' to sink 't'.
    *
    * This function traverses the augmenting path from sink vertex 't' to source vertex 's' and updates the flow values of the edges accordingly.
    * It iterates through the edges along the path and adjusts the flow based on the direction of the edge.
    *
    * @param s The source vertex of the augmenting path.
    * @param t The sink vertex of the augmenting path.
    * @param f The amount by which to augment the flow.
    *
    * @complexity Let k be the length of the augmenting path.
    *             The function iterates through the edges along the path once, performing constant-time operations at each step.
    *             Therefore, the overall time complexity is O(k), where k is the length of the augmenting path.
    */
    void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);


    /**
    * @brief Calculate the maximum flow in the graph using the Edmonds-Karp algorithm.
    *
    * This function computes the maximum flow in the graph using the Edmonds-Karp algorithm.
    * It first normalizes the graph by adding a super source and a super sink, then finds augmenting paths
    * from the super source to the super sink repeatedly until no more augmenting paths exist.
    * Along each augmenting path, it calculates the minimum residual capacity and augments the flow accordingly.
    * After computing the maximum flow, it performs additional processing, such as updating flow values and removing
    * the super source and super sink vertices from the graph.
    *
    * @complexity The time complexity of this function is O(V * E^2), where V is the number of vertices and E is the number of edges in the graph.
    *       This complexity arises from the repeated execution of BFS to find augmenting paths, where each BFS has a complexity of O(V + E),
    *       and the maximum number of iterations of BFS is O(E) in the worst case.
    */
    void maxFlowEdmonds();

    /**
    * @brief Calculate and display the maximum flow of water in the network, either total or for a specific city.
    *
    * This function computes the maximum flow of water in the network using the Edmonds-Karp algorithm and then displays the result.
    * It allows the user to choose between displaying the total maximum water flow for all cities or the maximum water flow for a specific city.
    *
    * @param choose An integer indicating the user's choice: 0 for total maximum water flow, 1 for maximum water flow for a specific city.
    * @param cityCodeOrName A string representing the city code or name for which the maximum water flow is to be calculated (relevant only when choose is 1).
    *
    */
    void maxFLowTotalCity(int choose, string cityCodeOrName);


    /**
    * @brief Calculate and display the deficit of water for each city.
    *
    * This function computes the deficit of water for each city in the network by subtracting the actual flow of water
    * from the city's demand. It then displays the deficit for each city along with its demand and actual flow.
    *
    * @complexity The overall time complexity of this function is O(n), where n is the number of cities in the network.
    */
    void getDeficit();


    /**
    * @brief Calculate and display the average difference, maximum difference, and variance between edge capacities and flows.
    *
    * This function computes the average difference, maximum difference, and variance between the capacities and flows of all edges in the network.
    * It then displays these statistical measures.
    *
    * @complexity The time complexity of this function depends on the number of vertices and edges in the graph.
    *       The function iterates through all edges in the graph to calculate the differences between their capacities and flows, resulting in a linear-time operation.
    *       After computing the differences, the function calculates the average and variance, which also have linear-time complexity.
    *       Therefore, the overall time complexity of this function is O(V * E), where V is the number of vertices and E is the number of edges in the graph.
    */
    void getAverageDifference();

    /**
    * @brief Balance the flow across edges in the graph to ensure that the total flow into each vertex matches its total capacity.
    *
    * This function iterates over all vertices in the graph and adjusts the flow across edges to balance it with the total capacity of the vertex.
    * If a vertex represents a reservoir (identified by starting with "R"), it ensures that the total flow into the reservoir does not exceed its maximum delivery capacity.
    *
    * @complexity The time complexity of this function depends on the number of vertices and edges in the graph.
    *       The function iterates through all vertices and their adjacent edges, resulting in a linear-time operation with respect to the number of vertices and edges.
    *       Within the nested loops, it performs calculations and adjustments with constant-time complexity.
    *       Therefore, the overall time complexity of this function is O(V * E), where V is the number of vertices and E is the number of edges in the graph.
    */
    void BalanceFlow();


    /**
    * @brief Verify city code or name.
    *
    * This function verifies if the given cityNameOrCode is a code or a name of the city.
    * If it's the name, its corresponding code is returned.
    * If it's the code, input cityNameOrCode is returned unchanged.
    *
    * @param cityNameOrCode The name or code of the city to verify.
    * @return The city code. If the input is already a code, it is returned unchanged.
    *
    *
    */
    string verifyReservoirCode(string reservoirNameOrCode);

    void stationRemoved(vector<string> sCodes);

    /**
    * @brief Simulate the removal of reservoirs from commission.
    *
    * This function simulates the effect of removing reservoirs from commission by setting their maximum delivery to zero.
    * It recalculates the maximum flow in the network after adjusting the reservoirs' maximum delivery values.
    * Then, it identifies cities affected by the removal based on the decrease in flow compared to the previous flow values.
    * Finally, it restores the original maximum delivery values of the removed reservoirs.
    *
    * @param vec A vector containing the codes or names of reservoirs to be removed from commission.
    *
    * @complexity The time complexity of this function depends on the number of cities and reservoirs in the respective maps.
    *       The function performs two iterations over the citiesC_ map to store and restore flow values, resulting in linear-time complexity with respect to the number of cities.
    *       It also performs operations on reservoirs, which have a constant-time complexity within the loop, resulting in linear-time complexity with respect to the number of reservoirs.
    *       Therefore, the overall time complexity of this function is O(V * E^2).
    */
    void reservoirOutOfCommission(vector<string> codeOrName);

    /**
    * @brief Simulate the removal of pipelines.
    *
    * This function simulates the effect of removing pipelines by setting the capacities of specified edges to zero.
    * It recalculates the maximum flow in the network after adjusting the edge capacities.
    * Then, it identifies cities affected by the removal based on the decrease in flow compared to the previous flow values.
    * Finally, it restores the original capacities of the removed edges.
    *
    * @param vector A vector containing pairs of strings representing the endpoints of the pipelines to be removed.
    *               Each pair represents a pipeline to be removed.
    *
    * @complexity The time complexity of this function depends on the number of cities and edges in the respective maps.
    *       The function performs an iteration over the citiesC_ map to store and restore flow values, resulting in linear-time complexity with respect to the number of cities.
    *       It also performs operations on edges connected to the removed pipelines, which have a constant-time complexity within the loop, resulting in linear-time complexity with respect to the number of edges affected.
    *       Therefore, the overall time complexity of this function is O(V * E^2).
    */
    void pipelineRemoved(vector<pair<string, string>> p );

    //Auxiliar

    /**
    * @brief Calculate and set the total flow of water into each city.
    *
    * This function iterates over all cities in the network and calculates the total flow of water into each city by summing
    * the flow across all incoming edges. It then sets the calculated total flow value for each city.
    *
    * @note This function assumes that each city in the network is represented by a vertex in the graph_ member variable.
    */
    void citiesFlow();



};


#endif //DA_PROJECT1_DATAMANIP_H
