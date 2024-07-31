/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:37:09 by areheman          #+#    #+#             */
/*   Updated: 2024/07/19 20:16:14 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node{

    protected:
        std::string name;

    public:
        Node();
        Node(const std::string &_name);
        Node(const Node& obj);
        Node& operator=(const Node& obj);

        std::string getName();
        void        setName(const std::string& _name);
        

};



#endif