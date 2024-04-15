/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:13:55 by areheman          #+#    #+#             */
/*   Updated: 2024/04/15 14:28:21 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOIUNT_HPP
#define ACCOIUNT_HPP

#include "iostream"
#include "Bank.cpp"

class Bank;

class Account{

  private:
    int id;
    double balance;
    Bank &bank;

    Account(const double balance=0, const Bank bank);
    Account(const Account &obj);
    Account& operator=(const Account& obj);
    
  public:
    ~Account();


};

#endif