#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int get_index(vector<ll> & arr, int element){
    for(int i=0; i<arr.size(); i++) if(arr[i]==element) return i;
    return -1;
}

vector<pair<int, int> > smart_to_heap(vector<ll> & arr, vector<ll> & arr2){
    vector<pair<int, int> > swaps ;
    for(int i=0; i<arr.size(); i++){
        int in = get_index(arr2, arr[i]);
        if (in <= i) continue ;
        swaps.push_back(make_pair(i, in));
    }
    return swaps;
}

void print_swaps(vector<pair<int, int> > & swaps){
    for(auto it : swaps) cout<<it.first<<" "<<it.second<<endl;
}

 
int main(){
    
    int n; cin>>n;
    vector<ll> arr (n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    
    vector<ll> arr2(arr);
    sort(arr2.begin(), arr2.end()) ;
    vector<pair<int, int> > swaps = smart_to_heap(arr, arr2);
    cout<<swaps.size()<<endl;
    print_swaps(swaps);
}