#ifndef SECOND_LAB1_SEM3_LISTSEQUENCE_HPP
#define SECOND_LAB1_SEM3_LISTSEQUENCE_HPP

#include "Sequence.hpp"
#include "LinkedList.hpp"
#include "Exceptions.hpp"

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> *data;
    int size{};
public:
    ListSequence();

    ListSequence(Option<T> *data, int size);

    explicit ListSequence(Sequence<T> *);

    explicit ListSequence(LinkedList<T> *data);

    ListSequence(const ListSequence<T> &other);

    LinkedList<T> * getData() const;

    [[nodiscard]] int getSize() const override;

    void print() override;

    void append(Option<T>) override;

    //void prepend(Option<T>) override;

    void setEl(int, Option<T>) override;

    Option<T> &getEl(int) override;

    void swap(int, int) override;

    Option<T> &operator[](int) override ;

    bool operator==(Sequence<T> *right);

    ~ListSequence();
};

template<typename T>
ListSequence<T>::ListSequence() {
    this->data = new LinkedList<T>();
    this->size = 0;
}

template<typename T>
ListSequence<T>::ListSequence(Option<T> *data, int size) {
    this->data = new LinkedList<T>(data, size);
    this->size = size;
}

template<typename T>
ListSequence<T>::ListSequence(LinkedList<T> *data) {
    this->data = data;
    this->size = data->getSize();
}

template<typename T>
ListSequence<T>::ListSequence(const ListSequence<T> &other) {
    this->data = other.getData();
    this->size = other.getSize();
}

template<typename T>
ListSequence<T>::ListSequence(Sequence<T> *other) {
    this->data = new LinkedList<T>();
    for(int i = 0; i < other->get_size(); i++){
        this->append(other->get_el(i));
    }
    this->size = other->get_size();
}


template<typename T>
LinkedList<T> *ListSequence<T>::getData() const {
    return this->data;
}

template<typename T>
int ListSequence<T>::getSize() const {
    return this->size;
}

template<typename T>
void ListSequence<T>::print() {
    this->data->print();
}

template<typename T>
void ListSequence<T>::append(Option<T> el) {
    this->data->append(el);
    this->size++;
}


template<typename T>
void ListSequence<T>::setEl(int index, Option<T> el) {
    this->data->setEl(el, index);
}

template<typename T>
Option<T> &ListSequence<T>::getEl(int index) {
    return this->data->getEl(index);
}


template<typename T>
void ListSequence<T>::swap(int i, int j) {
    this->data->swap(i, j);
}

template<typename T>
Option<T> &ListSequence<T>::operator[](int index) {
    return this->data->getEl(index);
}

template<typename T>
bool ListSequence<T>::operator==(Sequence <T> *right) {
    if (this->size == right->getSize()){
        int cur_size = this->size;
        for(int i = 0; i < cur_size; i++){
            return getEl(i) == right->getEl(i);
        }
    }else{
        throw exceptions::ListExceptions("Cant compare!", __LINE__, __FILE__);
    }
}


template<typename T>
ListSequence<T>::~ListSequence() = default;

#endif //SECOND_LAB1_SEM3_LISTSEQUENCE_HPP
