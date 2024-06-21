/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:38 by areheman          #+#    #+#             */
/*   Updated: 2024/06/20 16:42:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Course;
class Student;
class Professor;

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
        bool       _isFormFilled;

    public:
        Form(FormType p_formType)
        {
            _formType = p_formType;
            _isSigned = false;
            _isFormFilled = false;
        }
        virtual ~Form(){}

        bool    isSigned(){
            return _isSigned;
        }
        bool    isFormFilled(){
            return _isFormFilled;
        }
        void    SignForm();

        virtual void execute() = 0;  
};

class SubscriptionToCourseForm : public Form
{
    private:
        Course*     course;
        Student*    student;
        // bool        isStudentSigned;

    public:
        SubscriptionToCourseForm(FormType p_formType):
                Form(p_formType),
                course(NULL),
                student(NULL)
                {}
        // ~SubscriptionToCourseForm(){}

        void execute();

        void    setCourseName(Course* course){
            this->course = course;
        }
        void    setStudentName(Student* stu){
                student = stu;
        }

        void    signByStudent(Student* stu);


       
};


class NeedCourseCreationForm : public Form
{
    private:
        std::string     course_name;
        int             maxNumberStudent;
        Professor*      prof;

    public:
        NeedCourseCreationForm(FormType p_formType):Form(p_formType),course_name(""),maxNumberStudent(0), prof(NULL){}
        // ~NeedCourseCreationForm(){}
        void setcourseName(std::string course_name){
            this->course_name = course_name;
        }
        void setProf(Professor* professor){
            prof = professor;
        }

        void setMaxNumber(int num){ maxNumberStudent = num;}

        void signedByProfessor(Professor* prof);

        void execute();
};

class NeedMoreClassRoomForm : public Form
{
    private:
        // Course*     course;
    public:
        NeedMoreClassRoomForm(FormType p_formType):Form(p_formType){}
        // void set
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