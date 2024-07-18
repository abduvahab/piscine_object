#include "./professor.hpp"
#include "course.hpp"
#include "classRoom.hpp"


void Professor::doClass(){
    if(_currentCourse != NULL){
        Classroom* room = _currentCourse->getClassRoom();
        if(room != NULL){
           if (room->canEnter(this)){
                room->enter(this);
                this->setRoom(room);
                std::cout<<_name<<" is teaching "<<_currentCourse->getName()<<std::endl;

           }else{
            std::cout<<" you cant enter the room "<<std::endl;
           }

        }
        else{
             std::cout<<_name<<" hasn't a class room for "<<_currentCourse->getName()<<std::endl;
        }
    }
    else{
        std::cout<<_name<<" hasn't a class to teache "<<std::endl;
    }
}

void Professor::closeCourse(){
    if(_currentCourse != NULL){
        std::cout<<_name<<"  colse "<<_currentCourse->getName()<<std::endl;
    }
}

void Professor::fillCourseCreateForm(Form* form, std::string course_name, int maxNuberStudent, List<Course>* courseList, int numberofClass){
    NeedCourseCreationForm *createform = dynamic_cast<NeedCourseCreationForm*>(form);
    if(createform != NULL){
        createform->setcourseName(course_name);
        createform->setMaxNumber(maxNuberStudent);
        createform->setMaxNumberClass(numberofClass);
        createform->signedByProfessor(this, courseList);
    }
    else{
        std::cout<<"this is not a right form"<<std::endl;
    }
}


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

void Professor::oneBellRing(Event event, bool onBreak){
    if((event == RingBell) && (_currentCourse != NULL)){
        
        Room* room = _currentCourse->getClassRoom();
        if(room != NULL){
            if(onBreak){
                if(this->room() != NULL){
                    std::cout<<_name<<" is gong to have break"<<std::endl;
                    room->exit(this);
                    this->removeRoom();
                }
            }else{
               doClass();
            }
        }
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