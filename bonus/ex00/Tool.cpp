#include "./Tool.hpp"

Tool::Tool(const std::string name):numberOfUses(0),name_tool(name),currentWorker(NULL){};

void  Tool::setCurrentWorker(Worker& worker){
  currentWorker = &worker;
   std::cout<<worker.getName()<<" is setted as current worker for "<<this->getNameOfTool()<<std::endl;
}

void  Tool::removeCurrentWorker(){
  // currentWorker = NULL;
  std::cout<<"the "<<this->getNameOfTool()<<" is removed form the worker"<<std::endl;
  currentWorker = NULL;
}

Worker *Tool::getCurrentWorker(){
  std::cout<<"this is get Current worker function"<<std::endl;
  return this->currentWorker;
}