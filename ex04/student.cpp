#include "./student.hpp"
#include "course.hpp"
#include "form.hpp"


bool Student::hasSubscribed(Course* course){
    for(std::vector<Course*>::iterator it = _subscribedCourse.begin(); it!=_subscribedCourse.end();it++){
        if((*it) == course){
            return true;
        }
    }
    return false;  
}

void Student::attendClass(Classroom* p_classroom){
    if(p_classroom != NULL ){
        Course* course_attende = p_classroom->getCurrentCourse();
        if(p_classroom->canEnter(this)){
            if(course_attende != NULL){
                p_classroom->enter(this);
                setRoom(p_classroom);
                addOneToCompletedClass(course_attende->getName());
                std::cout<<this->getName()<<" is learning "<<course_attende->getName()<<std::endl;

            }else{
                std::cout<<"you class isn't in this classroom"<<std::endl;
            }

        }else{
            std::cout<<"you cant enter this room"<<std::endl;
        }

    }
    else{
        std::cout<<"this room doesn't exist"<<std::endl;
    }
}

bool Student::studentHasEnoughCourse(Course* course){
    if(completedClass.count(course->getName()) > 0){
        return course->attendentEngouhClass(completedClass[course->getName()]);
    }
    return false;
}



void Student::subscribeCourse(Course* course){
    if(!hasSubscribed(course)){
        // course->subscribe(this);
        _subscribedCourse.push_back(course);
    }
}

void Student::graduate(Course* p_course){
    
    for(std::vector<Course*>::iterator it=_subscribedCourse.begin(); it!=_subscribedCourse.end(); it++){
        if((*it) == p_course){
            _subscribedCourse.erase(it);
            return;
        }
    }
}


void Student::fillsubscribeForm(Form* form, Course* course){
    SubscriptionToCourseForm* _form = dynamic_cast<SubscriptionToCourseForm*>(form);
    if(_form != NULL){
        _form->setCourseName(course);
        _form->setStudentName(this);
        _form->signByStudent(this);
    }
}

void Student::printCourse(){
    std::cout<<_name<<" has subscribed to : ";
    for(std::vector<Course*>::iterator it=_subscribedCourse.begin(); it!=_subscribedCourse.end(); it++){
        std::cout<<(*it)->getName()<<",";

    }
    std::cout<<std::endl;
}

Course* Student::myCurrentCourse(){
    if(_subscribedCourse.empty()){
    return NULL;
    }
    else{
        return *(_subscribedCourse.begin());
    }
}

void Student::oneBellRing(Event event, bool onBreak){
    Course* course = myCurrentCourse();
    if((event == RingBell) && (course != NULL)){
        if(onBreak){
            if(this->room() != NULL){
                this->exitClass();
                std::cout<<_name<<" is going to have a break"<<std::endl;
            }
        }else{
            std::cout<<_name<<" is going to have a class"<<std::endl;
            this->attendClass(course->getClassRoom());
        }
    }
}