/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:46:38 by areheman          #+#    #+#             */
/*   Updated: 2024/07/05 16:51:44 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "singleton.hpp"

class Course;
class Student;
class Professor;
class Classroom;
class ClassroomList;


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
        List<Course>* course_list;
        int             _numberOfClassToGraduate;

    public:
        NeedCourseCreationForm(FormType p_formType):Form(p_formType),course_name(""),maxNumberStudent(0), prof(NULL),_numberOfClassToGraduate(0){}
        // ~NeedCourseCreationForm(){}
        void setcourseName(std::string course_name){
            this->course_name = course_name;
        }
        void setProf(Professor* professor){
            prof = professor;
        }
        void setCourseList(List<Course>* courseList){course_list = courseList;}
        void setMaxNumber(int num){ maxNumberStudent = num;}
        void setMaxNumberClass(int num){ _numberOfClassToGraduate = num;}

        void signedByProfessor(Professor* prof, List<Course>* courseList);

        void execute();
};

class NeedMoreClassRoomForm : public Form
{
    private:
        Course*              course;
        // ClassroomList*    classRooms;
        List<Classroom>*    classRooms;
        
    public:
        NeedMoreClassRoomForm(FormType p_formType):Form(p_formType),course(NULL),classRooms(NULL){}

        void setCourse(Course* course){this->course = course;}
       
        void signedByHeadMaster(Course* course, List<Classroom>* classRooms);
        
        void execute();
};


class CourseFinishedForm : public Form
{
    private:
        Professor*  prof;
        Student*     stu;
        Course*     course;
    public:
        CourseFinishedForm(FormType p_formType):Form(p_formType),prof(NULL),stu(NULL),course(NULL){}
        void setProf(Professor*  prof){this->prof = prof;}
        void setStudent(Student*     stu){this->stu = stu;}
        void setCourse(Course*     course){this->course = course;}
        void    signeByProfessor(Professor* pro);
        void execute();
};



#endif