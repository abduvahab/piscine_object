#include "./classRoom.hpp"
#include "./professor.hpp"
#include "./student.hpp"

bool Classroom::canEnter(Person* person){
    for (std::vector<Person*>::iterator it= _occupants.begin(); it!=_occupants.end();it++){
        if(*it == person){
            return false; 
        }
    }
    Student* st = dynamic_cast<Student*>(person);
    if(st){
        if(st->hasSubscribed(_currentCourse)){
            return true;
        }
    }
    Professor* pro = dynamic_cast<Professor*>(person);
    if(pro){
        if(pro->getCurrentCourse() == _currentCourse){
            return true;
        }
    }
    return false;
}
