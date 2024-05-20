
#include "./Worker.hpp"
#include "./Shovel.hpp"
#include "./Hammer.hpp"
#include "./WorkShop.hpp"

int main(){


  std::cout<<"-----create object----"<<std::endl;
  Shovel s_1;
  Shovel s_2;
  Hammer h_1;
  Hammer h_2;
  Worker jhon1("jhon1");
  Worker jhon2("jhon2");
  Worker tom1("tom1");
  Worker tom2("tom2");
  WorkShop shop_hmmer;
  shop_hmmer.setType<Hammer>();
  WorkShop shop_shovel;
  shop_shovel.setType<Shovel>();
  std::cout<<"-----take tools----"<<std::endl;
  jhon1.addTool(s_1);
  jhon1.addTool(h_1);
  jhon2.addTool(s_2);
  tom1.addTool(h_2);
  jhon1.printNameofTool();
  jhon2.printNameofTool();
  tom1.printNameofTool();
  tom2.printNameofTool();
  std::cout<<"----- lose tools----"<<std::endl;
  tom2.addTool(h_2);
  tom2.addTool(h_1);
  tom2.addTool(h_1);
  jhon1.printNameofTool();
  jhon2.printNameofTool();
  tom1.printNameofTool();
  tom2.printNameofTool();

  std::cout<<"-----register and leave from workshop----"<<std::endl;
  tom1.registerToWorkshop(shop_hmmer);
  tom2.registerToWorkshop(shop_hmmer);
  jhon1.registerToWorkshop(shop_shovel);
  jhon2.registerToWorkshop(shop_shovel);
  shop_hmmer.printWorker();
  shop_shovel.printWorker();
  jhon1.leaveWorkshop(shop_shovel);
  shop_shovel.printWorker();
  shop_hmmer.removeWorker(tom2);
  shop_hmmer.printWorker();
  shop_shovel.executeWorkDay();
  jhon2.printNameofTool();
  shop_shovel.setType<Hammer>();
  shop_shovel.printWorker();

  std::cout<<"-----get tool and remove ----"<<std::endl;
  jhon1.addTool(h_1);
  jhon1.addTool(h_2);
  jhon1.addTool(s_1);
  shop_hmmer.printWorker();
  jhon1.printNameofTool();
  jhon1.registerToWorkshop(shop_hmmer);
  Hammer *hammer_1 = jhon1.getTool<Hammer>();
  jhon1.removeTool(*hammer_1);
  jhon1.printNameofTool();
  shop_hmmer.printWorker();
  hammer_1 = jhon1.getTool<Hammer>();
  jhon1.removeTool(*hammer_1);
  jhon1.printNameofTool();
  shop_hmmer.printWorker();
  std::cout<<"----- worker leave fron workshop  and begin daywor  ----"<<std::endl;
  shop_hmmer.setType<Shovel>();
  jhon1.registerToWorkshop(shop_hmmer);
  shop_hmmer.printWorker();
  jhon1.leaveWorkshop(shop_hmmer);
  shop_hmmer.executeWorkDay();
  std::cout<<"-----end of example ----"<<std::endl;


}