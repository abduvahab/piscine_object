/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpeedController.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:30:50 by areheman          #+#    #+#             */
/*   Updated: 2024/05/24 18:06:26 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPEEDCONTROLLER_HPP
#define SPEEDCONTROLLER_HPP

#include "./PrintMe.hpp"
// #include <string>

class SpeedController{
    private:
        PrintMe print;

    public:
        void accelerate(float speed){
            print("increased speed by ", speed," units");
        }

};


#endif