#include "./Worker.hpp"

// void whoIam(const std::string myname){
//   std::cout<<myname<<std::endl;
// }

Worker::Worker(const std::string name):name(name),coordonnee(0,0,0),stat(0,0),tool(nullptr),workshops(){
   std::cout<<name<<" is born"<<std::endl;
}

Worker::Worker(const std::string name,const Position coordonnee, const Statistic stat)
        :name(name),
         coordonnee(coordonnee.x,coordonnee.y,coordonnee.z),
         stat(stat.level, stat.exp),
         tool(nullptr),
         workshops()
{
   std::cout<<name<<" is born with arguments"<<std::endl;

}

Worker::Worker(const Worker &other)
        :name(other.name),
         coordonnee(other.coordonnee.x, other.coordonnee.y,other.coordonnee.z),
         stat(other.stat.level, other.stat.exp),
         tool(nullptr),
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
  this->tool = nullptr;
  this->name = other.name;
  return *this;
}

Worker::~Worker(){
  takeToolFromWorker();
  std::cout<<name<<" has die"<<std::endl;
}

void Worker::giveToolToWorker(Tool& tool){
  //check the tool is took by others, 
  // if yes, remove the current worker, and remove the tool from the worker who hold
  // if no, give the address of tool the new worker
  if(tool.getCurrentWorker() != nullptr){
    Worker *formerWorker = tool.getCurrentWorker();
    formerWorker->takeToolFromWorker();
  }
  this->takeToolFromWorker();
  this->tool = &tool;
  tool.setCurrentWorker(*this);
  std::cout<<this->name<<" has took a "<<tool.getNameOfTool()<<std::endl;
}

std::string Worker::getName()const{
  // std::cout<<name<< " returned his name"<<std::endl;
  return name;
}

void Worker::takeToolFromWorker(){

  if(tool != nullptr){
    tool->removeCurrentWorker();
    tool = nullptr;
    std::cout<<name<<" has loose his tool"<<std::endl;
  }
  else{
    std::cout<<name<<" doesn't have a tool"<<std::endl;
  }
}

void Worker::work(WorkShop &workshop){
  for (std::vector<WorkShop*>::iterator it=workshops.begin(); it!=workshops.end(); it++){
        if(*it == &workshop){
          if(tool!=nullptr){
            std::cout<<this->getName()<<" begin working with "<<tool->getNameOfTool()<<"in a workshop"<<std::endl;
            this->tool->use();
          }
          else{
            std::cout<<this->getName()<<" dont have a tool to work in workShop"<<std::endl;
          }
          return ;
        }
  }
  std::cout<<this->getName()<<" doesn't registered in this workshop"<<std::endl;
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
          break;
        }
  } 
  workshop.removeWorker(*this);
}

std::ostream& operator<<(std::ostream& o, const Worker& obj){
  o<<"the worker :"<< obj.name<<std::endl
      <<"x , y, z"<<obj.coordonnee.x<<", "<<obj.coordonnee.y<<", "<<obj.coordonnee.z<<std::endl
      // <<"stat is:"<<std::endl
      <<"level:"<<obj.stat.level<<std::endl
      <<"exp:"<<obj.stat.exp<<std::endl
      <<"Does worker have tool:"<<(obj.tool == nullptr?"No":"Yes")<<std::endl;
      return o;
}
