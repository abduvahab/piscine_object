/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classRoom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:08:49 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 15:37:06 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include "./room.hpp"



class Course;
class Person;



class Classroom:public Room{

    private:
        Course* _currentCourse;

    public:
        Classroom():_currentCourse(NULL){}
        
        void assignCourse(Course* p_course){
            this->_currentCourse = p_course;
        }
        Course* getCurrentRoom()const{
            return _currentCourse;
        }
        
        bool canEnter(Person* person);
};


#endif