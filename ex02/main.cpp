/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/06/20 16:46:59 by areheman         ###   ########.fr       */
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


int main(){


    Headmaster master("master");
    Secretary secretary("secretary");
    Course      math("Math");
    Student     jhon("Jhon");
    Professor   prof("com_prof");

    Form* subForm = secretary.createForm(SubscriptionToCourse);
    jhon.fillsubscribeForm(subForm, &math);
    master.receiveForm(subForm);

    Form* createComputer = secretary.createForm(NeedCourseCreation);
    prof.fillCourseCreateForm(subForm, "Computer", 15);
    // prof.fillCourseCreateForm(createComputer, "Computer", 15);
    master.receiveForm(createComputer);
    Course* course = NULL;
    course = prof.getCurrentCourse();
    if(course != NULL)
        std::cout<<course->getName()<<std::endl;


    delete course;
    delete createComputer;
    delete subForm;



    // Classroom   classRoom;

    // Professor   Tom("tom");

    // math.assign(&Tom);

    // classRoom.assignCourse(&math);

    // jhon.subscribeCourse(&math);

    // jhon.attendClass(&classRoom);

    // classRoom.printOccupant();
    
    // Tom.doClass();

    // jhon.exitClass();

    // jhon.attendClass(&classRoom);

    // std::cout<<"ok"<<std::endl;
    
    return 0;
}