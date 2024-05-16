
#include "./Worker.hpp"
#include "./Shovel.hpp"
#include "./Hammer.hpp"
#include "./WorkShop.hpp"

int main(){


  std::cout<<"-----create object----"<<std::endl;
  Shovel s_1;
  Hammer h_1;
  Worker jhon("jhon");
  Worker tom("tom");
  WorkShop shop;
  WorkShop shop1;
  std::cout<<"-----take and lose tools----"<<std::endl;
  jhon.giveToolToWorker(s_1);
  tom.giveToolToWorker(h_1);
  jhon.giveToolToWorker(h_1);
  std::cout<<"-----register and leave from workshop----"<<std::endl;
  jhon.registerToWorkshop(shop);
  tom.registerToWorkshop(shop);
  tom.registerToWorkshop(shop1);
  shop.executeWorkDay();
  jhon.leaveWorkshop(shop);
  shop.executeWorkDay();
  shop1.executeWorkDay();
  std::cout<<"-----leave without registor----"<<std::endl;
  jhon.leaveWorkshop(shop);
  shop.removeWorker(jhon);
  shop.removeWorker(tom);
  shop1.executeWorkDay();
  std::cout<<"-----work without registor----"<<std::endl;
  jhon.work(shop);
  std::cout<<"-----end of example ----"<<std::endl;


}