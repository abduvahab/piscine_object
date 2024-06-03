/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:58:26 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 11:43:25 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

// Liskov Substitution Principle (LSP)

// Objects of a superclass should be replaceable with 
// objects of a subclass without affecting the 
// correctness of the program. 



class Shape{

    protected:
        double area;
        double perimeter;

    public:
        Shape():area(0){};
        virtual void calculating_area()=0;
        virtual void calculating_perimeter()=0;
};



#endif