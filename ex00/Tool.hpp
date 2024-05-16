/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:38:27 by areheman          #+#    #+#             */
/*   Updated: 2024/05/15 12:57:04 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOO_HPP
#define TOO_HPP
#include "./Worker.hpp"

class Worker;
class Tool{

  protected:
    int numberOfUses;
    Worker *currentWorker;

  public:
    Tool();
    Tool(const Tool& other);
    Tool& operator=(const Tool& other);
    void  removeCurrentWorker();
    void  setCurrentWorker(Worker& worker);
    Worker *getCurrentWorker();

    virtual void use()=0;
    virtual std::string getNameOfTool()=0;

};


#endif