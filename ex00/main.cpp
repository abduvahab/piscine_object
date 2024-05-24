
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
  Worker jhon1("jhon1");
  Worker tom2("tom2");
  WorkShop shop;
  WorkShop shop1;
  WorkShop shop2;


  shop.addWorker(jhon);
  shop.addWorker(tom);
  shop.addWorker(jhon1);
  shop.addWorker(tom2);
  shop1.addWorker(jhon);
  shop1.addWorker(tom);
  shop1.addWorker(tom2);
  shop2.addWorker(jhon);
  shop.removeWorker(jhon);
  shop.removeWorker(jhon1);

  tom2.work(shop);
  
  shop.printWorker();     
  shop.executeWorkDay();
  std::cout<<"--------------------------------"<<std::endl;
  shop1.executeWorkDay();
  std::cout<<"--------------------------------"<<std::endl;
  shop2.executeWorkDay();
  std::cout<<"-----take and lose tools----"<<std::endl;
  jhon.addTool(s_1);
  tom.addTool(h_1);
  jhon.addTool(h_1);
  tom.printNameofTool();
  jhon.removeTool(s_1);
  jhon.printNameofTool();
  std::cout<<"-----register and leave from workshop----"<<std::endl;
  jhon.registerToWorkshop(shop);
  tom.registerToWorkshop(shop);
  tom.registerToWorkshop(shop1);
  shop.printWorker();
  shop1.printWorker();
  shop.executeWorkDay();
  //he didnt tell workshop that i am going
  jhon.leaveWorkshop(shop);
  shop.printWorker();
  //workshop remove the jhon , because he left
  shop.executeWorkDay();
  shop1.removeWorker(tom);
  shop1.executeWorkDay();
  shop1.removeWorker(tom);
  std::cout<<"-----leave without registor----"<<std::endl;
  jhon.leaveWorkshop(shop);
  shop.removeWorker(jhon);
  shop.removeWorker(tom);
  shop1.executeWorkDay();
  std::cout<<"-----work without registor----"<<std::endl;
  jhon.work(shop);
  std::cout<<"-----end of example ----"<<std::endl;


}