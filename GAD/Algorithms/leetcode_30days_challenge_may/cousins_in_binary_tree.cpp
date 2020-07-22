#include <bits/stdc++.h>
using namespace std;

#define null 0 
class TreeNode{
public:
    int val = null;
    TreeNode * right = NULL;
    TreeNode * left = NULL;
    TreeNode(int v): val(v){} 
    ~TreeNode(){delete right; delete left;}

};

class Solution{
public:
    int get_index(TreeNode* root, int x, int index =1){
        if(root==nullptr) return 0;
        if (root->val == x) return index;
        int left = get_index(root->left, x, index*2);
        int right = get_index(root->right, x, (index*2)+1);
        if (left==0) return right;
        else return left;

    }
    bool isCousins(TreeNode* root, int x, int y){
        int pos1 = get_index(root, x);
        int pos2 = get_index(root, y);
        
        int ans1 = (int) log2(pos1);
        int ans2 = (int) log2(pos2);

        bool same_parent = false;
        if (pos1%2) {if(pos2 == pos1-1) same_parent = true;}
        else if(pos2 == pos1+1) same_parent = true;

        return (ans1 == ans2 && ! same_parent);
    }

};

TreeNode * get_tree(){
    TreeNode * root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left = new TreeNode(3);
    TreeNode * r = root->right; 
    TreeNode * l = root->left;
    l->left = new TreeNode(null);
    l->right = new TreeNode(4);
    r->left = new TreeNode(null);
    r->right = new TreeNode(5);
    return root;

}

int main(){
    TreeNode * tree = get_tree() ;
    Solution sol ; 
    cout<<sol.isCousins(tree, 5,4)<<endl;
}