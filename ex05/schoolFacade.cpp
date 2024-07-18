#include "schoolFacade.hpp"
#include "./professor.hpp"
#include "./student.hpp"
#include "./course.hpp"
#include "./room.hpp"


void SchoolFacade::recruteProfessor(Professor* prof){
    for(std::vector<Professor*>::iterator it=professors.begin(); it!=professors.end();it++){
        if(*it == prof){
            return ;
        }
    }
    if(prof !=NULL){
        professors.push_back(prof);
        headMaster.addProf(prof);
    
    }
}


void SchoolFacade::runDayRoutine(){
    launchClasses();
    requestRingBell(Break_Start);
    headMaster.printOccupantsInAllRoom();
    requestRingBell(Break_End);
    headMaster.printOccupantsInAllRoom();
    requestRingBell(Launch);
    headMaster.printOccupantsInAllRoom();
    launchClasses();
    headMaster.printOccupantsInAllRoom();
    requestRingBell(Break_Start);
    requestRingBell(Break_End);
    requestRingBell(Break_Start);
}

void SchoolFacade::recruteStudent(Student* student){
    for(std::vector<Student*>::iterator it=students.begin(); it!=students.end();it++){
        if(*it == student){
            return ;
        }
    }
    if(student !=NULL){
        students.push_back(student);
        headMaster.addStudent(student);
    }
}

Course* SchoolFacade::getCourse(std::string p_name){
    if(courseMap.count(p_name) > 0){
        return courseMap[p_name];
    }
    return NULL;
}

void    SchoolFacade::addCourse(std::string p_name, Course* course){
    courseMap[p_name] = course;
}

void SchoolFacade::graduationCeremony(){
    std::cout<<"today, we  celebrate graduate students !"<<std::endl;
    for(std::vector<Student*>::iterator it=students.begin(); it!=students.end();it++){
        if(minnumberofCourseToGraduate <= (*it)->getNumberOfCoursefinished()){
           std::cout<< (*it)->getName()<<" has graduated "<<std::endl;
        }
    }
}

void SchoolFacade::createCourse(Professor* prof, std::string name, int muxStudent, int numberToFinish){
    if(prof != NULL && name !=""){
        if(courseExist(name)){
            std::cout<<name<<"  already exist in the this school"<<std::endl;
            return ;
        }
        Form* createCourse = secretary.createForm(NeedCourseCreation);
        prof->fillCourseCreateForm(createCourse, name, muxStudent, headMaster.getCourseList(), numberToFinish);
        headMaster.receiveForm(createCourse);
        headMaster .executeForm();
        headMaster.magiclyCreateRoom(prof);
        Course* course = prof->getCurrentCourse();
        if(course != NULL){
            courses.push_back(course);
            addCourse(name, course);
            rooms.push_back(course->getClassRoom());
        }

    }
}

void SchoolFacade::subscribeToCourse(Student* student, std::string name){
    if(!studentExist(student)){
        std::cout<<"this student is not in the this school"<<std::endl;
        return;
    }
    if(name != ""){
        if(!courseExist(name)){
            std::cout<<name<<"  doesn't exist in the this school"<<std::endl;
            return ;
        }
    }
    else{
        return ;
    }
    Course* course = getCourse(name);
    Form* subForm = secretary.createForm(SubscriptionToCourse);
    student->fillsubscribeForm(subForm, course);
    headMaster.receiveForm(subForm);
    headMaster .executeForm();
}

bool SchoolFacade::studentExist(Student* stu){
    if(stu == NULL){
        return false;
    }
    for(std::vector<Student*>::iterator it=students.begin(); it!=students.end();it++){
        if(*it == stu){
            return true;
        }
    }
    return false;  
}

bool SchoolFacade::profExist(Professor* pro){
    if(pro == NULL){
        return false;
    }
    for(std::vector<Professor*>::iterator it=professors.begin(); it!=professors.end();it++){
        if(*it == pro){
            return true;
        }
    }
    return false;
}

bool SchoolFacade::courseExist(std::string name){
    if(getCourse(name) != NULL){
        return true;
    }
    return false;
}