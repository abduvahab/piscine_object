#include "./Graphic.hpp"

Graphic::Graphic():size(0,0),points(){}
Graphic::Graphic(const Graphic &other):size(other.size),points(other.points){}
Graphic& Graphic::operator=(const Graphic &other){
  if(this == &other){
    return *this;
  }
  size = other.size;
  points = other.points;
  return *this;
}

Graphic::~Graphic(){}

float round(float num){
  return num >0 ? int(num + 0.5f):int(num - 0.5f);
}

// check weather the point has minus coordinate or bigger than 100
void checkPoint(const Vector2 point){
  Vector2 new_point(round(point.getX()),round(point.getY()));
  if(new_point.getX() >= 100 || new_point.getY() >= 100)
    throw Graphic::Graphic_Exception("the point coordinate has  passed the limit 100");
  if (new_point.getX() < 0 || new_point.getY() < 0)
    throw Graphic::Graphic_Exception("the point  can't have the coordinate smaller than 0");
}

void Graphic::addPoint(const Vector2 point){
  // check weather the point exist
  if(findPoint(point)){
    // std::cout<<"this point already exist!"<<std::endl;
    return ;
  }
  checkPoint(point);
  // set the size of the graphiic
  if (points.empty()){
    size.setX(round(point.getX()) + 1);
    size.setY(round(point.getY()) + 1 );
  }
  else{
    if(size.getX() < round(point.getX())){
       size.setX(round(point.getX()) + 1);
    }
    if(size.getY() < round(point.getY())){
      size.setY(round(point.getY()) + 1 );
    }
  }
  // add point to grapthic
  points.push_back(Vector2(round(point.getX()),round(point.getY())));
}

bool Graphic::findPoint(const Vector2 point)const{

  //round the point incase of they are float number
  Vector2 new_point(round(point.getX()),round(point.getY()));

  for(std::vector<Vector2>::const_iterator it=points.begin(); it!=points.end();++it){
    if(it->getX() == new_point.getX() && it->getY() == new_point.getY()){
      return true;
    }
  }
  return false;
}
void Graphic::addPoint(const float X, const float Y){

  // check weather the point exist
  if(findPoint(Vector2(X,Y))){
    // std::cout<<"this point already exist!"<<std::endl;
    return ;
  }
  checkPoint(Vector2(X,Y));
  //set the size of the graphic
  if (points.empty()){
    size.setX(round(X) + 1);
    size.setY(round(Y) + 1 );
  }
  else{
    if(size.getX() < round(X)){
       size.setX(round(X) + 1);
    }
    if(size.getY() < round(Y)){
      size.setY(round(Y) + 1 );
    }
  }
  //add the point 
  points.push_back(Vector2(round(X),round(Y)));
}

void Graphic::drawGraphic()const{

  for (int i=size.getY(); i>=0; i--){
    std::cout<<">& "<<i<<" ";
    if(size.getY() >= 10 && i < 10 && size.getY() < 100){
      std::cout<<" ";
    }
    if(size.getY() == 100){
      if(i < 10){
        std::cout<<"  ";
      }
      if(i >= 10 && i != 100){
        std::cout<<" ";
      }
    }
    for(int j=0; j<=size.getX();j++){
      if(findPoint(Vector2(j, i))){
        //put the point 
        std::cout<<"x";
      }
      else{
        //put space 
        std::cout<<".";
      }
      //put space after point 
      std::cout<<" ";
      if(j >= 10){
        std::cout<<" ";
      }
    }
    //change the line 
    std::cout<<std::endl;
  }
  std::cout<<">&   ";
    if(size.getY() >= 10 ){
      std::cout<<" ";
    }
    if(size.getY() == 100 ){
      std::cout<<" ";
    }
  for (int i=0; i<=size.getX(); i++){
    std::cout<<i;
    std::cout<<" ";
  }
  std::cout<<std::endl;
}
