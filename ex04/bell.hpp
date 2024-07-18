/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:21:48 by areheman          #+#    #+#             */
/*   Updated: 2024/07/09 12:42:00 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BELL_HPP
#define BELL_HPP

#include <iostream>
#include <vector>


enum Event
{
	RingBell
};


class BellListener{

    public:
    virtual ~BellListener(){}
    virtual void oneBellRing(Event event, bool onBreak)=0;

};


class Bell{

    private:
        std::vector<BellListener*> bellListeners;
        bool                        onBreak;

    public:
        Bell():bellListeners(),onBreak(false){}
        ~Bell(){}

        void addlistener(BellListener* listener);
        void setOnBreak(bool flag)
        {
            onBreak = flag;
        }
        void ringBell();
    
};




#endif
