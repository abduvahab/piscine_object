#include "headmaster.hpp"
#include "./form.hpp"
#include "./course.hpp"
#include "./classRoom.hpp"
#include "./secretary.hpp"
#include "./bell.hpp"


Headmaster::Headmaster(std::string p_name):
        Staff(p_name),
        _formToValidate(),
        _secretary(NULL),
        bell()
{
    _listProf = List<Professor>::getInstance();
    _listStudent = List<Student>::getInstance();
    _listCourse = List<Course>::getInstance();
    _listClassRoom = List<Classroom>::getInstance();           
}

Headmaster::~Headmaster(){
    if(!_formToValidate.empty()){
        for(std::vector<Form*>::iterator it=_formToValidate.begin(); it != _formToValidate.end(); it++){
            delete (*it);
            *it = NULL;
        }
    }
    if(_listProf != NULL){
        _listProf->destruct();
    }
    if(_listStudent != NULL){
        _listStudent->destruct();
        
    }
    if(_listCourse != NULL){
        _listCourse->destruct();
       
    }
    if(_listClassRoom != NULL){
        _listClassRoom->destruct();
        
    }

}

void Headmaster::receiveForm(Form* p_form){
    _formToValidate.push_back(p_form);
    // this->sign(p_form);
    // p_form->execute();
}

void Headmaster::executeForm(){
    for(std::vector<Form*>::iterator it=_formToValidate.begin(); it != _formToValidate.end(); it++){
        this->sign(*it);
        (*it)->execute();
        delete (*it);
        *it = NULL;
    }
    _formToValidate.clear();
}

void Headmaster::magiclyCreateRoom(Professor* prof){

    if(_secretary != NULL){
        Form* newRoom_form = _secretary->createForm(NeedMoreClassRoom);
        this->fillCreateRoomForm(newRoom_form, prof->getCurrentCourse(), this->_listClassRoom);
        receiveForm(newRoom_form);
        executeForm();
    }
    else{
        std::cout<<"headmaster doesn't have a secretary!"<<std::endl;
    } 

}

void Headmaster::fillCreateRoomForm(Form* form,Course* course, List<Classroom>* classRooms){
    NeedMoreClassRoomForm* new_roomForm = dynamic_cast<NeedMoreClassRoomForm*>(form);
    if(new_roomForm != NULL){
        new_roomForm->signedByHeadMaster(course, classRooms);
    }
    else{
        std::cout<<"this is not a right form"<<std::endl;
    }
}


void Headmaster::launchClasses(){

    std::vector<Professor*> prof_list = _listProf->getList();
    //teacher is going to teache
    for(std::vector<Professor*>::iterator prof_it=prof_list.begin(); prof_it != prof_list.end(); prof_it++){
        if((*prof_it)->getCurrentCourse() != NULL){
            Course* current_class = (*prof_it)->getCurrentCourse();
            if(current_class->getClassRoom() == NULL){
                this->magiclyCreateRoom(*prof_it);
            }
            (*prof_it)->doClass();
        }
        else{
            std::cout<<(*prof_it)->getName()<<", you don't have a class, go to apply for teaching a class"<<std::endl;
        }
    }
    
    // student is going to learn 
    std::vector<Student*> student_list = _listStudent->getList();
    for(std::vector<Student*>::iterator it=student_list.begin(); it != student_list.end(); it++){
        Course* myCurrentCourse = (*it)->myCurrentCourse();
        if(myCurrentCourse !=NULL){
            (*it)->attendClass(myCurrentCourse->getClassRoom());
        }else{
            std::cout<<(*it)->getName()<<", you don't have a class, go to subscribe a class"<<std::endl;
        }
    }

    // print those in the classroom, 
    std::vector<Classroom*> classroom_list = _listClassRoom->getList();
    for(std::vector<Classroom*>::iterator class_it=classroom_list.begin(); class_it != classroom_list.end(); class_it++){
        (*class_it)->printOccupant();
    }

    //teacher check if there is student is qualifed to graduate
    for(std::vector<Professor*>::iterator prof_it=prof_list.begin(); prof_it != prof_list.end(); prof_it++){
        if((*prof_it)->getCurrentCourse() != NULL){
            Course* current_class = (*prof_it)->getCurrentCourse();
            std::vector<Student*> Students = current_class->getStudents();
            for(std::vector<Student*>::iterator stu_it=Students.begin(); stu_it!=Students.end();stu_it++){
                if((*stu_it)->studentHasEnoughCourse(current_class)){
                    std::cout<<(*stu_it)->getName()<<" has attend engouh class!"<<std::endl;
                    if(_secretary != NULL){
                        Form* course_finish = _secretary->createForm(CourseFinished);
                        (*prof_it)->fillCourseFinishedForm(course_finish, current_class, (*stu_it));
                        this->receiveForm(course_finish);

                    }else{
                        std::cout<<"headmaster doesn't have a secretary!"<<std::endl;
                    }
                }
            }
        }
    }
    this->executeForm(); // graduate the student who is qualified to graduate
    // bell.setOnBreak(false);
}

void Headmaster::printOccupantsInAllRoom(){
        // print those in the classroom, 
    std::vector<Classroom*> classroom_list = _listClassRoom->getList();
    for(std::vector<Classroom*>::iterator class_it=classroom_list.begin(); class_it != classroom_list.end(); class_it++){
        (*class_it)->printOccupant();
    }
}

void Headmaster::headMasterRingBell(Event event){
   
    bell.ringBell(event);
}
