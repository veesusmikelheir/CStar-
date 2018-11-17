#include "GridNodeProcessor.h"
using namespace Pathfinding;
GridNodeProcessor::GridNodeProcessor(int xSize, int ySize):nodes(),ySize(ySize),xSize(xSize), gridSize(xSize*ySize){
    
    for(int x = 0; x<xSize;x++){
        for(int y = 0; y<ySize;y++){
            int ID = getID(x,y);
            Node* newNode = new Node(ID);
            nodes.emplace(ID,newNode); 
        }
    }
}

GridNodeProcessor::~GridNodeProcessor(){
    for(auto i = nodes.begin();i!=nodes.end();i++){
        delete std::get<1>((*i));
    }
}
GridNodeProcessor::GridNodeProcessor(GridNodeProcessor&& node){
    std::cout<<"oh shit we mooooving this GridNodeProcessor"<<std::endl;
    for(auto i = node.nodes.begin();i!=node.nodes.end();i++){
        nodes.emplace(*i);
        node.nodes.erase(std::get<0>(*i));
    }
}
void GridNodeProcessor::clean(){
    for(auto i = nodes.begin();i!= nodes.end();i++){
        std::get<1>(*i)->clean();
    }
}


Node* GridNodeProcessor::getNode(int ID){
    return nodes.at(ID);
}
float GridNodeProcessor::getTravelCostBetween(Node* a, Node* b){
    return Point::getDistance(getPointFromID(a->nodeID),getPointFromID(b->nodeID));
}
float GridNodeProcessor::getHeuteristicCostBetween(Node* a, Node* b){
    return Point::getDistance(getPointFromID(a->nodeID),getPointFromID(b->nodeID));
}
std::set<Node*> GridNodeProcessor::getNeighbors(Node* a){
    std::set<Node*> neighbors;
    Point nodePoint = getPointFromID(a->nodeID);
    for(int x = -1; x<=1;x+=1){
        for(int y = -1;y<=1;y+=1){
            if(x==0&&y==0) continue;
            
            Point newPoint(x+nodePoint.x,y+nodePoint.y);
            if((newPoint.y>2&&newPoint.y<8&&newPoint.x==3)) continue; // really dumb way to put an obstacle
            if((newPoint.x>2&&newPoint.x<8&&newPoint.y==3)) continue;
            if(newPoint.x<0||newPoint.x>=xSize||newPoint.y<0||newPoint.y>=ySize) continue;
            neighbors.insert(getNode(getID(newPoint)));
            
        }
    }
    return neighbors;
}

