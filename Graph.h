
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

    vector<Edge*> adj;    // *
    vector<Edge*> incoming;
    unsigned int id;
    string code;
    bool visited;
    bool processing;
    unsigned indegree;
    Edge* path;


public:
    Vertex(unsigned int id,string code);

    vector<Edge*> &getAdj();   // *
    vector<Edge*> &getIncoming();
    unsigned int getId();
    string getCode();
    Edge* getPath();

    bool isVisited();

    void setId(unsigned int id);
    void setCode(string code);
    void setVisited(bool visited);
    void setPath(Edge* edj);

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
    Vertex* orig;
    unsigned int capacity;
    unsigned int flow;

public:
    Edge(Vertex* o, Vertex* d , unsigned int capacity);

    Vertex* getDest() const;
    Vertex* getOrig() const;
    unsigned int getCapacity() const;
    unsigned int getFlow();

    void setFlow(unsigned int flow_);

};

#endif //DA_PROJECT1_GRAPH_H
