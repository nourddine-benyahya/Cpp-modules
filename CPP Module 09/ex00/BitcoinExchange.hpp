#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cctype>

class BitcoinExchange
{
    private :
        std::map<std::string, long double> data;
        BitcoinExchange();
        //methods 
        void saveCsvData();
        void saveData(const std::string fileName);
        bool nonAnumber(const std::string data);
        bool nonAdate(const std::string data);
        void checkFile(const std::string fileName);
        std::string& trim(std::string& str);
        std::string& stringToLower(std::string& str);

    public :
        BitcoinExchange(const std::string fileName);
        BitcoinExchange(const std::map<std::string, long double> data);
        BitcoinExchange(const BitcoinExchange &data);
        BitcoinExchange &operator=(const BitcoinExchange &data);
        std::map<std::string, long double> &operator=(const std::map<std::string, long double> data);
        ~BitcoinExchange(){};
};