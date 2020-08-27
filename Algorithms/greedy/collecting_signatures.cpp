#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare_segs(pair<ll, ll> p1, pair<ll,ll> p2){
    return p1.first < p2.first;
}

void print(vector<ll> & v){
    for(auto i : v) cout<<i<<" ";
    cout<<endl;
}
ll get_intersection_point(vector<pair<ll, ll> > & v){
    ll point = -1;
    for(auto seg : v) if (seg.first > point) point = seg.first;
    return point;
}

bool fit_inside(pair<ll, ll> seg, vector<pair<ll, ll> > & v){
    for(auto s : v) if (seg.first > s.second) return false;
    return true;
}

int main(){
    int n; cin>>n;
    vector<pair<ll, ll > > segs(n);
    for(int i=0; i<n; i++){
        ll x1, x2 ; cin>>x1>>x2;
        segs[i] = make_pair(x1, x2);
    }

    sort(segs.begin(), segs.end(), compare_segs);
    
    vector<ll> results;
    int current = 0;
   for(int current=0; current<n; current++){
        vector<pair<ll, ll> > groups = {segs[current]};
        while (current+1 < n && fit_inside(segs[current+1], groups)) {current++; groups.push_back(segs[current]);}
        results.push_back(get_intersection_point(groups));
    }
    cout<<results.size()<<endl;
    print(results);
}