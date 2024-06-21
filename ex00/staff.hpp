/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:41:58 by areheman          #+#    #+#             */
/*   Updated: 2024/06/10 14:12:06 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAFF_HPP
#define STAFF_HPP

#include "person.hpp"
#include "form.hpp"


class Person;
class Form;


class Staff:public Person{

private:

public:
	Staff(std::string p_name):Person(p_name){}
	
	void sign(Form* p_form){p_form->signForm();};
    
};



#endif