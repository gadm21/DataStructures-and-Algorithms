//URL:: https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0


#include <bits/stdc++.h>
using namespace std;

string package(string s){
    return '('+s+')';
}

void apply_permutations(string s, vector<string> & v, int ii=1){
    
    for(int i=ii; i< s.length(); i++){
        string new_s= s.substr(0, i)+ ' '+ s.substr(i, s.length());
       
        apply_permutations(new_s, v, i+2);
    }
     v.push_back(package(s));

}

void print_v(vector<string> v){
    for(auto s : v){
        cout<<s;
    }
    cout<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        vector<string> v;
        apply_permutations(s, v);
        print_v(v);
    }
}