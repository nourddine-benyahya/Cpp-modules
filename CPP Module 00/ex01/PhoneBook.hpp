/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:08:10 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/23 23:47:31 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private : 
        std::vector<Contact> contact;
    public :
        // constrocter
        PhoneBook(void);
        void get_contact(void);
        void set_contact(Contact new_contact);
        bool add(void);
        // void commnad_checker(void);
        // destrocter
        ~PhoneBook(void);  
};

#endif