/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/07/09 12:18:25 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./person.hpp"
#include "./room.hpp"
#include "./classRoom.hpp"
#include "./professor.hpp"
#include "./student.hpp"
#include "./course.hpp"
#include "./form.hpp"
#include "./secretary.hpp"
#include "./headmaster.hpp"
#include "./singleton.hpp"
// #include "./singetons.hpp"


int main(){


    Headmaster master("master");
    Secretary* secretary  = new Secretary("secretary");

    Student*     jhon = new Student("Jhon");
    Student*     jhon1 = new Student("Jhon1");

    Student*     tom = new Student("tom");
    Student*     tom1 = new Student("tom1");

    Professor*   prof = new Professor("com_prof");
    Professor*   math_prof = new Professor("math_prof");

    master.setSecretary(secretary);
    master.addProf(prof);
    master.addStudent(jhon);
    master.addStudent(jhon1);
    master.addProf(math_prof);
    master.addStudent(tom);
    master.addStudent(tom1);

    // start first day 
    std::cout<<"first day ------------------"<<std::endl;
    master.runDailyRoutine();
   
    // ClassroomList& room_list = ClassroomList::getInstance();
    List<Classroom>* room_list = master.getClassRoomList();
    List<Course>* course_list = master.getCourseList();

    std::cout<<"number of the room1 :"<<room_list->getList().size()<<std::endl;

    // create classroom and a class
    Form* createComputer = secretary->createForm(NeedCourseCreation);
    prof->fillCourseCreateForm(createComputer, "Computer", 15, course_list, 2);
    // prof.fillCourseCreateForm(createComputer, "Computer", 15);
    master.receiveForm(createComputer);
    master .executeForm();

    Form* createmath = secretary->createForm(NeedCourseCreation);
    math_prof->fillCourseCreateForm(createmath, "math", 15, course_list, 2);
    // prof.fillCourseCreateForm(createComputer, "Computer", 15);
    master.receiveForm(createmath);
    master .executeForm();

    Course* course = prof->getCurrentCourse();
    if(course != NULL)
        std::cout<<course->getName()<<std::endl;

    // subscribe to a class
    Form* subForm = secretary->createForm(SubscriptionToCourse);
    Form* subscribeToComp = secretary->createForm(SubscriptionToCourse);
    jhon1->fillsubscribeForm(subForm, course);
    jhon->fillsubscribeForm(subscribeToComp, course);
    master.receiveForm(subForm);
    master.receiveForm(subscribeToComp);
    master .executeForm();
    course->printStudent();
    jhon->printCourse();
    jhon1->printCourse();

    Course* math_course = math_prof->getCurrentCourse();
    if(math_course != NULL)
        std::cout<<math_course->getName()<<std::endl;

    // subscribe to a class
    Form* subForm_math = secretary->createForm(SubscriptionToCourse);
    Form* subscribeTomath = secretary->createForm(SubscriptionToCourse);
    tom->fillsubscribeForm(subForm_math, math_course);
    tom1->fillsubscribeForm(subscribeTomath, math_course);
    master.receiveForm(subForm_math);
    master.receiveForm(subscribeTomath);
    master .executeForm();
    course->printStudent();
    tom->printCourse();
    tom1->printCourse();


    // start second day
    std::cout<<"second day ------------------"<<std::endl;
    master.runDailyRoutine();

    // start third day 
    std::cout<<"third day ------------------"<<std::endl;
    master.runDailyRoutine();


    // start fourth day 
    std::cout<<"fourth day ------------------"<<std::endl;
    master.runDailyRoutine();
    
    // start fifth day 
    // std::cout<<"fifth day ------------------"<<std::endl;
    // master.runDailyRoutine();

    // start sixth day 
    // std::cout<<"sixth day ------------------"<<std::endl;
    // master.runDailyRoutine();
    
    return 0;
}