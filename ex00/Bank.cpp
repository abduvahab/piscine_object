#include "./Bank.hpp"

Bank::Bank():fund(0),clients(){

}
Bank::Bank(const double fund=0):fund(fund),clients(){

}
Bank::Bank(const Bank& obj){
  *this = obj;
}
Bank&  Bank::operator=(const Bank& obj){
  if(this == &obj)
    return *this;
  this->fund = obj.fund;
  this->clients = obj.clients;
  return *this;
}

Bank::~Bank(){}

const double &Bank::getFundOfBank()const{
  return fund;
}

void Bank::createAccount(const double depost){
  int len = 0;
  if(!clients.empty()){
    len = this->clients.size();
  }
  double commision = 0;
  if (depost != 0){
    commision = depost * 0.05;
  }
  this->fund += commision;
  Account account(len, depost - commision);
  this->clients.push_back(account);
}


void Bank::deleteAccount(const int id){
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id){
      it->disactiveAccount();
      std::cout<<"account id "<<it->id<<" is disactive"<<std::endl
              <<*it<<std::endl;
        return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account doesn't exist"<<std::endl;
  }
}

void Bank::addMoneytoAccount(const double money, const int id){
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id){
      double commison = money * 0.05;
      it->balance += money - commison;
      fund += commison;
      std::cout<<"account id "<<it->id<<" is added "<<money - commison<<std::endl;
      return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account doesn't exist"<<std::endl;
  }
}
void Bank::drawMoneyFrtomAccount(const double money, const int id){
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id){
      if(it->balance < money){
        std::cout<<"the Account" << it->id<<"doesn't have enough money!"<<std::endl;
        return ;
      }
      it->balance -= money;
      std::cout<<"account id "<<it->id<<" draw "<<money<<std::endl;
      return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account doesn't exist"<<std::endl;
  }
}

void Bank::loanMoneytoAccount(const double loan, const int id){
  if (fund < loan){
    std::cout<<"the bank doesn't have enough money to loan!"<<std::endl;
    return ;
  }
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id){
      // double commison = loan * 0.05;
      fund -= loan;
      it->balance += loan;
      // fund += commison;
      std::cout<<"account id "<<it->id<<" loan "<<loan<<std::endl;
      return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account doesn't exist"<<std::endl;
  }

}


const std::vector<Account> &Bank::getClients()const{
  return clients;
}

 std::ostream&  operator<<(std::ostream& o,const Bank &bank){
    o<<"bank info : "<<bank.getFundOfBank()<<std::endl;
    for(std::vector<Account>::const_iterator it= bank.clients.begin(); it != bank.clients.end();++it){
      if( it->isActive()){
        o<<*it;
      }
    }
    return o;
  }