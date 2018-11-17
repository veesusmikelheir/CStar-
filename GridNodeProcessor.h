/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GridNodeProcessor.h
 * Author: veesusmikelheir
 *
 * Created on November 16, 2018, 4:24 PM
 */

#ifndef GRIDNODEPROCESSOR_H
#define GRIDNODEPROCESSOR_H
#include "INodeProcessor.h"
#include <utility>
#include <iostream>
#include "Point.h"
#include <map>
namespace Pathfinding{
class GridNodeProcessor:public INodeProcessor{
public:
    GridNodeProcessor(int xSize,int ySize);
    GridNodeProcessor(GridNodeProcessor&& node);
    virtual ~GridNodeProcessor() override;
    virtual void clean() override;
    virtual float getTravelCostBetween(Node* a, Node* b) override;
    virtual float getHeuteristicCostBetween(Node* a, Node* b) override;
    virtual Node* getNode(int ID) override;
    virtual std::set<Node*> getNeighbors(Node* a) override;
    int getID(int x, int y){
        return x*ySize+y;
    }
    int getID(Point p){
        return getID(p.x,p.y);
    }
    Point getPointFromID(int ID){
        return Point((ID/ySize),ID%ySize);
    }
private:
    GridNodeProcessor(const GridNodeProcessor& other) = delete; // NO COPYING >:( 
    GridNodeProcessor& operator =(const GridNodeProcessor& other)=delete; // NO ASSIGNMENT EITHER YOU NAUGHTY LITTLE SAUSAGE YOU >:(
    std::map<int,Node*> nodes;
    int xSize;
    int ySize;
    int gridSize;
};
}
#endif /* GRIDNODEPROCESSOR_H */

