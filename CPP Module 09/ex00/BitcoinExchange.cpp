#include "BitcoinExchange.hpp"

const char *BitcoinExchange::FileException::what(void) const throw()
{
    return "invalid parameter";
}


void checkFile(const std::string fileName)
{
    if ((fileName.substr(fileName.length() - 4)).compare(".txt"))
        throw std::exception();
}

void saveData(const std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    std::string line;

    if (!inFile.is_open())
        throw std::exception();
        
    // std::getline(inFile, line);
    // if ()

}

void BitcoinExchange::saveCsvData()
{
    std::ifstream inFile;
    inFile.open("data.csv");
    std::string line;

    if (!inFile.is_open())
        throw std::exception();
    std::getline(inFile, line);
    while (std::getline(inFile, line))
    {
        this->data[line.substr(0, 10)] = static_cast<long double>(std::atof((line.substr(11)).c_str()));
    }
}

BitcoinExchange::BitcoinExchange(const std::string fileName)
{
    try{
        saveCsvData();
        checkFile(fileName);
        saveData(fileName);
        std::cout << "test is passed with seccess" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}