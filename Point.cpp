#include "Point.h"
namespace Pathfinding{
Point operator +(const Point& a, const Point& b){
    return Point(a.x+b.x,a.y+b.y);
}
Point operator -(const Point& a, const Point& b){
    return Point(a.x-b.x,a.y-b.y);
}

Point operator *(const Point& a, const float b){
    return Point(a.x*b,a.y*b);
}

Point operator *(const float b,const Point& a){
    return Point(a.x*b,a.y*b);
}

}
using namespace Pathfinding;


float Point::length(){
    return sqrt(x*x+y*y);
}
float Point::getDistance(const Point& a, const Point& b){
    return (a-b).length();
}
float Point::getDistanceSquared(const Point& a, const Point& b){
    return (a-b).squaredLength();
}
float Point::squaredLength(){
    return x*x+y*y;
}




