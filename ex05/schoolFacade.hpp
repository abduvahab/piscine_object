/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schoolFacade.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:24:12 by areheman          #+#    #+#             */
/*   Updated: 2024/07/10 14:23:46 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOOLFACADE_HPP
#define SCHOOLFACADE_HPP

#include <iostream>
#include "./headmaster.hpp"
#include "./secretary.hpp"
#include "./bell.hpp"


class Student;
class Professor;
class Course;
class Room;


class SchoolFacade{

    protected:
        Headmaster                      headMaster;
        Secretary                       secretary;
        std::vector<Professor*>         professors;
        std::vector<Student*>           students;
        std::vector<Course*>            courses;
        std::vector<Room*>              rooms;
        std::map<std::string, Course*> courseMap;
        int                             minnumberofCourseToGraduate;            

    public:
        SchoolFacade():
                    headMaster("master"),
                    secretary("secretary"),
                    professors(),
                    students(),
                    courses(),
                    rooms(),
                    courseMap(),
                    minnumberofCourseToGraduate(2)
        {
            headMaster.setSecretary(&secretary);
        }
        ~SchoolFacade(){}

        void runDayRoutine();

        void launchClasses(){
            headMaster.launchClasses();
        }

        void requestRingBell(Event event){
            headMaster.headMasterRingBell(event);
        }

        void recruteProfessor(Professor* prof);

        void recruteStudent(Student* student);

        Course* getCourse(std::string p_name);
        void    addCourse(std::string p_name, Course* course);

        std::vector<Student*> getStudents(){
            return students;
        }

        std::vector<Professor*> getProfessors(){
            return professors;
        }
        Headmaster getHeadmaster(){
            return headMaster;
        }
        bool studentExist(Student* stu);
        bool profExist(Professor* pro);
        bool courseExist(std::string name);

        void createCourse(Professor* pro, std::string name, int muxStudent, int numberToFinish);

        void subscribeToCourse(Student* student, std::string name);

        Secretary getSecretary(){
            return secretary;
        }
        void setMinNumberCourseToGraduare(int num){
            minnumberofCourseToGraduate = num;
        }

        void graduationCeremony();


};



#endif