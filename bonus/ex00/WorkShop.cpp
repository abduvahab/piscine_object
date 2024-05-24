#include "./WorkShop.hpp"

WorkShop::WorkShop():worker_list(),required_type(NULL){
    std::cout<<"workshop constructor"<<std::endl;
    // required_type = &typeid(ToolType);
}

WorkShop::WorkShop(const WorkShop &other){
    std::cout<<"workshop copy constructor"<<std::endl;
    *this= other;
}
WorkShop& WorkShop::operator=(const WorkShop &other){
    std::cout<<"workshop assign opeartor"<<std::endl;
    if(this == &other){
        return *this;
    }
    this->worker_list = other.worker_list;
    return *this;
}

WorkShop::~WorkShop(){
    std::cout<<"workshop destructor"<<std::endl;
}

bool WorkShop::addWorker(Worker& worker){
    if(required_type == NULL){
        return false;
    }
    if(checkRequiredTool(worker)){
        worker_list.insert(&worker);
        std::cout<<worker.getName()<<" is added to workshop"<<std::endl;
        return true;
    }
    return false;
    
}

// std::set<Worker *>::iterator WorkShop::removeWorker(Worker& worker){
void WorkShop::removeWorker(Worker& worker){
    // for (std::set<Worker *>::iterator it = worker_list.begin(); it != worker_list.end();){
    //     if((*it) == &worker){
    //         worker_list.erase(it);
    //         worker.leaveWorkshop(*this);
    //     }
    // }
    std::set<Worker *>::iterator it = worker_list.find(&worker);
    if( it != worker_list.end()){
        worker_list.erase(it);
        worker.leaveWorkshop(*this);
        std::cout<<worker.getName()<<" is removed from workshop"<<std::endl;
        return;
    }
}

void WorkShop::deleteWorker(Worker& worker){
    std::set<Worker *>::iterator it = worker_list.find(&worker);
    if( it != worker_list.end()){
         worker_list.erase(it);
        // worker.leaveWorkshop(*this);
        std::cout<<worker.getName()<<" is removed from workshop"<<std::endl;
        return ;
    }
    return ;
}


bool WorkShop::checkRequiredTool(Worker& worker){
    return worker.hasNecessaryTool(*this);
}

const std::type_info* WorkShop::getRequiredType() {
    return required_type;
}

void WorkShop::executeWorkDay(){
    std::cout << "workShop begin to execute day work:" << std::endl;
    std::set<Worker*>::iterator it=worker_list.begin();
    while ( it!=worker_list.end()){
        if(!(*it)->work(*this)){
           deleteWorker(**it++);
        //    it++;
        }
        else{
            it++;
        }
    }
}

void WorkShop::printWorker(){
    std::cout<<"the worker in the worshop: ";
    for (std::set<Worker*>::iterator it=worker_list.begin(); it!=worker_list.end(); it++){
        std::cout<<(*it)->getName()<<" ";
    }
    std::cout<<std::endl;
}

void WorkShop::updateAfterSetType(){
    std::set<Worker*>::iterator it = worker_list.begin(); 
    while(it != worker_list.end()){
      if(!(*it)->hasNecessaryTool(*this)){
          this->removeWorker(**it++);
        //   it++;
      }
      else{
        it++;
      }
    }
}
