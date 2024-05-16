/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:53:31 by areheman          #+#    #+#             */
/*   Updated: 2024/05/15 15:40:29 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
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
    Tool *tool;
    std::vector<WorkShop*> workshops;

  public:
    Worker(const std::string name);
    Worker(const std::string name,const Position coordonnee, const Statistic stat);
    Worker(const Worker &other);
    Worker& operator=(const Worker &other);
    ~Worker();

    void giveToolToWorker(Tool& shovel);
    void takeToolFromWorker();
    void work(WorkShop &workshop);
    void registerToWorkshop(WorkShop& workshop);
    void leaveWorkshop(WorkShop& workshop);
    std::string getName()const;

  friend std::ostream& operator<<(std::ostream& o, const Worker& obj);
};



#endif