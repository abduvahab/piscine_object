#include "node.hpp"

Node::Node(){

}
Node::Node(const std::string &_name):name(_name){

}


Node::Node(const Node& obj):name(obj.name){

}

Node& Node::operator=(const Node& obj){
    if(this == &obj){
        return *this;
    }
    name = obj.name;
    return *this;
}


std::string Node::getName(){
    return name;
}

void        Node::setName(const std::string& _name){
    name = _name;
}
