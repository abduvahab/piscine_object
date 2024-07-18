/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:38:33 by areheman          #+#    #+#             */
/*   Updated: 2024/07/10 13:52:34 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>
#include "person.hpp"
#include "classRoom.hpp"
#include <map>
#include "./bell.hpp"



class Course;
class Form;



class Student:public Person, public BellListener{

    private:
        std::vector<Course*>        _subscribedCourse;
        std::map<std::string, int>  completedClass;
        int                         _numberOfClassfinished;

    public:
        Student(std::string p_name):
                Person(p_name),
                BellListener(),
                _subscribedCourse(),
                completedClass(),
                _numberOfClassfinished(0)
        {

        }

        void attendClass(Classroom* p_classroom);

        void subscribeCourse(Course* course);

        bool hasSubscribed(Course* course);

        void addOneToCompletedClass(std::string course_name){
            completedClass[course_name]++;
        }
        bool studentHasEnoughCourse(Course* course);

        void fillsubscribeForm(Form* form, Course* course);

        void exitClass(){
            if(_currentRoom != NULL){
                _currentRoom->exit(this);
                this->removeRoom();
            }
           this->_currentRoom = NULL;
        }

        void graduate(Course* p_course);

        Course* myCurrentCourse();

        void oneBellRing(Event event);

        int getNumberOfCoursefinished(){
            return _numberOfClassfinished;
        }

        void printCourse();
};



#endif