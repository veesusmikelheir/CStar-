/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   INodeMap.h
 * Author: veesusmikelheir
 *
 * Created on November 16, 2018, 4:15 PM
 */

#ifndef INODEPROCESSOR_H
#define INODEPROCESSOR_H
#include "Node.h"
#include <set>
namespace Pathfinding{
class INodeProcessor{
public:
    virtual ~INodeProcessor(){}
    virtual float getTravelCostBetween(Node* a, Node* b)=0;
    virtual float getHeuteristicCostBetween(Node* a, Node* b)=0;
    virtual std::set<Node*> getNeighbors(Node* a)=0;
    virtual Node* getNode(int ID)=0;
    virtual void clean()=0;
};
}

#endif /* INODEPROCESSOR_H */

