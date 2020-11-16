#ifndef SECOND_LAB1_SEM3_SORTTESTS_HPP
#define SECOND_LAB1_SEM3_SORTTESTS_HPP

#include <iostream>
#include "HeapSorter.hpp"
#include "ShellSorter.hpp"
#include "ArraySequence.hpp"


int integerCompare(int a, int b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return 0;
    } else {
        return 2;
    }
}


int (*intCmp)(int, int) = integerCompare;

namespace sortTest {

    void heapSortTest() {
        ArraySequence<int> first;
        ArraySequence<int> second;
        for (int i = 0; i < 3; ++i) {
            Option<int> el(i);
            first.append(el);
        }
        for (int i = 2; i >= 0; --i) {
            Option<int> el(i);
            second.append(el);
        }
        HeapSorter<int> heapSorter{};
        Sequence<int> *pointer = &second;
        pointer = heapSorter.sort(&second, intCmp);
        if (first == pointer) {
            std::cout << "Test passed";
        } else {
            std::cout << "Test failed";
        }
    }

    void shellSortTest() {
        ArraySequence<int> first;
        ArraySequence<int> second;
        for (int i = 0; i < 3; ++i) {
            Option<int> el(i);
            first.append(el);
        }
        for (int i = 2; i >= 0; --i) {
            Option<int> el(i);
            second.append(el);
        }
        ShellSorter<int> shellSorter{};
        Sequence<int> *pointer = &second;
        pointer = shellSorter.sort(&second, intCmp);
        if (first == pointer) {
            std::cout << "Test passed";
        } else {
            std::cout << "Test failed";
        }
    }
}

#endif //SECOND_LAB1_SEM3_SORTTESTS_HPP
