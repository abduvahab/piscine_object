/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:10:55 by areheman          #+#    #+#             */
/*   Updated: 2024/07/08 18:01:07 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COURSE_HPP
#define COURSE_HPP

#include <vector>
#include "professor.hpp"



class Student;
class Classroom;

class Course{
    
    private:
    
        std::string             _name;
        Professor*              _responsable;
        std::vector<Student*>   _students;
        int             _numberOfClassToGraduate;
        int             _maximumNumberOfStudent;
        Classroom*      room;

    public:
        Course(std::string p_name, int _maxStudent=20, int numberOfClass=10):
                _name(p_name),
                _responsable(NULL),
                _students(),
                _numberOfClassToGraduate(numberOfClass),
                _maximumNumberOfStudent(_maxStudent),
                room(NULL)
        {

        }
        void assign(Professor* p_professor){
            _responsable = p_professor;
            // _responsable->assignCourse(this);
            // _numberOfClassToGraduate = 0;
            
        }

        void subscribe(Student* p_student);

        std::vector<Student*>::iterator removeStudent(Student* p_student);

        bool havePlace(){
            if(_students.size() < size_t(_maximumNumberOfStudent)){
                return true;
            }
            return false;
        }
        
        void   setClassRoom(Classroom *room){
             this->room = room;
        }

        bool attendentEngouhClass(int num){
            return num >= _numberOfClassToGraduate;
        }

        Classroom* getClassRoom(){return room;}

        void removeClassRoom(){
            room = NULL;
        }

        std::string getName() const{return _name;}

        Professor* getResponsabble(){return _responsable;}

        std::vector<Student*> getStudents(){return _students;}

        void printStudent();

};


#endif