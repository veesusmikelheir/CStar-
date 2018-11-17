#include <cstdlib>
#include <iostream>
#include <utility>
#include "GridNodeProcessor.h"
#include <memory>
#include "Path.h"
using namespace std;
using namespace Pathfinding;
/*
 * 
 */
int main(int argc, char** argv) {
    std::shared_ptr<GridNodeProcessor> pointer(new GridNodeProcessor(10,10));
    Path path(pointer,pointer->getNode(0),pointer->getNode(99));
    path.computePath();
    std::list<Node*> finishedPath =path.getCompletedPath();
    for(auto i = finishedPath.begin();i!=finishedPath.end();i++){
        std::cout<<pointer->getPointFromID((*i)->nodeID);
    }
    return 0;
}

