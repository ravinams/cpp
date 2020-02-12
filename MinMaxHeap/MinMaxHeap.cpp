#include "MinMaxHeap.h"
#include <iostream>

using namespace std;

template <typename T>
MinMaxHeap<T>::MinMaxHeap(int capacity) {
    l_size = 0;
    l_capacity = capacity;
    minHeap = new Heap[l_capacity + 1];
    maxHeap = new Heap[l_capacity + 1];
}

template <typename T>
MinMaxHeap<T>::MinMaxHeap(const MinMaxHeap<T>& other) {

    delete[] minHeap;
    delete[] maxHeap;

    l_size = other.size();
    l_capacity = other.capacity;

    minHeap = new Heap[l_capacity + 1];
    maxHeap = new Heap[l_capacity + 1];

    for (int i = 1; i <= l_capacity; i++) {
        minHeap[i] = other.minHeap[i];
        maxHeap[i] = other.maxHeap[i];
    }

}

template <typename T>
MinMaxHeap<T>::~MinMaxHeap() {
    delete[] minHeap;
    delete[] maxHeap;
}

template <typename T>
const MinMaxHeap<T>& MinMaxHeap<T>::operator=(const MinMaxHeap<T>& rhs) {

    if (this != &rhs) {

        delete[] minHeap;
        delete[] maxHeap;

        l_size = rhs.size();
        l_capacity = rhs.capacity();

        minHeap = new Heap[l_capacity + 1];
        maxHeap = new Heap[l_capacity + 1];

        for (int i = 1; i <= l_capacity; i++) {
            minHeap[i] = rhs.minHeap[i];
            maxHeap[i] = rhs.maxHeap[i];
        }

    }
    return *this;
}

template <typename T>
int MinMaxHeap<T>::size() {
    return l_size;
}

template <typename T>
int MinMaxHeap<T>::capacity() {
    return l_capacity;
}

template <typename T>
void MinMaxHeap<T>::insert(const T& data) {

    ++l_size;

    minHeap[l_size].setKeyValue(data);
    minHeap[l_size].setIndex(l_size);

    maxHeap[l_size].setKeyValue(data);
    maxHeap[l_size].setIndex(l_size);

}

template <typename T>
T MinMaxHeap<T>::deleteMin() {

}

template <typename T>
T MinMaxHeap<T>::deleteMax() {

}

template <typename T>
void MinMaxHeap<T>::dump() {

    cout << "... MinMaxHeap::dump() ..." << endl;

    cout << "\n\n------------Min Heap------------" << endl;
    cout << "size = " << size() << "," << "capacity = " << capacity() << endl;
    for (int i = 1; i <= size(); i++)
        cout << "Heap[" << i << "] = (" << minHeap[i].getKeyValue() << "," << minHeap[i].getIndex() << ")" << endl;

    cout << "\n\n------------Max Heap------------" << endl;
    cout << "size = " << size() << "," << "capacity = " << capacity() << endl;
    for (int i = 1; i <= size(); i++)
        cout << "Heap[" << i << "] = (" << maxHeap[i].getKeyValue() << "," << maxHeap[i].getIndex() << ")" << endl;
}

template <typename T>
void MinMaxHeap<T>::locateMin(int pos, T& data, int& index) {

}

template <typename T>
void MinMaxHeap<T>::locateMax(int pos, T& data, int& index) {

}