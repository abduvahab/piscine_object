/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:13:55 by areheman          #+#    #+#             */
/*   Updated: 2024/04/17 18:33:43 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOIUNT_HPP
#define ACCOIUNT_HPP

#include "iostream"
#include "Bank.hpp"

class Bank;

class Account{

  friend class Bank;
  private:
    int id;
    double balance;
    bool active;
    // Bank &bank;

    Account();
    Account(const int id, const double balance);
    void disactiveAccount();
  public:
    Account(const Account &obj);
    Account& operator=(const Account& obj);
    
    ~Account();

    // int &getId();
    // double &getBalance();
    // bool &isActive();
    const int &getId()const;
    const double &getBalance()const;
    const bool &isActive()const;

};

std::ostream& operator<<(std::ostream& o, const Account& obj);

#endif