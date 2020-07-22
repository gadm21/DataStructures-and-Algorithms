#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void fill_primes(int n){
    int last= 2;
    while(last<=n){
        bool found= true;
        for(int i=2; i<=sqrt(last); i++) if(last%i==0) {found= false; break;}
        if(found) primes.push_back(last);
        last++;
    }
}

int find_type(int l, int r, int a, int b){
    for(int i=r-1; i>=l; i--){
        int counter=0;
        int temp= i;
        for(int j=0; j< primes.size() && temp!=1 ; j++)
            if(temp%primes[j]==0)
                { temp/=primes[j];  counter++;}
        if(counter>= a && counter<= b && temp==1) return i;
    }
    return -1;
}

void print(){
    for(int i=0; i<primes.size(); i++) cout<<primes[i]<<" ";
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){

        int l, r, a, b; cin>>l>>r>>a>>b;
        fill_primes(r);
        cout<<find_type(l, r, a, b)<<endl;
        primes.clear();
    }
}
