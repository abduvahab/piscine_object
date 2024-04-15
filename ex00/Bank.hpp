/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:31:37 by areheman          #+#    #+#             */
/*   Updated: 2024/04/15 14:26:44 by areheman         ###   ########.fr       */
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
    Bank(const double fund);
    Bank(const Bank& obj);
    Bank& operator=(const Bank& obj);
    ~Bank();
    // friend std::ostream& operator<<(const std::ostream& o, const Bank &bank);

};

std::ostream&  operator<<(std::ostream& o, Bank &bank);

#endif