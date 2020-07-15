#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int get_index(TreeNode* root, int x, int index =1){
        if(root==NULL) return NULL;
        if (root->val != NULL && root->val == x) return index;
        int left = get_index(root->left, x, index+1);
        int right = get_index(root->right, x, index+2);
        if (left==NULL) return right;
        else return left;

    }
    bool isCousins(TreeNode* root, int x, int y){
        int pos1 = get_index(root, x);
        int pos2 = get_index(root, y);
        int ans1 = (int) log2(pos1);
        int ans2 = (int) log2(pos2);
        return ans1 == ans2
    }

};

int main(){
    
}