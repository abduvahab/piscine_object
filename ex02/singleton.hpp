/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:10:49 by areheman          #+#    #+#             */
/*   Updated: 2024/06/24 14:30:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <vector>
#include <iostream>

class Classroom;

class ClassroomList{

    private:
        static ClassroomList* instance;
        std::vector<Classroom*>      list;
        ClassroomList():list(){}
        ~ClassroomList(){}
        ClassroomList& operator=(const ClassroomList& obj);
        ClassroomList(const ClassroomList& obj);


    public:
        static ClassroomList& getInstance(){
            if(instance == NULL){
                instance = new ClassroomList();
            }
            return *instance;
        }
        void addList(Classroom* object);
        std::vector<Classroom*> getAll();
        void distruct();

};



#endif