/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:19:40 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 14:49:03 by areheman         ###   ########.fr       */
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


int main(){

    Classroom   classRoom;
    Course      math("Math");

    Student     jhon("Jhon");

    Professor   Tom("tom");

    math.assign(&Tom);

    classRoom.assignCourse(&math);

    jhon.subscribeCourse(&math);

    jhon.attendClass(&classRoom);

    classRoom.printOccupant();
    
    Tom.doClass();

    jhon.exitClass();

    jhon.attendClass(&classRoom);



    std::cout<<"ok"<<std::endl;
    return 0;
}