#include "./form.hpp"
#include "./course.hpp"
#include "./student.hpp"
#include "professor.hpp"



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
    if(course != NULL){
        student = stu;
        _isFormFilled = true;
    }
    else{
        std::cout<<"you didn't write your course"<<std::endl;
    }
}



// NeedCourseCreationForm
void NeedCourseCreationForm::signedByProfessor(Professor* prof){
    if(course_name != ""){
       this->prof =  prof;
        _isFormFilled = true;
    }
    else{
        std::cout<<"you didn't write name of the course"<<std::endl;
    }
}

void NeedCourseCreationForm::execute(){
    if(this->_isSigned){
        if(prof != NULL){
            Course* new_couurse = new Course(course_name,(maxNumberStudent!=0 ? maxNumberStudent:20));
            new_couurse->assign(prof);
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

