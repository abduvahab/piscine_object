/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/07/10 14:42:36 by areheman         ###   ########.fr       */
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
#include "./schoolFacade.hpp"
// #include "./singetons.hpp"


int main(){


    SchoolFacade school;
    Student*     jhon = new Student("Jhon");
    Student*     jhon1 = new Student("Jhon1");

    Student*     tom = new Student("tom");
    Student*     tom1 = new Student("tom1");

    Professor*   com_prof = new Professor("com_prof");
    Professor*   math_prof = new Professor("math_prof");
    
    school.recruteStudent(jhon);
    school.recruteStudent(jhon1);
    school.recruteStudent(tom);
    school.recruteStudent(tom1);
    school.recruteProfessor(com_prof);
    school.recruteProfessor(math_prof);

    school.createCourse(com_prof, "computer" , 10, 4);
    school.createCourse(math_prof, "math" , 10, 4);


    school.subscribeToCourse(jhon, "math");
    school.subscribeToCourse(jhon, "computer");

    school.subscribeToCourse(jhon1, "computer");
    school.subscribeToCourse(jhon1, "math");

    school.subscribeToCourse(tom, "computer");
    school.subscribeToCourse(tom1, "math");

    std::cout<<"---------------first day start---------"<<std::endl;
    school.runDayRoutine();
    school.graduationCeremony();
    std::cout<<"---------------second day start---------"<<std::endl;
    school.runDayRoutine();
    std::cout<<"---------------third day start---------"<<std::endl;
    school.runDayRoutine();
    school.graduationCeremony();
    std::cout<<"---------------end ---------"<<std::endl;
  
    return 0;
}