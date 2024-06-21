#include "./room.hpp"
#include "person.hpp"

long long Room::generatNumber = 0;

// bool Room::canEnter(Person* person){
//     for (std::vector<Person*>::iterator it= _occupants.begin(); it!=_occupants.end();it++){
//         if(*it == person){
//             return false; 
//         }
//     }
//     if(this == person->room()){
//         return true;
//     }
//     return false;
// }
// void Room::enter(Person* person){
//     _occupants.push_back(person);
// }
void Room::exit(Person* person){
    if(this == person->room()){
        for (std::vector<Person*>::iterator it= _occupants.begin(); it!=_occupants.end();it++){
            if(*it == person){
                _occupants.erase(it);
                return;
            }
        } 
    }
}

void Room::printOccupant(){
    std::cout<<"the occupants in the room are : "<<std::endl;
    for (std::vector<Person*>::iterator it= _occupants.begin(); it!=_occupants.end();it++){
        std::cout<<"-"<<(*it)->getName()<<std::endl;
    }
}