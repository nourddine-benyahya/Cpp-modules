#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
    private :
        std::map<std::string, long double> data;
        BitcoinExchange();
    public :
        BitcoinExchange(const std::string fileName);
        BitcoinExchange(const std::map<std::string, long double> data);
        std::map<std::string, long double> &operator=(const std::map<std::string, long double> data);
        ~BitcoinExchange(){};
        
        //exception
        class FileException : public std::exception
        {
            public :
                virtual const char *what(void) const throw();
        };

        //methods 
        void saveCsvData();

};