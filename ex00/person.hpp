/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:40 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 15:39:04 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
// #include "room.hpp"

class Room;

class Person{

	protected:
		std::string _name;
		Room* _currentRoom;
	public:

		Person(std::string p_name):
		_name(p_name),
		_currentRoom(NULL)
		{}

		virtual ~Person(){}

		Room* room() {return (_currentRoom);}

		void setRoom(Room* room) { _currentRoom = room; }

		std::string getName()const{return _name;}
};



#endif