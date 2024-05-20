#include "./Tool.hpp"

Tool::Tool():numberOfUses(0),currentWorker(nullptr){};

void  Tool::setCurrentWorker(Worker& worker){
  currentWorker = &worker;
   std::cout<<worker.getName()<<" is setted as current worker for "<<this->getNameOfTool()<<std::endl;
}

void  Tool::removeCurrentWorker(){
  // currentWorker = nullptr;
  std::cout<<"the "<<this->getNameOfTool()<<" is removed form the worker"<<std::endl;
  currentWorker = nullptr;
}

Worker *Tool::getCurrentWorker(){
  std::cout<<"this is get Current worker function"<<std::endl;
  return this->currentWorker;
}