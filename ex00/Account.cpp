#include "./Account.hpp"

Account::Account(const int id, const double balance):id(id),balance(balance),active(true){

}
Account::Account(const Account &obj):id(obj.id),balance(obj.balance),active(obj.active){
}
Account& Account::operator=(const Account& obj){
  if (this == &obj)
    return *this;
  this->id = obj.id;
  this->balance = obj.balance;
  this->active = obj.active;
  return *this;
}

Account::~Account(){}

const int &Account::getId()const{
  return id;
}
const double &Account::getBalance()const{
  return balance;
}
const bool &Account::isActive()const {
  return active;
}
// int &Account::getId(){
//   return id;
// }
// double &Account::getBalance(){
//   return balance;
// }
// bool &Account::isActive(){
//   return active;
// }
void Account::disactiveAccount(){
  active = false;
}


std::ostream& operator<<(std::ostream& o, const Account& obj){
  o << std::boolalpha;
  o<<"account id:"<<obj.getId()<<std::endl
    <<"account balance: "<<obj.getBalance()<<std::endl
    <<"account is acctive :"<<obj.isActive()<<std::endl;
    return o;
}