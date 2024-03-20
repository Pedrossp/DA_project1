#include "Graph.h"

//Vertex

void Vertex::addEdge(Vertex *dest, unsigned int capacity) {
    adj.push_back(Edge(dest,capacity));
}

//constructer
Vertex::Vertex(unsigned int id, string code) {
    this->id = id;
    this->code = code;
}

// getters
unsigned int Vertex::getId() {
    return id;
}

string Vertex::getCode() {
    return code;
}

bool Vertex::isVisited() {
    return visited;
}

//setters
void Vertex::setId(unsigned int id) {
    this->id = id;
}

void Vertex::setCode(string code) {
    this->code = code;
}

void Vertex::setVisited(bool visited) {
    this->visited= visited;
}

vector<Edge> &Vertex::getAdj() {
    return adj;
}

Vertex *Graph::findVertex(const string &code) const {
    auto it = vertexSet.find(code);

    if(it!= vertexSet.end()){
        return it->second;
    }
    return nullptr;
}

bool Graph::addVertex(unsigned int id, string code) {
    if(findVertex(code)!= nullptr){
        return false;
    }
    vertexSet.insert({code,new Vertex(id,code)});
    return true;
}

bool Graph::addEdge(const string &sourceCode, const string &destCode, unsigned int capacity) {
    auto v1 = findVertex(sourceCode);
    auto v2 = findVertex(destCode);
    if(v1 == nullptr|| v2 == nullptr){
        return false;
    }
    v1->addEdge(v2,capacity);
    return true;
}

unordered_map<string, Vertex *> Graph::getVertexSet() {
    return vertexSet;
}

//Edge
Edge::Edge(Vertex *d, unsigned int capacity) {
    this->dest= d;
    this->capacity= capacity;
}

Vertex *Edge::getDest() const {
    return dest;
}

unsigned int Edge::getCapacity() const {
    return capacity;
}

