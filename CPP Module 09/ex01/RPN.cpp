#include "RPN.hpp"

static std::string& trim(std::string& str)
{
   while(str[0] == ' ') str.erase(str.begin());
   while(str[str.size() - 1] == ' ') str.pop_back();
   return str;
}

static int calculate(char _operator, int a, int b)
{
    if (_operator == '+')
        return a + b;
    if (_operator == '-')
        return a - b;
    if (_operator == '*')
        return a * b;
    if (_operator == '/')
    {
        if (b == 0)
            throw "cannot division by 0";
        return a / b;
    }
    return 1;
}

void RPN(char *av)
{
    std::stack<int> monStack;
    const std::string _operators("*-+/");
    const std::string _numbers("0123456789");
    std::string data(av);

    while (!data.empty())
    {
        std::string undef;
        data = trim(data);
        undef = data.substr(0, data.find(' '));
        if (undef.length() != 1)
            throw "invalid data";
        if (_operators.find(undef) != std::string::npos)
        {
            if (monStack.size() < 2)
                throw "invalid data";
            int a = monStack.top();
            monStack.pop();
            int b = monStack.top();
            monStack.pop();
            monStack.push(calculate(undef[0], b, a));
        }
        else if (_numbers.find(undef) != std::string::npos)
            monStack.push(atoi(undef.c_str()));
        else
            throw "invalid data";
        data.erase(0, undef.length() + 1);
    }
    if (monStack.size() != 1)
        throw "invalid data";
    else
        std::cout << monStack.top() << std::endl;
}