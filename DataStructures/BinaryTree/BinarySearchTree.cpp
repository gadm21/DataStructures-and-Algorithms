#include "BinarySearchTree.h"

template <class K, class V>
Node<K, V>::Node(K k, V v){
    key= k;
    value= v;

    left_node= nullptr;
    right_node= nullptr;
    parent= nullptr;
}

template <class K, class V>
bool Node<K,V>::operator < ( Node<K, V>  n){
    return key < n.get_key();
}

template <class K, class V> 
bool Node<K, V>::operator > (Node<K, V> n){
    return key > n.get_key();
}

template <class K, class V>
void Node<K, V>::print(){
    cout<<"key:"<<key<<" value:"<<value<<endl;
}



template <class K, class V> 
K Node<K, V>::get_key(){ return key;}

template <class K, class V> 
V Node<K, V>::get_value(){return value;}

template <class K, class V>
void Node<K, V>::set_key(K k){ key= k;}

template <class K, class V>
void Node<K, V>::set_value(V v){ value= v;}

template <class K, class V>
Node<K, V> * Node<K, V>::get_left_node(){ return left_node;}

template <class K, class V>
Node<K, V> * Node<K, V>::get_right_node(){ return right_node;}

template <class K, class V>
Node<K, V> * Node<K, V>::get_parent(){ return parent;}

template <class K, class V>
void Node<K, V>::set_right_node( Node<K, V> * n){ right_node= n;}

template <class K, class V>
void Node<K, V>::set_left_node( Node<K, V> * n){ left_node= n;}

template <class K, class V> 
void Node<K, V>::set_parent(Node<K, V> * n){ parent= n;}
























template <class K, class V> 
BinarySearchTree<K, V>::BinarySearchTree(){ root= nullptr;}



template <class K, class V>
void BinarySearchTree<K,V>::insert(K key, V value){
    if(!root){
        root= new Node<K,V> (key, value);
        return;
    }

    Node<K,V> *temp= root;
    bool inserted= false;
    while(!inserted){
        if(key > temp->get_key()){
            if(!temp->get_left_node()){
                temp->set_left_node(new Node<K,V> (key, value));
                temp->get_left_node()->set_parent(temp);
                inserted= true;
            }else temp= temp->get_left_node();
        }else{
            if(!temp->get_right_node()){
                temp->set_right_node(new Node<K,V> (key, value));
                temp->get_right_node()->set_parent(temp);
                inserted= true;
            }else temp= temp->get_right_node();
        }
    }
}

template <class K, class V>
bool  BinarySearchTree<K,V>::remove(K key){
    if(!root) return false;
    else if (root->get_key()==key){
        Node<K,V> * temp= root->get_right_node();
        delete root;
        root= temp;
        return true;
    }

    Node<K, V> * temp= root;

    while(temp){
        if(temp->get_key() < key){
            if(!temp->get_left_node()) return false;
            else{
                if(temp->get_left_node()->get_key() ==key) break;
                else temp= temp->get_left_node();
            }
        }else{
            if(!temp->get_left_node()) return false;
            else{
                if(temp->get_right_node()->get_key()==key) break;
                else temp= temp->get_right_node();
            }
        }
    }

    if(temp->get_left_node()->get_key()== key){
        Node<K, V> * abandoned_node= temp->get_left_node();
        temp->set_left_node(abandoned_node->get_left_node());
        if(temp->get_left_node()) temp->get_left_node()->set_parent(temp);
        delete abandoned_node;
    }else{
        Node<K, V> * abandoned_node= temp->get_right_node();
        temp->set_right_node(abandoned_node->get_right_node());
        if(temp->get_right_node()) temp->get_right_node()->set_parent(temp);
        delete abandoned_node;
    }

    return true;

}

template <class K, class V>
void BinarySearchTree<K,V>::internal_traverse(Node<K,V> * n){

    if(n){
        internal_traverse(n->get_right_node());
        n->print();
        internal_traverse(n->get_left_node());
    }
}

template <class K, class V>
void BinarySearchTree<K,V>::print(){
    internal_traverse(root);
}

int main(){
    BinarySearchTree<int, int> b;
    b.insert(33, 12);
    b.insert(33, 3);
    b.insert(33, 4);
    b.insert(33, 40);
    b.remove(33);
    b.remove(3);
    b.remove(33);
    b.insert(300, 4);
    b.print();
}