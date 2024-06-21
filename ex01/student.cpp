#include "./student.hpp"
#include "course.hpp"


bool Student::hasSubscribed(Course* course){
    for(std::vector<Course*>::iterator it = _subscribedCourse.begin(); it!=_subscribedCourse.end();it++){
        if((*it) == course){
            return true;
        }
    }
    return false;  
}

void Student::attendClass(Classroom* p_classroom){
    if(p_classroom->canEnter(this)){
        p_classroom->enter(this);
        setRoom(p_classroom);
    }
}

void Student::subscribeCourse(Course* course){
    if(!hasSubscribed(course)){
        course->subscribe(this);
        _subscribedCourse.push_back(course);
    }
}