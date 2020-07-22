//contest URL:: https://codeforces.com/contest/1208/problems

#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

int main(){
    int t; cin>>t;
    while(t--){
        ui a, b, n; cin>>a>>b>>n;
        switch(n%3){
        case 0:
            cout<<a<<endl;
            break;
        case 1:
            cout<<b<<endl;
            break;
        default:
            cout<<(a^b)<<endl;
        }
    }
    return 0;
}
