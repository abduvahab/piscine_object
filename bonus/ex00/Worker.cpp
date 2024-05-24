#include "./Worker.hpp"
#include <typeinfo>
#include <string>
// void whoIam(const std::string myname){
//   std::cout<<myname<<std::endl;
// }

Worker::Worker(const std::string name):name(name),coordonnee(0,0,0),stat(0,0),tools(),workshops(){
   std::cout<<name<<" is born"<<std::endl;
}

Worker::Worker(const std::string name,const Position coordonnee, const Statistic stat)
        :name(name),
         coordonnee(coordonnee.x,coordonnee.y,coordonnee.z),
         stat(stat.level, stat.exp),
         tools(),
         workshops()
{
   std::cout<<name<<" is born with arguments"<<std::endl;

}

Worker::Worker(const Worker &other)
        :name(other.name),
         coordonnee(other.coordonnee.x, other.coordonnee.y,other.coordonnee.z),
         stat(other.stat.level, other.stat.exp),
         tools(),
         workshops()
{

  std::cout<<name<<" is born with copy constructor"<<std::endl;

}

Worker& Worker::operator=(const Worker &other){
  std::cout<<name<<" is born with assignment operator"<<std::endl;
  if (this == &other){
    return *this;
  }
  this->coordonnee.x=other.coordonnee.x;
  this->coordonnee.y=other.coordonnee.y;
  this->coordonnee.z=other.coordonnee.z;
  this->stat.exp = other.stat.exp;
  this->stat.level = other.stat.level;
  this->name = other.name;
  this->tools = other.tools;
  this->workshops = other.workshops;
  return *this;
}

Worker::~Worker(){
  takeToolsFromWorker();
  std::cout<<name<<" has die"<<std::endl;
}




std::string Worker::getName()const{
  // std::cout<<name<< " returned his name"<<std::endl;
  return name;
}


void Worker::addTool(Tool &tool){
  for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
    if(*it == &tool){
      std::cout<<this->getName()<<" already has the "<<tool.getNameOfTool()<<std::endl;
      return ;
    }
  }

  if(tool.getCurrentWorker() != NULL){
    Worker *formerWorker = tool.getCurrentWorker();
    formerWorker->removeTool(tool);
  }
  tools.push_back(&tool);
  tool.setCurrentWorker(*this);
  std::cout<<this->getName();
  std::cout<<" has add a ";
  std::cout<<tool.getNameOfTool();
  std::cout<<" to box"<<std::endl;
}

void Worker::removeTool(Tool &tool){
  bool isExist = false;
  for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
    if(*it == &tool){
      isExist = true;
      tool.removeCurrentWorker();
      tools.erase(it);
      break;
    }
  }

  if(isExist){
    std::cout<<this->getName()<<" has removed the "<<tool.getNameOfTool()<<" from box"<<std::endl;
    std::set<WorkShop*>::iterator it= workshops.begin();
    while(it != workshops.end()){
      if(!hasNecessaryTool(**it)){
        (*it)->deleteWorker(*this);
        leaveWorkshop(**it++);
        // it++;
      }
      else{
        it++;
      }
    }
  }
}

void Worker::registerToWorkshop(WorkShop& workshop){
  if(workshop.addWorker(*this)){
    this->workshops.insert(&workshop);
  }
}

bool Worker::hasNecessaryTool(WorkShop& workshop){
  if(workshop.getRequiredType() == NULL){
    return false;
  }
  const std::type_info* requiredType = workshop.getRequiredType();
  std::string requiredTypeName = requiredType->name();
  for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
    Tool *tl =*it;
    const std::type_info &toolType = typeid(*tl);
    std::string toolTypeName = toolType.name();
    if( toolTypeName == requiredTypeName){
      return true;
    }
  }
  std::cout<<"--------------------------------------======================="<<std::endl;
  return false;
}


void Worker::leaveWorkshop(WorkShop& workshop){
  std::set<WorkShop*>::iterator it=workshops.find(&workshop);
    if(it != workshops.end()){
      workshops.erase(it);
      return ;
    }
}



void Worker::takeToolsFromWorker(){

  if(!tools.empty()){
    for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
      (*it)->removeCurrentWorker();
    }
    tools.clear();
    std::cout<<name<<" has loose his tool"<<std::endl;
  }
  else{
    std::cout<<name<<" doesn't have a tool"<<std::endl;
  }
}


bool Worker::work(WorkShop &workshop){
  if(this->workshops.find(&workshop) != this->workshops.end()){
    std::cout<<this->getName()<<" begin working with in a workshop"<<std::endl;
    return true;
  }
  // workshop.removeWorker(*this);
  std::cout<<this->getName()<<" doesn't registered in this workshop"<<std::endl;
  return false;
}

void Worker::printNameofTool(){

      std::cout<<this->getName()<<" has tools: ";
   for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
      std::cout<<(*it)->getNameOfTool()<<" ";
    }
      std::cout<<std::endl;
}


