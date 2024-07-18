/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staffRooms.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:56:25 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 12:36:22 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAFFROOMS_HPP
#define STAFFROOMS_HPP

#include "./room.hpp"
#include "./course.hpp"
#include "./form.hpp"

class Form;

class SecretarialOffice: public Room
{
    private:
        std::vector<Form*> _archivedForms;

    public:
        SecretarialOffice():Room(),_archivedForms(){}
        bool canEnter(Person* person){
            if(person != NULL){
                return true;
            }
            return false;
        }
        
};

class HeadmasterOffice : public Room
{
    private:

    public:
        HeadmasterOffice():Room(){}
        bool canEnter(Person* person){
            if(person != NULL){
                return true;
            }
            return false;
        }

};

class StaffRestRoom : public Room
{
    private:

    public:
        StaffRestRoom():Room(){}
        bool canEnter(Person* person){
            if(person != NULL){
                return true;
            }
            return false;
        }

};

class Courtyard : public Room
{
    private:

    public:
        Courtyard():Room(){}
        bool canEnter(Person* person){
            if(person != NULL){
                return true;
            }
            return false;
        }

};


#endif