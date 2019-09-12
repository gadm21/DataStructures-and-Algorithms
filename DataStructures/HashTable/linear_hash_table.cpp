#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int

template< class T>
class Node{
    public:
        string key;
        T value;
        Node(string k, T v);
};

template<class T>
Node<T>::Node(string k, T v){ key= k; value= v;}


template< class T>
class LinearHashTable{
    private:
        ui MAXSIZE;
        Node<T>** arr;
        ui hash(string key);
    public:
        LinearHashTable(ui maxsize= 100);

        bool insert(string key, T value);
        bool delete_element(string key);

        void print();
        Node<T>* operator[] (string key);
};


template <class T>
LinearHashTable<T>::LinearHashTable(ui maxsize){
    MAXSIZE= maxsize;
    arr=(Node<T>**) malloc(MAXSIZE* sizeof(Node<T>*));
    for(int i=0; i<MAXSIZE; i++) arr[i]= nullptr;
}

template<class T>
ui LinearHashTable<T>::hash(string key){
    ui total=0;
    for(int i=0; i<key.length(); i++) total+= (int) key[i];

    return total% MAXSIZE;
}

template<class T>
bool LinearHashTable<T>::insert(string key, T value){
    ui index= hash(key);
    ui counter =0; //to avoid infinite loop

    while(arr[index % MAXSIZE] && arr[index % MAXSIZE]->key!= key && counter < MAXSIZE)index++, counter++;

    index%= MAXSIZE;
    if(!arr[index]) arr[index]= new Node<T>(key, value);
    else if (arr[index]->key== key) arr[index]->value= value;
    else return false;

    return true;
}

template<class T>
bool LinearHashTable<T>::delete_element(string key){
    ui index= hash(key);

    ui counter=0; //to avoid inifinite loop
    while(arr[index % MAXSIZE] && arr[index % MAXSIZE]->key!= key && counter< MAXSIZE) index++, counter++;

    index%= MAXSIZE;
    if(!arr[index] || counter== MAXSIZE) return false;

    delete arr[index];
    arr[index]= nullptr;
    return true;
}

template<class T>
void LinearHashTable<T>::print(){
    for(int i=0; i<MAXSIZE; i++){
        
        cout<<i<<". ";

        if(arr[i]) cout<<arr[i]->value;
        else cout<<"__";

        cout<<"       ";

        if(i && i% 10 == 0) cout<<'\n';
    }
    cout<<endl;
}

template<class T>
Node<T>* LinearHashTable<T>::operator[](string key){
    ui index= hash(key);

    ui counter=0; //to avoid infinite loop
    while(arr[index % MAXSIZE] && arr[index % MAXSIZE]->key!= key && counter< MAXSIZE) index++, counter++;

    index%= MAXSIZE;
    //if(arr[index] && counter< MAXSIZE) 
    return arr[index];

}

