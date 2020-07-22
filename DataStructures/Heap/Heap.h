#include <bits/stdc++.h>

#define MAX_HEAP true
#define MIN_HEAP false

template <class D, bool H>
class Heap{
private:
    int * arr;
    int current_size;
    int capacity;
    bool heap_type;
    void extend_heap();

public:
    Heap();
    Heap(int capacity_);             //initialize arr with this capacity_
    ~Heap();
    int get_capacity();
    void HeapifyDown(int index_);        //heapify starting from index_
    void HeapifyUp(int index_);
    int get_parent(int index_);
    int get_left(int index_);
    int get_right(int index_);
    bool extractMin(int & key);       //get min value (root), delete it, and heapify
    bool getMin(int & key);           //get min value (root)
    void insert(int key_);
    bool remove(int index_);
    void print();
};