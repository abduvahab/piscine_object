/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:32:50 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 11:21:18 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ILogger.hpp"
#include "./fileLogger.hpp"
#include "./streamLogger.hpp"
#include <vector>


int main(){


    std::vector<ILogger*> logger_list;
    std::vector<std::string> s_list;
    s_list.push_back("this is a message 1");
    s_list.push_back("this is a message 2");
    s_list.push_back("this is a message 3");


    FileLogger file1("file1.text");
    FileLogger file2("file2.text", "thisis header");
    FileLogger file3("file3.text", "date");

    std::ostream& os = std::cout;
    std::ostream& err = std::cerr;
    StreamLogger stream1(os);
    StreamLogger stream2(err, "this is header");
    StreamLogger stream3(os, "date");

    logger_list.push_back(&file1);
    logger_list.push_back(&stream1);
    logger_list.push_back(&file2);
    logger_list.push_back(&stream2);
    logger_list.push_back(&file3);
    logger_list.push_back(&stream3);

    for (std::vector<std::string>::iterator st= s_list.begin(); st != s_list.end(); st++){
        for(std::vector<ILogger*>::iterator it=logger_list.begin(); it != logger_list.end(); it++){
            (*it)->write(*st);
        }
    }

    return 0;
}