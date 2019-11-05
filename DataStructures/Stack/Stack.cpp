//there's a bug:
//if "end" got big enough it will overload and return to 0 which will corrupt the bounds
//of "arr". Although this is an extreme case, it is still considered a bug

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack{
private:
    T* arr;
    unsigned int top=0, max_size;
    void resize();
public:
    Stack(int size= 100);
    ~Stack();

    void push(T element);
    T* pop();

    void print();
};

template <class T>
Stack<T>::Stack(int size){
    arr= (T*) calloc(size, sizeof(T));
    max_size= size;
}

template <class T>
Stack<T>::~Stack(){
    delete arr;
}

template <class T>
void Stack<T>::resize(){
    max_size*=2;
    T *new_arr= (T*) calloc(max_size, sizeof(T));

    for(int i=0; i<top; i++) new_arr[i]= arr[i];
    
    delete arr;
    arr= new_arr;

}

template <class T>
void Stack<T>::push(T element){
    if(top==max_size) resize();

    arr[top++]= element;
}

template <class T>
T* Stack<T>::pop(){

    if(!top) return nullptr;
    
    return &arr[--top];
}

template <class T>
void Stack<T>::print(){
    for(int i=0; i<top; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

