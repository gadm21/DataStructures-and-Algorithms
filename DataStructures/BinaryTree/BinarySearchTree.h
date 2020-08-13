#include <bits/stdc++.h>
using namespace std;

template <class K, class V>
class Node{
    private:
        K key;
        V value;

        Node<K, V> * left_node;
        Node<K, V> * right_node; 
        Node<K, V> * parent;
        
    public:
        Node(K k, V v);
        bool operator < ( Node<K, V> n);
        bool operator > ( Node<K, V> n);
        void print();
        
        void set_key(K k);
        void set_value(V v);
        K get_key();
        V get_value();

        void set_left_node(Node<K, V> * n);
        void set_right_node(Node<K, V> * n);
        void set_parent(Node<K,V> * n);
        Node<K, V> * get_left_node();
        Node<K, V> * get_right_node();
        Node<K, V> * get_parent();

        bool isLeaf();
};




template <class K, class V> 
class BinarySearchTree{
    private:
        Node<K,V> * root;
        void internal_traverse(Node<K,V> * n);
    public:
        BinarySearchTree();
        Node<K,V> * get_root();
        void insert( K key, V value=0);
        bool remove( K key);
        void print();
};