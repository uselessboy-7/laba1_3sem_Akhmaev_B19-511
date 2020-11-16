#ifndef SECOND_LAB1_SEM3_ARRAYSEQUENCE_HPP
#define SECOND_LAB1_SEM3_ARRAYSEQUENCE_HPP

#include "Sequence.hpp"
#include "DynamicArray.hpp"

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> *data;
    int size{};
public:
    ArraySequence();

    [[maybe_unused]] ArraySequence(Option<T> *data, int size);

    explicit ArraySequence(int size);

    //explicit ArraySequence(DynamicArray<T> *data);

    [[maybe_unused]] explicit ArraySequence(Sequence<T> *);

    [[maybe_unused]] ArraySequence(const ArraySequence<T> &other);

    DynamicArray<T> * getData();

    void append(Option<T>) override;

    void print() override;

    [[nodiscard]] int getSize() const override;

    void swap(int, int) override;

    void setEl(int, Option<T>) override ;

    Option<T> &operator[](int) override ;

    Option<T> &getEl(int) override ;

    bool operator==(Sequence<T> *right);

    ~ArraySequence();

};

template<typename T>
ArraySequence<T>::ArraySequence() {
    this->data = new DynamicArray<T>();
    this->size = 0;
}

template<typename T>
[[maybe_unused]] ArraySequence<T>::ArraySequence(Option<T> *data, int size) {
    this->data = new DynamicArray<T>(data, size);
    this->size = size;
}

/*template<typename T>
ArraySequence<T>::ArraySequence(DynamicArray <T> *data) {

}*/

template<typename T>
[[maybe_unused]] ArraySequence<T>::ArraySequence(const ArraySequence<T> &other) {
    this->data = other.getData();
    this->size = other.getSize();
}

template<typename T>
[[maybe_unused]] ArraySequence<T>::ArraySequence(Sequence<T> *other) {
    this->data = new DynamicArray<T>();
    for (int i = 0; i < other->getSize(); i++) {
        append(other->getEl(i));
    }
    this->size = other->getSize();
}

template<typename T>
void ArraySequence<T>::append(Option<T> el) {
    this->data->append(el);
    this->size++;
}

template<typename T>
void ArraySequence<T>::print() {
    this->data->print();
}

template<typename T>
int ArraySequence<T>::getSize() const {
    return this->data->getSize();
}

template<typename T>
void ArraySequence<T>::swap(int i, int j) {
    this->data->swap(i, j);
}

template<typename T>
Option<T> &ArraySequence<T>::operator[](int index) {
    return this->data->getEl(index);
}

template<typename T>
Option<T> &ArraySequence<T>::getEl(int index) {
    return this->data->getEl(index);
}

template<typename T>
ArraySequence<T>::ArraySequence(int size) {
    this->size = size;
    this->data = new DynamicArray<T>(size);
}

template<typename T>
void ArraySequence<T>::setEl(int index, Option<T> el) {
    this->data->setEl(index, el);
}

template<typename T>
DynamicArray<T> *ArraySequence<T>::getData() {
    return this->data;
}

template<typename T>
bool ArraySequence<T>::operator==(Sequence<T> *right) {
    if (this->size == right->getSize()){
        for(int i = 0; i < this->size; i++){
            return getEl(i) == right->getEl(i);
        }
    }else{
        throw exceptions::ArrayExceptions("Can't compare!", __LINE__, __FILE__);
    }
}


template<typename T>
ArraySequence<T>::~ArraySequence() = default;


#endif //SECOND_LAB1_SEM3_ARRAYSEQUENCE_HPP
