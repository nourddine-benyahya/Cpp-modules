/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:08:10 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/27 15:33:46 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private : 
        Contact contact[8];
        int contact_count;
        int first_contact;
        void add(void);
        void search(void);
        void print_ten(std::string s);
        void show_infos(Contact contact);
    public :
        PhoneBook(void);
        void menu(void);
        ~PhoneBook(void);  
};

#endif