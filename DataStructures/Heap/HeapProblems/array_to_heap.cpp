#include <bits/stdc++.h>
using namespace std;

#define ui unsigned int

bool swap(vector<ui> & v, int pos1, int pos2, vector<pair<int, int> > & swaps){
    if (v[pos1] <= v[pos2]) return false;
    ui temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp; 
    swaps.push_back(make_pair(pos1, pos2));
    return true;
}

int heapify(vector<ui> & v, int pos, vector<pair<int, int> > & swaps){
    //if v[pos] is swapped, take a step back. Otherwise, take a step forward
    bool swapped = false; 

    if (pos*2+1 < v.size() && pos*2+2 < v.size() ){
        if (v[pos*2+1] < v[pos*2+2]) swapped = swap(v, pos, pos*2+1, swaps);
        else swapped = swap(v, pos, pos*2+2, swaps);

    }else if (pos*2+1 < v.size()) swapped = swap(v, pos, pos*2+1, swaps);
 
    return swapped ? -1 : 1 ;
}
vector<pair<int, int> > to_heap(vector<ui> & v){
    vector<pair<int, int> > swaps ;
    int pos = 0;
    while(pos < v.size()){
        int step = heapify(v, pos, swaps);
        pos = max(0, pos + step);
    }
    return swaps;
}

void print_swaps(vector<pair<int, int> > & v){
    for(auto it : v) cout<<it.first <<" "<<it.second<<endl;
}
void print_v(vector<ui> & v){
    for(auto it: v) cout<<it<<" ";
    cout<<endl;
}

int main(){
    int n; cin>>n;
    vector<ui> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<pair<int, int> > swaps = to_heap(v);
    cout<<swaps.size()<<endl;
    print_swaps(swaps); 
}