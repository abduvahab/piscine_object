/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:38:33 by areheman          #+#    #+#             */
/*   Updated: 2024/06/20 11:44:29 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>
#include "person.hpp"
#include "classRoom.hpp"



class Course;
class Form;



class Student:public Person{

    private:
        std::vector<Course*> _subscribedCourse;

    public:
        Student(std::string p_name):
                Person(p_name),
                _subscribedCourse()
        {

        }

        void attendClass(Classroom* p_classroom);

        void subscribeCourse(Course* course);

        bool hasSubscribed(Course* course);

        void fillsubscribeForm(Form* form, Course* course);

        void exitClass(){
           _currentRoom->exit(this);
           this->_currentRoom = NULL;
        }

        void graduate(Course* p_course){
            if(p_course != NULL){
                std::cout<<"ok"<<std::endl;
            }
            // std::cout<<_name<<" has graduted the course "<<p_course->getName()<<std::endl;
            std::cout<<"pk"<<std::endl;
        }

};



#endif