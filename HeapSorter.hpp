#ifndef SECOND_LAB1_SEM3_HEAPSORTER_HPP
#define SECOND_LAB1_SEM3_HEAPSORTER_HPP

#include "ISorter.hpp"
#include <chrono>


template<typename T>
void heapify(Sequence<T> *arr, int n, int i, int (*cmp)(T, T)) {
    int largest = i;
// Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && cmp(arr->getEl(l).getValue(), arr->getEl(largest).getValue()) == 1) {
        largest = l;
    }

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент

    if (r < n && cmp(arr->getEl(r).getValue(), arr->getEl(largest).getValue()) == 1) {
        largest = r;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        arr->swap(i, largest);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest, cmp);
    }
}


template<typename T>
class HeapSorter : public ISorter<T> {
public:
    HeapSorter();

    ~HeapSorter();

    Sequence<T> *sort(Sequence<T> *, int (*cmp)(T, T)) override;

    //void heapify(Sequence<T>*, int, int, int (*cmp)(T,T));
};

template<typename T>
Sequence<T> *HeapSorter<T>::sort(Sequence<T> *arr, int (*cmp)(T, T)) {
    auto startTime = std::chrono::system_clock::now();
    for (int i = arr->getSize() / 2 - 1; i >= 0; i--)
        heapify<T>(arr, arr->getSize(), i, cmp);

    // Один за другим извлекаем элементы из кучи
    for (int i = arr->getSize() - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        arr->swap(0, i);

        // вызываем процедуру heapify на уменьшенной куче
        heapify<T>(arr, i, 0, cmp);
    }
    auto endTime = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> elapsedMilliseconds = endTime - startTime;
    this->numberOfIterationMilliseconds = elapsedMilliseconds.count();
    return arr;
}


template<typename T>
HeapSorter<T>::~HeapSorter() = default;

template<typename T>
HeapSorter<T>::HeapSorter() = default;

#endif //SECOND_LAB1_SEM3_HEAPSORTER_HPP
