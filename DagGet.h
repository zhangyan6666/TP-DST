//
// Created by HAI YAN ZHANG on 2023/3/15.
//

#ifndef TP_DST_DAGGET_H
#define TP_DST_DAGGET_H
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "Vertex.h"
#include "GraphUpdateObservable.h"
#include "Graph.h"

class Grail;

using namespace std;

typedef unordered_map<int, int > MyMap;
typedef unordered_set<int> MySet;

class DagWrapper : public Graph {
private:
    void constructDag();
    void tarjan(int);
    MyMap sccmap;

    // some containers that are defined as class members to avoid
    // passing as arguments
    MyMap high;
    MyMap low;
    MySet inStack;
    MyMap visited;
    stack<int> nodeStack;
    queue<int> nodeQueue;
    int _tIndex;
    int opCnt;

public:
    DagWrapper(Graph& org);
    //	DagWrapper();

    Graph& orig;
    MyMap csize;

    vector<int> templist;
    //	EdgeList tellist;
    set<int> roots;
    int nextNumber;
    int dagsize;

    int getNextId();
    int dagSize();
    int dagSize(int);
    int getNodeSize(int index);
    int getScc(int index);
    int getSccOld(int index);
    void writeMap();
    void printStatistics();

    int addDagEdge(int,int,int);
    int removeDagEdge(int,int);

    void insertEdge(int, int, Grail*);
    void updateDagAfterMerge(int&, vector<int>&);
    int mergeComponents(int src, int trg, vector<int>& list, int & center, Grail* gr);

    void deleteEdge(int, int, Grail*);
    void updateDagEdgesAfterSplit(int&, MySet&);
    int extractComponents(int , int , int , MySet& );
    void formComponentDuringSplit(int, int, MySet&);

    void removeNode(int);

    Vertex& operator[](int index);
    Vertex& getVertex(int index);
    EdgeList& getOutEdges(int index, EdgeList&);
    EdgeList& getInEdges(int index, EdgeList&);
    EdgeList& getOutEdgesFast(int index);
    EdgeList& getInEdgesFast(int index);

    vector<int> edgeAdded(int,int);
    vector<int> edgeDeleted(int, int);
    virtual ~DagWrapper();
};


#endif //TP_DST_DAGGET_H
