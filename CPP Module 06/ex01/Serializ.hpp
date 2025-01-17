#pragma once

#include <string>
#include <iostream>
#include <cstdint>

struct  Data
{
    int id;
    std::string name;
};

class Serializ
{
    private :
        Serializ();
        ~Serializ();
        Serializ(const Serializ& other);
        Serializ& operator=(const Serializ& other);
    public : 
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};