#ifndef SECOND_LAB1_SEM3_INTERFACE_HPP
#define SECOND_LAB1_SEM3_INTERFACE_HPP

#include <iostream>
#include "ArrayTest.hpp"
#include "ListTest.hpp"
#include "SortTests.hpp"

using namespace std;


template<typename T>
void runInterface() {
    cout << "Run tests: \n";
    cout << "Shell sort test: ";
    sortTest::shellSortTest();
    cout << "\n";
    cout << "Heap sort tests: ";
    sortTest::heapSortTest();
    cout << "\n";
    cout << "List tests: ";

    listTest::SetTest<int> set_test_list;
    set_test_list.test();

    cout << " ";

    listTest::GetTest<int> get_test_list;
    get_test_list.test();

    cout << "\n Array tests: ";

    arrayTest::SetTest<int> set_test_array;
    set_test_array.test();

    cout << " ";

    arrayTest::GetTest<int> get_test_array;
    get_test_array.test();

    cout << "\n";


    cout << "Run benchmark: ";
    ArraySequence<int> array;
    ArraySequence<int> array_second;
    int cur_size = 10000;


    srand(time(nullptr));
    // заполнение матрицы ГСЧ
    for (int i = 0; i < cur_size; i++) {
        Option<int> el(1 + rand() % 4000);
        array.append(el);
        array_second.append(el);
    }

    HeapSorter<int> heapSorter{};
    Sequence<int> *heap_pointer = &array_second;

    heap_pointer = heapSorter.sort(&array, intCmp);
    cout << "\n";
    cout << "Heap sort: " << heapSorter.getNumberOfIterationSeconds();
    cout << "\n";

    Sequence<int> *pointer = &array;
    ShellSorter<int> shellSorter{};
    pointer = shellSorter.sort(&array, intCmp);
    cout << "\n";
    cout << "Shell sort: " << shellSorter.getNumberOfIterationSeconds();
    cout << "\n";

    cout << " 1. Enter elements 2. Random elements ";

    int type;
    int size;
    int sort_type;
    cin >> type;
    ArraySequence<T> cur_array;
    ArraySequence<T> *s_array = &cur_array;

    switch (type) {
        case 1: {
            cout << "Size: ";
            cin >> size;
            T elem;
            for (int i = 0; i < size; ++i) {
                cout << "Enter element :";
                cin >> elem;
                Option<T> el(elem);
                s_array->append(el);
            }
            cout << "\n";
            s_array->print();
            break;
        }
        case 2: {
            cout << "Size: ";
            cin >> size;
            srand(time(nullptr));
            for (int i = 0; i < size; i++) {
                Option<T> el(1 + rand() % 4000);
                s_array->append(el);
            }
            s_array->print();
            break;
        }
    }

    cout << " \n1. Heap Sort 2. Shell sort   ";
    cin >> sort_type;
    switch (sort_type) {
        case 1: {
            HeapSorter<T> cur_heap_sorter{};
            Sequence<T> *cur_heap_pointer = s_array;

            cur_heap_pointer = heapSorter.sort(s_array, intCmp);
            cur_heap_pointer->print();
            break;
        }
        case 2: {
            ShellSorter<T> cur_shell_sorter{};
            Sequence<T> *cur_shell_pointer = s_array;

            cur_shell_pointer = shellSorter.sort(s_array, intCmp);
            cur_shell_pointer->print();
            break;
        }
    }
}

#endif //SECOND_LAB1_SEM3_INTERFACE_HPP
