/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/06/11 13:56:55 by areheman         ###   ########.fr       */
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
#include "./singetons.hpp"
#include "./staffRooms.hpp"


int main(){

    Singleton<Student>& studentList= Singleton<Student>::getInstance();
    Singleton<Staff>& staffList= Singleton<Staff>::getInstance();
    Singleton<Course>& courseList= Singleton<Course>::getInstance();
    Singleton<Room>& roomList= Singleton<Room>::getInstance();

// test the student list
    std::cout<<"student list test"<<std::endl;
    Student student1("student1"); 
    Student student2("student2"); 
    Student student3("student3"); 

    studentList.addElement(&student1);
    studentList.addElement(&student2);
    studentList.addElement(&student3);

    std::vector<Student*> st = studentList.getAllElement();
    for(std::vector<Student*>::iterator it=st.begin(); it!=st.end();it++){
        std::cout<<"-"<<(*it)->getName()<<std::endl;
    }

// test the course list
    std::cout<<"course list test"<<std::endl;
    Course course1("course1"); 
    Course course2("course2"); 
    Course course3("course3"); 

    courseList.addElement(&course1);
    courseList.addElement(&course2);
    courseList.addElement(&course3);

    std::vector<Course*> course_list = courseList.getAllElement();
    for(std::vector<Course*>::iterator it=course_list.begin(); it!=course_list.end();it++){
        std::cout<<"-"<<(*it)->getName()<<std::endl;
    }

// test the room list
    std::cout<<"room list test"<<std::endl;
    Room* classRoom =new Classroom();
    Room* secrataryRoom =new SecretarialOffice();
    Room* headmaster =new HeadmasterOffice();
    Room* staffRoom =new StaffRestRoom();
    Room* yard =new Courtyard();


    roomList.addElement(classRoom);
    roomList.addElement(secrataryRoom);
    roomList.addElement(headmaster);
    roomList.addElement(staffRoom);
    roomList.addElement(yard);
    std::vector<Room*> room_list = roomList.getAllElement();
    for(std::vector<Room*>::iterator it=room_list.begin(); it!=room_list.end();it++){
        std::cout<<"-"<<(*it)->getId()<<std::endl;
    }


// test the staff list
    std::cout<<"staff list test"<<std::endl;
    Staff staff1("staff1"); 
    Staff staff2("staff2"); 
    Staff staff3("staff3");

    Staff* pro1 =new  Professor("pro1"); 
    Staff* pro2 =new  Professor("pro2"); 
    Staff* pro3 =new  Professor("pro3"); 


    staffList.addElement(&staff1);
    staffList.addElement(&staff2);
    staffList.addElement(&staff3);
    staffList.addElement(pro1);
    staffList.addElement(pro2);
    staffList.addElement(pro3);
    std::vector<Staff*> st_staff = staffList.getAllElement();
    for(std::vector<Staff*>::iterator it=st_staff.begin(); it!=st_staff.end();it++){
        std::cout<<"-"<<(*it)->getName()<<std::endl;
    }


// test only has one instace 
    {
        std::cout<<"student list test only has one instance"<<std::endl;
        Singleton<Student>& studentList1= Singleton<Student>::getInstance();
        std::vector<Student*> st1 = studentList1.getAllElement();
        for(std::vector<Student*>::iterator it=st1.begin(); it!=st1.end();it++){
            std::cout<<"-"<<(*it)->getName()<<std::endl;
        }

    }

    {
        std::cout<<"course list test only has one instance"<<std::endl;
        Singleton<Course>& course_list1= Singleton<Course>::getInstance();
        std::vector<Course*> st1 = course_list1.getAllElement();
        for(std::vector<Course*>::iterator it=st1.begin(); it!=st1.end();it++){
            std::cout<<"-"<<(*it)->getName()<<std::endl;
        }

    }


    {
        std::cout<<"room list test only has one instance"<<std::endl;
        Singleton<Room>& room_list1= Singleton<Room>::getInstance();
        std::vector<Room*> st1 = room_list1.getAllElement();
        for(std::vector<Room*>::iterator it=st1.begin(); it!=st1.end();it++){
            std::cout<<"-"<<(*it)->getId()<<std::endl;
        }

    }


    {
        std::cout<<"staff list test only has one instance"<<std::endl;
        Singleton<Staff>& staffList2= Singleton<Staff>::getInstance();
        std::vector<Staff*> st1 = staffList2.getAllElement();
        for(std::vector<Staff*>::iterator it=st1.begin(); it!=st1.end();it++){
            std::cout<<"-"<<(*it)->getName()<<std::endl;
        }

    }


    delete classRoom;
    delete secrataryRoom;
    delete headmaster;
    delete staffRoom;
    delete yard;

    delete pro1;
    delete pro2;
    delete pro3;
    studentList.destruct();
    staffList.destruct();
    courseList.destruct();
    roomList.destruct();

    return 0;
}