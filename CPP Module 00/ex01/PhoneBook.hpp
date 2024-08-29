/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:08:10 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/29 23:51:28 by nbenyahy         ###   ########.fr       */
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
        bool is_number(std::string s);
        void print_ten(std::string s);
        void save_line(Contact &contact);
        void show_infos(Contact contact);
        void add(void);
        void search(void);
    public :
        PhoneBook(void);
        void menu(void);
        ~PhoneBook(void);  
};

#endif