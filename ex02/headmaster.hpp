/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:15:23 by areheman          #+#    #+#             */
/*   Updated: 2024/06/24 16:21:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <vector>
#include "./staff.hpp"
#include "singetons.hpp"


class Form;

class Headmaster:public Staff{

    private:
        std::vector<Form*> _formToValidate;
        
    public:
        Headmaster(std::string p_name):Staff(p_name),_formToValidate(){}
        void receiveForm(Form* p_form);
        void executeForm();

        void fillCreateRoomForm(Form* form,Course* course, Singleton<Classroom>* classRooms);
        // void fillCreateRoomForm(Form* form,Course* course, ClassroomList* classRooms);

        
    
};



#endif