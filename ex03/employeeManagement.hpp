/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:31:10 by areheman          #+#    #+#             */
/*   Updated: 2024/05/30 18:03:00 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEEMANAGER_HPP
#define EMPLOYEEMANAGER_HPP

#include <iostream>
#include <set>

#include "./employee.hpp"

class EmployeeManager{

    protected:
        std::set<Employee*> employee_list;

    public:
        EmployeeManager():employee_list(){}
        void addEmployee(Employee* worker){
            employee_list.insert(worker);
        }
        void removeEmployee(Employee* worker){
            std::set<Employee*>::iterator it= employee_list.find(worker);
            if (it != employee_list.end()){
                employee_list.erase(it);
            }
        }
        void executeWorkday(){
            for(std::set<Employee*>::iterator it= employee_list.begin(); it!=employee_list.end(); it++){
                (*it)->executeWorkday();
            }
        }

        void calculatePayroll(){
            for(std::set<Employee*>::iterator it= employee_list.begin(); it!=employee_list.end(); it++){
                (*it)->calculateSalary();
            }
        }

};


#endif