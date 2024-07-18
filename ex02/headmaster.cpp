#include "headmaster.hpp"
#include "./form.hpp"

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


void Headmaster::fillCreateRoomForm(Form* form,Course* course, Singleton<Classroom>* classRooms){
    NeedMoreClassRoomForm* new_roomForm = dynamic_cast<NeedMoreClassRoomForm*>(form);
    if(new_roomForm != NULL){
        new_roomForm->signedByHeadMaster(course, classRooms);
    }
    else{
        std::cout<<"this is not a right form"<<std::endl;
    }
}
