#include "../../../DataStructures/BinaryTree/BinarySearchTree.cpp" 



int diameterHelper(Node<int,int> * node, vector<int> & results){
    int right=0, left=0;
    if(node==nullptr) return 0;
    else{
        if (node->get_left_node()) right = diameterHelper(node->get_left_node(), results) + 1;
        if (node->get_right_node()) left = diameterHelper(node->get_right_node(), results) + 1;
        results.push_back(right+left);
    }
    return max(right, left);    
}

int diameterOfBinaryTree(Node<int, int> * node){
    vector<int> results;
    diameterHelper(node, results);
    return results.empty() ? 0 : * max_element(results.begin(), results.end());
}

int main(){
    for(int i=0; i<1; i++){
        BinarySearchTree<int, int> b;
        b.insert(10);
        b.insert(3);
        b.insert(33);
        b.insert(333);
        b.insert(334);
        b.insert(300, 4);
        b.insert(290, 4);
        b.insert(7);
        b.insert(6);
        b.insert(294);
        b.insert(331); 
    cout<< diameterOfBinaryTree(b.get_root())<<endl;
    }

}