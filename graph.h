//
// Created by HAI YAN ZHANG on 2023/3/14.
//

#ifndef TP_DST_GRAPH_H
#define TP_DST_GRAPH_H

#include <unordered_map>
#include <iostream>
#include "Vertex.h"
#include "GraphUpdateObservable.h"
using namespace std;

typedef unordered_map<int, Vertex> VertexList;

class Graph : public GraphUpdateObservable {
private:


public:
    Graph();
Graph(int);
Graph(VertexList&);
Graph(istream&);

VertexList vertices;
int vsize;
int edgeCount;
int MAX_ID;
int MIN_ID;


void readGraph(istream&);
void printGraph();
void writeGraph(ostream&);
void writeGra(ostream&);
void insertEdge(int sid, int tid);
void deleteEdge(int sid, int tid);
void insertNode(int sid, vector<int>&, vector<int>&);
void deleteNode(int sid);

Vertex& operator[](int index);
Vertex& getVertex(int index);

int size();
int randomNodeSelection();
int randomNodeSelection2();
int edgeSize();
virtual ~Graph();

private:
    void strTrimRight(string& );
};

#endif /* TP_DST_GRAPH_H */
