/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:48 by areheman          #+#    #+#             */
/*   Updated: 2024/07/10 13:57:57 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BELL_HPP
#define BELL_HPP

#include <iostream>
#include <vector>


enum Event
{
	Break_Start,
    Break_End,
    Launch
};


class BellListener{

    public:
    virtual ~BellListener(){}
    virtual void oneBellRing(Event event)=0;

};


class Bell{

    private:
        std::vector<BellListener*> bellListeners;
        // bool                        onBreak;

    public:
        Bell():bellListeners(){}
        ~Bell(){}

        void addlistener(BellListener* listener);
        // void setOnBreak(bool flag)
        // {
        //     onBreak = flag;
        // }
        void ringBell(Event event );
    
};




#endif
