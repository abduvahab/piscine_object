#ifndef SINGETONS_TPP
#define SINGETONS_TPP

#include "singetons.hpp"

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

template <typename T>
void Singleton<T>::destruct(){
    if(!_elements.empty()){
        typedef typename std::vector<T*>::iterator _iterator;
        for( _iterator it = _elements.begin(); it != _elements.end(); it++){
            delete (*it);
            *it = NULL;
        }
        _elements.clear();
    }
    if(instance != NULL){
        delete instance;
        instance  = NULL;
    }
}


#endif