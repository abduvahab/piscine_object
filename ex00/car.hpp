/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:41:38 by areheman          #+#    #+#             */
/*   Updated: 2024/05/24 18:17:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAR_HPP
#define CAR_HPP

#include "./Engine.hpp"
#include "./SpeedController.hpp"
#include "./BrakeControl.hpp"
#include "./Wheel.hpp"

class Car{
    private:
        Engine          engine;
        // Transmission    transmission;
        Wheel           wheel;
        BrakeControl    brakeControl;
        SpeedController speedController;

    public:
        void start(){
            engine.startEngin();
        }

        void stop(){
            engine.stopEngine();
        }

        void accelerate(float speed){
            speedController.accelerate(speed);
        }

        void apply_force_on_brakes(float force){
            brakeControl.apply_force_on_Brake(force);
        }

        void apply_emergency_brakes(){
            brakeControl.emergencyBrake();
        }

        void turn_wheel(float angle){
            wheel.turn_wheel(angle);
        }

        void straighten_wheels(){
            wheel.straighten_wheels();
        }

};


#endif