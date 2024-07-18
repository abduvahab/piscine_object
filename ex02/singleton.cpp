#include "singleton.hpp"
#include "classRoom.hpp"


ClassroomList* ClassroomList::instance = NULL;


void ClassroomList::addList(Classroom* object){
    std::vector<Classroom*>::iterator it = list.begin();
    for( ; it != list.end(); it++){
        if((*it) == object){
            return ;
        }
    }
    list.push_back(object);
}


std::vector<Classroom*>  ClassroomList::getAll(){
    return list;
}


void ClassroomList::distruct(){
    if(!list.empty()){
        for( std::vector<Classroom*>::iterator it = list.begin(); it != list.end(); it++){

            delete (*it);
            *it = NULL;
        }
        list.clear();
    }
    if(instance != NULL){
        delete instance;
    }
}