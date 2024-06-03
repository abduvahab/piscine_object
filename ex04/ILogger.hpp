/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILogger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:28:01 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 11:43:36 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <iostream>

// Dependency Inversion Principle (DIP)

// High-level modules should not depend on low-level modules. 
// Both should depend on abstractions. Also, 
// abstractions should not depend on details. 
// Details should depend on abstractions. 
// This principle helps in decoupling the code 
// and making it more modular.

class ILogger{

    public:
        virtual ~ILogger(){}
        virtual void write(std::string msg)=0;

};


#endif