/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wheel.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:32:54 by areheman          #+#    #+#             */
/*   Updated: 2024/05/24 18:16:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEEL_HPP
#define WHEEL_HPP


#include "./PrintMe.hpp"

class Wheel{
    private:
        PrintMe print;

    public:
        void  turn_wheel(float angle){
            print("the Wheels turned by ", angle, " degrees");
        }
        
        void straighten_wheels(){
            print("the Wheels straightened");
        }

};


#endif