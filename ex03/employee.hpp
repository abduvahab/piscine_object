/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:31:04 by areheman          #+#    #+#             */
/*   Updated: 2024/05/30 18:28:25 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

// Interface Segregation Principle (ISP)

// Clients should not be forced to 
// depend on interfaces they do not use. 
// This principle encourages creating specific interfaces 
// rather than a general-purpose interface to avoid 
// implementing unnecessary methods.


// In other words, larger interfaces should be split into smaller and 
// more specific ones so that clients only need to know about 
// the methods that are of interest to them.


#include <iostream>

class Employee{

    protected:
        int         hourlyValue;
        std::string name;

    public:
        Employee(const std::string name, int hourlyValue):hourlyValue(hourlyValue), name(name){}
        virtual int executeWorkday()=0;
        virtual void calculateSalary()=0;
        virtual ~Employee(){}
        int getHourlyValue() const{
            return hourlyValue;
        }

        void setHourlyValue(int value){
            hourlyValue = value;
        }

        void setName(const std::string name){
            this->name = name;
        }

        std::string getName()const{
            return name;
        }


};


#endif