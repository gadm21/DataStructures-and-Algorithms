// solving https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3292/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node(int d, Node * p = nullptr, Node * r = nullptr, Node * l = nullptr ) :
        data(d), right(r), left(l), parent(p) {} 

    int data ;
    Node * right = nullptr;
    Node * left = nullptr;
    Node * parent = nullptr;

    ~Node(){
        delete right;
        delete left;
        delete parent;
    }
};

class MinStack{
private:
    Node * root = nullptr;
public: 
    void push(int d){
        if (!root){
            root = new Node(d);
            return;
        }
        
        Node * current = root;
        bool inserted = false;
        while(! inserted){
            if (root->data > d){
                if (root->right) current = root->right;
                else {
                    root->right = new Node(d, current);
                    current = root->right;
                    inserted = true;
                }
                    
                
            }else{
                if (root->left) current = root->left;
                else {
                    root->left = new Node(d, current);
                    current = root->left;
                    inserted = true;
                }
            }
        }

        heapify_up(current);
    }

    int pop(){
        if (!root) return ;
        Node * new_root = get_random_leaf_node();
        int root_data = root->data;
        root = new_root ;
        return root_data;
    }

    Node * get_random_leaf_node(){
        Node * last = root;
        if(root->right) while(last->right) last = last->right;
        else while(last->left) last = last->left;

        if (last->parent) last->parent->right = nullptr;
        return last;
    }

    void heapify_up(Node * node){ 
        while(node){
            if (node->data < node->parent->data) swap_nodes(node, node->parent);
            else break;
            node = node->parent;
        }
    }
    void heapify_down(Node * node){
        
    }
    static void swap_nodes(Node * node1, Node * node2){
        int temp = node1->data ; 
        node1->data = node2->data ;
        node2->data = temp;
    }

};