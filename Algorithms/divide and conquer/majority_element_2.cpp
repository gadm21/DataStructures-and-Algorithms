#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int n; cin>>n;
    map<int, int> m;
   for(int i=0; i<n; i++){
        int x ; cin>>x;
        m[x]++;
    }
    int answer = 0;
    for(auto i : m) if (i.second > (int)n/2) {answer =1; break;} 
    cout<<answer<<endl;
}