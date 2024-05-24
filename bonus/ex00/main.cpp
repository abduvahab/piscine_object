
#include "./Worker.hpp"
#include "./Shovel.hpp"
#include "./Hammer.hpp"
#include "./WorkShop.hpp"

int main(){

  {
    Shovel s_1;
    Shovel s_2;
    Shovel s_3;
    Hammer h_1;
    Hammer h_2;
    Hammer h_3;
    Worker jhon("jhon");
    jhon.addTool(h_1);
    jhon.addTool(s_1);
    jhon.printNameofTool();
    Worker jhon1("jhon1");
    jhon1.addTool(h_3);
    jhon1.printNameofTool();

    Worker tom("tom");
    // tom.work();
    tom.addTool(s_2);
    tom.addTool(h_2);
    tom.printNameofTool();
    // jhon1.addTool(s_3);
    Worker tom2("tom2");
    tom2.addTool(s_3);
    tom2.printNameofTool();
    WorkShop shop;
    shop.setType<Hammer>();
    WorkShop shop1;
    shop1.setType<Shovel>();
    WorkShop shop2;
    shop2.setType<Hammer>();
    tom.work(shop2);

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
    std::cout<<"--------------------------------"<<std::endl;
    shop.printWorker();
    shop1.printWorker();
    shop2.printWorker();
    std::cout<<"--------------------------------"<<std::endl;
    tom2.work(shop);
    std::cout<<"--------------------------------"<<std::endl;
    shop.printWorker();     
    shop.executeWorkDay();
    shop.printWorker();
    std::cout<<"--------------------------------"<<std::endl;
    shop1.executeWorkDay();
    shop1.printWorker();
    std::cout<<"--------------------------------"<<std::endl;
    shop2.executeWorkDay();
    shop2.printWorker();
  }
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
  std::cout<<"-----take tools---------------------"<<std::endl;
  jhon1.addTool(s_1);
  jhon1.addTool(h_1);
  jhon2.addTool(s_2);
  tom1.addTool(h_2);
  std::cout<<"-------------------------------------"<<std::endl;
  jhon1.printNameofTool();
  jhon2.printNameofTool();
  tom1.printNameofTool();
  tom2.printNameofTool();
  std::cout<<"----- lose tools----------------------------"<<std::endl;
  tom2.addTool(h_2);
  tom2.addTool(h_1);
  tom2.addTool(h_1);
  std::cout<<"-------------------------------------"<<std::endl;
  jhon1.printNameofTool();
  jhon2.printNameofTool();
  tom1.printNameofTool();
  tom2.printNameofTool();

  std::cout<<"-----register and leave from workshop----------------"<<std::endl;
  tom1.registerToWorkshop(shop_hmmer);
  tom2.registerToWorkshop(shop_hmmer);
  jhon1.registerToWorkshop(shop_shovel);
  jhon2.registerToWorkshop(shop_shovel);
  std::cout<<"-------------------------------------"<<std::endl;
  shop_hmmer.printWorker();
  shop_shovel.printWorker();
  std::cout<<"-------------------------------------"<<std::endl;
  jhon1.leaveWorkshop(shop_shovel);
  std::cout<<"-------------------------------------"<<std::endl;
  shop_shovel.printWorker();
  shop_shovel.executeWorkDay();
  std::cout<<"-------------------------------------"<<std::endl;
  shop_hmmer.removeWorker(tom2);
  shop_hmmer.printWorker();
  std::cout<<"-------------------------------------"<<std::endl;
  jhon2.printNameofTool();
  shop_shovel.setType<Hammer>();
  std::cout<<"-------------------------------------"<<std::endl;
  shop_shovel.printWorker();

  std::cout<<"-----get tool and remove ----"<<std::endl;
  jhon1.addTool(h_1);
  jhon1.addTool(h_2);
  jhon1.addTool(s_1);
  std::cout<<"-------------------------------------"<<std::endl;
  shop_hmmer.printWorker();
  jhon1.printNameofTool();
  std::cout<<"-------------------------------------"<<std::endl;
  jhon1.registerToWorkshop(shop_hmmer);
  Hammer *hammer_1 = jhon1.getTool<Hammer>();
  jhon1.removeTool(*hammer_1);
  std::cout<<"-------------------------------------"<<std::endl;
  jhon1.printNameofTool();
  shop_hmmer.printWorker();
  hammer_1 = jhon1.getTool<Hammer>();
  jhon1.removeTool(*hammer_1);
  std::cout<<"-------------------------------------"<<std::endl;
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