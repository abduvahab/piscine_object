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

void Professor::fillCourseCreateForm(Form* form, std::string course_name, int maxNuberStudent){
    NeedCourseCreationForm *createform = dynamic_cast<NeedCourseCreationForm*>(form);
    if(createform != NULL){
        createform->setcourseName(course_name);
        createform->setMaxNumber(maxNuberStudent);
        createform->signedByProfessor(this);
    }
    else{
        std::cout<<"this is not a right form"<<std::endl;
    }
}