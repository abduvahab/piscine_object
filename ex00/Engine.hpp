/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:29:19 by areheman          #+#    #+#             */
/*   Updated: 2024/05/24 17:48:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "./PrintMe.hpp"

class Engine{
    private:
        PrintMe print;

    public:
        void startEngin(){
            print("the engine started");
        }
        void stopEngine(){
            print("the engine stop");
        }

};


#endif