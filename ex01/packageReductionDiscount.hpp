/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packageReductionDiscount.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:56:19 by areheman          #+#    #+#             */
/*   Updated: 2024/05/28 15:31:56 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
#define PACKAGEREDUCTIONDISCOUNT_HPP

#include "./command.hpp"

// class Command;

class PackageReductionDiscountCommand:public Command{

    private:

    public:
        PackageReductionDiscountCommand(const std::string name):Command(name){}
        void get_total_price(){
            float total = 0;
            std::cout<<"your articals in you box are :"<<std::endl;
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                std::cout<<"-"<<it->getArticalName()<<" "<< it->getArticalNumber()<<" "<<it->getArticalPrice()<<std::endl;
                total += it->getArticalNumber() * it->getArticalPrice();
            }
            if (total > 150){
                std::cout<<"you are lucky, he total command value exceed 150 euros, so you have 10 euro discount"<<std::endl;     
                std::cout<<"you have  to pay "<<(total - 10)<< " euros"<<std::endl;     

            }
            else{
                std::cout<<"you have  to pay "<<total<< " euros"<<std::endl;
            }
        }
        
};


#endif