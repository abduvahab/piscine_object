/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:30:49 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 11:46:44 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./employee.hpp"
#include "./employeeManagement.hpp"
#include "./hourlyEmployee.hpp"
#include "./salariedEmployee.hpp"

int main(){
    {

        hourlyEmployee hem("tom", 10);
        TempWorker tmp("jhon", 10);
        salariedEmployee sem("sam", 10);
        ContractEmployee cem("sam1", 10);
        Apprentice appem("sam3", 10);

        EmployeeManager manager;
        manager.addEmployee(&hem);
        manager.addEmployee(&tmp);
        manager.addEmployee(&sem);
        manager.addEmployee(&cem);
        manager.addEmployee(&appem);
        
        tmp.registorHoursMobilise(5);
        cem.registorHoursNotWorked(10);
        appem.registorHoursNotWorked(10);
        appem.registorHoursGoToSchool(10);
        manager.executeWorkday();
        // manager.executeWorkday();
        manager.calculatePayroll();
    }


    return 0;
}