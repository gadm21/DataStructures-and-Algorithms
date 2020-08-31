#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int binary_search(vector<ll> & v, ll k){
    int l = 0, r = v.size()-1;
    while(l <=r){
        int middle = l + (r-l)/2;
        if(v[middle] == k) return middle;
        if(v[middle] < k) l = middle +1;
        else r = middle -1;
    }
    return -1;
}

void print(vector<ll> & v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}

int main(){
    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int k; cin>>k;
    vector<ll> ans(k); 
    for(int i=0; i<k; i++) cin>>ans[i];
    for(int i=0; i<k; i++) ans[i] = binary_search(v, ans[i]);
    print(ans);
}