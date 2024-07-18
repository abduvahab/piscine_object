#ifndef SINGLETON_TPP
#define SINGLETON_TPP

#include "singleton.hpp"


template <typename T>
List<T>* List<T>::instance = NULL;

template <typename T>
void List<T>::addList(T* object){
    typedef typename std::vector<T*>::iterator _iterator;
    for(_iterator it=list.begin(); it!=list.end();it++){
        if((*it) == object){
            return ;
        }
    }
    list.push_back(object);
}


template <typename T>
std::vector<T*> List<T>::getList(){
    return list;
}

template <typename T>
void List<T>::destruct(){
    if(!list.empty()){
        typedef typename std::vector<T*>::iterator _iterator;
        for(_iterator it=list.begin(); it!=list.end();it++){
            delete (*it);
            *it = NULL;
        }  
        list.clear();
    }
    if(instance != NULL){
        delete instance;
        instance = NULL;
    }
}




#endif