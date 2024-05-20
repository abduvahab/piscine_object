/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:39:52 by areheman          #+#    #+#             */
/*   Updated: 2024/05/15 12:57:14 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include <iostream>
#include "./Worker.hpp"
#include "./Tool.hpp"

class Worker;

class Shovel:public Tool{
  private:
  std::string name_tool;

  public:
    Shovel();
    Shovel(const Shovel& other);
    Shovel& operator=(const Shovel& other);
    ~Shovel();

    void  use();
    std::string getNameOfTool();
    // void  removeCurrentWorker();
    // void  setCurrentWorker(Worker& worker);
    // Worker *getCurrentWorker();
};


#endif