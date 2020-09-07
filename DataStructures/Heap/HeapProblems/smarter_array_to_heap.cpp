#include <bits/stdc++.h>
using namespace std;

#define ll long long 

bool critereon(pair<ll, int> p1, pair<ll, int> p2){
    return p1.first < p2.first ;
}

vector<pair<int, int> > get_swaps(vector<pair<ll, int> > & v0, vector<pair<ll, int> > & v){
    vector<pair<int, int> > swaps ;
    for(int i=0; i<v.size(); i++){
        if (i >= v[i].second) continue;
        swaps.push_back(make_pair(i, v[i].second));
    }
    return swaps;
}

void print_swaps(vector<pair<int, int> > & swaps){
    for(auto it : swaps) cout<<it.first<<" "<<it.second<<endl;
}

void print_v(vector<pair<ll, int> > & v){
    for(auto it : v) cout<<it.first<<" "<<it.second<<endl;
    
}



int main(){
    int n; cin>>n;
    vector<pair< ll, int> > v(n);
    for(int i=0; i<n; i++){
        ll x; cin>>x;
        v[i] = make_pair(x, i);
    }
    vector<pair< ll, int> > sorted_v(v);
    sort(sorted_v.begin(), sorted_v.end(), critereon);
    
    vector<pair<int, int> > swaps = get_swaps(v, sorted_v);

    cout<<swaps.size()<<endl;
    print_swaps(swaps);
}

