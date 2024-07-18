/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:15:23 by areheman          #+#    #+#             */
/*   Updated: 2024/07/09 12:24:27 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <vector>
#include "./staff.hpp"
// #include "singetons.hpp"
#include "singleton.hpp"
#include "./bell.hpp"
#include "./student.hpp"
#include "./professor.hpp"



class Form;
class Secretary;
// class BellListener;


class Headmaster:public Staff{

    private:
        std::vector<Form*>      _formToValidate;
        List<Professor>*        _listProf;
        List<Student>*          _listStudent;
        List<Course>*           _listCourse;
        List<Classroom>*       _listClassRoom;
        Secretary*              _secretary;
        Bell                    bell;
        
    public:
        Headmaster(std::string p_name);
        ~Headmaster();
                
        void receiveForm(Form* p_form);
        void executeForm();

        void runDailyRoutine();

        void magiclyCreateRoom(Professor* prof);

        void setSecretary(Secretary* secretary){
            this->_secretary = secretary;
        }

        void addProf(Professor* one){
            _listProf->addList(one);
            bell.addlistener(one);
        }
        
        void addStudent(Student* one){
            _listStudent->addList(one);
            bell.addlistener((one));
        }

        void addCourse(Course* one){
            _listCourse->addList(one);
        }

        void addClassRoom(Classroom* one){
            _listClassRoom->addList(one);
        }

        List<Course>* getCourseList(){
            return _listCourse;
        }
        List<Classroom>* getClassRoomList(){
            return _listClassRoom;
        }
        List<Student>* getStudentList(){
            return _listStudent;
        }
        List<Professor>* getPtofList(){
            return _listProf;
        }

        void headMasterRingBell();

        void printOccupantsInAllRoom();

        void fillCreateRoomForm(Form* form,Course* course, List<Classroom>* classRooms);
        

};



#endif