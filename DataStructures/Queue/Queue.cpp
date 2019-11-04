#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue{
    T *arr;
    unsigned int current_size= 0;
    unsigned int max_size;
public:
    Queue(int size= 100);
    void push(T element);
    T* pop();
    void print();

    ~Queue();
};

template<class T>
Queue<T>::Queue(int size){
    arr= (int*) calloc(size, sizeof(T));
    max_size= size;
}

template<class T>
Queue<T>::~Queue(){
    delete arr;
}

template<class T>
void Queue<T>::push(T element){
    if(current_size>= max_size) resize();
    arr[(current_size%max_size)++]= element;
}

template<class T>
T* Queue<T>::pop(){
    
}