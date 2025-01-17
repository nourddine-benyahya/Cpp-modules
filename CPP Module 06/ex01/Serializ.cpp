#include "Serializ.hpp"

uintptr_t Serializ::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializ::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
