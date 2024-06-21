/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:38 by areheman          #+#    #+#             */
/*   Updated: 2024/06/07 11:12:13 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP




enum  FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};


class Form{

    protected:
        FormType    _formType;
        bool       _isSigned;

    public:
        Form(FormType p_formType)
        {
            _formType = p_formType;
            _isSigned = false;
        }

        void signForm(){_isSigned = true;}
        bool getIsSigned(){return _isSigned;}

        virtual void execute() = 0;
    
};

class SubscriptionToCourseForm : public Form
{
    private:

    public:
        SubscriptionToCourseForm(FormType p_formType):Form(p_formType){}
        void execute(){
            std::cout<<"SubscriptionToCourseForm execute"<<std::endl;
        }
};


class NeedCourseCreationForm : public Form
{
    private:

    public:
        NeedCourseCreationForm(FormType p_formType):Form(p_formType){}
        void execute(){
            std::cout<<"NeedCourseCreationForm execute"<<std::endl;
        }
};

class NeedMoreClassRoomForm : public Form
{
    private:

    public:
        NeedMoreClassRoomForm(FormType p_formType):Form(p_formType){}
        void execute(){
            std::cout<<"NeedMoreClassRoomForm execute"<<std::endl;
        }
};


class CourseFinishedForm : public Form
{
    private:

    public:
         CourseFinishedForm(FormType p_formType):Form(p_formType){}
        void execute(){
            std::cout<<"CourseFinishedForm execute"<<std::endl;
        }
};



#endif