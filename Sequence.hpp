#ifndef SECOND_LAB1_SEM3_SEQUENCE_HPP
#define SECOND_LAB1_SEM3_SEQUENCE_HPP

#include "Option.hpp"

template<typename T>
class Sequence {
public:
    virtual void append(Option<T>) = 0;

    [[nodiscard]] virtual int getSize() const = 0;

    virtual void swap(int, int) = 0;

    virtual void print() = 0;

    virtual Option<T> &getEl(int) = 0;

    virtual void setEl(int, Option<T>) = 0;

    virtual Option<T> &operator[](int) = 0;

    virtual bool operator==(Sequence<T> *) = 0;

};


#endif //SECOND_LAB1_SEM3_SEQUENCE_HPP
