#include <bits/stdc++.h>

class MinHeap{
private:
    int * arr;
    int current_size;
    int capacity;

public:
    MinHeap();
    MinHeap(int capacity_);             //initialize arr with this capacity_
    ~MinHeap();
    int get_capacity();
    void MinHeapify(int index_);        //heapify starting from index_
    int get_parent(int index_);
    int get_left(int index_);
    int get_right(int index_);
    bool extractMin(int & key);       //get min value (root), delete it, and heapify
    bool getMin(int & key);           //get min value (root)
    void insert(int key_);
    bool remove(int index_);
    void print();
};