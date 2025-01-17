#pragma once
#include <string>
#include <iostream>

template <typename T>
class Array {
private:
    T *data;
    unsigned int arrSize;

public:
    Array() : data(NULL), arrSize(0) {}

    ~Array() {
        if (data)
            delete[] data;
    }

    Array(unsigned int n) {
        if (n > 0) {
            data = new T[n];
            arrSize = n;
        } else {
            data = NULL;
            arrSize = 0;
        }
    }

    Array(const Array &obj) {
        arrSize = obj.size();
        if (arrSize == 0) {
            data = NULL;
        } else {
            data = new T[arrSize];
            for (unsigned int i = 0; i < arrSize; i++) {
                data[i] = obj.data[i];
            }
        }
    }

    Array &operator=(const Array &obj) {
        if (this != &obj) {
            delete[] data;
            arrSize = obj.size();
            if (arrSize == 0) {
                data = NULL;
            } else {
                data = new T[arrSize];
                for (unsigned int i = 0; i < arrSize; i++) {
                    data[i] = obj.data[i];
                }
            }
        }
        return *this;
    }

    T &operator[](const int index) {
        if (index >= static_cast<int>(arrSize) || index < 0)
            throw outOfBounds();
        return data[index];
    }

    const T &operator[](const int index) const {
        if (index >= static_cast<int>(arrSize) || index < 0)
            throw outOfBounds();
        return data[index];
    }

    unsigned int size() const {
        return arrSize;
    }

    class outOfBounds : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Index out of bounds";
        }
    };
};
