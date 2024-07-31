#include "event.hpp"

Event::Event(double probability, int duration):probability(probability), duration(duration){

}

Event::Event(const std::string &_name, double probability, int duration, const Node &location):
        name(_name),
        probability(probability),
        duration(duration),
        location(location){

}

Event::Event(const Event& obj):
        name(obj.name),
        probability(obj.probability),
        duration(obj.duration),
        location(obj.location){

}

Event& Event::operator=(const Event& obj){
    if(this == &obj){
        return *this;
    }

    name = obj.name;
    probability = obj.probability;
    duration = obj.duration;
    location = obj.location;
    return *this;
}


std::string     Event::getName(){
    return name;
}

double          Event::getProbability(){
    return probability;
}

int             Event::getDuration(){
    return duration;
}

Node            Event::getLocation(){
    return location;
}


void            Event::setName(const std::string &_name){
    name = _name;
}

void            Event::setProbability(double probability){
    this->probability = probability;
}

void            Event::setDuration(int duration){
    this->duration = duration;
}

void            Event::setLocation(const Node &location){
    this->location = location;
}
