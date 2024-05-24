
#ifndef WORKSHOP_TPP
#define WORKSHOP_TPP

#include "WorkShop.hpp"

// class Worker;
template <typename ToolType>
void  WorkShop::setType(){
    // std::cout<<<<"set type for workShop"<<std::endl;
    required_type = &typeid(ToolType);
    std::cout<<(std::string(required_type->name()).substr(1))<<" set type for workShop"<<std::endl;
    updateAfterSetType();
    // for(std::set<Worker*>::iterator it = worker_list.begin(); it != worker_list.end(); it++){
    //   if(!(*it)->hasNecessaryTool(*this)){
    //       this->removeWorker(**it);
    //   }
    // }

}

#endif