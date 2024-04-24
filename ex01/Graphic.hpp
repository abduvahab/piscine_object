/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:05:50 by areheman          #+#    #+#             */
/*   Updated: 2024/04/18 14:58:09 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "./Vector2.hpp"
#include "vector"
#include "iostream"

class Vector2;

class Graphic{

  private:
    Vector2 size;
    std::vector<Vector2> points;

  public:
    Graphic();
    Graphic(const Graphic &other);
    Graphic& operator=(const Graphic &other);
    ~Graphic();
    void addPoint(const Vector2 point);
    void addPoint(const float X, const float Y);
    void drawGraphic()const;
    bool findPoint(const Vector2 point)const;
  class Graphic_Exception :public std::exception{
    public:
      std::string msg;
      Graphic_Exception(const std::string &message):msg(message){}
      const char* what()const throw(){
        return msg.c_str();
      }
      virtual ~Graphic_Exception() throw() {}
  };
};


#endif