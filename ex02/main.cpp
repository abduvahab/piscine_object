/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:25:07 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 11:42:26 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rectangle.hpp"
#include "./triangle.hpp"
#include "./circle.hpp"

int main(){
    try{

        Rectangle rec(3, 4);
        Circle cir(2.5);
        Triangle trian(5, 2, 4);

        rec.calculating_area();
        cir.calculating_area();
        trian.calculating_area();

    }
    catch(Triangle::Traingle_exception e){
        std::cout<<e.what()<<std::endl;
    }



    return 0;
}