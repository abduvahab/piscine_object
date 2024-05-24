#include "./WorkShop.hpp"

WorkShop::WorkShop():worker_list(){
    std::cout<<"workshop constructor"<<std::endl;
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

void WorkShop::addWorker(Worker& worker){
    for (std::vector<Worker*>::iterator it=worker_list.begin(); it!=worker_list.end(); it++){
        if(*it == &worker){
            std::cout<<worker.getName()<<" is already in the workshop"<<std::endl;
            return ;
        }
    }
    worker_list.push_back(&worker);
    
}

void WorkShop::removeWorker(Worker& worker){
    for (std::vector<Worker*>::iterator it=worker_list.begin(); it!=worker_list.end(); it++){
        if(*it == &worker){
            worker_list.erase(it);
            worker.leaveWorkshop(*this);
            std::cout<<worker.getName()<<" is released from workshop"<<std::endl;
            return ;
        }
    }
    std::cout<<worker.getName()<<" dont exist in the workshop"<<std::endl;
}


std::vector<Worker*>::iterator WorkShop::deleteWorker(Worker& worker){
    std::vector<Worker*>::iterator it=worker_list.begin();
    while ( it!=worker_list.end()){
        if(*it == &worker){
           return  worker_list.erase(it);

        }
        else{
            it++;
        }
    }
    return it;
}

void WorkShop::executeWorkDay(){
    std::cout << "workShop begin to execute day work:" << std::endl;
    for (std::vector<Worker*>::iterator it=worker_list.begin(); it!=worker_list.end();){
        if(!(*it)->work(*this)){
            it = deleteWorker(**it);
        }
        else{
            ++it;
        }
    }

}

void WorkShop::printWorker(){
    std::cout<<"the worker in the worshop: ";
    for (std::vector<Worker*>::iterator it=worker_list.begin(); it!=worker_list.end(); it++){
        std::cout<<(*it)->getName()<<" ";
    }
    std::cout<<std::endl;
}