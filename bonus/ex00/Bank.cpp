#include "./Bank.hpp"
//account 
Bank::Account::Account(const int id, const double balance):id(id),balance(balance),active(true){

}
Bank::Account::Account(const Account &obj):id(obj.id),balance(obj.balance),active(obj.active){
}
Bank::Account& Bank::Account::operator=(const Account& obj){
  if (this == &obj)
    return *this;
  this->id = obj.id;
  this->balance = obj.balance;
  this->active = obj.active;
  return *this;
}

Bank::Account::~Account(){}

int Bank::Account::getId()const{
  return id;
}
double Bank::Account::getBalance()const{
  return balance;
}
bool Bank::Account::isActive()const {
  return active;
}

std::ostream& operator<<(std::ostream& o, const Bank::Account& obj){
  o << std::boolalpha;
  o<<"account id:"<<obj.getId()<<std::endl
    <<"account balance: "<<obj.getBalance()<<std::endl
    <<"account is acctive :"<<obj.isActive()<<std::endl;
    return o;
}
//Bank

Bank::Bank():fund(0),clients(){

}
Bank::Bank(const double fund=0):fund(fund),clients(){

}
Bank::Bank(const Bank& obj):fund(obj.fund),clients(obj.clients){
  
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
  Bank::Account account(len, depost - commision);
  this->clients.push_back(account);
}

void Bank::disactiveAccount(Account& one){
  one.active = false;
}
void Bank::deleteAccount(const int id){
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id && it->active){
      disactiveAccount(*it);
      std::cout<<"account id "<<it->id<<" is disactive"<<std::endl
              <<*it<<std::endl;
        return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account "<< id <<" doesn't exist"<<std::endl;
  }
}

void Bank::addMoneytoAccount(const double money, const int id){
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id && it->active){
      double commison = money * 0.05;
      it->balance += money - commison;
      fund += commison;
      std::cout<<"account id "<<it->id<<" is added "<<money - commison<<std::endl;
      return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account "<<id<<"doesn't exist"<<std::endl;
  }
}
void Bank::drawMoneyFrtomAccount(const double money, const int id){
  std::vector<Account>::iterator it;
  for(it=clients.begin(); it != clients.end();++it){
    if(it->getId() == id && it->active){
      if(it->balance < money){
        // throw Bank_Exception("the account with " + std::string(it->id) + " doesn't exist");
        std::cout<<"the Account" << it->id<<"doesn't have enough money!"<<std::endl;
        return ;
      }
      it->balance -= money;
      std::cout<<"account id "<<it->id<<" draw "<<money<<std::endl;
      return ;
    }
  }
  if (it == clients.end()){
    std::cout<<"the Account "<<id<<"doesn't exist"<<std::endl;
  }
}

Bank::Account& Bank::operator[](const size_t id){
  size_t len = clients.size();
  std::stringstream ss;
  ss << id;
  std::string num = ss.str();
  if (id >= len){
    throw Bank_Exception("the account " + num + " doesn't exist");
  }
  if (!clients[id].active){
    throw Bank_Exception("the account " + num + " doesn't exist");
  }
  return clients[id];
}

void Bank::loanMoneytoAccount(const double loan, const int id){
    std::stringstream ss;
    ss << id;
    std::string num = ss.str();
  if (fund < loan){
    throw Bank_Exception("the bank doesn't have enough money to loan for account "+num);
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
    throw Bank_Exception("the account " + num + " doesn't exist");
  }

}


const std::vector<Bank::Account> &Bank::getClients()const{
  return clients;
}

 std::ostream&  operator<<(std::ostream& o,const Bank &bank){
    o<<"bank info : "<<bank.getFundOfBank()<<std::endl;
    for(std::vector<Bank::Account>::const_iterator it= bank.clients.begin(); it != bank.clients.end();++it){
      if( it->isActive()){
        o<<*it;
      }
    }
    return o;
  }