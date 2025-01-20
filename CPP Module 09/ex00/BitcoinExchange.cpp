#include "BitcoinExchange.hpp"

bool BitcoinExchange::nonAnumber(const std::string data)
{
    size_t len = data.length();
    size_t i = 0;
    if (data[0] == '+' || data[0] == '-')
        i++;
    std::string number("0123456789.f");
    while (i < len && number.find(data[i++]) != std::string::npos);
    return i != len || data[0] == '.' ||  (i == len && number.find(data.at(len - 1)) == std::string::npos) || (data.find("f") != data.rfind("f")) ? true : false;
}

bool BitcoinExchange::nonAdate(const std::string data)
{
    size_t len = data.length();
    size_t i = 0;
    std::string number("0123456789-");
    while (i < len && number.find(data[i]) != std::string::npos)
    {
        if ((i == 4 || i == 7) && data[i] != '-')
            return true;
        if (i != 4 && i != 7 && data[i] == '-')
            return true;
        i++;
    };
    if (data.length() != 10 || i != len || ((i == len && number.find(data.at(len - 1)) == std::string::npos))) return true ;

    int day = atoi(data.substr(8, 10).c_str()),month = atoi(data.substr(5, 7).c_str()) ,year = atoi(data.substr(0, 4).c_str());
    if (day < 1 || year < 1 || month < 1 || month > 12)
        return true;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        days[1] = 29;
    if (day > days[month - 1])
        return true;
    return false;
}

void BitcoinExchange::checkFile(const std::string fileName)
{
    if ((fileName.substr(fileName.length() - 4)).compare(".txt"))
        throw "Error: could not open file.";
}
std::string& BitcoinExchange::trim(std::string& str)
{
   while(str[0] == ' ') str.erase(str.begin());
   while(str[str.size() - 1] == ' ') str.pop_back();
   return str;
}

std::string& BitcoinExchange::stringToLower(std::string& str)
{
    for(int i = 0; str[i]; i++)
        {str[i] = tolower(str[i]);};
    return str;
}

void BitcoinExchange::saveData(const std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    std::string line;
    std::map<std::string, long double>::iterator it;

    if (!inFile.is_open())
        throw "Error: could not open file.";
        
    std::getline(inFile, line);
    std::string date = line.substr(0, line.find("|"));
    std::string value = line.substr(line.find("|") + 1);
    trim(value);
    trim(date);
    if ((stringToLower(trim(date))).compare("date") || (stringToLower(trim(value))).compare("value"))
        throw "invlaid header should be \"date | value\"";
        
    while (std::getline(inFile, line))
    {
            date = line.substr(0, line.find("|"));
            value = line.substr(line.find("|") + 1);
            trim(value);
            trim(date);
            it = data.find(date);
            if (value == date || value.empty() || data.empty() || line.find("|") == std::string::npos || nonAnumber(value) || nonAdate(date))
                    std::cerr << "Error: bad input => " << line << std::endl;
            else if (it != data.end())
            {   
                long double vl = (static_cast<long double>(std::atof(value.c_str())));
                if (vl > 1000)
                    std::cerr << "Error: too large a number." << std::endl;
                else if (vl < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else
                    std::cout << date << " => " << value << " = " << it->second * (static_cast<long double>(std::atof(value.c_str()))) << std::endl;
            }
            else
            {
                std::map<std::string, long double>::iterator itt;
                itt = data.lower_bound(date);
                if (itt == data.begin())
                    std::cerr << "invalid year btc not exist" << std::endl;
                else
                {
                    itt--;
                    std::cout << date << " => " << value << " = " << itt->second * (static_cast<long double>(std::atof(value.c_str()))) << std::endl;
                }
            }
    }
}

void BitcoinExchange::saveCsvData()
{
    std::ifstream inFile;
    inFile.open("data.csv");
    std::string line;

    if (!inFile.is_open())
        throw "Error: could not open file.";
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
    }
    catch (const char  *e)
    {
        std::cerr << e << std::endl;
    }
}