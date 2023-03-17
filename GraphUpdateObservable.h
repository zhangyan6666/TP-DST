//
// Created by HAI YAN ZHANG on 2023/3/15.
//

#ifndef TP_DST_GRAPHUPDATEOBSERVABLE_H
#define TP_DST_GRAPHUPDATEOBSERVABLE_H

#include <set>
#include <vector>
#include "GraphUpdateObserver.h"

class GraphUpdateObservable {
    set<GraphUpdateObserver*> observers;
public:
    void AddObserver(GraphUpdateObserver& o){
        observers.insert(&o);
    };
    void RemoveObserver(GraphUpdateObserver& o){
        observers.erase(&o);
    };
    void NotifyEdgeDeletion(int src,int trg){
        set<GraphUpdateObserver*>::iterator itr;

        for ( itr = observers.begin();
        itr != observers.end(); itr++ )
            (*itr)->edgeDeleted(src,trg);

    };

    void NotifyEdgeInsertion(int src,int trg){
        set<GraphUpdateObserver*>::iterator itr;

        for ( itr = observers.begin();
        itr != observers.end(); itr++ )
            (*itr)->edgeAdded(src,trg);

    };

    void NotifyNodeInsertion(int src,vector<int>& incoming,vector<int>& outgoing){
        set<GraphUpdateObserver*>::iterator itr;

        for ( itr = observers.begin();
        itr != observers.end(); itr++ )
            (*itr)->nodeAdded(src,incoming,outgoing);

    };

    void NotifyNodeDeletion(int src){
        set<GraphUpdateObserver*>::iterator itr;

        for ( itr = observers.begin();
        itr != observers.end(); itr++ )
            (*itr)->nodeDeleted(src);

    };

    GraphUpdateObservable() { };

};

#endif //TP_DST_GRAPHUPDATEOBSERVABLE_H
