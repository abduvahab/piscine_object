/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:54:35 by areheman          #+#    #+#             */
/*   Updated: 2024/04/18 11:02:50 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2{

  private:
    float X;
    float Y;

  public:
    Vector2(const float X, const float Y);
    Vector2(const Vector2 &other);
    Vector2& operator=(const Vector2 &other);
    ~Vector2();

    float getX()const;
    float getY()const;

    void setX(const float X);
    void setY(const float Y);
  
};



#endif