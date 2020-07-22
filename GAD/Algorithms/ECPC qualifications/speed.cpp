#include <bits/stdc++.h>
using namespace std;

bool sorting(pair<long long int, string> a, pair<long long int, string> b){ return a.first> b.first;}

int main(){

    int t; cin>>t;
    while(t--){
        vector<pair<long long int, string> > v= {make_pair(0, "Alex"), make_pair(0, "Katy"), make_pair(0, "Mahdi"), make_pair(0, "Noura")};
        for(int i=0; i<4; i++) cin>>v[i].first;
        sort(v.begin(), v.end(), sorting);
        cout<<v[0].second<<" "<<v[1].second<<endl;
    }
}

