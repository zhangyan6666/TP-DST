//
// Created by HAI YAN ZHANG on 2023/3/15.
//

#ifndef TP_DST_GRAPHUPDATEOBSERVER_H
#define TP_DST_GRAPHUPDATEOBSERVER_H

class GraphUpdateObserver {
public:
    virtual void edgeAdded(int,int) = 0;
    virtual void edgeDeleted(int,int) = 0;
    virtual void nodeAdded(int, vector<int>& , vector<int>&) = 0;
    virtual void nodeDeleted(int) = 0;
};

#endif //TP_DST_GRAPHUPDATEOBSERVER_H
