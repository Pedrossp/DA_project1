
#ifndef DA_PROJECT1_GRAPH_H
#define DA_PROJECT1_GRAPH_H

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
class Edge;
class Graph;
class Vertex;

class Vertex{

    vector<Edge> adj;
    unsigned int id;
    string code;
    bool visited;
    bool processing;
    unsigned indegree;


public:
    Vertex(unsigned int id,string code);

    vector<Edge> &getAdj();
    unsigned int getId();
    string getCode();
    bool isVisited();

    void setId(unsigned int id);
    void setCode(string code);
    void setVisited(bool visited);

    void addEdge(Vertex* dest, unsigned int capacity);

};
class Graph {
    unordered_map< string , Vertex* > vertexSet; // unordered map faz sentido ? esperem pelo próximo episódio
public:
    Vertex* findVertex(const string& code) const;
    bool addVertex(unsigned int id,string code);
    bool addEdge(const string &sourceCode,const string &destCode, unsigned int capacity);
    unordered_map<string, Vertex*> getVertexSet();
};

class Edge{
    Vertex* dest;
    unsigned int capacity;

public:
    Edge(Vertex* d , unsigned int capacity);

    Vertex* getDest() const;
    unsigned int getCapacity() const;

};

#endif //DA_PROJECT1_GRAPH_H
