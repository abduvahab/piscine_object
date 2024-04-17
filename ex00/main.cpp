#include "iostream"
#include "./Account.hpp"
#include "./Bank.hpp"

int main(){
  std::cout<<"create a bank"<<std::endl;
  Bank bank(0);
  std::cout<<bank;
  std::cout<<"end create a bank"<<std::endl;

  std::cout<<"-------------------------------"<<std::endl;
  std::cout<<"create accounts "<<std::endl;
  bank.createAccount(100);
  bank.createAccount(500);
  bank.createAccount(300);
  bank.createAccount(200);
  bank.createAccount(600);
  bank.createAccount(0);
  std::cout<<bank;
  std::cout<<"end create accounts "<<std::endl;
  std::cout<<"-------------------------------"<<std::endl;

  std::cout<<"delete  accounts "<<std::endl;
  bank.deleteAccount(3);
  bank.deleteAccount(1);
  bank.deleteAccount(4);
  std::cout<<bank;
  std::cout<<"end delete  accounts "<<std::endl;
  std::cout<<"---------------------------------"<<std::endl;

  {
    std::cout<<"example of  an account not exist"<<std::endl;
    Bank b1;
    b1.deleteAccount(3);
    b1.addMoneytoAccount(109, 3);
    b1.drawMoneyFrtomAccount(100,5);
    b1.loanMoneytoAccount(0,3);

  }
  // {
  //  Account a;
  //  Account a(1,5998);
  // }
  {
    std::cout<<"example of  changing the account"<<std::endl;
    Bank b1;
    b1.createAccount(100);
    b1.createAccount(300);
    b1.createAccount(200);
    b1.createAccount(400);
    b1.createAccount(0);

    std::vector<Account> clients = b1.getClients();
    for(std::vector<Account>::iterator it=clients.begin(); it != clients.end();++it){
      std::cout<<*it;
    }
    // int &id=clients[0].getId();
    // double &ba=clients[0].getBalance();
    // bool &active=clients[0].isActive();
    const int &id=clients[0].getId();
    const double &ba=clients[0].getBalance();
    const bool &active=clients[0].isActive();
    std::cout<<"id: "<<id<<std::endl
              <<"balance:"<<ba<<std::endl
              <<"active:"<<active<<std::endl;
    // id =8;
    // ba = 80.0;
    // active=false;
    // std::cout<<"id: "<<clients[0].getId()<<std::endl
    //           <<"balance:"<<clients[0].getBalance()<<std::endl
    //           <<"active:"<<clients[0].isActive()<<std::endl;
    for(std::vector<Account>::iterator it=clients.begin(); it != clients.end();++it){
      std::cout<<*it;
    }
  }
}