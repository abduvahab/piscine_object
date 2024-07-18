/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:43:57 by areheman          #+#    #+#             */
/*   Updated: 2024/07/10 13:53:13 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP


#include "staff.hpp"
#include "./bell.hpp"


class Course;



class Professor:public Staff, public BellListener{

    private:
        Course* _currentCourse;

    public:
        Professor(std::string p_name):Staff(p_name),BellListener(),_currentCourse(NULL){}

        ~Professor(){}


        void assignCourse(Course* p_course){
           _currentCourse = p_course;
        //    p_course->assign(this);

        }
        void oneBellRing(Event event);

        Course* getCurrentCourse(){return _currentCourse;}

        void doClass();

        void closeCourse();


        void fillCourseCreateForm(Form* form, std::string course_name, int maxNuberStudent, List<Course>* courseList, int numberofClass);

        void fillCourseFinishedForm(Form* form, Course* course, Student* student);

        // void fillNeedMoreClassRoomForm(Form* form);

};



#endif