#ifndef SECOND_LAB1_SEM3_SHELLSORTER_HPP
#define SECOND_LAB1_SEM3_SHELLSORTER_HPP

#include "ISorter.hpp"
#include <iostream>

template<typename T>
class ShellSorter : public ISorter<T> {
public:
    ShellSorter();

    ~ShellSorter();

    Sequence<T> *sort(Sequence<T> *, int (*cmp)(T, T)) override;
};

template<typename T>
ShellSorter<T>::ShellSorter() = default;

template<typename T>
ShellSorter<T>::~ShellSorter() = default;

template<typename T>
Sequence<T> *ShellSorter<T>::sort(Sequence<T> * input, int (*cmp)(T, T)) {
    int step, i, j;
    Option<T> el{};
    auto startTime = std::chrono::system_clock::now();
    // Выбор шага
    for (step = input->getSize()/ 2; step > 0; step /= 2) {
        ++this->cntIterations;
        // Перечисление элементов, которые сортируются на определённом шаге
        for (i = step; i < input->getSize(); i++) {
            // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
            for (j = i - step; j >= 0 && cmp(input->getEl(j).getValue(),input->getEl(j + step).getValue()) == 1; j -= step) {
                input->swap(j, j + step);
            }
        }
    }
    auto endTime = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> elapsedMilliseconds = endTime - startTime;
    this->numberOfIterationMilliseconds = elapsedMilliseconds.count();
    return input;
}


#endif //SECOND_LAB1_SEM3_SHELLSORTER_HPP
