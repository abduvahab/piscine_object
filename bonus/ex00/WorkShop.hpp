/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WorkShop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:47:40 by areheman          #+#    #+#             */
/*   Updated: 2024/05/22 14:16:23 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <set>
#include <typeinfo>
#include "./Worker.hpp"

class Worker;



class WorkShop{

  private:
    std::set<Worker*> worker_list;
    
    const std::type_info* required_type;

  public:
    
    WorkShop();
    WorkShop(const WorkShop &other);
    WorkShop& operator=(const WorkShop &other);
    ~WorkShop();

    template<typename ToolType>
    void setType();

    bool addWorker(Worker& worker);
    void removeWorker(Worker& worker);
    void deleteWorker(Worker& worker);
    // void executeWorkDay();
    bool checkRequiredTool(Worker& worker);
    const std::type_info* getRequiredType();
    void executeWorkDay();
    void updateAfterSetType();
    void printWorker();

};

#include "./WorkShop.tpp"

// class Worker;
// template<typename ToolType>
// void  WorkShop::setType(){
//     // std::cout<<<<"set type for workShop"<<std::endl;
//     required_type = &typeid(ToolType);
//     std::cout<<(std::string(required_type->name()).substr(1))<<"set type for workShop"<<std::endl;
//     for(std::set<Worker*>::iterator it = worker_list.begin(); it != worker_list.end(); it++){
//       if(!(*it)->hasNecessaryTool(*this)){
//           this->removeWorker(**it);
//       }
//     }

// }


#endif