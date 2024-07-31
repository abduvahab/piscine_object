#include "rail.hpp"


Rail::Rail():length(0){

}

Rail::Rail(const Node &node_start, const Node &node_end, double length):node_start(node_start), node_end(node_end), length(length){

}

Rail::Rail(const Rail& obj):node_start(obj.node_start), node_end(obj.node_end),length(obj.length){

}

Rail& Rail::operator=(const Rail& obj){
    if(this == &obj){
        return *this;
    }
    node_start = obj.node_start;
    node_end   = obj.node_end;
    length =obj.length;
    return *this;
}

Node    Rail::getStartNode(){
    return node_start;
}


Node    Rail::getEndNode(){
    return node_end;
}


double  Rail::getLength(){
    return length;
}



void    Rail::setStartNode(Node& node){
    node_start = node;
}


void    Rail::setEndNode(Node& node){
    node_end = node;
}


void    Rail::setLength(double len){
    length = len;
}

