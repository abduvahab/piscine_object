/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:23:24 by areheman          #+#    #+#             */
/*   Updated: 2024/05/20 16:39:28 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAMMER_HPP
#define HAMMER_HPP

#include <iostream>
#include "./Worker.hpp"
#include "./Tool.hpp"

// class Worker;

class Hammer:public Tool{
  private:
  std::string name_tool;

  public:
    Hammer();
    Hammer(const Hammer& other);
    Hammer& operator=(const Hammer& other);
    ~Hammer();

    void  use();
    std::string getNameOfTool();
    // void  removeCurrentWorker();
    // void  setCurrentWorker(Worker& worker);
    // Worker *getCurrentWorker();
};


#endif