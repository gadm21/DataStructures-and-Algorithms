#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long int n; cin>>n;
        long long int result= 0;
        n--;
        for(int i=2; i<=10; i++){
            for(int j=0; j<n; j++) if(j%2==0) result+= (pow(i, n)); else result+= pow((10-i), n);

        }
        cout<<result<<endl;
    }
}
