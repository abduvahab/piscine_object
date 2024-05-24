/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WorkShop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:47:40 by areheman          #+#    #+#             */
/*   Updated: 2024/05/22 17:47:46 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <vector>
#include "./Worker.hpp"

class Worker;



class WorkShop{

  private:
    std::vector<Worker*> worker_list;

  public:
    WorkShop();
    WorkShop(const WorkShop &other);
    WorkShop& operator=(const WorkShop &other);
    ~WorkShop();

    void addWorker(Worker& worker);
    void removeWorker(Worker& worker);
    std::vector<Worker*>::iterator deleteWorker(Worker& worker);
    void executeWorkDay();
    void printWorker();

};



#endif