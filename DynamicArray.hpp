#ifndef SECOND_LAB1_SEM3_DYMANICARRAY_HPP
#define SECOND_LAB1_SEM3_DYMANICARRAY_HPP

#include <iostream>
#include <string>
#include "Option.hpp"

template<typename T>
class DynamicArray {
private:
    Option<T> *data;
    bool has_data{};
    int size{};
public:
    explicit DynamicArray() : size(0), data(nullptr), has_data(false) {}

    [[maybe_unused]] DynamicArray(const DynamicArray &a);

    DynamicArray(Option<T> *, int);

    explicit DynamicArray(int);

    void append(Option<T>);


    void print();

    int getSize();

    void swap(int, int);

    void setEl(int, Option<T>);

    Option<T> &getEl(int);

    Option<T> &operator[](int);

    ~DynamicArray();
};

template<typename T>
[[maybe_unused]] DynamicArray<T>::DynamicArray(const DynamicArray &a) {
    try {
        this->data = a.get_data();
        this->size = a.get_size();
    } catch (const char *msg) {
        std::cout << msg;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(Option<T> *el, int count) {
    this->data = el;
    this->size = count;
}

template<typename T>
DynamicArray<T>::DynamicArray(int size) {
    this->data = new Option<T>[size];
    this->size = size;
    this->has_data = true;
}



template<typename T>
void DynamicArray<T>::append(Option<T> el) {

    if (!this->has_data) {
        this->size++;

        this->data = new Option<T>[this->size];
        this->data[0].setValue(el.getValue());
        this->has_data = true;

    } else {
        this->size++;
        auto *buff = new Option<T>[this->size];

        for (int i = 0; i < this->size - 1; i++) {
            try {
                buff[i].setValue(this->data[i].getValue());
            } catch (const char *msg) {
                std::cout << msg;
            }
        }

        buff[this->size - 1].setValue(el.getValue());

        delete[] this->data;
        this->data = new Option<T>[this->size];

        for (int i = 0; i < this->size; i++) {
            try {
                this->data[i].setValue(buff[i].getValue());
            } catch (const char *msg) {
                std::cout << msg;
            }
        }
    }
}


template<typename T>
void DynamicArray<T>::print() {
    for (int i = 0; i < this->size; i++) {
        if (this->has_data) {
            std::cout << "val: " << this->data[i].getValue() << " ";
        } else {
            std::string error = "No data";
            throw error;
        }
    }
}


template<typename T>
int DynamicArray<T>::getSize() {
    return this->size;
}

template<typename T>
void DynamicArray<T>::swap(int i, int j) {
    Option<T> el = this->data[i];
    this->data[i] = this->data[j];
    this->data[j] = el;
}

template<typename T>
Option<T> &DynamicArray<T>::operator[](const int index) {
    return this->data[index];
}

template<typename T>
Option<T> &DynamicArray<T>::getEl(int index) {
    return this->data[index];
}

template<typename T>
void DynamicArray<T>::setEl(int index, Option<T> el) {
    this->data[index] = el;
}

template<typename T>
DynamicArray<T>::~DynamicArray() = default;

#endif //SECOND_LAB1_SEM3_DYNAMICARRAY_HPP
