#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

template <class T>
class HashTable{
    public:
        int MAXSIZE;
        vector<vector<pair<string, T> > > v;
        ui hash(string key);
    public:
        int x=3;
        HashTable(int maxsize=100);

        void insert(string key, T value);
        bool delete_element(string key);

        void print();
        T* operator[](string key);
};

template <class T>
HashTable<T>::HashTable(int maxsize){
    MAXSIZE= maxsize;
    v.resize(maxsize);
}

template<class T>
ui HashTable<T>::hash(string key){
    ui total=0;
    for(int i=0; i<key.length(); i++) total+= (int)key[i];
    
    
    return total%MAXSIZE;
}

template<class T>
bool HashTable<T>::delete_element(string key){
    ui index= hash(key);
    vector<pair<string, T> > target_v= v[index];

    int i=0;
    for(; i<target_v.size(); i++) if(v[index][i].first== key) break;

    if(i==target_v.size()) return false;
    
    v[index].erase(v[index].begin()+ i);
    return true;
}

template<class T>
void HashTable<T>::insert(string key, T value){
    ui index= hash(key);
    vector<pair<string, T> > target_v= v[index];

    for(int i=0; i<target_v.size(); i++) if(target_v[i].first== key) {target_v[i].second= value; return;}

    v[index].push_back(make_pair (key, value));
}

template<class T>
T* HashTable<T>::operator[](string key){
    ui index= hash(key);

    for(int i=0; i<v[index].size(); i++) if(v[index][i].first== key) return (&v[index][i].second);

    return nullptr;
    
}

template<class T>
void HashTable<T>::print(){
    for(int i=0; i<MAXSIZE; i++){
        if(v[i].size()==0) continue;
        vector<pair<string, T> > target= v[i];
        cout<<"i:"<<i<<" ->";
        for(int j=0; j<target.size(); j++)cout<<target[j].first<<" ";
        cout<<endl;
    }
}
