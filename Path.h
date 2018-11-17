/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Path.h
 * Author: veesusmikelheir
 *
 * Created on November 16, 2018, 3:07 PM
 */

#ifndef PATH_H
#define PATH_H
#include <queue>
#include <set>
#include "Node.h"
#include "INodeProcessor.h"
#include <memory>
#include <list>
using namespace std;

namespace Pathfinding{
    
class NodePointerComparer{
public:
    bool operator()(const Node* a, const Node* b){
        return (*a)>(*b);
    }
};
class Path{
    priority_queue<Node*,std::vector<Node*>,NodePointerComparer> openSet;
    std::list<Node*> finishedPath;
    std::shared_ptr<INodeProcessor> nodeProcessor;
    Node* startNode;
    Node* endNode;
    void completePath();
public:
    Path():Path(NULL,NULL,NULL){}
    Path(std::shared_ptr<INodeProcessor> processor, Node* start, Node* end):finishedPath(),startNode(start),endNode(end),nodeProcessor(processor),openSet(){}
    void clean();
    void computePath();
    std::list<Node*> getCompletedPath(){
        return finishedPath;
    }
};
}
#endif /* PATH_H */

