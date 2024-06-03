/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:21:45 by areheman          #+#    #+#             */
/*   Updated: 2024/05/29 11:34:19 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "./shape.hpp"

class Circle:public Shape{
    protected:
        double radius;
        double PI;
    public:
        Circle(const double radius):Shape(),radius(radius),PI(3.14){}
        void calculating_area(){
            area = (radius * radius)*PI;
            std::cout<<"area of the circle: "<<area<<std::endl;
        }
        void calculating_perimeter(){
            perimeter = (radius * PI) * 2;
             std::cout<<"perimeter of the rectangle: "<<perimeter<<std::endl;
        }
        
};


#endif