/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: veesusmikelheir
 *
 * Created on November 16, 2018, 3:10 PM
 */

#ifndef NODE_H
#define NODE_H
#include "Point.h"
#include <iostream>
namespace Pathfinding{
class Node{
public:
    int nodeID;
    float gScore; // Score from the beginning
    float hScore; // Score to the end node
    Node* parentNode;
    Node(int ID, float gScore,float hScore,Node* parentNode):nodeID(ID), hScore(hScore), gScore(gScore),parentNode(parentNode){
    }
    ~Node(){
    }
    
    float getTotalScore() const{
        return gScore+hScore;
    }
    Node(int ID):Node(ID,0,0,NULL){}
    
    friend bool operator >(const Node& a, const Node& b){
        return a.getTotalScore()>b.getTotalScore();
    }
    
    friend bool operator <(const Node& a, const Node& b){
        return a.getTotalScore()<b.getTotalScore();
    }
    friend bool operator >=(const Node& a, const Node& b){
        return a.getTotalScore()>=b.getTotalScore();
    }
    friend bool operator <=(const Node& a, const Node& b){
        return a.getTotalScore()<=b.getTotalScore();
    }
    friend bool operator ==(const Node& a, const Node& b){
        return a.nodeID==b.nodeID;
    }
    
    void clean(){
        gScore=0;
        hScore=0;
        parentNode=NULL;
    }
};
}
#endif /* NODE_H */

