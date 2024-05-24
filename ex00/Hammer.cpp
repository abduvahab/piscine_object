#include "./Hammer.hpp"

void whoIam2(const std::string myname){
  std::cout<<myname<<std::endl;
}

Hammer::Hammer():Tool(),name_tool("hammer"){
  whoIam2("Hammer Constructor without arguments");
}

Hammer::Hammer(const Hammer& other):Tool(){
  whoIam2("Hammer copy Constructor ");
  *this = other;
}

Hammer& Hammer::operator=(const Hammer& other){
  whoIam2("Hammer Assign operator");
  if(this == &other){
    return *this;
  }
  this->name_tool = other.name_tool;
  this->numberOfUses = other.numberOfUses;
  this->currentWorker = other.currentWorker;
  return *this;
}

Hammer::~Hammer(){
  currentWorker = NULL;
  whoIam2("Hammer distructor");
}

void  Hammer::use(){
  numberOfUses += 1;
  std::cout<<"hammer is used by "<<currentWorker->getName()<<" "<<numberOfUses<<" times"<<std::endl;
}
std::string Hammer::getNameOfTool(){
  return this->name_tool;
}