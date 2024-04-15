#include "./Account.hpp"

Account::Account(const double balance=0, const Bank bank):balance(balance),bank(bank){
  this->id = 0;
}

Account::Account(const Account &obj){
  *this = obj;
}
Account& Account::operator=(const Account& obj){
  if (this == &obj)
    return *this;
  this->id = obj.id;
  this->balance = obj.balance;
  this->bank = obj.bank;
  return *this;
}

Account::~Account(){}


