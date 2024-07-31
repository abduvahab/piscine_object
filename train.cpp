#include "train.hpp"

int Train::ID = 0;

Train::Train(double maxAcceleration , double maxBrake):id(ID++), maxAcceleration(maxAcceleration), maxBrake(maxBrake){

}

Train::Train(const std::string &_name, double maxAcceleration , double maxBrake, const Node &departureStation, const Node &arrivalStation):
        id(ID++),
        name(_name), 
        maxAcceleration(maxAcceleration), 
        maxBrake(maxBrake),
        departureStation(departureStation),
        arrivalStation(arrivalStation){

}

Train::Train(const Train& obj):
        id(ID++),
        name(obj.name), 
        maxAcceleration(obj.maxAcceleration), 
        maxBrake(obj.maxBrake),
        departureStation(obj.departureStation),
        arrivalStation(obj.arrivalStation),
        departureTime(obj.departureTime){

}

Train& Train::operator=(const Train& obj){
    if(this == &obj){
        return *this;
    }
    id = obj.id;
    name = obj.name;
    maxAcceleration = obj.maxAcceleration;
    maxBrake = obj.maxBrake;
    departureStation = obj.departureStation;
    arrivalStation = obj.arrivalStation;
    departureTime = obj.departureTime;
    return *this;
}


int                 Train::getId(){
    return id;
}

std::string         Train::getName(){
    return name;

}

double              Train::getMaxAcceleration(){
        return maxAcceleration;
}

double              Train::getMaxBrake(){
    return maxBrake;
}

Node                Train::getDepartureStation(){
    return  departureStation;
}

Node                Train::getArrivalStation(){
    return  arrivalStation;
}

std::string         Train::getDepartureTime(){
    return  departureTime;
}



void                Train::setName(const std::string &name){
    this->name = name; 
}

void                Train::setMaxAcceleration( double maxAcceleration){
    this->maxAcceleration = maxAcceleration;
}

void                Train::setMaxBrake(double maxBrake){
    this->maxBrake = maxBrake;
}

void                Train::setDepartureStation(const Node &departureStation){
    this->departureStation = departureStation;
}

void                Train::setArrivalStation(const Node &arrivalStation){
    this->arrivalStation = arrivalStation;
}

void                Train::setDepartureTime(const std::string &time){
    this->departureTime = time;
}
