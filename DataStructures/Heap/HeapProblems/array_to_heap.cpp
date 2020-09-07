#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool swap(vector<ll> & v, int pos1, int pos2, vector<pair<int, int> > & swaps){
    if (v[pos1] <= v[pos2]) return false;
    ll temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp; 
    swaps.push_back(make_pair(pos1, pos2));
    return true;
}

int heapify(vector<ll> & v, int pos, vector<pair<int, int> > & swaps){
    //if v[pos] is swapped, take a step back. Otherwise, take a step forward
    bool swapped = false; 

    if (pos*2+1 < v.size() && pos*2+2 < v.size() ){
        if (v[pos*2+1] < v[pos*2+2]) swapped = swap(v, pos, pos*2+1, swaps);
        else swapped = swap(v, pos, pos*2+2, swaps);

    }else if (pos*2+1 < v.size()) swapped = swap(v, pos, pos*2+1, swaps);
 
    return swapped ? (pos-1)/2 : pos+1 ;
}
vector<pair<int, int> > to_heap(vector<ll> & v){
    vector<pair<int, int> > swaps ;
    int pos = 0;
    while(pos < v.size()){
        int new_pos = heapify(v, pos, swaps);
        
        pos = max(0, new_pos); 
    }
    return swaps;
}

void print_swaps(vector<pair<int, int> > & v){
    for(auto it : v) cout<<it.first <<" "<<it.second<<endl;
}
void print_v(vector<ll> & v){
    for(auto it: v) cout<<it<<" ";
    cout<<endl;
}


int main(){
    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<pair<int, int> > swaps = to_heap(v);
    cout<<swaps.size()<<endl;
    print_swaps(swaps); 
}
