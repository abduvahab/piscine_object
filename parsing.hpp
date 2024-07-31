/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:57:49 by areheman          #+#    #+#             */
/*   Updated: 2024/07/25 16:08:45 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
#define PARSING_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Parsing{

    protected:
       std::string      railsFileName;
       std::string      trainsFileName;

       std::vector<std::string> nodeLines;
       std::vector<std::string> railLines;
       std::vector<std::string> eventLines;
       std::vector<std::string> trainLines;
       std::vector<std::string> nodeNames;

       std::vector<std::string> splitString(std::string line);

    public:
        Parsing(const std::string& railsFileName, const std::string& trainsFileName);
        Parsing(const Parsing& obj);
        Parsing& operator=(const Parsing& obj);

       std::string      getRailsFileName();
       std::string      getTrainsFileName();
     
       void             setRailsFileName(const std::string &filename);
       void             setTrainsFileName(const std::string &filename);

       void             readRailsFile();
       void             readTrainssFile();
       void             addNodesName(const std::string name);
       void             checkNodes();
       void             checkEvents();
       void             checkRails();
       void             checkTrains();
       void             checkAllTokens();


       class ParsingException:public std::exception{
            private:
                std::string msg;
            public:
                ParsingException(const std::string &message):msg(message){}
                ~ParsingException()throw(){}
                const char *what()const throw() {
                    return msg.c_str();
                }
       };

       void printAll(){
        printVector(nodeLines);
        printVector(railLines);
        printVector(eventLines);
        printVector(trainLines);
        printVector(nodeNames);
       }

       void printVector(std::vector<std::string> vt){
        for(std::vector<std::string>::iterator it=vt.begin(); it!=vt.end(); it++){
            std::cout<<(*it)<<std::endl;
        }
       }

};



#endif