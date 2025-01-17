#include "Serializ.hpp"

int main()
{
    Data *data = new Data;
    data->id = 42;
    data->name = "tninOrb3in";
    uintptr_t test = Serializ::serialize(data);
    std::cout << test << std::endl;
    Data *data2 = Serializ::deserialize(test);
    std::cout << data2->id << " " << data2->name << std::endl;
    delete data;
}