/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:03:21 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 15:35:32 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <vector>


class Person;

class Room{

    private:
        static long long generatNumber;

    protected:
        long long ID;
        std::vector<Person*> _occupants;

    public:
        Room():ID(generatNumber), _occupants(){
            generatNumber += 1;
        }
        virtual ~Room(){}

        
        virtual bool canEnter(Person* person)=0;

        void enter(Person* person){
            if(canEnter(person)){
                _occupants.push_back(person);
            }
        }
        
        void exit(Person* person);
        
        void printOccupant();
};




#endif
