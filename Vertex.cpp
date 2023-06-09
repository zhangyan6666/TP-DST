//
// Created by HAI YAN ZHANG on 2023/3/15.
//

#include "Vertex.h"
#include <sstream>
using namespace std;

Vertex::Vertex(int Id): id(Id){
}

Vertex::Vertex() {
}

Vertex::~Vertex() {
}

void Vertex::eraseOutEdge(int x){
    outList.erase(x);
}
EdgeList& Vertex::outEdges(){
    return outList;
}
EdgeList& Vertex::inEdges(){
    return inList;
}
int Vertex::outDegree(){
    return outList.size();
}
int Vertex::inDegree(){
    return inList.size();
}
int Vertex::degree(){
    return inList.size()+outList.size();
}
int Vertex::hasEdge(int endNode){
    return outList.find(endNode) != outList.end();
}
void Vertex::addInEdge(int sid){
    inList[sid]++;
}
void Vertex::addOutEdge(int tid){
    outList[tid]++;
}
