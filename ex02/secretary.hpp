/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:12:47 by areheman          #+#    #+#             */
/*   Updated: 2024/06/07 15:21:42 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include "./staff.hpp"
#include "./form.hpp"


class Staff;
class Form;


class Secretary:public Staff{

    private:

    public:
        Secretary(std::string p_name):Staff(p_name){}

        Form* createForm(FormType p_formType);

        void archiveForm(){}
    
};



#endif