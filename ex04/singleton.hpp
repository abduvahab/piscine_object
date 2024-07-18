/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:10:49 by areheman          #+#    #+#             */
/*   Updated: 2024/06/30 13:26:51 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <vector>
#include <iostream>

template <typename T>
class List{

    private:
        static List* instance;
        std::vector<T*>      list;
        List():list(){}
        ~List(){}
        List& operator=(const List& obj);
        List(const List& obj);


    public:
        static List* getInstance(){
            if(instance == NULL){
                instance = new List();
            }
            return instance;
        }
        void addList(T* object);
        std::vector<T*> getList();
        void destruct();
};

#include "singleton.tpp"


#endif