#include "./Shovel.hpp"

void whoIam(const std::string myname){
  std::cout<<myname<<std::endl;
}

Shovel::Shovel():Tool("shovel"){
  whoIam("Shovel Constructor without arguments");
}

Shovel::Shovel(const Shovel& other):Tool(other.name_tool){
  whoIam("Shovel copy Constructor ");
  *this = other;
}

Shovel& Shovel::operator=(const Shovel& other){
  whoIam("Shovel Assign operator");
  if(this == &other){
    return *this;
  }
  this->name_tool = other.name_tool;
  this->numberOfUses = other.numberOfUses;
  this->currentWorker = other.currentWorker;
  return *this;
}

Shovel::~Shovel(){
  currentWorker = NULL;
  whoIam("Shovel distructor");
}

void  Shovel::use(){
  numberOfUses += 1;
  std::cout<<"shovel is used by "<<currentWorker->getName()<<" "<<numberOfUses<<" times"<<std::endl;
}
std::string Shovel::getNameOfTool(){
  return this->name_tool;
}

// void  Shovel::setCurrentWorker(Worker& worker){
//   currentWorker = &worker;
//    std::cout<<worker.getName()<<" is setted as current worker for shovel"<<std::endl;
// }

// void  Shovel::removeCurrentWorker(){
//   // currentWorker = NULL;
//   std::cout<<"the shovel is removed form the worker"<<std::endl;
//   currentWorker = NULL;
// }

// Worker *Shovel::getCurrentWorker(){
//   std::cout<<"this is get Current worker function"<<std::endl;
//   return this->currentWorker;
// }