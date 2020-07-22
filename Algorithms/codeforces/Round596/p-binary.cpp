#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    int p; cin>>p;

    n+=p;
    
    if(n<=0) cout<<-1<<endl;
    else{
        int count=0;
        while(n){
            if(n&1) count++;
            n>>=1;
        }
        cout<<count<<endl;
    }
}