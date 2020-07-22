//contest URL:: https://codeforces.com/contest/1208/problems

#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

ui nsquare_logn_solution(const vector<ui> &v){
    if(v.empty()) return 0;
    int n= v.size();


    ui ans= n-1;
    map<ui, ui> m;
    for(int i=0; i<n; i++){
        bool validPrefix= true;

        for(int j=0; j<i; j++)
            if(m[v[j]]) {validPrefix= false; break;}
            else m[v[j]]++;

        ui min_suffix_index= n;
        for(int j=n-1; j>=i; j--)
            if(m[v[j]]) break;
            else {m[v[j]]++; min_suffix_index= j;}

        if(validPrefix) ans= min(ans, min_suffix_index-i);

        m.clear();
    }

    return ans;
}

ui n_logn_solution(const vector<ui> &v){
    if(v.empty()) return 0;
    int n= v.size();
    map<ui, ui> m;

    int i=0;
    for(; i<n; i++)
        if(!m[v[i]]) m[v[i]]++;
        else break;

    int j=n-1;
    for(; j> i; j--)
        if(!m[v[j]]) m[v[j]]++;
        else break;

    ui ans= n- (i+ (n-j-1));
    return ans;
}


int main(){
    ui n; cin>>n;
    vector<ui> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    cout<<n_logn_solution(v)<<endl;
    cout<<nsquare_logn_solution(v)<<endl;
}
