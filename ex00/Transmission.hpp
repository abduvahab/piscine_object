/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transmission.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:30:07 by areheman          #+#    #+#             */
/*   Updated: 2024/05/27 13:45:43 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include "./PrintMe.hpp"

class Transmission{

    private:
        PrintMe print;

    public:
        void shfir_gears_up(){
            print("Transmission shift gears up");
        }
        void shfir_gears_down(){
            print("Transmission shift gears down");

        }
        void reverse(){
            print("Transmission reverse gear");

        }

};


#endif