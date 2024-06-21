/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:10:55 by areheman          #+#    #+#             */
/*   Updated: 2024/06/20 15:31:30 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COURSE_HPP
#define COURSE_HPP

#include <vector>
#include "professor.hpp"



class Student;

class Course{
    
    private:
        std::string _name;
        Professor* _responsable;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;
    public:
        Course(std::string p_name, int _maxStudent=20):
                _name(p_name),
                _responsable(NULL),
                _students(),
                _numberOfClassToGraduate(0),
                _maximumNumberOfStudent(_maxStudent)
        {

        }
        void assign(Professor* p_professor){
            _responsable = p_professor;
            // _responsable->assignCourse(this);
            _numberOfClassToGraduate = 0;
            
        }

        void subscribe(Student* p_student);

        bool havePlace(){
            if(_students.size() < size_t(_maximumNumberOfStudent)){
                return true;
            }
            return false;
        }
        
        std::string getName() const{return _name;}
};


#endif