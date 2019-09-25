//contest URL:: https://codeforces.com/contest/1208/problems

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli find_max(const vector<lli> &v, int index, int w){
    int lost= w- v.size();
    int n= v.size();
    lli ans= INT_MIN;
    int start= max(0, index- lost);
    int end= min(index+1, n);

    for(int i= start; i<end; i++) ans= ((ans>= v[i])? ans: v[i]);

    if(lost && ans<0) ans=0;
    return ans;

}

int main(){
    int n, w; cin>>n>>w;
    vector< vector<lli> > v(n);

    for(int i=0; i<n; i++){
        int x; cin>>x;
        v[i]= vector<lli> (x);
        for(int j=0; j<x; j++) cin>>v[i][j];
    }

    for(int i=0; i<w; i++){
        lli sum=0;
        for(int j=0; j<n; j++){
            lli ans= find_max(v[j], i, w);
            sum+= ans;
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}
