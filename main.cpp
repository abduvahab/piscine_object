/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:51:12 by areheman          #+#    #+#             */
/*   Updated: 2024/07/25 15:59:28 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.hpp"
#include "parsing.hpp"
#include <iostream>

int main(){
    try{
        Node cityA("CityA");
        Parsing parsingFile("rail_des.txt", "train_des.txt");
        parsingFile.readRailsFile();
        parsingFile.readTrainssFile();
        parsingFile.checkNodes();
        parsingFile.printAll();

        std::cout<<"ok"<<std::endl;

    }
    catch(Parsing::ParsingException e){
        std::cout<<e.what()<<std::endl;
    }


    return 0;
}