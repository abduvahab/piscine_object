/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:39:13 by areheman          #+#    #+#             */
/*   Updated: 2024/07/20 12:34:28 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include "node.hpp"

class Train{

    protected:
        static int          ID;
        int                 id;
        std::string         name;
        double              maxAcceleration;
        double              maxBrake;
        Node                departureStation;
        Node                arrivalStation;
        std::string         departureTime;

        

    public:
        Train(double maxAcceleration , double maxBrake);
        Train(const std::string &_name, double maxAcceleration , double maxBrake, const Node &departureStation, const Node &arrivalStation);
        Train(const Train& obj);
        Train& operator=(const Train& obj);

        int                 getId();
        std::string         getName();
        double              getMaxAcceleration();
        double              getMaxBrake();
        Node                getDepartureStation();
        Node                getArrivalStation();
        std::string         getDepartureTime();


        void                setName(const std::string &name);
        void                setMaxAcceleration( double maxAcceleration);
        void                setMaxBrake(double maxBrake);
        void                setDepartureStation(const Node &departureStation);
        void                setArrivalStation(const Node &arrivalStation);
        void                setDepartureTime(const std::string &time);


};



#endif