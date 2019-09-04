#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int

template<class T>
class Node{
    public:
        T Data;
        Node *Prev, *Next;
        Node(T data, Node* prev= nullptr, Node* next= nullptr){
            Data= data;
            Prev= prev;
            Next= next;
        }

        void print(){
            std::cout<<Data<<std::endl;
        }
};

template <class T>
class DLList{
    private:
        ui count=0;
        void merge_sort(int first, int last);
        void merge(int first, int middle, int last);
    public:
        Node<T> *head;

        DLList();
        ~DLList(); 

        void push_back(T data);
        void push_front(T data);

        Node<T>* pop_back(); //we return pointer so that we can return nullptr if the list is empty
        Node<T>* pop_front();
        
        bool delete_element(T data);

        void merge_sort();
        
        Node<T>* operator[](int i);

        void print();
};


template <class T>
DLList<T>::DLList(){ this->head= nullptr;}

template<class T>
DLList<T>::~DLList(){
    
}

template <class T>
void DLList<T>::push_back(T data){
    Node<T> *n= new Node<T> (data);

    if(!head) head=n;
    else{
        Node<T>* temp= head;
        while(temp->Next!= nullptr) temp= temp->Next;

        temp->Next= n;
        n->Prev= temp;
    }
    count++;
}

template <class T>
void DLList<T>::push_front(T data){
    Node<T>* n= new Node<T>(data);

    if(!head) head= n;
    else{
        head->Prev= n;
        n->Next= head;
        head= n;
    }
    count++;

}

template <class T>
void DLList<T>::print(){
    for(Node<T>* temp= head; temp; temp= temp->Next) temp->print();
}

template<class T>
Node<T>* DLList<T>::pop_back(){
    if(!head) return nullptr;
    Node<T>* tail= head;
    while(tail->Next!= nullptr) tail= tail->Next;

    if(tail->Prev) tail->Prev->Next= nullptr;
    else head= nullptr;
    tail->Prev= tail->Next= nullptr;
    count--;
    return tail;
}

template <class T>
Node<T>* DLList<T>::pop_front(){

    if(!head) return nullptr;
    Node<T>* temp= head;
    head= temp->Next;
    if(head) head->Prev= nullptr;
    temp->Next= nullptr;
    count--;
    return temp;
}

template <class T>
bool DLList<T>::delete_element(T data){
    
    Node<T>* temp= head;
    for(; temp!= nullptr; temp= temp->Next) if(temp->Data== data) break;

    if(temp== nullptr) return false;
    if(temp->Prev!= nullptr) temp->Prev->Next= temp->Next;
    if(temp->Next!= nullptr) temp->Next->Prev= temp->Prev;
    delete temp;
    count--;
    return true;
}

template<class T>
void DLList<T>::merge_sort(){
    merge_sort(0, count-1);
}

template<class T>
void DLList<T>::merge_sort(int first, int last){
    if(first< last){
        int middle= first+ (last- first)/2;

        merge_sort(first, middle);
        merge_sort(middle+1, last);

        merge(first, middle, last);
    }
}

template<class T>
void DLList<T>::merge(int first, int middle, int last){
    ui size1= middle- first+1;
    ui size2= last- middle;

    vector<T> v1(size1);
    vector<T> v2(size2);

    for(int i=0; i<size1; i++) v1[i]= (*this)[i+ first]->Data;
    for(int i=0; i<size2; i++) v2[i]= (*this)[middle+ i+ 1]->Data;

    int i=0, j=0, k=first;
    while(i< size1 && j< size2){
        if(v1[i]<= v2[j]) (*this)[k++]->Data= v1[i++];
        else (*this)[k++]->Data= v2[j++];
    }

    while(i< size1) (*this)[k++]->Data= v1[i++];
    while(j< size2) (*this)[k++]->Data= v2[j++];
}

template<class T>
Node<T>* DLList<T>::operator[](int index){
    if(!head) return nullptr;
    int i=0;
    for(Node<T>* temp= head; temp; i++, temp= temp->Next) if(i== index) return temp;
    return nullptr;
}
