#include "./Bank.hpp"

Bank::Bank(const double fund=0):fund(fund){

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

std::ostream&  operator<<(std::ostream& o, const Bank &bank){
  o<<"bank info : "<<std::endl;
  return o;
};
