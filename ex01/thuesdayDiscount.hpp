/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuesdayDiscount.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:57:03 by areheman          #+#    #+#             */
/*   Updated: 2024/05/28 15:44:04 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THUESDAYDISCOUNT_HPP
#define THUESDAYDISCOUNT_HPP

#include "./command.hpp"

class ThuesdayDiscountCommand:public Command{
    private:


    public:
        ThuesdayDiscountCommand(const std::string name):Command(name){}
        void get_total_price(){
            float total = 0;
            std::cout<<"your articals in you box are :"<<std::endl;
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                std::cout<<"-"<<it->getArticalName()<<" "<< it->getArticalNumber()<<" "<<it->getArticalPrice()<<std::endl;
                total += it->getArticalNumber() * it->getArticalPrice();
            }
            
            std::cout<<"you are lucky, today is thuesday, so we have 10 percents of discount for your command"<<std::endl;     
            std::cout<<"you have  to pay "<<(total * (0.9)) << " euros"<<std::endl;     
        }
};


#endif