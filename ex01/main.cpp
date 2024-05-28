/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:13:01 by areheman          #+#    #+#             */
/*   Updated: 2024/05/28 16:26:00 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command.hpp"
#include "./thuesdayDiscount.hpp"
#include "./packageReductionDiscount.hpp"

int main(){
    
    {

        Command command1("jhon");
        Command command2("tom");
        Artical pantalon("pantalon", 20);
        Artical manto("manto", 40);
        Artical chemise("chemise", 30);
        

        command1.addArtical(pantalon);
        command1.addArtical(manto);
        command1.increaseNumberOfArtical(manto);
        command1.increaseNumberOfArtical(manto);
        command1.decreaseNumberOfArtical(manto);
        command1.addArtical(chemise);
        // command1.printCommand();
        std::cout<<"--------------------------------"<<std::endl;
        command1.get_total_price();
    }

    {
        Command command2("tom");
        Artical pantalon("pantalon", 20,1);
        Artical manto("manto", 50, 1);
        Artical chemise("chemise", 30,1);
  

        command2.addArtical(pantalon);
        command2.addArtical(manto);
        command2.increaseNumberOfArtical(manto);
        command2.addArtical(chemise);
        // command2.printCommand();
        std::cout<<"--------------------------------"<<std::endl;
        command2.get_total_price();
    }

    {
        PackageReductionDiscountCommand command2("tom");
        Artical pantalon("pantalon", 20,1);
        Artical manto("manto", 50, 2);
        Artical chemise("chemise", 30,1);
  

        command2.addArtical(pantalon);
        command2.addArtical(manto);
        command2.increaseNumberOfArtical(manto);
        command2.addArtical(chemise);
        // command2.printCommand();
        std::cout<<"--------------------------------"<<std::endl;
        command2.get_total_price();
    }
    {
        ThuesdayDiscountCommand command2("tom");
        Artical pantalon("pantalon", 20,1);
        Artical manto("manto", 50, 2);
        Artical chemise("chemise", 30,1);
  

        command2.addArtical(pantalon);
        command2.addArtical(manto);
        command2.increaseNumberOfArtical(manto);
        command2.addArtical(chemise);
        // command2.printCommand();
        std::cout<<"--------------------------------"<<std::endl;
        command2.get_total_price();
    }
    

    return 0;
}