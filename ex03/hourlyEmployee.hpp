/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:31:01 by areheman          #+#    #+#             */
/*   Updated: 2024/05/30 17:44:54 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOURLYEMPLOYEE_HPP 
#define HOURLYEMPLOYEE_HPP

#include "./employee.hpp"

class hourlyEmployee:public Employee{
    protected:
        int hoursWorked;
    
    public:
        hourlyEmployee(const std::string name, int hourlyvalue):Employee(name, hourlyvalue),hoursWorked(0){}
        
        virtual int executeWorkday(){
            hoursWorked += 7;
            std::cout<<name<<" has worked one day"<<std::endl;
            return hoursWorked;
        }
        virtual void calculateSalary(){
            int total = hoursWorked * hourlyValue;
            std::cout<<"the salary of the "<<name<<": "<<total<<" euros"<<std::endl;
        }
};

class TempWorker:public hourlyEmployee{
    protected:
        int hoursMobilise;

    public:
        TempWorker(const std::string name, int hourlyvalue):hourlyEmployee(name, hourlyvalue), hoursMobilise(0){}

        int registorHoursMobilise(int hours){
            hoursMobilise += hours;
            return hoursMobilise;
        }

        virtual void calculateSalary(){
            int total = (hoursWorked + hoursMobilise)* hourlyValue;
            std::cout<<"the salary of the "<<name<<": "<<total<<" euros"<<std::endl;
        }
};      


#endif