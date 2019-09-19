#include <bits/stdc++.h>
using namespace std;

bool sorting(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.first< b.first;
}

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int, pair<int, int> > > v;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            v.push_back(make_pair(x, make_pair(0, 0)));
        }
        for(int i=0; i<n; i++){
            int x, y; cin>>x>>y;
            v[i].second.first= x;
            v[i].second.second= y;
        }
        sort(v.begin(), v.end(), sorting);
        unsigned int distance= 0;
        pair<int, int> current= v[0].second;
        for(int i=1; i<n; i++){
            #cout<<"first:"<<current.first<<" second:"<<current.second<<endl;
            pair<int, int> temp= v[i].second;
            distance+= abs(temp.first- current.first) + abs(temp.second- current.second);
            current= temp;
        }
        cout<<distance;
    }
}
