#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

template <typename T>
class MinMaxHeap {
private:

    class Heap {
    private:

        T keyVlaue;
        int index;

    public:

        Heap() {
      
        }

        const Heap& operator=(const Heap& rhs) {
            if (this != &rhs) {
                keyVlaue = rhs.keyVlaue;
                index = rhs.index;
            }
            return *this;
        }

        T& getKeyValue() {
            return keyVlaue;
        }

        int& getIndex() {
            return index;
        }

        void setKeyValue(const T& data) {
            keyVlaue = data;
        }

        int setIndex(const int indx) {
            index = indx;
        }

    };

    int l_size, l_capacity;
    Heap *minHeap, *maxHeap;

public:

    MinMaxHeap(int capacity);
    MinMaxHeap(const MinMaxHeap<T>& other);
    ~MinMaxHeap();
    const MinMaxHeap<T>& operator=(const MinMaxHeap<T>& rhs);
    int size();
    int capacity();
    void insert(const T& data);
    T deleteMin();
    T deleteMax();
    void dump();
    void locateMin(int pos, T& data, int& index);
    void locateMax(int pos, T& data, int& index);



};

#endif /* MINMAXHEAP_H */

