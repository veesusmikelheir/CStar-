/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: veesusmikelheir
 *
 * Created on November 16, 2018, 3:15 PM
 */

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
namespace Pathfinding{
class Point{
public:
    float x;
    float y;
    float length();
    static float getDistance(const Point& a, const Point& b);
    float squaredLength();
    static float getDistanceSquared(const Point& a, const Point& b);
    friend Point operator -(const Point& a, const Point& b);
    friend Point operator +(const Point& a, const Point& b);
    friend Point operator *(const Point& a, const float b);
    friend Point operator *(const float b, const Point& a);
    friend std::ostream& operator<<(std::ostream &out, const Point& point){
        return out<<"{"<<point.x<<", "<<point.y<<"}";
    }
    Point(float x, float y):x(x),y(y){}
};
}
#endif /* POINT_H */

