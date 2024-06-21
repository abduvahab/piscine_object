#include "./professor.hpp"
#include "course.hpp"

void Professor::doClass(){
    if(_currentCourse != NULL){
        
        std::cout<<_name<<" is teaching "<<_currentCourse->getName()<<std::endl;             
    }
}

void Professor::closeCourse(){
    if(_currentCourse != NULL){
        std::cout<<_name<<"  colse "<<_currentCourse->getName()<<std::endl;
    }
}