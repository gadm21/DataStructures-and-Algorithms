#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;

    vector<int> options= {10, 5, 1};
    int coins = 0 ;
    for(auto option : options){
        if (n >= option ){
            int tmp_coins = int(n/option);
            n -= (tmp_coins * option);
            coins += tmp_coins;
        }
    }

    cout<<coins<<endl;
}