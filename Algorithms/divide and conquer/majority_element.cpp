#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void print(vector<ll> & v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}

ll majority(vector<ll> & v){ 

    for(int i=0; i<v.size(); i++){
        ll temp_m = v[i];
        ll temp_c = 1;
        while(i<v.size() && v[i] == temp_m) {temp_c++; i++;}
        if (temp_c > (int)v.size()/2 + 1) return 1;
    }
    return 0;
}

void merge(vector<ll> & v, int l, int m, int r){
    vector<ll> tempL(m-l+1);
    vector<ll> tempR(r-m);
    for(int i=0; i<tempL.size(); i++) tempL[i] = v[l + i];
    for(int i=0; i<tempR.size(); i++) tempR[i] = v[m + i+1]; 
    
    int i=0, j=0, k=l;
    while (i<tempL.size() && j<tempR.size()){
        if (tempL[i] <= tempR[j]) v[k++] = tempL[i++];
        else v[k++] = tempR[j++];
    }
    while (i < tempL.size()) v[k++] = tempL[i++]; 
    while (j < tempR.size()) v[k++] = tempR[j++];
}

void merge_sort(vector<ll> & v, int l, int r){ 
    
    if(l <r){
        int m = l + (r-l)/2;
        merge_sort(v, l, m );
        merge_sort(v, m+1, r );
        merge(v, l, m, r);  
    }
}


int main(){
    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    merge_sort(v, 0, v.size()-1);
    //print(v);
    cout<<majority(v)<<endl;

}