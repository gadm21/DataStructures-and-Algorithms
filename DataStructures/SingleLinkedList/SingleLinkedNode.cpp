#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int


template<class T>
class Node{
    public:
        T Data;
        Node *Next; //SingleLinkedList Doens't have Node<T> *prev pointer, DoubleLinkedList has
        Node(T data, Node* next= nullptr){
            Data= data;
            Next= next;
        }

        void print(){
            std::cout<<Data<<std::endl;
        }
};

template <class T>
class SLList{
    private:
        ui count=0;
        void merge_sort(int first, int last);
        void merge(int first, int middle, int last);
    public:
        Node<T> *head;

        SLList();
        ~SLList(); 

        void push_back(T data);
        void push_front(T data);

        Node<T>* pop_back(); //we return pointer so that we can return nullptr if the list is empty
        Node<T>* pop_front();
        
        bool delete_element(T data);

        void merge_sort();
        
        Node<T>* operator[](int i);

        void print();
};