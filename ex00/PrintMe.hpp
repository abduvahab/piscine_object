/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintMe.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:35:55 by areheman          #+#    #+#             */
/*   Updated: 2024/05/24 18:06:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTME_HPP
#define PRINTME_HPP

#include <iostream>

class PrintMe{
    private:
        
    public:
        PrintMe& operator()(const std::string& msg){
            std::cout<<msg<<std::endl;
            return *this;
        }
        PrintMe& operator()(const std::string& msg1,const std::string& msg2){
            std::cout<<msg1<<msg2<<std::endl;
            return *this;
        }
        PrintMe& operator()(const std::string& msg1,float num,const std::string& msg3){
            std::cout<<msg1<<num<<msg3<<std::endl;
            return *this;
        }

};


#endif