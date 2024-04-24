/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:31:37 by areheman          #+#    #+#             */
/*   Updated: 2024/04/18 17:56:57 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <sstream>
// #include "./Account.hpp"
#include <vector>

class Bank{

  public:
    class Account{
      friend class Bank;
      private:
        int id;
        double balance;
        bool active;
      public:
        Account();
        Account(const int id, const double balance);
        void disactiveAccount();
        Account(const Account &obj);
        Account& operator=(const Account& obj);
        ~Account();
        int getId()const;
        double getBalance()const;
        bool isActive()const;
    };
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
    Bank::Account& operator[](const size_t id);

    friend std::ostream&  operator<<(std::ostream& o,const Bank &bank);
    friend std::ostream& operator<<(std::ostream& o, const Account& obj);
    class Bank_Exception:public std::exception{
      public:
        std::string msg;
        Bank_Exception(const std::string message):msg(message){}
        const char *what()const throw(){return msg.c_str();}
        ~Bank_Exception()throw(){}
    };

  private:
    double fund;
    std::vector<Bank::Account> clients;
    void disactiveAccount(Bank::Account& one);
};


#endif