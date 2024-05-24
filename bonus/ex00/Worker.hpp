/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:53:31 by areheman          #+#    #+#             */
/*   Updated: 2024/05/22 14:21:10 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <set>
#include <vector>
#include "./Tool.hpp"
#include "./WorkShop.hpp"

class Tool;
class WorkShop;

struct Position{
  int x;
  int y;
  int z;

  Position(int x, int y, int z):x(x),y(y),z(z){}
};

struct Statistic{
  int level;
  int exp;
  Statistic(int level, int exp):level(level), exp(exp){}
};

class Worker{

  private:
    std::string name;
    Position coordonnee;
    Statistic stat;
    std::vector<Tool*> tools;
    std::set<WorkShop*> workshops;

    void takeToolsFromWorker();
  public:
    Worker(const std::string name);
    Worker(const std::string name,const Position coordonnee, const Statistic stat);
    Worker(const Worker &other);
    Worker& operator=(const Worker &other);
    ~Worker();

    template<typename T>
    T *getTool();

    void addTool(Tool &tool);
    void removeTool(Tool &tool);
    bool work(WorkShop &workshop);
    void registerToWorkshop(WorkShop& workshop);
    void leaveWorkshop(WorkShop& workshop);
    bool hasNecessaryTool(WorkShop& workshop);
    void printNameofTool();

    std::string getName()const;

  
};

    template<typename T>
    T *Worker::getTool(){
      for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
        T *specificTool = dynamic_cast<T *>(*it);
        if(specificTool){
          return specificTool;
        }
      }
      return NULL;
    }

#endif