/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrakeControl.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:31:57 by areheman          #+#    #+#             */
/*   Updated: 2024/05/24 18:11:41 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAKECONTROL_HPP
#define BRAKECONTROL_HPP

#include "./PrintMe.hpp"

class BrakeControl{
    private:
        PrintMe print;

    public:
        void apply_force_on_Brake(float force){
            print("applied ", force," on the brake");
        }
        void emergencyBrake(){
            print("The Emergency brake applied by maxium force");
        }

};


#endif