//URL:: https://practice.geeksforgeeks.org/problems/inorder-traversal-and-bst/0

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);

        bool BST= true;
        int xx; 
        cin>>xx; 
        v[0]= xx;
        for(int i=1; i<n; i++){
            int x; cin>>x;
            if(x <= v[i-1]) BST= false;
            v[i]= x;
        }
        if(BST) cout<<1<<endl; else cout<<0<<endl;
    }   
}