/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:31:42 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/12 15:40:57 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    size_t pos = 0;
    std::string s1;
    std::string s2;
    std::string line;
    std::string outfile_name;
    if (ac != 4)
    {
        std::cout << "the programe take only 3 parameter" << std::endl;
        return (0);
    }
    s1 = av[2];
    s2 = av[3];
    outfile_name = av[1];
    outfile_name.append(".replace");
    std::ifstream in_file(av[1]);
    std::ofstream out_file(outfile_name);
    if (!in_file.is_open() || !out_file.is_open())
    {
        std::cout << "error in opening files" << std::endl;
        return (1);
    }
    while (std::getline(in_file, line))
    {
        while ((pos = line.find(s1)) != (size_t) - 1)
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length(), line.length() - s1.length() + s2.length());
        out_file << line << std::endl;
    }
}