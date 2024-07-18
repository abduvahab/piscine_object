/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/06/24 19:10:31 by areheman         ###   ########.fr       */
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
#include "./singetons.hpp"


int main(){


    Headmaster master("master");
    Secretary secretary("secretary");
    Course      math("Math");
    Student     jhon("Jhon");
    Professor   prof("com_prof");
    // ClassroomList& room_list = ClassroomList::getInstance();
    Singleton<Classroom>& room_list = Singleton<Classroom>::getInstance();
    Singleton<Course>& course_list = Singleton<Course>::getInstance();

    std::cout<<"number of the room1 :"<<room_list.getAllElement().size()<<std::endl;

    // create classroom and a class
    Form* createComputer = secretary.createForm(NeedCourseCreation);
    prof.fillCourseCreateForm(createComputer, "Computer", 15, &course_list);
    // prof.fillCourseCreateForm(createComputer, "Computer", 15);
    master.receiveForm(createComputer);
    master .executeForm();

    Course* course = prof.getCurrentCourse();
    if(course != NULL)
        std::cout<<course->getName()<<std::endl;

    // subscribe to a class
    Form* subForm = secretary.createForm(SubscriptionToCourse);
    Form* subscribeToComp = secretary.createForm(SubscriptionToCourse);
    jhon.fillsubscribeForm(subForm, &math);
    jhon.fillsubscribeForm(subscribeToComp, course);
    master.receiveForm(subForm);
    master.receiveForm(subscribeToComp);
    master .executeForm();
    course->printStudent();
    jhon.printCourse();


    // graduated the class

    Form* courseFinished = secretary.createForm(CourseFinished);
    prof.fillCourseFinishedForm(courseFinished, course, &jhon);
    master.receiveForm(courseFinished);
    master.executeForm();
    jhon.printCourse();
    course->printStudent();


    // create more class room 
    Form* needRoom = secretary.createForm(NeedMoreClassRoom);
    master.fillCreateRoomForm(needRoom, course, &room_list);
    master.receiveForm(needRoom);
    master.executeForm();

    std::cout<<"number of the room2 :"<<room_list.getAllElement().size()<<std::endl;
    course = prof.getCurrentCourse();

    course_list.destruct();
    room_list.destruct();
    // delete course;

    
    return 0;
}