#ifndef SECOND_LAB1_SEM3_LINKEDLIST_HPP
#define SECOND_LAB1_SEM3_LINKEDLIST_HPP

#include <iostream>
#include "Option.hpp"


template<typename T>
class LinkedList {
private:
    struct Node {
        Node() : n_next(nullptr) {}

        explicit Node(Option<T> t) : data(t), n_next(nullptr) {}

        Option<T> data;
        Node *n_next;
    };

    Node *head;
    Node *end;
    int size{};
public:
    LinkedList() : head(nullptr), end(nullptr), size(0) {};

    LinkedList(Node *head, Node *end, int size) : head(head), end(end), size(size) {};

    LinkedList(Option<T> *, int);

    LinkedList(const LinkedList &a);

    ~LinkedList();

    void append(Option<T>);

    //void prepend(Option<T>);

    //void remove();

    void print();

    //bool has_el(Option<T>);

    //bool is_empty();

    //Option<T> getLast() const;

    //Option<T> getFirst() const;

    Option<T> &getEl(int) const;

    void setEl(Option<T>, int);

    void swap(int, int);

    //void insertEl(Option<T>, int);

    //LinkedList<T> get_index_data(int, int);

    //void concat(const LinkedList &a);

    [[nodiscard]] int getSize() const;
};

template<typename T>
LinkedList<T>::~LinkedList() = default;

/*template<typename T>
void LinkedList<T>::prepend(Option<T> el) {
    if (Node *node = new Node(el)) {
        if (head) {
            node->n_next = head;
            head = node;
            size++;
        } else {
            node->n_next = head;
            head = node;
            end = node;
            size++;
        }
    }
}*/


template<typename T>
void LinkedList<T>::append(Option<T> el) {
    if (Node *node = new Node(el)) {
        if (head) {
            end->n_next = node;
            end = node;
            size++;
        } else {
            node->n_next = head;
            head = node;
            end = node;
            size++;
        }
    }
}

/*template<typename T>
void LinkedList<T>::remove() {
    if (head) {
        Node *new_head = head->n_next;
        delete head;
        head = new_head;
    } else {
        throw "Remove from empty LinkedList";
    }
}*/

template<typename T>
void LinkedList<T>::print() {
    Node *el_pointer = head;
    while (el_pointer) {
        Option<T> el = el_pointer->data;
        std::cout << "val: " <<el.getValue() << "\t";
        el_pointer = el_pointer->n_next;
    }
}


template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

/*template<typename T>
bool LinkedList<T>::has_el(Option<T> el) {
    Node *el_pointer = head;
    while (el_pointer) {
        Option<T> c_el = el_pointer->data;
        if (c_el.get_value() == el.get_value()) {
            return true;
        }
        el_pointer = el_pointer->n_next;
    }
    return false;
}

template<typename T>
bool LinkedList<T>::is_empty() {
    return not head;
}
*/
template<typename T>
LinkedList<T>::LinkedList(Option<T>*items, int count) {
    if (Node *node_f = new Node(items[0])) {
        head = node_f;
    }
    if (Node *node_l = new Node(items[count - 1])) {
        end = node_l;
    }
    for (int i = 0; i < count - 1; i++) {
        Node *node = new Node(items[i]);
        Node *next_node = new Node(items[i + 1]);
        node->n_next = next_node;
    }
    end->n_next = nullptr;
}

/*

template<typename T>
Option<T> LinkedList<T>::getLast() const{
    Option<T> el = end->data;
    return el;
}

template<typename T>
Option<T> LinkedList<T>::getFirst() const{
    Option<T> el = head->data;
    return el;
}*/

template<typename T>
Option<T> &LinkedList<T>::getEl(int index) const{
    if (index <= size - 1 && index >= 0) {
        Node *el_pointer = head;
        for (int i = 0; i < index; i++) {
            el_pointer = el_pointer->n_next;
        }
        return el_pointer->data;
    } else {
        throw exceptions::ListExceptions("Index out of range!", __LINE__, __FILE__);
    }
}

/*template<typename T>
void LinkedList<T>::insertEl(Option<T> el, int index) {
    if (index <= size - 1 && index >= 0) {
        Node *el_pointer = head;
        for (int i = 0; i < index - 1; i++) {
            el_pointer = el_pointer->n_next;
        }
        if (Node *node = new Node(el)) {
            node->n_next = el_pointer->n_next;
            el_pointer->n_next = node;
            size++;
        }
    } else {
        throw "Index out of range";
    }
}

template<typename T>
LinkedList<T> LinkedList<T>::get_index_data(int k, int j) {
    if (k >= 0 && j >= 0 && k <= size - 1 && j <= size - 1) {
        LinkedList<T> buff;
        for(int i = k; i <= j; i++){
            buff.append(this->getEl(i));
        }
        return buff;
    } else {
        throw "Index out of range";
    }
}*/

template<typename T>
LinkedList<T>::LinkedList(const LinkedList &a) {
    this->head = nullptr;
    this->end = nullptr;
    this->size = 0;
    for(int i = 0; i < a.getSize(); i++){
        if (Node *node = new Node(a.getEl(i))) {
            if (this->head) {
                this->end->n_next = node;
                this->end = node;
                this->size++;
            } else {
                node->n_next = this->head;
                this->head = node;
                this->end = node;
                this->size++;
            }
        }
    }
}
/*
template<typename T>
void LinkedList<T>::concat(const LinkedList &a) {
    end->n_next = *a.getFirst();
    end = *a.getLast();
}*/

template<typename T>
void LinkedList<T>::setEl(Option<T> el, int index) {
    if (index <= size - 1 && index >= 0) {
        Node *el_pointer = head;
        for (int i = 0; i < index; i++) {
            el_pointer = el_pointer->n_next;
        }
        if(Node *node = new Node(el)){
            node->n_next = el_pointer->n_next;
            el_pointer = node;
        }
    } else {
        throw exceptions::ListExceptions("Index out of range!", __LINE__, __FILE__);
    }
}

template<typename T>
void LinkedList<T>::swap(int i, int j) {
    Option<T> el = this->getEl(i);
    this->setEl(this->getEl(i), i);
    this->setEl(el,j);
}


#endif //SECOND_LAB1_SEM3_LINKEDLIST_HPP
