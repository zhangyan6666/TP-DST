//
// Created by HAI YAN ZHANG on 2023/3/15.
//

#ifndef TP_DST_VERTEX_H
#define TP_DST_VERTEX_H

#include <unordered_map>
#include <iostream>
using namespace std;
typedef unordered_map<int,int> EdgeList;

class Vertex {

public:
    int id;
    EdgeList inList;
    EdgeList outList;
    EdgeList& outEdges();
    EdgeList& inEdges();
    int outDegree();
    int inDegree();
    int degree();
    int hasEdge(int end);
    void addOutEdge(int tid);
    void addInEdge(int sid);
    void eraseOutEdge(int x);

    Vertex(int);
    Vertex();
    virtual ~Vertex();
};


#endif //TP_DST_VERTEX_H
