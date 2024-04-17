/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:31:37 by areheman          #+#    #+#             */
/*   Updated: 2024/04/17 18:34:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
#define BANK_HPP

#include "iostream"
#include "./Account.hpp"
#include "vector"

class Account;

class Bank{

  private:
    double fund;
    std::vector<Account> clients;

  public:
    Bank();
    Bank(const double fund);
    Bank(const Bank& obj);
    Bank& operator=(const Bank& obj);
    ~Bank();

    const double &getFundOfBank()const;
    void createAccount(const double depost);
    void deleteAccount(const int id);
    const  std::vector<Account> &getClients()const;

    void addMoneytoAccount(const double money, const int id);
    void drawMoneyFrtomAccount(const double money, const int id);
    void loanMoneytoAccount(const double loan, const int id);

    friend std::ostream&  operator<<(std::ostream& o,const Bank &bank);
};


#endif