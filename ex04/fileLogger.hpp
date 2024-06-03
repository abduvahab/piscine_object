/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileLogger.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:33:40 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 10:42:03 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "./ILogger.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

class FileLogger:public ILogger{

    private:
        std::string         nameFile;
        std::ofstream       fileStream;
        std::string         header;

        std::string getCurrentTime(){
            time_t currentTime =std::time(0);
            tm *localTime = std::localtime(&currentTime);
            int year = localTime->tm_year + 1900;
            int month = localTime->tm_mon + 1;
            int day = localTime ->tm_mday;

            int hours = localTime->tm_hour;
            int minutes = localTime->tm_min;
            int seconds = localTime->tm_sec;
            
            return to_string(year) + "-"
                                + (month > 9 ? (to_string(month) + "-"):("0" + to_string(month) + "-"))
                                + (day > 9 ? (to_string(day) + " "):("0" + to_string(day) + " "))
                                + (hours > 9 ? (to_string(hours) + ":"):("0" + to_string(hours) + ":"))
                                + (minutes > 9 ? (to_string(minutes) + ":"):("0" + to_string(minutes) + ":"))
                                + (seconds > 9 ? (to_string(seconds) + ""):("0" + to_string(seconds) + ""));

        }

        std::string to_string(int value){
            std::ostringstream oss;
            oss<<value;
            return oss.str();
        }

        std::string getHeader(){
            if(header.empty()){
                return "";
            }
            if(header == "date"){
                return getCurrentTime() + " ";
            }else{
                return header + " ";
            }

        }


    public:
        FileLogger(const std::string namefile,const std::string header=""):
                    nameFile(namefile),
                    fileStream(nameFile.c_str(),std::ios_base::app),
                    header(header){}
                    
        ~FileLogger(){
            if(fileStream.is_open()){
                fileStream.close();
            }
        }
        void write(std::string msg){
            if(fileStream.is_open()){
                fileStream<<getHeader()<<msg<<std::endl;
                // fileStream.close(); 
            }else{
                std::cerr<<"failed opeing the file"<<std::endl;
            }
        }



};


#endif