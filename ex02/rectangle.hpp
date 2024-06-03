/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:11:54 by areheman          #+#    #+#             */
/*   Updated: 2024/05/29 11:33:51 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "./shape.hpp"

class Rectangle:public Shape{
    protected:
        double width;
        double height;
    public:
        Rectangle(const double width, const double height):Shape(),width(width),height(height){}
        void calculating_area(){
            area = width * height;
            std::cout<<"area of the rectangle: "<<area<<std::endl;
        } 
        void calculating_perimeter(){
            perimeter = (width + height) * 2;
             std::cout<<"perimeter of the rectangle: "<<perimeter<<std::endl;
        }
};


#endif