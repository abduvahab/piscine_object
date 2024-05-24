#include "./Worker.hpp"

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
  return *this;
}

Worker::~Worker(){
  removeAllTool();
  std::cout<<name<<" has die"<<std::endl;
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
  std::cout<<this->name<<" has add a "<<tool.getNameOfTool()<<" to box"<<std::endl;
}

void Worker::removeTool(Tool &tool){
  for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
    if(*it == &tool){
      tool.removeCurrentWorker();
      tools.erase(it);
      break;
    }
  }
  std::cout<<this->getName()<<" has removed the "<<tool.getNameOfTool()<<" from box"<<std::endl;

}

void Worker::removeAllTool(){
  for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
      (*it)->removeCurrentWorker();
  }
  tools.clear();
  std::cout<<"remove all tools from worker"<<std::endl;
}



std::string Worker::getName()const{
  // std::cout<<name<< " returned his name"<<std::endl;
  return name;
}


bool Worker::work(WorkShop &workshop){
  for (std::vector<WorkShop*>::iterator it=workshops.begin(); it!=workshops.end(); it++){
        if(*it == &workshop){
          if(!tools.empty()){
            std::cout<<this->getName()<<" begin working  in a workshop"<<std::endl;
            // this->tool->use();
          }
          else{
            std::cout<<this->getName()<<" dont have a tool to work in workShop"<<std::endl;
          }
          return true;
        }
  }
  std::cout<<this->getName()<<" doesn't registered in this workshop"<<std::endl;
  return false;
  // workshop.removeWorker(*this);

}

void Worker::registerToWorkshop(WorkShop& workshop){
  for (std::vector<WorkShop*>::iterator it=workshops.begin(); it!=workshops.end(); it++){
        if(*it == &workshop){
          workshop.addWorker(*this);
          return ;
        }
  }
  workshops.push_back(&workshop);
  workshop.addWorker(*this);
}


void Worker::leaveWorkshop(WorkShop& workshop){
  for (std::vector<WorkShop*>::iterator it=workshops.begin(); it!=workshops.end(); it++){
        if(*it == &workshop){
          workshops.erase(it);
           std::cout<<getName()<<" leave from the workshop"<<std::endl;
          break;
        }
  } 
  // workshop.removeWorker(*this);
}

void Worker::printNameofTool(){
      std::cout<<this->getName()<<" has tools: ";
   for(std::vector<Tool*>::iterator it=tools.begin(); it!=tools.end(); it++){
      std::cout<<(*it)->getNameOfTool()<<" ";
    }
      std::cout<<std::endl;
}

// std::ostream& operator<<(std::ostream& o, const Worker& obj){
//   o<<"the worker :"<< obj.name<<std::endl
//       <<"x , y, z"<<obj.coordonnee.x<<", "<<obj.coordonnee.y<<", "<<obj.coordonnee.z<<std::endl
//       // <<"stat is:"<<std::endl
//       <<"level:"<<obj.stat.level<<std::endl
//       <<"exp:"<<obj.stat.exp<<std::endl
//       <<"Does worker have tool:"<<(obj.tool == NULL?"No":"Yes")<<std::endl;
//       return o;
// }
