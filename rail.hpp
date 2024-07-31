/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rail.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:11:07 by areheman          #+#    #+#             */
/*   Updated: 2024/07/19 20:48:04 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAIL_HPP
#define RAIL_HPP

#include <iostream>
#include "node.hpp"


class Rail{

    protected:
        Node    node_start;
        Node    node_end;
        double  length;

    public:
        Rail();
        Rail(const Node &node_start, const Node &node_end, double length);
        Rail(const Rail& obj);
        Rail& operator=(const Rail& obj);
        Node    getStartNode();
        Node    getEndNode();
        double  getLength();

        void    setStartNode(Node& node);
        void    setEndNode(Node& node);
        void    setLength(double len);
   
};


#endif