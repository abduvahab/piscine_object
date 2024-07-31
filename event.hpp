/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:10:37 by areheman          #+#    #+#             */
/*   Updated: 2024/07/20 11:35:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include "node.hpp"

class Event{

    protected:
        std::string      name;
        double          probability;
        int             duration;//in minute
        Node            location;

    public:
        Event(double probability, int duration);
        Event(const std::string &_name, double probability, int duration, const Node &location);
        Event(const Event& obj);
        Event& operator=(const Event& obj);

        std::string     getName();
        double          getProbability();
        int             getDuration();
        Node            getLocation();

        void            setName(const std::string &_name);
        void            setProbability(double probability);
        void            setDuration(int duration);
        void            setLocation(const Node &location);
        

};



#endif