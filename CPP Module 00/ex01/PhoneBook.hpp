/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:08:10 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/01 15:20:01 by nbenyahy         ###   ########.fr       */
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
        void byebye(void);
        bool _is_empty(std::string s);
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