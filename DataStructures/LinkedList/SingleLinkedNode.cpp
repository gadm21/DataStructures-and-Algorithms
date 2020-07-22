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
            std::cout<<Data<<" ";
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

template<class T>
SLList<T>::SLList(){ head= nullptr;}
template<class T>
SLList<T>::~SLList(){}

template<class T>
void SLList<T>::push_back(T data){
    Node<T>* n= new Node<T>(data);

    if(!head) head= n;
    else{
        Node<T>* temp= head;
        while(temp->Next) temp= temp->Next;
        temp->Next= n;
    }
    count++;
}
template<class T>
void SLList<T>::push_front(T data){
    Node<T>* n= new Node<T>(data);
    n->Next= head;
    head= n;
    count++;
}

template<class T>
Node<T>* SLList<T>::pop_back(){
    if(!head) return nullptr;

    Node<T>* temp= (*this)[count-1];
    if(count>1) ((*this)[count-2])->Next= temp->Next;
    count--;

    return temp;
}
template<class T>
Node<T>* SLList<T>::pop_front(){
    if(!head) return nullptr;

    Node<T>* temp= head;
    head= temp->Next;
    count--;
    
    return temp;
}

template<class T>
bool SLList<T>::delete_element(T data){
    if(!head) return nullptr;

    Node<T>* temp= head;
    int i=0; 
    for(; temp; i++, temp= temp->Next) if(temp->Data== data) break;

    if(temp){
        if(i) ((*this)[i-1])->Next= temp->Next;
        delete temp;
        count--;

        return true;
    }else return false;
}

template<class T>
void SLList<T>::merge_sort(){
    merge_sort(0, count-1);
}
template<class T>
void SLList<T>::merge_sort(int first, int last){
    if(first< last){
        int middle= first+ (last- first)/2;

        merge_sort(first, middle);
        merge_sort(middle+1, last);

        merge(first, middle, last);
    }
}
template<class T>
void SLList<T>::merge(int first, int middle, int last){
    int size1= middle- first+ 1;
    int size2= last- middle;

    vector<T> v1(size1);
    vector<T> v2(size2);

    for(int i=0; i<size1; i++) v1[i]= (*this)[first+ i]->Data;
    for(int i=0; i<size2; i++) v2[i]= (*this)[middle+1 +i]->Data;

    int i=0, j=0, k=first;
    while(i< size1 && j< size2){
        if(v1[i]<= v2[j]) (*this)[k++]->Data= v1[i++];
        else (*this)[k++]->Data= v2[j++];
    }

    while(i< size1) (*this)[k++]->Data= v1[i++];
    while(j< size2) (*this)[k++]->Data= v2[j++];
}


template<class T>
Node<T>* SLList<T>::operator[](int index){
    if(!head) return nullptr;

    int i=0; 
    for(Node<T>* temp= head; temp; i++, temp= temp->Next) if(i== index) return temp;
    return nullptr;
}

template<class T>
void SLList<T>::print(){
    for(Node<T>* temp= head; temp; temp= temp->Next) temp->print();
    cout<<endl;
}
