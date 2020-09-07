#include <bits/stdc++.h>
#include "smarter_array_to_heap.cpp"
using namespace std;

#define ll long long 

const int C = 1e9 / RAND_MAX;

bool check_min_heap(vector<pair<ll, int> > & v){
    for(int i=0; i<v.size(); i++){
        if (i*2+1 < v.size() && v[i*2+1].first < v[i].first) return false;
        if (i*2+2 < v.size() && v[i*2+2].first < v[i].first) return false;
    }
    return true;
}

bool check_2(vector<pair<ll, int> > & v){
    ll m = 0;
    for(auto it : v) if (it.first < m) return false; else m = it.first;
    return true;
}

vector<pair<ll, int> > generate_heap(int len, int seed = 10){
    vector<pair<ll, int> > arr(len);
    srand(seed);
    for(int i=0; i<len ;i++) arr[i].first = rand() ;
    for(int i=0; i<len ;i++) arr[i].second = i;
    return arr;
}



int main(){
    for(int i=0; i<100; i++){
        vector<pair<ll, int> > arr = generate_heap(5000);
        bool check1 = check_min_heap(arr);  
        vector<pair<ll, int> > arr2 = arr;
        sort(arr2.begin(), arr2.end(), critereon);

        vector<pair<int, int> > swaps ;

        bool check2 = check_2(arr2); 
        
        if (i%10==0)cout<<"trail :"<<i<<endl;
        if (!check2){
            cout<<"failed at:"<<i<<endl;
            print_v(arr2);
            print_v(arr);
            print_swaps(swaps);
            break;
        }
        if (i==99) cout<<"no faults"<<endl;
    }
    
}
