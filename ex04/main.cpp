/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/07/09 13:10:14 by areheman         ###   ########.fr       */
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

    // ClassroomList& room_list = ClassroomList::getInstance();
    List<Classroom>* room_list = master.getClassRoomList();
    List<Course>* course_list = master.getCourseList();

    std::cout<<"number of the room1 :"<<room_list->getList().size()<<std::endl;
    
    // create  computer class
    Form* createComputer = secretary->createForm(NeedCourseCreation);
    prof->fillCourseCreateForm(createComputer, "Computer", 15, course_list, 4);
    // prof.fillCourseCreateForm(createComputer, "Computer", 15);
    master.receiveForm(createComputer);
    master .executeForm();

    //create math class
    Form* createmath = secretary->createForm(NeedCourseCreation);
    math_prof->fillCourseCreateForm(createmath, "math", 15, course_list, 4);
    // prof.fillCourseCreateForm(createComputer, "Computer", 15);
    master.receiveForm(createmath);
    master .executeForm();

    Course* com_course = prof->getCurrentCourse();
    if(com_course != NULL)
        std::cout<<com_course->getName()<<std::endl;
    Course* math_course = math_prof->getCurrentCourse();
    if(math_course != NULL)
        std::cout<<math_course->getName()<<std::endl;


    // jhon , jhon1 subscribe to compuetr class
    Form* subForm = secretary->createForm(SubscriptionToCourse);
    Form* subscribeToComp = secretary->createForm(SubscriptionToCourse);
    jhon1->fillsubscribeForm(subForm, com_course);
    jhon->fillsubscribeForm(subscribeToComp, com_course);
    master.receiveForm(subForm);
    master.receiveForm(subscribeToComp);
    master .executeForm();
    com_course->printStudent();
    jhon->printCourse();
    jhon1->printCourse();

    // jhon , jhon1 subscribe to math class
    Form* subForm1 = secretary->createForm(SubscriptionToCourse);
    Form* subscribeToComp1 = secretary->createForm(SubscriptionToCourse);
    jhon1->fillsubscribeForm(subForm1, math_course);
    jhon->fillsubscribeForm(subscribeToComp1, math_course);
    master.receiveForm(subForm1);
    master.receiveForm(subscribeToComp1);
    master .executeForm();
    math_course->printStudent();
    jhon->printCourse();
    jhon1->printCourse();


    // tom and tom1 subscribe to a math class 
    Form* subForm_math = secretary->createForm(SubscriptionToCourse);
    Form* subscribeTomath = secretary->createForm(SubscriptionToCourse);
    tom->fillsubscribeForm(subForm_math, math_course);
    tom1->fillsubscribeForm(subscribeTomath, math_course);
    master.receiveForm(subForm_math);
    master.receiveForm(subscribeTomath);
    master .executeForm();
    math_course->printStudent();
    tom->printCourse();
    tom1->printCourse();

    // subscribe to computer  class 
    Form* subForm_com = secretary->createForm(SubscriptionToCourse);
    Form* subscribe_com = secretary->createForm(SubscriptionToCourse);
    tom->fillsubscribeForm(subForm_com, com_course);
    tom1->fillsubscribeForm(subscribe_com, com_course);
    master.receiveForm(subForm_com);
    master.receiveForm(subscribe_com);
    master .executeForm();
    com_course->printStudent();
    tom->printCourse();
    tom1->printCourse();


        // start first day 
    std::cout<<"first day ------------------"<<std::endl;
    master.runDailyRoutine();

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    std::cout<<"---------====== ------------------"<<std::endl;

    master.headMasterRingBell(); // go to learn
    master.printOccupantsInAllRoom();
    std::cout<<"--------- =====------------------"<<std::endl;

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    std::cout<<"--------- ======------------------"<<std::endl;

    
    // start second day
    std::cout<<"second day ------------------"<<std::endl;
    master.runDailyRoutine();

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    std::cout<<"---------====== ------------------"<<std::endl;

    master.headMasterRingBell(); // go to learn
    master.printOccupantsInAllRoom();
    std::cout<<"--------- =====------------------"<<std::endl;

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    
    std::cout<<"--------- ======------------------"<<std::endl;

    // start third day 
    std::cout<<"third day ------------------"<<std::endl;
    master.runDailyRoutine();

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    std::cout<<"---------====== ------------------"<<std::endl;

    master.headMasterRingBell(); // go to learn
    master.printOccupantsInAllRoom();
    std::cout<<"--------- =====------------------"<<std::endl;

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    
    std::cout<<"--------- ======------------------"<<std::endl;

    // start fourth day 
    std::cout<<"fourth day ------------------"<<std::endl;
    master.runDailyRoutine();

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    std::cout<<"---------====== ------------------"<<std::endl;

    master.headMasterRingBell(); // go to learn
    master.printOccupantsInAllRoom();
    std::cout<<"--------- =====------------------"<<std::endl;

    master.headMasterRingBell(); // go to have a break
    master.printOccupantsInAllRoom();
    
    std::cout<<"--------- ======------------------"<<std::endl;


    
    return 0;
}