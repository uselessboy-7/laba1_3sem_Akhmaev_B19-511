#ifndef SECOND_LAB1_SEM3_ARRAYTEST_HPP
#define SECOND_LAB1_SEM3_ARRAYTEST_HPP

#include "ArraySequence.hpp"

namespace arrayTest {
    template<typename T>
    class SetTest {
    private:
        ArraySequence<T> first;
        ArraySequence<T> second;
    public:
        SetTest() : first(), second() {};

        void test();

        ~SetTest();
    };

    template<typename T>
    void SetTest<T>::test() {
        Option<int> test_el(10);
        for (int i = 0; i < 2; i++) {
            Option<T> el(i);
            first.append(el);
        }
        first.append(test_el);
        for (int i = 3; i < 4; i++) {
            Option<T> el(i);
            first.append(el);
        }
        for (int i = 0; i < 4; i++) {
            Option<T> el(i);
            second.append(el);
        }
        second.setEl(2, test_el);
        if (first == &second) {
            std::cout << "Test passed";
        } else {
            std::cout << "Test failed";
        }
    }


    template<typename T>
    class GetTest {
    private:
        ArraySequence<T> first;
        Option<T> second;
    public:
        GetTest() : first(), second() {};

        void test();

        ~GetTest();
    };

    template<typename T>
    void GetTest<T>::test() {
        for (int i = 0; i < 4; i++) {
            Option<T> el(i);
            first.append(el);
        }
        second.setValue(2);
        if (second == first.getEl(2)) {
            std::cout << "Test passed";
        } else {
            std::cout << "Test failed";
        }

    }


    template<typename T>
    GetTest<T>::~GetTest() = default;


    template<typename T>
    SetTest<T>::~SetTest() = default;

}

#endif //SECOND_LAB1_SEM3_ARRAYTEST_HPP
