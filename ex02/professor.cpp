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

void Professor::fillCourseCreateForm(Form* form, std::string course_name, int maxNuberStudent, Singleton<Course>* courseList){
    NeedCourseCreationForm *createform = dynamic_cast<NeedCourseCreationForm*>(form);
    if(createform != NULL){
        createform->setcourseName(course_name);
        createform->setMaxNumber(maxNuberStudent);
        createform->signedByProfessor(this, courseList);
    }
    else{
        std::cout<<"this is not a right form"<<std::endl;
    }
}
// void Professor::fillNeedMoreClassRoomForm(Form* form){
//     NeedMoreClassRoomForm *needRoom = dynamic_cast<NeedMoreClassRoomForm*>(form);
//     if(needRoom != NULL){
//         if(_currentCourse !=NULL){
//             // needRoom->setProfessor(this);
//             needRoom->signedByProfessor(this);
//         }
//         else{
//           std::cout<<this->_name<<" donesn't need a class room"<<std::endl;  
//         }
//     }
//     else{
//         std::cout<<"this is not a right form"<<std::endl;
//     }
// }



void Professor::fillCourseFinishedForm(Form* form, Course* course, Student* student){
    CourseFinishedForm *courseFinished = dynamic_cast<CourseFinishedForm*>(form);
    if(courseFinished != NULL){
        courseFinished->setCourse(course);
        courseFinished->setStudent(student);
        courseFinished->setProf(this);
        courseFinished->signeByProfessor(this);
    }
    else{
        std::cout<<"this is not a right form"<<std::endl;
    }
}