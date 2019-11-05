#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
private:
    T *arr;
    unsigned int current_size = 0, start = 0, end = 0;
    unsigned int max_size;
    void resize();

public:
    Queue(int size = 100);
    void push(T element);
    T *pop();
    void print();

    ~Queue();
};

template <class T>
Queue<T>::Queue(int size)
{
    arr = (int *)calloc(size, sizeof(T));
    max_size = size;
}

template <class T>
Queue<T>::~Queue()
{
    delete arr;
}

template <class T>
void Queue<T>::push(T element)
{
    if (current_size >= max_size)
        resize();

    current_size++;
    arr[(end++ % max_size)] = element;
}

template <class T>
T *Queue<T>::pop()
{
    if (!current_size)
        return nullptr;

    current_size-=1;
    //note that ptr will still point to the element location even after it's returned,
    // but since we consider it a deleted element in the queue there's nothing to worry about
    // even if the user changed it after it's returned to him
    T *ptr = &arr[start++];

    return ptr;
}

template <class T>
void Queue<T>::resize()
{
    max_size *= 2;
    int *new_arr = (int *)calloc(max_size, sizeof(T));

    for (int i = start, counter = 0; counter <= current_size; counter++, i++)
        new_arr[counter] = arr[i];
    

    start = 0, end = current_size;
    delete arr;
    arr= new_arr;
}


template<class T>
void Queue<T>::print(){
    for(int i=0, index= start; i<current_size; i++, index++){
        cout<<arr[index]<<" ";
    }
    cout<<endl;
}

