/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:57:26 by areheman          #+#    #+#             */
/*   Updated: 2024/05/27 13:51:23 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./car.hpp"

int main(){

    Car car;
    car.start();
    car.shift_gears_up();
    car.accelerate(50);
    car.apply_force_on_brakes(10);
    car.shift_gears_down();
    car.turn_wheel(90);
    car.straighten_wheels();
    car.apply_emergency_brakes();
    car.stop();
    car.reverse();
    return 0;
}