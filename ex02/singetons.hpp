/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singetons.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:52:03 by areheman          #+#    #+#             */
/*   Updated: 2024/06/24 17:05:59 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGETONS_HPP
#define SINGETONS_HPP

#include <iostream>
#include <vector>

template <typename T>
class Singleton{
    
    public:
        static Singleton& getInstance(){
            if(instance == NULL){
                instance = new Singleton;
            }
            return *instance;
        }
        
        void destruct();
        
        void            addElement(T* objet);
        std::vector<T*>    getAllElement();

    private:

        Singleton():_elements(){}
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
        ~Singleton(){}
        static Singleton* instance;
        std::vector<T*> _elements;
   
};

#include "singetons.tpp"

#endif