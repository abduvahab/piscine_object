#include "headmaster.hpp"
#include "./form.hpp"

void Headmaster::receiveForm(Form* p_form){
    this->sign(p_form);
    p_form->execute();
}