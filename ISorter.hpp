#ifndef SECOND_LAB1_SEM3_ISORTER_HPP
#define SECOND_LAB1_SEM3_ISORTER_HPP

#include "Sequence.hpp"

template<typename T>
class ISorter {
protected:
    unsigned int numberOfIterationMilliseconds{};
    unsigned int cntIterations{};
public:
    //virtual Sequence<T> *giveData() = 0;

    //virtual void shuffle() = 0;

    //virtual void sort() = 0;

    //virtual void bubbleSort(int (*cmp) (T,T)) = 0;

    //virtual Sequence<T>* bubbleSort(Sequence<T>* ,int (*cmp) (T,T)) = 0;

    virtual Sequence<T> *sort(Sequence<T> *, int (*cmp) (T,T)) = 0;

    unsigned int getCntIterations();

    unsigned int getNumberOfIterationSeconds();

    void resetMetrics();
};

template<typename T>
unsigned int ISorter<T>::getNumberOfIterationSeconds() {
    return this->numberOfIterationMilliseconds;
}

template<typename T>
void ISorter<T>::resetMetrics() {
    this->cntIterations = 0;
    this->numberOfIterationMilliseconds = 0;
}

template<typename T>
unsigned int ISorter<T>::getCntIterations() {
    return this->cntIterations;
}

#endif //SECOND_LAB1_SEM3_ISORTER_HPP
