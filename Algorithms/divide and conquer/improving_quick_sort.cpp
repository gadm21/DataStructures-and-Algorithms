#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void print(vector<ll> & v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}



vector<int> get_borders(vector<ll> & v, int pivot, int l, int r){
    vector<int> m = {-1, -1};
    for(int i=l; i<=r; i++){
        if (v[i]==v[pivot]){
            if (m[0] == -1) m[0] = i;
            else if (i+1 == v.size()|| v[i+1]!=v[pivot]) m[1] = i; 
        }
    }
    return m;
}

void swap(vector<ll> & v, int s, int i){
    //cout<<"swaping"<<" s:"<<s<<" L:"<<i<<endl;
    ll temp = v[s];
    v[s] = v[i];
    v[i] = temp;
}

int comfort_pivot(vector<ll> & v, int l, int r){
    int p = l;
    int s=l, b=0;
    for(int i=l+1; i<=r; i++){
        if (v[i] < v[p]){
            s++;
            swap(v, s, i);
        }
    }
    swap(v, p, s);
    return s;
}



void quicksort(vector<ll> & v, int l, int r, int c=0){
    if (c>100) return;
    if (l<r){
        int pivot = comfort_pivot(v, l, r);
        cout<<"pivot:"<<pivot<<" l:"<<l<<" r:"<<r<<" c:"<<c<<endl;
        print(v);
        vector<int> m = get_borders(v, pivot, l, r);
        //quicksort(v, l, m[0]-1, c+1);
        //quicksort(v, m[1]+1, r, c+1);
        quicksort(v, l, pivot-1, c+1);
        quicksort(v, pivot+1, r, c+1);
    }
}






int main(){
    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    quicksort(v, 0, v.size()-1);
    print(v);
}