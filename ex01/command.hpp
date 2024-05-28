/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:55:05 by areheman          #+#    #+#             */
/*   Updated: 2024/05/28 15:40:42 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

//Opened/Closed rules:
// Software entities (classes, modules, functions, etc.)
// should be open for extension but closed for modification. 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

class Date{
    private:
        std::string time_order;
        std::string order_day;
    public:
        Date(){
            time_t cuurent_time = std::time(0);
            struct tm* localtime = std::localtime(&cuurent_time);
            int years = localtime->tm_year + 1900;
            int month = localtime->tm_mon;
            int day = localtime->tm_mday;
            int hours = localtime->tm_hour;
            int minuts = localtime->tm_min;
            int seconds = localtime->tm_sec;
            time_order = to_string(years) + " " \
                        +to_string(month) + "/" \
                        +to_string(day) + "  " \
                        +to_string(hours) + ":" \
                        +to_string(minuts) + ":" \
                        +to_string(seconds);
            order_day = localtime->tm_wday == 1 ? "Tuesday" : "other";
        }
        std::string to_string(int value){
            std::ostringstream oss;
            oss<<value;
            return oss.str();
        }
        std::string getOrderTime()const {
            return time_order;
        }
        std::string getOrderDay()const {
            return order_day;
        }

};

class Client{

    private:
        std::string name;
    public:
        Client():name("noName"){}
        Client(const std::string name):name(name){}

        std::string getNameOfClient(){
            return name;
        }
        void setNameOfClient(const std::string name){
            this->name = name;
        }
};

class Artical{
    private:
        std::string name;
        float price;
        int number_artical;
    public:
        Artical(const std::string name, float price, int number=0):name(name),price(price),number_artical(number){}
        void increaseOne(){number_artical += 1;}
        void decreaseOne(){
            if(number_artical > 0){
                number_artical -= 1;
            }
        }
        std::string getArticalName()const{
            return name;
        }
        float getArticalPrice()const{
            return price;
        }
        int getArticalNumber()const {
            return number_artical;
        }

};

std::ostream& operator<<(std::ostream& os, const Artical& obj){
    os<<" Name artical: "<<obj.getArticalName()<<std::endl
        <<" price artical: "<<obj.getArticalPrice()<<std::endl
        <<" number of artical: "<<obj.getArticalNumber()<<std::endl;
        return os;
}

class Command{

    protected:
        static int ids;
        int id;
        Date date;
        Client client;
        std::vector<Artical> articals;

    public:
        Command(const std::string nameOfClient):id(ids),date(),client(nameOfClient),articals(){
            ids += 1; 
        }

        void get_total_price(){
            float total = 0;
            std::cout<<"your articals in you box are :"<<std::endl;
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                std::cout<<"-"<<it->getArticalName()<<" "<< it->getArticalNumber()<<" "<<it->getArticalPrice()<<std::endl;
                total += it->getArticalNumber() * it->getArticalPrice();
            }
            std::cout<<"you have  to pay "<<total << " euros"<<std::endl;     
        }

        void addArtical(Artical& one){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == one.getArticalName()){
                    return ;
                }
            }
            articals.push_back(one);
        }
        void removeArtical(Artical& one){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == one.getArticalName()){
                    articals.erase(it);
                    return ;
                }
            }
        }
        void removeArtical(const std::string articalName){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == articalName){
                    articals.erase(it);
                    return ;
                }
            }
        }
        void increaseNumberOfArtical(const std::string articalName){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == articalName){
                    it->increaseOne();
                    return ;
                }
            }
        }
        void increaseNumberOfArtical(Artical& one){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == one.getArticalName()){
                    it->increaseOne();
                    return ;
                }
            }
        }

        void decreaseNumberOfArtical(const std::string articalName){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == articalName){
                    it->decreaseOne();
                    return ;
                }
            }
        }
        void decreaseNumberOfArtical(Artical& one){
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                if(it->getArticalName() == one.getArticalName()){
                    it->decreaseOne();
                    return ;
                }
            }
        }

        void clearAll(){
            articals.clear();
        }

        void setClientName(const std::string name){
            client.setNameOfClient(name);
        }

        void printCommand(){
            std::cout<<"command_id: "<<id<<std::endl
                    <<"command_date: "<<date.getOrderTime()<<std::endl
                    <<"Client_name: "<<client.getNameOfClient()<<std::endl;
            for(std::vector<Artical>::iterator it= articals.begin(); it!=articals.end(); it++){
                std::cout<<*it;
            }
        }

};


int Command::ids =0;


#endif