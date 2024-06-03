/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:56 by areheman          #+#    #+#             */
/*   Updated: 2024/05/29 12:04:20 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "./shape.hpp"
#include <cmath>

class Triangle:public Shape{
    protected:
        double side1, side2, side3;

    public:
        Triangle(const double side1, const double side2,const double side3):Shape(),side1(side1),side2(side2),side3(side3){
            if ((side1 + side2 <= side3) || (side2 + side3 <= side1) || (side3 + side1 <= side1)){
                throw Traingle_exception("side parameters are not suitable for creating a triangle!");
            }
        }
        void calculating_area(){
            double s = (side1 + side2+ side3)/2;
            area = std::sqrt(s*(s- side1)*(s- side2)*(s- side3));
            std::cout<<"area of the triangle: "<<area<<std::endl;
        }

        void calculating_perimeter(){
            perimeter = side1 + side2 + side3;
             std::cout<<"perimeter of the rectangle: "<<perimeter<<std::endl;
        }

        class Traingle_exception:public std::exception{
            private:
                std::string msg;
            public:
                Traingle_exception(const std::string& msg):msg(msg){}
                ~Traingle_exception() throw(){}
                const char* what() const throw(){
                    return msg.c_str();
                }
        };
        
};


#endif