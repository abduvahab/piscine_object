#include "./secretary.hpp"


Form* Secretary::createForm(FormType p_formType){
    Form* form;
    switch (p_formType)
    {
    case CourseFinished:
        form = new CourseFinishedForm(p_formType);
        break;
    case NeedMoreClassRoom:
        form = new NeedMoreClassRoomForm(p_formType);
        break;
    case NeedCourseCreation:
        form = new NeedCourseCreationForm(p_formType);
        break;
    case SubscriptionToCourse:
        form = new SubscriptionToCourseForm(p_formType);
        break;
    
    default:
        form = NULL;
        break;
    }
    return form;
}

// void Secretary::archiveForm(){
    
// }