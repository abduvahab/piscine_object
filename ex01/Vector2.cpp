#include "./Vector2.hpp"

Vector2::Vector2(const float X, const float Y):X(X),Y(Y){}
Vector2::Vector2(const Vector2 &other):X(other.X),Y(other.Y){}
Vector2& Vector2::operator=(const Vector2 &other){
  if(this == &other){
    return *this;
  }
  X = other.X;
  Y = other.Y;
  return *this;
}
Vector2::~Vector2(){}

float Vector2::getX()const{
  return X;
}

float Vector2::getY()const{
  return Y;
}

void Vector2::setX(const float X){
  this->X = X;
}
void Vector2::setY(const float Y){
  this->Y = Y;
}