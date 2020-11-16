#ifndef SECOND_LAB1_SEM3_SORTER_HPP
#define SECOND_LAB1_SEM3_SORTER_HPP

#include <random>
#include <cstdlib>
#include <ctime>
#include <stack>
#include "ArraySequence.hpp"
#include "ISorter.hpp"

/*template<typename T>
int partition(ArraySequence<T>* a, int l, int r){
    Option<T> v(a->getEl((l+r)/2));
    int i = l;
    int j = r;
    while(i <= j){
        while(a->getEl(i).getValue() < v.getValue()){
            i++;
        }
        while(a->getEl(j).getValue() > v.getValue()){
            j--;
        }
        if(i >= j){
            break;
        }
        a->swap(i++, j--);
    }
    return j;
}*/


bool checkIn(const int *arr, int size, int x) {
    bool answer = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            answer = true;
        }
    }
    return answer;
}

int *getRandomNumbers(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    auto *answer = new int[max - min];
    int check;
    int size = 0;
    for (int i = min; i < max; ++i) {
        check = static_cast<int>(rand() * fraction * (max - min + 1) + min);
        if (!checkIn(answer, size, check)) {
            answer[i] = check;
            size++;
        } else {
            i--;
        }
    }
    return answer;
}


template<typename T>
class Sorter : public ISorter<T> {
private:
    Sequence<T> *data;
public:
    Sorter();

    explicit Sorter(Sequence<T> *);

    Sequence<T> *giveData() override;

    void shuffle() override;

    void bubbleSort(int (*cmp) (T,T)) override;

    //void quickSort(ArraySequence<T> *, int, int);
    Sequence<T>* bubbleSort(Sequence<T>*, int (*cmp) (T,T)) override;

    ~Sorter();
};

template<typename T>
Sorter<T>::Sorter() {
    this->data = new ArraySequence<T>();
}

template<typename T>
Sorter<T>::Sorter(Sequence<T> *other) {
    this->data = new ArraySequence<T>();
    for (int i = 0; i < other->getSize(); i++) {
        this->data->append(other->getEl(i));
    }
}

template<typename T>
Sequence<T> *Sorter<T>::giveData() {
    if (this->data) {
        return this->data;
    }
}

template<typename T>
void Sorter<T>::bubbleSort(int (*cmp) (T,T)) {
    for (int i = 0; i < this->data->getSize() - 1; i++)
        for (int j = 0; j < this->data->getSize() - i - 1; j++)
            if (cmp(this->data->getEl(j).getValue(), this->data->getEl(j + 1).getValue()) == 1)
                this->data->swap(j, j + 1);
}

template<typename T>
void Sorter<T>::shuffle() {
    auto *buff = new ArraySequence<T>(this->data->getSize());
    int *indexes = getRandomNumbers(0, this->data->getSize());
    for (int i = 0; i < this->data->getSize(); ++i) {
        buff->setEl(indexes[i], this->data->getEl(i));
    }
    this->data = buff;
}

template<typename T>
Sequence<T> *Sorter<T>::bubbleSort(Sequence<T> * sequence, int (*cmp)(T, T)) {
    this->data = sequence;
    for (int i = 0; i < this->data->getSize() - 1; i++)
        for (int j = 0; j < this->data->getSize() - i - 1; j++)
            if (cmp(this->data->getEl(j).getValue(), this->data->getEl(j + 1).getValue()) == 1)
                this->data->swap(j, j + 1);
    return this->data;
}



/*template<typename T>
void Sorter<T>::quickSort(ArraySequence<T> * a, int l, int r) {
    std::stack<std::pair<int, int>> s;
    auto p = std::make_pair(l ,r);
    s.push(p);
    while(!s.empty()){
        p = s.pop();
        if(r <= l){
            continue;
        }
        int i = partition(a, l, r);
        if(i - l > r - i){
            p = std::make_pair(l, i-1);
            s.push(p);
            p = std::make_pair(i+1, r);
            s.push(p);
        }else{
            p = std::make_pair(i+1, r);
            s.push(p);
            p = std::make_pair(l, i-1);
            s.push(p);
        }
    }

}*/

/*template<typename T>
void Sorter<T>::quickSort(ArraySequence<T> *numbers, int left, int right) {
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers->getEl(left);
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers->getSize()[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
    this->data = numbers;
}*/

/*template<typename T>
void Sorter<T>::quickSort(int left, int right) {
    int l_hold = left;
    int l_right = right;
    //Option<T> pivot = this->data->getEl(0);
    int pivot = left;
    while (left < right) {
        while ((this->data->getEl(right).getValue() >= this->data->getEl(pivot).getValue()) && (left < right)) {
            right--;
        }
        if (left != right) {
            this->data->setEl(left, this->data->getEl(right));
            left++;
        }
        while ((this->data->getEl(left).getValue()) <= this->data->getEl(pivot).getValue() && (left < right)) {
            left++;
        }
        if (left != right) {
            this->data->setEl(right, this->data->getEl(left));
            right--;
        }
    }
    this->data->setEl(left, this->data->getEl(pivot));
    pivot = left;
    left = l_hold;
    right = l_right;
    if (left < pivot){
        quickSort(left, pivot - 1);
    }
    if (right > pivot){
        quickSort(pivot + 1, right);
    }
}*/

template<typename T>
Sorter<T>::~Sorter() = default;

#endif //SECOND_LAB1_SEM3_SORTER_HPP
