/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streamLogger.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:49:28 by areheman          #+#    #+#             */
/*   Updated: 2024/06/03 11:08:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STREAMLOGGER_HPP
#define STREAMLOGGER_HPP

#include "./ILogger.hpp"
#include <ostream>
#include <sstream>
#include <ctime>


class StreamLogger:public ILogger{

    private:
        std::ostream&    streams;
        std::string     header;

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
        StreamLogger(std::ostream& stream, const std::string header=""):streams(stream), header(header){}
        void write(std::string msg){
            streams<<getHeader()<<msg<<std::endl;
        }

};



#endif