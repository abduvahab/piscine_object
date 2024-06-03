/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:30:57 by areheman          #+#    #+#             */
/*   Updated: 2024/05/30 17:44:17 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SALARIEDEMPLOYEE_HPP 
#define SALARIEDEMPLOYEE_HPP

#include "./employee.hpp"

class salariedEmployee:public Employee{

    public:
        salariedEmployee(const std::string name, int hourlyvalue):Employee(name, hourlyvalue){}
        
        virtual int executeWorkday(){
            std::cout<<name<<" has worked one day"<<std::endl;
            return 0;
        }
        virtual void calculateSalary(){
            int total = hourlyValue * 160;//one month equal 160 hours
            std::cout<<"the salary of the "<<name<<": "<<total<<" euros"<<std::endl;
        }
};

class ContractEmployee:public salariedEmployee{

    protected:
        int hoursNotWorked;

    public:
        ContractEmployee(const std::string name, int hourlyvalue):salariedEmployee(name, hourlyvalue),hoursNotWorked(0){}
        
        int registorHoursNotWorked(int hours){
            hoursNotWorked +=hours;
            return hoursNotWorked;
        }
        virtual void calculateSalary(){
            int total = hourlyValue * (160 - hoursNotWorked);//one month equal 160 hours
            std::cout<<"the salary of the "<<name<<": "<<total<<" euros"<<std::endl;
        }

};
class Apprentice:public ContractEmployee{
    protected:
        int hoursGoToSchool;

    public:
        Apprentice(const std::string name, int hourlyvalue):ContractEmployee(name, hourlyvalue),hoursGoToSchool(0){}
        
        int registorHoursGoToSchool(int hours){
            hoursGoToSchool +=hours;
            return hoursGoToSchool;
        }
        virtual void calculateSalary(){
            double total = hourlyValue * (160 - hoursNotWorked - hoursGoToSchool / 2 );//one month equal 160 hours
            std::cout<<"the salary of the "<<name<<": "<<total<<" euros"<<std::endl;
        }
};


#endif