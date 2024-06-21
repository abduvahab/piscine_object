/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singetons.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:52:03 by areheman          #+#    #+#             */
/*   Updated: 2024/06/11 13:20:26 by areheman         ###   ########.fr       */
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
        static void destruct(){
            if(instance != NULL){
                delete instance;
                instance  = NULL;
            }
        }
        
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

template <typename T>
Singleton<T>* Singleton<T>::instance=NULL;

template <typename T>
void            Singleton<T>::addElement(T* element){

   typedef typename std::vector<T*>::iterator _iterator;
    for( _iterator it = _elements.begin(); it!=_elements.end();it++){
        if(*it == element){
            return ;
        }
    }
    _elements.push_back(element);
}

template <typename T>
std::vector<T*>    Singleton<T>::getAllElement(){
    return _elements;
}

#endif