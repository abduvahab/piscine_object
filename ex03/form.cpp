#include "./form.hpp"
#include "./course.hpp"
#include "./student.hpp"
#include "professor.hpp"
#include "classRoom.hpp"
#include "singleton.hpp"



//form
void    Form::SignForm(){
    if(_isFormFilled){
        _isSigned = true;
    }
    else{
        std::cout<<"the form hasn't been filled"<<std::endl;
    }
}

//SubscriptionToCourseForm
void SubscriptionToCourseForm::execute(){
    if(this->_isSigned){
        if(course->havePlace()){
            course->subscribe(student);
            student->subscribeCourse(course);
            std::cout<<student->getName()<<" has subscribed to "<<course->getName()<<std::endl;
            return ;
        }
        std::cout<<"the number of student reached maximum in course "<<course->getName()<<std::endl;
    }
    else{
        std::cout<<"the form hasn't been signed "<<std::endl;
    }
    // std::cout<<"SubscriptionToCourseForm execute"<<std::endl;
}

void    SubscriptionToCourseForm::signByStudent(Student* stu){
    if(course != NULL && stu != NULL){
        student = stu;
        _isFormFilled = true;
    }
    else{
        std::cout<<"you didn't write your course"<<std::endl;
    }
}



// NeedCourseCreationForm
void NeedCourseCreationForm::signedByProfessor(Professor* prof, List<Course>* courseList){
    if(course_name != "" && prof != NULL && courseList){
       this->prof =  prof;
       this->course_list = courseList;
        _isFormFilled = true;
    }
    else{
        std::cout<<"you didn't write name of the course"<<std::endl;
    }
}

void NeedCourseCreationForm::execute(){
    if(this->_isSigned){
        if(prof != NULL){
            Course* new_couurse = new Course(course_name,(maxNumberStudent!=0 ? maxNumberStudent:20),_numberOfClassToGraduate);
            new_couurse->assign(prof);
            course_list->addList(new_couurse);
            prof->assignCourse(new_couurse);
            std::cout<<course_name<<" course has been created and assigned to "<<prof->getName()<<std::endl;
        }
    }
    else{
        std::cout<<"the form hasn't been signed "<<std::endl;
    }
    // std::cout<<"SubscriptionToCourseForm execute"<<std::endl;
}


//NeedMoreClassRoomForm

void NeedMoreClassRoomForm::execute(){
    if(this->_isSigned){
        if(classRooms != NULL ){
            Classroom* new_room = new Classroom();
            if(course != NULL){
                new_room->assignCourse(course);
                course->setClassRoom(new_room);
            }
            // classRooms->addList(new_room);
            classRooms->addList(new_room);
            std::cout<<" a class room  has been created and added to class room list"<<std::endl;
        }
    }
    else{
        std::cout<<"the form hasn't been signed "<<std::endl;
    }
    // std::cout<<"SubscriptionToCourseForm execute"<<std::endl;
}

void NeedMoreClassRoomForm::signedByHeadMaster(Course* course, List<Classroom>* classRooms){
        this->course =  course;
        this->classRooms = classRooms;
        if(classRooms != NULL){
            _isFormFilled = true;
        }
        else{
           std::cout<<"there is no class room list"<<std::endl; 
        }
}


// CourseFinishedForm

void CourseFinishedForm::execute(){
    if(this->_isSigned){
        if(stu->room() == prof->room()){
            stu->exitClass();
        }
       stu->graduate(course);
       course->removeStudent(stu);
       std::cout<<stu->getName()<<" graduated from "<<course->getName()<<std::endl;

    }
    else{
        std::cout<<"the form hasn't been signed "<<std::endl;
    }
    // std::cout<<"SubscriptionToCourseForm execute"<<std::endl;
}

void    CourseFinishedForm::signeByProfessor(Professor* pro){
    this->prof = pro;
    if(prof == NULL){
        std::cout<<"you have to write the teacher!"<<std::endl;
        return ;
    }
    if(stu == NULL){
        std::cout<<"you have to write the student!"<<std::endl;
        return ;
    }
    if(course == NULL){
        std::cout<<"you have to write the course!"<<std::endl;
        return ;
    }
    if(prof != course->getResponsabble()){
        std::cout<<"the professor is not responsable of the course"<<std::endl;
        return ;  
    }

    _isFormFilled = true;
}

