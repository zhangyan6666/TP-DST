#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include "DagGet.h"
#include "DagGet.cpp"
#include "Vertex.cpp"
#include "Vertex.h"
#include <fstream>
const char *file[1]={
        "/Users/haiyanzhang/desktop/datasets/input.txt"
     //   "/Users/haiyanzhang/desktop/datasets/email-EuAll.txt"
};

int main() {
    Graph g;
    FILE *f;

    for(int k =0; k < 1; k++)
    {
        ifstream ib(file[k],ios::in);

        Graph g(ib);

    //    g.printGraph();

        DagWrapper dw(g);

        dw.printStatistics();

        for (auto it = g.vertices.begin(); it != g.vertices.end(); ++it) {
            Vertex& v = it->second;
            cout << v.id << "scc is :"<< dw.getScc(v.id);
            cout << endl;
        }



    }

    return 0;
}