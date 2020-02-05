

/**
 * DONE: extend the array when you reach full capacity
 * DONE: make the print() function visualize the heap good (hint: use log2(current_size+1))
 * 
 * TODO: make print() even better
 * TODO: fix bug in remove() (hint: try remove() then print())
 * 
 * 
 * */

#include "Heap.h"
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

template <class D, bool H>
Heap<D, H>::Heap() : Heap(10) {}

template <class D, bool H>
Heap<D, H>::Heap(int capacity_)
{
    capacity = capacity_;
    arr = (int *)malloc(capacity * sizeof(int));
    current_size = 0;
    heap_type = H;
}

template <class D, bool H>
void Heap<D, H>::extend_heap()
{
    capacity *= 2;
    void *added = realloc(arr, capacity * sizeof(int));

    if (added == NULL)
    {
        cout<<"added is NULL"<<endl;
        int *temp_arr = (int *)malloc(capacity * sizeof(int));
        temp_arr = copy(arr, arr+current_size, temp_arr);
        arr = temp_arr;
    }
}

template <class D, bool H>
Heap<D, H>::~Heap()
{
    delete arr;
}

template <class D, bool H>
int Heap<D, H>::get_capacity() { return capacity; }

template <class D, bool H>
void Heap<D, H>::insert(int key_)
{
    if (current_size == capacity)
    {
        extend_heap();
        insert(key_);
    }
    else
    {
        int i = current_size;
        arr[current_size++] = key_;

        HeapifyUp(i); //i here equals current_size-1
    }
}

template <class D, bool H>
bool Heap<D, H>::remove(int index)
{
    if (index >= current_size)
        return false;
    current_size--;
    arr[index] = INT_MAX;
    HeapifyDown(index);
    return true;
}

template <class D, bool H>
void Heap<D, H>::HeapifyDown(int index)
{
    if (index < current_size)
    {
        int left_index = get_left(index);
        int right_index = get_right(index);
        if (heap_type == MAX_HEAP)
        {
            int biggest_index = index;

            if (left_index < current_size && arr[left_index] > arr[index])
                biggest_index = left_index;
            if (right_index < current_size && arr[right_index] > arr[biggest_index])
                biggest_index = right_index;

            if (biggest_index != index)
            {
                swap(arr[biggest_index], arr[index]);
                HeapifyDown(biggest_index);
            }
        }
        else
        {

            int smallest_index = index;

            if (left_index < current_size && arr[left_index] < arr[index])
                smallest_index = left_index;
            if (right_index < current_size && arr[right_index] < arr[smallest_index])
                smallest_index = right_index;

            if (smallest_index != index)
            {
                swap(arr[smallest_index], arr[index]);
                HeapifyDown(smallest_index);
            }
        }
    }
}

template <class D, bool H>
void Heap<D, H>::HeapifyUp(int index)
{
    if (index > 0)
    {
        int parent = get_parent(index);
        if (heap_type == MAX_HEAP)
        {
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                HeapifyUp(parent);
            }
        }
        else
        {
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                HeapifyUp(parent);
            }
        }
    }
}

template <class D, bool H>
bool Heap<D, H>::getMin(int &key)
{
    if (!current_size)
        return false;
    key = arr[0];
    return true;
}

template <class D, bool H>
bool Heap<D, H>::extractMin(int &key)
{
    if (!current_size)
        return false;
    current_size--;
    key = arr[0];
    if (current_size)
    {
        arr[0] = arr[current_size];
        HeapifyDown(0);
    }
    return true;
}

template <class D, bool H>
int Heap<D, H>::get_parent(int index_) { return (index_ - 1) / 2; }
template <class D, bool H>
int Heap<D, H>::get_left(int index_) { return (index_ * 2) + 1; }
template <class D, bool H>
int Heap<D, H>::get_right(int index_) { return (index_ * 2) + 2; }

template <class D, bool H>
void Heap<D, H>::print()
{
    
    cout << "...................................................." << endl;

    int current_line= 0;
    for(int i=0; i<current_size; i++){
        if((int) log2(i+1) != current_line){
            cout<<endl;
            current_line++;
        }
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout << "____________________________________________________" << endl;

}
