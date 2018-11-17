#include "Path.h"

using namespace Pathfinding;

void Path::clean(){
    finishedPath.clear();
    while(!openSet.empty()) openSet.pop();
    nodeProcessor->clean();
}

void Path::computePath(){
    clean();
    openSet.push(startNode);
    
    while(!openSet.empty()){
        Node* current = openSet.top();
        openSet.pop();
        
        if(current == endNode){
            //idk do some kind of end logic
            std::cout<<"Damn we found a path nice ";
            completePath();
            std::cout<<"with length: "<<finishedPath.size()<<std::endl;
            break;
        }
        
        std::set<Node*> neighbors(nodeProcessor->getNeighbors(current));
        for(auto i = neighbors.begin();i!=neighbors.end();i++){
            Node* neighborNode = *i;
            float new_cost = current->gScore+nodeProcessor->getTravelCostBetween(current,neighborNode);
            if(!(neighborNode->parentNode)||new_cost<neighborNode->gScore){
                neighborNode->gScore=new_cost;
                neighborNode->parentNode = current;
                neighborNode->hScore = nodeProcessor->getHeuteristicCostBetween(neighborNode,endNode);
                openSet.push(neighborNode);
            }
        }
    }
}
void Path::completePath(){
    Node* current = endNode;
    while(current!=startNode){
        finishedPath.push_front(current);
        current = current->parentNode;
    }
    finishedPath.push_front(current);
    
}