/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:31:37 by areheman          #+#    #+#             */
/*   Updated: 2024/04/12 12:35:05 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
#define BANK_HPP

#include "iostream"
#include "./Accouint"
#include "vector"

class Account;

class Bank{

  private:
    double fund;
    std::vector<Account> clients;

  public:
    Bank(const double fund);
    Bank(const Bank& obj);
    Bank operator=(const Bank& obj);


}


#endif