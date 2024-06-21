/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:43:57 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 15:30:50 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP


#include "staff.hpp"


class Course;



class Professor:public Staff{

    private:
        Course* _currentCourse;

    public:
        Professor(std::string p_name):Staff(p_name),_currentCourse(NULL){}

        void assignCourse(Course* p_course){
           _currentCourse = p_course;
        //    p_course->assign(this);

        }
        Course* getCurrentCourse(){return _currentCourse;}

        void doClass();

        void closeCourse();

};



#endif