#include <bits/stdc++.h>
using namespace std;

#define ll long long 




int count_inversions(vector<ll> & v){
    int count = 0;
    for(int i=1; i<v.size(); i++){
        if (v[i] < v[i-1]){
            int j=i-1;
            while(j>=0 && v[j] > v[i]){j--; count++;}
        }
    }
    return count;
}


int main(){
    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<count_inversions(v)<<endl;
}